/*<RBHead>

 * $Filename__:rba_MemLay_Defines.h$
 *
 *
 * $Function__:.$
 *
 ***********************************************************************************************************************

 * $User______:JWI2SI$
 * $Date______:24.01.2018$
 * $Class_____:SWHDR$
 * $Name______:rba_MemLay_Defines$
 * $Variant___:1.32.0$
 * $Revision__:0$
 * $Type______:H$
 * $State_____:AVAILABLE$
 * $Generated_:$
 ***********************************************************************************************************************
 *
 * $UniqueName:$
 * $Component_:$
 *
 ***********************************************************************************************************************
</RBHead>*/


#ifndef RBA_MEMLAY_DEFINES_H_
#define RBA_MEMLAY_DEFINES_H_

/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */
/* attention: changing of addressing mode is not supported for Tasking and HTC arm compiler using this interface. */

#define RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(section_s, flag_s)   __attribute__ ((asection(section_s,flag_s)))


/* for import of FAR adressed linker labels */
/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */
#define RBA_MEMLAY_USE_LABEL(typ, var)                    typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".label_only","f=awB")

/* Force inlining */
/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */
#define RBA_MEMLAY_USE_FORCE_INLINE(fct)                  static inline fct __attribute__ ((always_inline)); \
                                                          static inline fct
/* Functions in Scratch Pad Ram */
/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */

#define RBA_MEMLAY_USE_PRAM_CODE(fct)             fct RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".text.spram","f=ax")



/* calibration data */
/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */
#define RBA_MEMLAY_USE_CALDATA(typ, var)                  typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".caldata","f=a")
/***********************************************************************/
/** GCC >= 4.x.x.x requires additional flag 'B' for uninitialized RAM **/
/***********************************************************************/
/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */
/* Variables in Ram which where cleared in every start up before other Rams a cleared*/
#define RBA_MEMLAY_USE_BOOTFIXRAM(typ, var)                 typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.bootfixram","f=awB")
/* Variables in Protected Ram */
#define RBA_MEMLAY_USE_PROTRAM(typ, var)                  typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.protram","f=awB")
#define RBA_MEMLAY_USE_PROTRAM0(typ, var)                 typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.protram0","f=awB")
#define RBA_MEMLAY_USE_PROTRAM1(typ, var)                 typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.protram1","f=awB")
/* Variables in EdRam: only available, if RBA_MEMLAY_EDRAM_START is defined and rba_Eec_EdRamAvailable() returns not 0 */
#define RBA_MEMLAY_USE_EDRAM_STANDBY(typ, var)            typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.edram_standby","f=awB")
#define RBA_MEMLAY_USE_EDRAM_CLEAR(typ, var)              typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.edram_clear","f=awB")
#define RBA_MEMLAY_USE_EDRAM_POWERFAIL(typ, var)          typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.edram_powerfail","f=awB")
#define RBA_MEMLAY_USE_EDRAM_FIXCAL(typ, var)             typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.edram_fixcal","f=awB")


/* Compiler does support alignment up to 32 bytes. Larger alignment must be handled by the linker */
#define RBA_MEMLAY_USE_RAM0_A32768(typ, var)               typ var __attribute__ ((asection(".bss.ram0_a32768","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A16384(typ, var)               typ var __attribute__ ((asection(".bss.ram0_a16384","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A8192(typ, var)                typ var __attribute__ ((asection(".bss.ram0_a8192","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A4096(typ, var)                typ var __attribute__ ((asection(".bss.ram0_a4096","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A2048(typ, var)                typ var __attribute__ ((asection(".bss.ram0_a2048","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A1024(typ, var)                typ var __attribute__ ((asection(".bss.ram0_a1024","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A512(typ, var)                 typ var __attribute__ ((asection(".bss.ram0_a512","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A256(typ, var)                 typ var __attribute__ ((asection(".bss.ram0_a256","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A128(typ, var)                 typ var __attribute__ ((asection(".bss.ram0_a128","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A64(typ, var)                  typ var __attribute__ ((asection(".bss.ram0_a64","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A32(typ, var)                  typ var __attribute__ ((asection(".bss.ram0_a32","f=awB","a=32")))
#define RBA_MEMLAY_USE_RAM0_A16(typ, var)                  typ var __attribute__ ((asection(".bss.ram0_a16","f=awB","a=16")))
#define RBA_MEMLAY_USE_RAM0_A8(typ, var)                   typ var __attribute__ ((asection(".bss.ram0_a8","f=awB","a=8")))
#define RBA_MEMLAY_USE_SYSRAM_A32768(typ, var)               typ var __attribute__ ((asection(".bss.sysram_a32768","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A16384(typ, var)               typ var __attribute__ ((asection(".bss.sysram_a16384","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A8192(typ, var)                typ var __attribute__ ((asection(".bss.sysram_a8192","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A4096(typ, var)                typ var __attribute__ ((asection(".bss.sysram_a4096","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A2048(typ, var)                typ var __attribute__ ((asection(".bss.sysram_a2048","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A1024(typ, var)                typ var __attribute__ ((asection(".bss.sysram_a1024","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A512(typ, var)                 typ var __attribute__ ((asection(".bss.sysram_a512","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A256(typ, var)                 typ var __attribute__ ((asection(".bss.sysram_a256","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A128(typ, var)                 typ var __attribute__ ((asection(".bss.sysram_a128","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A64(typ, var)                  typ var __attribute__ ((asection(".bss.sysram_a64","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A32(typ, var)                  typ var __attribute__ ((asection(".bss.sysram_a32","f=awB","a=32")))
#define RBA_MEMLAY_USE_SYSRAM_A16(typ, var)                  typ var __attribute__ ((asection(".bss.sysram_a16","f=awB","a=16")))
#define RBA_MEMLAY_USE_SYSRAM_A8(typ, var)                   typ var __attribute__ ((asection(".bss.sysram_a8","f=awB","a=8")))


/* MR12 RULE 20.7 VIOLATION: Parentheses are not necessary if the macro parameters are not used as an expression. Approved by MISRA2012_SUPPORT_TEAM. */
#define RBA_MEMLAY_USE_RAM_DMA_BUFFER(typ, var)           typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".bss.dma_buffer","f=awB")
#define RBA_MEMLAY_USE_RAM_DMA_INIT_BUFFER(typ, var)      typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".data.dma_buffer","f=aw")
#define RBA_MEMLAY_USE_RAM_DMA_CONST(typ, var)            typ var RBA_MEMLAY_ATTRIBUTE_SECTION_FLAG(".rodata.dma","f=a")

#define RBA_MEMLAY_USE_RAM_A32768             RBA_MEMLAY_USE_RAM0_A32768
#define RBA_MEMLAY_USE_RAM_A16384             RBA_MEMLAY_USE_RAM0_A16384
#define RBA_MEMLAY_USE_RAM_A8192              RBA_MEMLAY_USE_RAM0_A8192
#define RBA_MEMLAY_USE_RAM_A4096              RBA_MEMLAY_USE_RAM0_A4096
#define RBA_MEMLAY_USE_RAM_A2048              RBA_MEMLAY_USE_RAM0_A2048
#define RBA_MEMLAY_USE_RAM_A1024              RBA_MEMLAY_USE_RAM0_A1024
#define RBA_MEMLAY_USE_RAM_A512               RBA_MEMLAY_USE_RAM0_A512
#define RBA_MEMLAY_USE_RAM_A256               RBA_MEMLAY_USE_RAM0_A256
#define RBA_MEMLAY_USE_RAM_A128               RBA_MEMLAY_USE_RAM0_A128
#define RBA_MEMLAY_USE_RAM_A64                RBA_MEMLAY_USE_RAM0_A64
#define RBA_MEMLAY_USE_RAM_A32                RBA_MEMLAY_USE_RAM0_A32
#define RBA_MEMLAY_USE_RAM_A16                RBA_MEMLAY_USE_RAM0_A16
#define RBA_MEMLAY_USE_RAM_A8                 RBA_MEMLAY_USE_RAM0_A8
#define RBA_MEMLAY_USE_RAM_A4                 RBA_MEMLAY_USE_RAM0_A4
#define RBA_MEMLAY_USE_RAM_A2                 RBA_MEMLAY_USE_RAM0_A2
#define RBA_MEMLAY_USE_RAM_A1                 RBA_MEMLAY_USE_RAM0_A1


#define RBA_MEMLAY_UNDEF_RESULT   0x01u
/* <<<< TSWCOM_CHECK_START >>>> (Do not remove this comment) */
#define RBA_MEMLAY_BLK_NOT_FOUND  0x02u
#define RBA_MEMLAY_FCT_NOT_FOUND  0x03u
#define RBA_MEMLAY_BLK_NO_INFTAB  0x04u
#define RBA_MEMLAY_BLKADR_INVALID 0x05u
/* <<<< TSWCOM_CHECK_END >>>> (Do not remove this comment) */

#define RBA_MEMLAY_CRC_CALCSIZE  0x20000u



/* Vendor and module identification */
#define RBA_MEMLAY_VENDOR_ID   (6)
#define RBA_MEMLAY_MODULE_ID   (255)

/* RBA_MEMLAY_DEFINES_H_ */
#endif

/*<RBHead>
 ***********************************************************************************************************************
 * List of changes
 *
 * $History
 * 
 *   -
 * 
 * $
 *
 ***********************************************************************************************************************
</RBHead>*/
