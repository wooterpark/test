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
 * $Namespace_:\Comp\rta_bsw_BswSrv$
 * $Class_____:C$
 * $Name______:rta_bsw_BswSrv_MemCopy$
 * $Variant___:AR40.1.1.0$
 * $Revision__:0$
 **********************************************************************************************************************
</BASDKey>*/

/****************************************************************************
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *****************************************************************************
 * Project : Basic Software Service
 * Component : RTA_BSW_BSWSRV
 * Date : Mon December 28 2015
 * Version : 1.0
 * Description : RTA-BASE first revision
 ****************************************************************************/

/*
 *********************************************************************
 * Includes
 *********************************************************************
 */
#include "rta_bsw_BswSrv.h"

/*
 *********************************************************************
 * Defines
 *********************************************************************
 */

/*
 *********************************************************************
 * Variables
 *********************************************************************
 */

/*
 *********************************************************************
 * Functions
 *********************************************************************
 */

#define RTA_BSW_BSWSRV_START_SEC_CODE
#include "rta_bsw_BswSrv_MemMap.h"
/**
 ***********************************************************************************************************************
 * \brief Memcopy with the same parameters as C90-memcpy
 *
 * This function implements Memcopy with the same parameters as C90-memcpy
 * It copies 32 bit data, if possible. So it is save to copy structures which require consistent 32 bit data.
 *
 * \param[in]       void* xDest_pv, const void* xSrc_pcv, sint32 numBytes_s32
 * \return          void*
 ***********************************************************************************************************************
 */
 
void* rta_bsw_BswSrv_MemCopy(void* xDest_pv, const void* xSrc_pcv, sint32 numBytes_s32)
{
    uint32* xDest_pu32       = (uint32*)xDest_pv;
    const uint32* xSrc_pcu32 = (const uint32*)xSrc_pcv;
    uint16* xDest_pu16;
    const uint16* xSrc_pcu16;
    uint8* xDest_pu8;
    const uint8* xSrc_pcu8;
    uint32 numBytes_u32 = (uint32) numBytes_s32;
    uint32 ctLoop_u32;

    /* 32 bit aligned copy */
    /* MISRA RULE 11.3 VIOLATION: cast cannot be avoided here */
    if ((numBytes_u32 >= 4) && ((((uint32)xDest_pu32 | (uint32)xSrc_pcu32) & 0x03) == 0))
    {
        ctLoop_u32 = numBytes_u32 / 4;
        numBytes_u32 &= 0x03;
        do
        {
            *xDest_pu32 = *xSrc_pcu32;
            xDest_pu32++;
            xSrc_pcu32++;
            ctLoop_u32--;
        } while(ctLoop_u32 > 0);
    }
    /* MISRA RULE 11.4 VIOLATION: cast cannot be avoided here */
    xDest_pu16 = (uint16*)xDest_pu32;
    xSrc_pcu16 = (const uint16*)xSrc_pcu32;

    /* 16 bit aligned copy */
    /* MISRA RULE 11.3 VIOLATION: cast cannot be avoided here */
    if ((numBytes_u32 >= 2) && ((((uint32)xDest_pu16 | (uint32)xSrc_pcu16) & 0x01) == 0))
    {
        ctLoop_u32 = numBytes_u32 / 2;
        numBytes_u32 &= 0x01;
        do
        {
            *xDest_pu16 = *xSrc_pcu16;
            xDest_pu16++;
            xSrc_pcu16++;
            ctLoop_u32--;
        } while(ctLoop_u32 > 0);
    }
    /* MISRA RULE 11.4 VIOLATION: cast cannot be avoided here */
    xDest_pu8 = (uint8*)xDest_pu16;
    xSrc_pcu8 = (const uint8*)xSrc_pcu16;

    /* 8 bit copy for remaining data */
    for(ctLoop_u32 = 0; ctLoop_u32 < numBytes_u32; ctLoop_u32++)
    {
        *xDest_pu8 = *xSrc_pcu8;
        xDest_pu8++;
        xSrc_pcu8++;
    }
    return xDest_pv;
}

#define RTA_BSW_BSWSRV_STOP_SEC_CODE
#include "rta_bsw_BswSrv_MemMap.h"

/*<BASDKey>
**********************************************************************************************************************
* $History__:$
**********************************************************************************************************************
</BASDKey>*/
