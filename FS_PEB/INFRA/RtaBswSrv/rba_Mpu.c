/*<BASDKey>
 **********************************************************************************************************************
 *
 * COPYRIGHT RESERVED, 2010 Robert Bosch GmbH. All rights reserved.
 * The reproduction, distribution and utilization of this document as well as the communication of its contents to
 * others without explicit authorization is prohibited. Offenders will be held liable for the payment of damages.
 * All rights reserved in the event of the grant of a patent, utility model or design.
 *
 **********************************************************************************************************************
 * Administrative Information (automatically filled in)
 * $Domain____:BASD$
 * $Namespace_:\Comp\rba_Mpu$
 * $Class_____:C$
 * $Name______:rba_Mpu$
 * $Variant___:AR40.4.0.0$
 * $Revision__:0$
 **********************************************************************************************************************
</BASDKey>*/

/*!
 * \rba_comp rba_Mpu
 *  @{
 */

/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
 */

#include "Mcal.h"
//#include "rba_Emm.h"
//#include "rba_Reg.h"
#include "rba_BswSrv.h"     // MPU special function register
#include "rba_Mpu.h"
#include "rba_Mpu_Prv.h"
#include "rba_Mpu_Cfg.h"
#include "IfxCpu_reg.h"
#include "rba_Reset.h"

/* **************************************** */

#if ((MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1))


/*
 ***************************************************************************************************
 * Global Variables
 ***************************************************************************************************
 */

/* Start MemMap for default code */
#define RBA_MPU_START_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

/**
 ***************************************************************************************************
 * \brief configuration function for the crossbar MPU
 *
 * \param[in]       indexCores_u32      number of cores to configure
 * \param[in]       rba_Mpu_Region_ast  two dimentional array structure with the regions for the cores
 * \param[in]       regionCounter_au32  array with the different region counter for the cores
 *
 * \return void
 *
 * This function configures the all defined regions for the uC.
 *
 * \rb_example Example:
 * \code
 * void main(void)
 * {
 *      uint32 regionCounter[1];
 *      regionCounter[0] = 1;
 *      rba_Mpu_Region_tst rba_Mpu_Region_st[1][1];
 *
 *      rba_Mpu_Region_st[0][0].startAddress_u32 = 0x00000000;
 *      rba_Mpu_Region_st[0][0].endAddress_u32 = 0xFFFFFFFF;
 *      rba_Mpu_Region_st[0][0].accessCfg_u32 = 0x00010003;
 *
 *      rba_Mpu_SetCrossbarMpuCfg(1, rba_Mpu_Region_st, 1);
 * }
 * \endcode
 *
 ***************************************************************************************************
 */
/* MISRA RULE 16.7 VIOLATION: QAC is wrong, the array is modified in a sub function */
void rba_Mpu_SetCrossbarMpuCfg(uint32 indexCores_u32, rba_Mpu_Region_tst rba_Mpu_Region_ast[][RBA_MPU_MAX_REGION_NUMBER], const uint32 regionCounter_au32[])
{

    Std_ReturnType xRet = E_OK;
    uint32 index_u32;

    uint32 coreFlag0_u32 = 0;
    uint32 coreFlag1_u32 = 0;
    uint32 coreFlag2_u32 = 0;
    uint32 tmp_Flag_u32;

    uint32 coreIndex0_u32 = 0;
    uint32 coreIndex1_u32 = 0;
    uint32 coreIndex2_u32 = 0;

    uint32 i_u32;

    uint32 startMemAddressCore0_u32 = 0x0;
    uint32 startMemAddressCore1_u32 = 0x0;
    uint32 startMemAddressCore2_u32 = 0x0;
    uint32 endMemAddressCore0_u32 = 0x0;
    uint32 endMemAddressCore1_u32 = 0x0;
    uint32 endMemAddressCore2_u32 = 0x0;

    uint32 smpuIndex_u32 = 0;


    /* check the configuration start - end of each region */
    index_u32 = 0;
    while((index_u32 < indexCores_u32) && (xRet == E_OK))
    {
        xRet = rba_Mpu_CheckCoreRegionCfg(regionCounter_au32[index_u32], rba_Mpu_Region_ast[index_u32]);
        index_u32++;    // increment for loop
    }

    /* sort the region direction */
    if(xRet == E_OK)
    {
        index_u32 = 0;
        while((index_u32 < indexCores_u32))
        {
            rba_Mpu_BubbleSort(regionCounter_au32[index_u32], rba_Mpu_Region_ast[index_u32]);
            index_u32++;    // increment for loop
        }
    }
    /* ************************************************** */

    /* check the different core regions/ranges and set core flags */
    index_u32 = 0;
    while((index_u32 < indexCores_u32) && (xRet == E_OK))
    {
        tmp_Flag_u32 = rba_Mpu_CheckAddresses(regionCounter_au32[index_u32], rba_Mpu_Region_ast[index_u32]);

        if(tmp_Flag_u32 != RBA_MPU_INVALID_ADDR)
        {
            /* CPU0 */
            if((tmp_Flag_u32 == RBA_MPU_CORE0ID) && (coreFlag0_u32 != RBA_MPU_CORE0ID))
            {
                // OK

                coreFlag0_u32 = RBA_MPU_CORE0ID;
                coreIndex0_u32 = index_u32;

                /* find out the first address of the protected ranges for first free range */
                if((startMemAddressCore0_u32 == 0x0))
                {
                    startMemAddressCore0_u32 = rba_Mpu_Region_ast[coreIndex0_u32][0].startAddress_u32;
                }
                else if((rba_Mpu_Region_ast[coreIndex0_u32][0].startAddress_u32 < startMemAddressCore0_u32))
                {
                    startMemAddressCore0_u32 = rba_Mpu_Region_ast[coreIndex0_u32][0].startAddress_u32;
                }
                else
                {
                    // do nothing
                }

                xRet = E_OK;
            }

            /* CPU1 */
            else if((tmp_Flag_u32 == RBA_MPU_CORE1ID) && (coreFlag1_u32 != RBA_MPU_CORE1ID))
            {
                // OK

                coreFlag1_u32 = RBA_MPU_CORE1ID;
                coreIndex1_u32 = index_u32;

                /* find out the first address of the protected ranges for first free range */
                if((startMemAddressCore1_u32 == 0x0))
                {
                    startMemAddressCore1_u32 = rba_Mpu_Region_ast[coreIndex1_u32][0].startAddress_u32;
                }
                else if((rba_Mpu_Region_ast[coreIndex1_u32][0].startAddress_u32 < startMemAddressCore1_u32))
                {
                    startMemAddressCore1_u32 = rba_Mpu_Region_ast[coreIndex1_u32][0].startAddress_u32;
                }
                else
                {
                    // do nothing
                }

                xRet = E_OK;
            }

            /* CPU2 */
            else if((tmp_Flag_u32 == RBA_MPU_CORE2ID) && (coreFlag2_u32 != RBA_MPU_CORE2ID))
            {
                // OK

                coreFlag2_u32 = RBA_MPU_CORE2ID;
                coreIndex2_u32 = index_u32;

                /* find out the first address of the protected ranges for first free range */
                if((startMemAddressCore2_u32 == 0x0))
                {
                    startMemAddressCore2_u32 = rba_Mpu_Region_ast[coreIndex2_u32][0].startAddress_u32;
                }
                else if((rba_Mpu_Region_ast[coreIndex2_u32][0].startAddress_u32 < startMemAddressCore2_u32))
                {
                    startMemAddressCore2_u32 = rba_Mpu_Region_ast[coreIndex2_u32][0].startAddress_u32;
                }
                else
                {
                    // do nothing
                }

                xRet = E_OK;
            }
            else
            {
                // error
                xRet = E_NOT_OK;
            }
        }
        else
        {
            // error
            xRet = E_NOT_OK;
        }

        index_u32++;    // increment for loop
    }
    /* ********************************************************** */

    /* check the different areas for 32 Byte accuracy */
    index_u32 = 0;
    while((index_u32 < indexCores_u32) && (xRet == E_OK))
    {
        xRet = rba_Mpu_CheckFor32ByteAddressAlignment(regionCounter_au32[index_u32], rba_Mpu_Region_ast[index_u32]);

        index_u32++;
    }


    /* ***** Safety MPU Configuration ***** */

    /* set the different core regions */

    /* set core 0 if defined */
    if((coreFlag0_u32 == RBA_MPU_CORE0ID) && (xRet == E_OK))
    {

        /* set first area */
        if(rba_Mpu_Region_ast[coreIndex0_u32][0].startAddress_u32 > RBA_MPU_CORE0_START_ADDR)
        {
            /* Reset Safety ENDINIT */
            Mcal_ResetSafetyENDINIT_Timed(200);

            MODULE_CPU0_SPROT.RGN[smpuIndex_u32].ACCENA.U= 0xFFFFFFFF;   // define the master who can access this region
            MODULE_CPU0_SPROT.RGN[smpuIndex_u32].LA.U=  RBA_MPU_CORE0_START_ADDR;                              // start address
            MODULE_CPU0_SPROT.RGN[smpuIndex_u32].UA.U = rba_Mpu_Region_ast[coreIndex0_u32][0].startAddress_u32;       // end address

            /* Set ENDINIT */
            Mcal_SetSafetyENDINIT_Timed();

            if(smpuIndex_u32 < 8)
            {
                smpuIndex_u32++;        // increment the SMPU index
            }
            else
            {
                // DET hint
                xRet = E_NOT_OK;
            }

            endMemAddressCore0_u32 = rba_Mpu_Region_ast[coreIndex0_u32][0].startAddress_u32;
        }

        /* Reset Safety ENDINIT */
        Mcal_ResetSafetyENDINIT_Timed(200);

        /* set the regions to protect */
        for(i_u32 = 0; i_u32 < regionCounter_au32[coreIndex0_u32]; i_u32++)
        {
        	MODULE_CPU0_SPROT.RGN[smpuIndex_u32].ACCENA.U = rba_Mpu_Region_ast[coreIndex0_u32][i_u32].accessCfg_u32;// define the master who can access this region
        	MODULE_CPU0_SPROT.RGN[smpuIndex_u32].LA.U = endMemAddressCore0_u32;                                           // start address
        	MODULE_CPU0_SPROT.RGN[smpuIndex_u32].UA.U = rba_Mpu_Region_ast[coreIndex0_u32][i_u32].endAddress_u32 + 0x1;   // end address

            if(smpuIndex_u32 < 8)
            {
                smpuIndex_u32++;    // increment the SMPU index
            }
            else
            {
                // DET hint
                xRet = E_NOT_OK;
            }

            endMemAddressCore0_u32 = rba_Mpu_Region_ast[coreIndex0_u32][i_u32].endAddress_u32 + 0x1;
        }

        /* Set ENDINIT */
        Mcal_SetSafetyENDINIT_Timed();

        /* disable the remaining areas */
        if((xRet == E_OK) && (smpuIndex_u32 < 8) && (endMemAddressCore0_u32 < RBA_MPU_CORE0_END_ADDR))
        {
            /* Reset Safety ENDINIT */
            Mcal_ResetSafetyENDINIT_Timed(200);

            for(i_u32 = smpuIndex_u32; i_u32 < 8; i_u32++)
            {
                MODULE_CPU0_SPROT.RGN[i_u32].ACCENA.U= 0xFFFFFFFF;           // define the master who can access this region
                MODULE_CPU0_SPROT.RGN[i_u32].LA.U=endMemAddressCore0_u32;   // start address
                MODULE_CPU0_SPROT.RGN[i_u32].UA.U= RBA_MPU_CORE0_END_ADDR;   // end address

            }

            /* Set ENDINIT */
            Mcal_SetSafetyENDINIT_Timed();
        }

    }

    smpuIndex_u32 = 0;      // set the index to 0 for the next core

    /* set core 1 if defined */
    if((coreFlag1_u32 == RBA_MPU_CORE1ID) && (xRet == E_OK))
    {
        /* set first area */
        if(rba_Mpu_Region_ast[coreIndex1_u32][0].startAddress_u32 > RBA_MPU_CORE1_START_ADDR)
        {
            /* Reset Safety ENDINIT */
            Mcal_ResetSafetyENDINIT_Timed(200);
            MODULE_CPU1_SPROT.RGN[smpuIndex_u32].ACCENA.U= 0xFFFFFFFF;       // define the master who can access this region
            MODULE_CPU1_SPROT.RGN[smpuIndex_u32].LA.U= RBA_MPU_CORE1_START_ADDR;                                 // start address
            MODULE_CPU1_SPROT.RGN[smpuIndex_u32].UA.U= rba_Mpu_Region_ast[coreIndex1_u32][0].startAddress_u32;   // end address

            /* Set ENDINIT */
            Mcal_SetSafetyENDINIT_Timed();

            if(smpuIndex_u32 < 8)
            {
                smpuIndex_u32++;        // increment the SMPU index
            }
            else
            {
                // DET hint
                xRet = E_NOT_OK;
            }

            endMemAddressCore1_u32 = rba_Mpu_Region_ast[coreIndex1_u32][0].startAddress_u32;
        }

        /* Reset Safety ENDINIT */
        Mcal_ResetSafetyENDINIT_Timed(200);

        /* set the regions to protect */
        for(i_u32 = 0; i_u32 < regionCounter_au32[coreIndex1_u32]; i_u32++)
        {
            MODULE_CPU1_SPROT.RGN[smpuIndex_u32].ACCENA.U= rba_Mpu_Region_ast[coreIndex1_u32][i_u32].accessCfg_u32;   // define the master who can access this region
            MODULE_CPU1_SPROT.RGN[smpuIndex_u32].LA.U= endMemAddressCore1_u32;                                           // start address
            MODULE_CPU1_SPROT.RGN[smpuIndex_u32].UA.U = rba_Mpu_Region_ast[coreIndex1_u32][i_u32].endAddress_u32 + 0x1;   // end address

            if(smpuIndex_u32 < 8)
            {
                smpuIndex_u32++;        // increment the SMPU index
            }
            else
            {
                // DET hint
                xRet = E_NOT_OK;
            }

            endMemAddressCore1_u32 = rba_Mpu_Region_ast[coreIndex1_u32][i_u32].endAddress_u32 + 0x1;
        }

        /* Set ENDINIT */
        Mcal_SetSafetyENDINIT_Timed();

        /* disable the remaining areas */
        if((xRet == E_OK) && (smpuIndex_u32 < 8) && (endMemAddressCore1_u32 < RBA_MPU_CORE1_END_ADDR))
        {
            /* Reset Safety ENDINIT */
            Mcal_ResetSafetyENDINIT_Timed(200);

            for(i_u32 = smpuIndex_u32; i_u32 < 8; i_u32++)
            {
                MODULE_CPU1_SPROT.RGN[i_u32].ACCENA.U= 0xFFFFFFFF;           // define the master who can access this region
                MODULE_CPU1_SPROT.RGN[i_u32].LA.U= endMemAddressCore1_u32;   // start address
                MODULE_CPU1_SPROT.RGN[i_u32].UA.U = RBA_MPU_CORE1_END_ADDR;   // end address

            }

            /* Set ENDINIT */
            Mcal_SetSafetyENDINIT_Timed();
        }

    }

    smpuIndex_u32 = 0;      // set the index to 0 for the next core

    /* set core 2 if defined */
    if((coreFlag2_u32 == RBA_MPU_CORE2ID) && (xRet == E_OK))
    {

        /* set first area */
        if(rba_Mpu_Region_ast[coreIndex2_u32][0].startAddress_u32 > RBA_MPU_CORE2_START_ADDR)
        {
            /* Reset Safety ENDINIT */
            Mcal_ResetSafetyENDINIT_Timed(200);

            MODULE_CPU2_SPROT.RGN[smpuIndex_u32].ACCENA.U= 0xFFFFFFFF;       // define the master who can access this region
            MODULE_CPU2_SPROT.RGN[smpuIndex_u32].LA.U = RBA_MPU_CORE2_START_ADDR;                                 // start address
            MODULE_CPU2_SPROT.RGN[smpuIndex_u32].UA.U= rba_Mpu_Region_ast[coreIndex2_u32][0].startAddress_u32;   // end address

            /* Set ENDINIT */
            Mcal_SetSafetyENDINIT_Timed();

            if(smpuIndex_u32 < 8)
            {
                smpuIndex_u32++;        // increment the SMPU index
            }
            else
            {
                // DET hint
                xRet = E_NOT_OK;
            }

            endMemAddressCore2_u32 = rba_Mpu_Region_ast[coreIndex2_u32][0].startAddress_u32;
        }

        /* Reset Safety ENDINIT */
        Mcal_ResetSafetyENDINIT_Timed(200);

        /* set the regions to protect */
        for(i_u32 = 0; i_u32 < regionCounter_au32[coreIndex2_u32]; i_u32++)
        {
            MODULE_CPU2_SPROT.RGN[smpuIndex_u32].ACCENA.U= rba_Mpu_Region_ast[coreIndex2_u32][i_u32].accessCfg_u32;  // define the master who can access this region
            MODULE_CPU2_SPROT.RGN[smpuIndex_u32].LA.U = endMemAddressCore2_u32;                                           // start address
            MODULE_CPU2_SPROT.RGN[smpuIndex_u32].UA.U = rba_Mpu_Region_ast[coreIndex2_u32][i_u32].endAddress_u32 + 0x1;   // end address


            if(smpuIndex_u32 < 8)
            {
                smpuIndex_u32++;        // increment the SMPU index
            }
            else
            {
                // DET hint
                xRet = E_NOT_OK;
            }

            endMemAddressCore2_u32 = rba_Mpu_Region_ast[coreIndex2_u32][i_u32].endAddress_u32 + 0x1;
        }

        /* Set ENDINIT */
        Mcal_SetSafetyENDINIT_Timed();

        /* disable the remaining areas */
        if((xRet == E_OK) && (smpuIndex_u32 < 8) && (endMemAddressCore2_u32 < RBA_MPU_CORE2_END_ADDR))
        {
            /* Reset Safety ENDINIT */
            Mcal_ResetSafetyENDINIT_Timed(200);

            for(i_u32 = smpuIndex_u32; i_u32 < 8; i_u32++)
            {
                MODULE_CPU2_SPROT.RGN[i_u32].ACCENA.U = 0xFFFFFFFF;           // define the master who can access this region
                MODULE_CPU2_SPROT.RGN[i_u32].LA.U = endMemAddressCore2_u32;   // start address
                MODULE_CPU2_SPROT.RGN[i_u32].UA.U = RBA_MPU_CORE2_END_ADDR;   // end address

            }

            /* Set ENDINIT */
            Mcal_SetSafetyENDINIT_Timed();
        }

    }

    /* Reset Safety ENDINIT */
    Mcal_ResetSafetyENDINIT_Timed(200);

    /* set the special function register accessment */
    MODULE_CPU0_SPROT.ACCENA.U = 0xFFFFFFFF;     // CSFR + SFR access rights
    MODULE_CPU1_SPROT.ACCENA.U = 0xFFFFFFFF;     // CSFR + SFR access rights
    MODULE_CPU2_SPROT.ACCENA.U = 0xFFFFFFFF;     // CSFR + SFR access rights

    /* Set ENDINIT */
    Mcal_SetSafetyENDINIT_Timed();

    /* if error occurred make a reset for the first implementation of Crossbar MPU */
    if(xRet == E_NOT_OK)
    {
        rba_Reset_Request(RBA_MPU_RESET_GROUP,RBA_RESET_CPU2_TRAP_NMI_SMU_CPU0_MPU_E,1);
    }
    /* *************************************************************************** */

    /* ************************************ */
}

/* Stop MemMap for default code */
#define RBA_MPU_STOP_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

/* ((MCU_RB_MACHINE_FAM == MCU_RB_IFX_UC1)) */
#endif
/* **************************************** */


/* ************************************* */
/* ***** functions for IFX and JDP ***** */
/* ************************************* */

/* Start MemMap for default code */
#define RBA_MPU_START_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* ***************************** */

/**
 ***************************************************************************************************
 * \rba_internal
 * \brief address region sort function
 *
 * \param[in]   regionCounter_u32   number of regions
 * \param[in]   rba_Mpu_Region_ast  array structure with the different regions
 *
 * \param[in,out]   void
 *
 * This function sorts the different regions of a core for the right direction.
 *
 * \rb_example Example:
 * \code
 * void main(void)
 * {
 *      uint32 regionCounter_u32 = 1;
 *      rba_Mpu_Region_ast[1];
 *
 *      rba_Mpu_Region_st[0].startAddress_u32 = 0x00000000;
 *      rba_Mpu_Region_st[0].endAddress_u32 = 0xFFFFFFFF;
 *      rba_Mpu_Region_st[0].accessCfg_u32 = 0x00010003;
 *
 *      rba_Mpu_BubbleSort(regionCounter_u32, rba_Mpu_Region_ast);
 * }
 * \endcode
 *
 ***************************************************************************************************
 */
void rba_Mpu_BubbleSort(uint32 regionCounter_u32, rba_Mpu_Region_tst *rba_Mpu_Region_ast)
{
    uint32 i_u32;
    uint32 j_u32;
    rba_Mpu_Region_tst tmp_st;


    for(i_u32 = regionCounter_u32 - 1; i_u32 > 0; i_u32--)
    {
        for(j_u32 = 1; j_u32 <= i_u32; j_u32++)
        {
            if(rba_Mpu_Region_ast[j_u32 - 1].startAddress_u32 > rba_Mpu_Region_ast[j_u32].startAddress_u32)
            {
                tmp_st = rba_Mpu_Region_ast[j_u32 - 1];
                rba_Mpu_Region_ast[j_u32 - 1] = rba_Mpu_Region_ast[j_u32];
                rba_Mpu_Region_ast[j_u32] = tmp_st;
            }
        }
    }
}

/**
 ***************************************************************************************************
 * \rba_internal
 * \brief Address region check function
 *
 * \param[in]   regionCounter_u32   number of regions
 * \param[in]   rba_Mpu_Region_ast  array structure with the different regions
 *
 * \retval  E_OK        OK
 * \retval  E_NOT_OK    not OK
 *
 * This function checks the plausibility of the region address definitions.
 *
 * \rb_example Example:
 * \code
 * void main(void)
 * {
 *      uint32 regionCounter_u32 = 1;
 *      Std_ReturnType xRet;
 *      rba_Mpu_Region_ast[1];
 *
 *      rba_Mpu_Region_st[0].startAddress_u32 = 0x00000000;
 *      rba_Mpu_Region_st[0].endAddress_u32 = 0xFFFFFFFF;
 *      rba_Mpu_Region_st[0].accessCfg_u32 = 0x00010003;
 *
 *      xRet = rba_Mpu_CheckCoreRegionCfg(regionCounter_u32, rba_Mpu_Region_ast);
 * }
 * \endcode
 *
 ***************************************************************************************************
 */
Std_ReturnType rba_Mpu_CheckCoreRegionCfg(uint32 regionCounter_u32, const rba_Mpu_Region_tst rba_Mpu_Region_ast[])
{
    Std_ReturnType xRet = E_OK;

    uint32 index_u32;

    /* check the seperate regions of the core for the correct direction */
    index_u32 = 0;
    while((index_u32 < regionCounter_u32) && (xRet == E_OK))
    {
        if(rba_Mpu_Region_ast[index_u32].startAddress_u32 > rba_Mpu_Region_ast[index_u32].endAddress_u32)
        {
            // DET !!!
            xRet = E_NOT_OK;
        }
        else
        {
            // OK
            xRet = E_OK;
        }
        index_u32++;
    }

    /* check the correckt direction of the regions of the core */

    return xRet;
}

/**
 ***************************************************************************************************
 * \rba_internal
 * \brief Address direction check function
 *
 * \param[in]   regionCounter_u32   number of regions
 * \param[in]   rba_Mpu_Region_ast  array structure with the different regions
 *
 * \retval  RBA_MPU_CORE0ID         core0
 * \retval  RBA_MPU_CORE1ID         core1
 * \retval  RBA_MPU_CORE2ID         core2
 * \retval  RBA_MPU_INVALID_ADDR          not OK
 *
 * This function check the seperate regions of the core for the correct direction
 * and for the same address area of a core.
 *
 * \rb_example Example:
 * \code
 * void main(void)
 * {
 *      uint32 regionCounter_u32 = 1;
 *      uint32 xRet;
 *      rba_Mpu_Region_ast[1];
 *
 *      rba_Mpu_Region_st[0].startAddress_u32 = 0x00000000;
 *      rba_Mpu_Region_st[0].endAddress_u32 = 0xFFFFFFFF;
 *      rba_Mpu_Region_st[0].accessCfg_u32 = 0x00010003;
 *
 *      xRet = rba_Mpu_CheckAddresses(regionCounter_u32, rba_Mpu_Region_ast);
 * }
 * \endcode
 *
 ***************************************************************************************************
 */
uint32 rba_Mpu_CheckAddresses(uint32 regionCounter_u32, const rba_Mpu_Region_tst rba_Mpu_Region_ast[])
{
    uint32 returnValue_u32 = 0x00000000;        // return value of this function
    uint32 index_u32;

    /* check the seperate regions of the core for the correct direction and for the same address area of a core */
    index_u32 = 0;
    while((index_u32 < regionCounter_u32) && (returnValue_u32 != RBA_MPU_INVALID_ADDR))
    {
        // JDP core0 adress range check
        if((rba_Mpu_Region_ast[index_u32].startAddress_u32 >= RBA_MPU_CORE0_START_ADDR) && (rba_Mpu_Region_ast[index_u32].endAddress_u32 <= RBA_MPU_CORE0_END_ADDR))
        {
            if((returnValue_u32 == RBA_MPU_CORE0ID) || (returnValue_u32 == 0x00000000))
            {
                // OK
                returnValue_u32 = RBA_MPU_CORE0ID;
            }
            else
            {
                // error !!! --> break
                returnValue_u32 = RBA_MPU_INVALID_ADDR;
            }
        }

        // JDP core1 adress range check
        if((rba_Mpu_Region_ast[index_u32].startAddress_u32 >= RBA_MPU_CORE1_START_ADDR) && (rba_Mpu_Region_ast[index_u32].endAddress_u32 <= RBA_MPU_CORE1_END_ADDR))
        {
            if((returnValue_u32 == RBA_MPU_CORE1ID) || (returnValue_u32 == 0x00000000))
            {
                // OK
                returnValue_u32 = RBA_MPU_CORE1ID;
            }
            else
            {
                // error !!! --> break
                returnValue_u32 = RBA_MPU_INVALID_ADDR;
            }
        }

        // JDP core2 adress range check
        if((rba_Mpu_Region_ast[index_u32].startAddress_u32 >= RBA_MPU_CORE2_START_ADDR) && (rba_Mpu_Region_ast[index_u32].endAddress_u32 <= RBA_MPU_CORE2_END_ADDR))
        {
            if((returnValue_u32 == RBA_MPU_CORE2ID) || (returnValue_u32 == 0x00000000))
            {
                // OK
                returnValue_u32 = RBA_MPU_CORE2ID;
            }
            else
            {
                // error !!! --> break
                returnValue_u32 = RBA_MPU_INVALID_ADDR;
            }
        }

        index_u32++;
    }

    return returnValue_u32;
}

/**
 ***************************************************************************************************
 * \rba_internal
 * \brief Address alignment check function
 *
 * \param[in]   regionCounter_u32   number of regions
 * \param[in]   rba_Mpu_Region_ast  array structure with the different regions
 *
 * \retval  E_OK        OK
 * \retval  E_NOT_OK    not OK
 *
 * This function checks the 32Bit alignment for the different address regions.
 *
 * \rb_example Example:
 * \code
 * void main(void)
 * {
 *      uint32 regionCounter_u32 = 1;
 *      Std_ReturnType xRet;
 *      rba_Mpu_Region_ast[1];
 *
 *      rba_Mpu_Region_st[0].startAddress_u32 = 0x00000000;
 *      rba_Mpu_Region_st[0].endAddress_u32 = 0xFFFFFFFF;
 *      rba_Mpu_Region_st[0].accessCfg_u32 = 0x00010003;
 *
 *      xRet = rba_Mpu_CheckFor32ByteAddressAlignment(regionCounter_u32, rba_Mpu_Region_ast);
 * }
 * \endcode
 *
 ***************************************************************************************************
 */
Std_ReturnType rba_Mpu_CheckFor32ByteAddressAlignment(uint32 regionCounter_u32, const rba_Mpu_Region_tst rba_Mpu_Region_ast[])
{
    Std_ReturnType xRet = E_OK;
    uint32 index_u32;

    /* check the addresses for a 32Byte accuracy */
    index_u32 = 0;
    while((index_u32 < regionCounter_u32) && (xRet == E_OK))
    {
        if((rba_Mpu_Region_ast[index_u32].startAddress_u32 & RBA_MPU_ALIGNMENT) > 0x0)
        {
            // no 32Byte alignment --> DET
            xRet = E_NOT_OK;
        }
        else if(((rba_Mpu_Region_ast[index_u32].endAddress_u32 + 1) & RBA_MPU_ALIGNMENT) > 0x0)
        {
            // no 32Byte alignment --> DET
            xRet = E_NOT_OK;
        }
        else
        {
            xRet = E_OK;
        }

        index_u32++;
    }

    return xRet;
}

/**
 ***************************************************************************************************
 * \brief Init function for the Crossbar MPU
 *
 * \param[in,out]   void
 *
 * \return void
 *
 * This is a API function which calls the Crossbar MPU configuration.
 *
 * \rb_example Example:
 * \code
 * void main(void)
 * {
 *      rba_Mpu_CrossbarMpuInit();
 * }
 * \endcode
 *
 ***************************************************************************************************
 */
void rba_Mpu_CrossbarMpuInit(void)
{
    rba_Mpu_SetCrossbarMpuConfiguration();
}

/* Stop MemMap for default code */
#define RBA_MPU_STOP_SEC_DEFAULT_CODE
#include "rba_Mpu_MemMap.h"
/* **************************** */

/*! @} */

/* <BASDKey>
*********************************************************************************************************
* $History__:$
*********************************************************************************************************
</BASDKey>*/
