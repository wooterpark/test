OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)
ENTRY(_RESET)

__ISTACK_SIZE = DEFINED (__ISTACK_SIZE) ? __ISTACK_SIZE : 1K;	                    /* RTA-OS uses shared global stack for interrupt */
__USTACK_SIZE = DEFINED (__USTACK_SIZE) ? __USTACK_SIZE : 16K;
__HEAP_SIZE = DEFINED (__HEAP_SIZE) ? __HEAP_SIZE : 0K;
__CSA_SIZE = DEFINED (__CSA_SIZE) ? __CSA_SIZE : 4K;

MEMORY
{
    /* PFlash0 2MByte_Range: 0x8000 0000 ~ 0x801F FFFF */
    PFLASH0_BMHD0               (rx!p) : org = 0x80040000, len = 32               /* Boot header, BMHD1 */
    PFLASH0_STARTUP             (rx!p) : org = 0x80040020, len = 0xE0             /* startup code */

    PFLASH0_CPU0_PRIVATE        (rx!p) : org = 0x80040100, len = 0x68000 - 256    /* 416K - 256: CPU0 Code */
  
    PFLASH0_TRAP_INT_TAB        (rx!p) : org = 0x800A8000, len = 0x8000 - 0x1000  /* OS interrupt & trap vector table */
    /* Reserve memory for flash routines */
    PFLASH0_FLS_RES_3           (rx!p) : org = 0x800AF000, len = 0x1000-0x400     /* 3K: Reserved */
    PFLASH0_FLS_ERASE           (rx!p) : org = 0x800AFC00, len = 0x200            /* Program Flash Memory (PFLASH0) */
    PFLASH0_FLS_WRITE           (rx!p) : org = 0x800AFE00, len = 0x200            /* Program Flash Memory (PFLASH0) */
    
    PFLASH0_CPU1_PRIVATE        (rx!p) : org = 0x800B0000, len = 0x1FC80          /* 128K: PFLASH0 - CPU1 Code */
    /* Patterns for PFlash ECC/EDC test in PF0 */
    PF0_PMU_PATTERNS            (rx!p) : org = 0x800CFC80, len = 0x380
    PFLASH0_CPU2_PRIVATE        (rx!p) : org = 0x800D0000, len = 0x10000          /* 64K: PFLASH0 - CPU2 Code */
    PFLASH0_SHARED_CODE         (rx!p) : org = 0x800E0000, len = 0x60000          /* 384K: Shared Program Memory (PFLASH0) */
	
    PFLASH0_CALIB               (rx!p) : org = 0x80140000, len = 0x8000           /* 24K: Calibaration Flash */
   /* PFLASH0_CALIB_FS            (rx!p) : org = 0x80146000, len = 0x4000           /* 16K: Calibaration Flash For Function Safety */
    PFLASH0_CALIB_RES_232       (rx!p) : org = 0x80148000, len = 0x18000    /* 232K - 256: Reserved for Calibaration Flash */
    
    /*   PF0_PMU_PATTERNS            (rx!p) : org = 0x80000100, len = 0x380 */
    /* SBST (any 32K aligned address is ok for SBST) and RODATA allocated in this region */
    PF0_SafeTlib_Code		    (rx!p) : org = 0x80160000, len = 0x20000- 256 
    
    PFLASH0_FINGERPRINT         (rx!p) : org = 0x8017FF00, len = 256              /* Fingerprint Info */
    
    PFLASH0_FAULT_REC           (rx!p) : org = 0x80180000, len = 0x40000          /* 256K: Reserved for fault record */
    PFLASH0_CONST               (rx!p) : org = 0x801C0000, len = 0x40000 - 256    /* 256K - 256: For const and copy table */ 
    PFLASH0_APP_PROG_FLAG       (rx!p) : org = 0x801FFF00, len = 256              /* Reserve for Application Program Flag */

    /* Patterns for PFlash ECC/EDC test in PF1 */
    PF1_PMU_PATTERNS		    (rx!p) : org = 0x80200000, len = 0x380
    
    
    
    /* CPU0 DSPR 112KByte_Range: 0x7000 0000 ~ 0x7001 BFFF */
    CPU0_DSPR                   (w!xp) : org = 0x70000000, len = 0xEC00           /* 59K: RAM for OsApp */
    CPU0_DSPR_STACK             (w!xp) : org = 0x7000EC00, len = 0x4400           /* 16k Stack, 1K istack and 16K ustack */
    CPU0_DSPR_CSA               (w!xp) : org = 0x70013000, len = 0x1000           /* 4k, CSA */
    CPU0_DSPR_CALIB_RES         (w!xp) : org = 0x70014000, len = 0x6000           /* 24K, Reserve for Calibaration */
   
    
    
    /*CPU0_DSPR_UART_BUFFER       (w!xp) : org = 0x7001AC00, len = 16                Reserve for Uart Buffer */
    CPU0_DSPR_FBL_FLAG          (w!xp) : org = 0x7001AC10, len = 1K - 48          /* Reserve for Flag */
    CPU0_DSPR_FR_DFLS_BUFFER    (w!xp) : org = 0x7001AFE0, len = 32               /* Reserve for DFls Buffer */
    CPU0_FLS_SECTOR_BACKUP      (w!xp) : org = 0x7001B000, len = 0x1000           /* 4KB, Reserved for FLS sector back up */
 
    /* CPU1 DSPR 120KByte_Range: 0x6000 0000 ~ 0x6001 DFFF */
    CPU1_DSPR                   (w!xp) : org = 0x60000000, len = 0x10800          /* 73k, Local Data RAM (DSPR) */
    CPU1_DMI_DSPR_NEAR          (w!xp) : org = 0x60010800, len = 0x1F00           /* 7k, SafeTlib Local Data RAM (DSPR) */
    MCU_STANDBY_DSPR0           (rw!p) : org = 0x60012700, len = 0x44             /* DSPR0 Stanby RAM + CRC */
 
    CPU1_DSPR_RDC_BUFFER        (w!xp) : org = 0x60016700, len = 256       
    CPU1_DSPR_UART_BUFFER       (w!xp) : org = 0x60016800, len = 16               /* Reserve for Uart Buffer*/
    CPU1_DSPR_STACK             (w!xp) : org = 0x60018800, len = 17K              /* Stack, 1K istack and 16K ustack */
    CPU1_DSPR_CSA               (w!xp) : org = 0x6001D000, len = 4K               /* CSA */

    /* CPU2 DSPR 120KByte_Range: 0x5000 0000 ~ 0x5001 DFFF */
    CPU2_DSPR                   (w!xp) : org = 0x50000000, len = 0x10000          /* 90K.Local Data RAM (DSPR) */
    CPU2_DSPR_SHARE_DATA        (w!xp) : org = 0x50010000, len = 0x8000           /* 90K.Local Data RAM (DSPR) */
    CPU2_DSPR_STACK             (w!xp) : org = 0x50018800, len = 17K              /* Stack, 1K istack and 16K ustack */
    CPU2_DSPR_CSA               (w!xp) : org = 0x5001D000, len = 4K               /* CSA */

    /* CPU0 PSPR 24KByte_Range: 0x7010 0000 ~ 0x7010 5FFF */
    CPU0_PSPR_FLS_DRV           (wx!p) : org = 0x70100000, len = 0x1000           /* PRAM 4k */
    CPU0_PSPR_FLS_ERASE         (wx!p) : org = 0x70101000, len = 0x300            /* Global Scratch-Pad RAM (PSPR) */
    CPU0_PSPR_FLS_WRITE         (wx!p) : org = 0x70101300, len = 0x200            /* Global Scratch-Pad RAM (PSPR) */
    /* PMU Test Code */
    PSPR0_SafeTlib_PMU          (rx)   : org = 0x70101500, len = 0x2000
    CPU0_PSPR                   (wx!p) : org = 0x70103500, len = 0x2500      /* PSPR for Flsloader demo */

    /* CPU1 PSPR 32KByte_Range: 0x6010 0000 ~ 0x6010 7FFF */
    CPU1_PSPR                   (wx!p) : org = 0x60100000, len = 0x8000           /* PRAM 32k */
    
    /* CPU2 PSPR 32KByte_Range: 0x5010 0000 ~ 0x5010 7FFF */
    CPU2_PSPR                   (wx!p) : org = 0x50100000, len = 0x8000           /* PRAM 32k */

    /* LMU 32KByte_Range: 0xB000 0000 ~ 0xB000 7FFF */
    LMU_SRAM                    (wx!p) : org = 0xB0000000, len = 32K              /* Global LMU RAM */
}

SECTIONS
{
  /* SafeTlib data */
  .rodata.SafeTlib_rodata :
  {
		*(.rodata.SafeTlib_*) 
  } > PF0_SafeTlib_Code
  
  /* SafeTlib code */	
  .text.SafeTlib_text :
  {
		*(.text.SafeTlib_*) 
  } > PF0_SafeTlib_Code

  /* SafeTlib data init */	
  .SafeTlib_data :
  {
		*(.data.SafeTlib_*) 
  } > CPU1_DMI_DSPR_NEAR AT > PF0_SafeTlib_Code

  .SafeTlib_MTL_PMU_ECC_EDC_TST_PF0 :  ALIGN(32)
  {
		/*896 bytes need to be reserved for this section*/
		PROVIDE(LOC_START_PF0_PATTERNS = .);
		KEEP(*(.PF.MTL_PMU_ECC_EDC_TST_PF0*))
		. = ALIGN(32);
  } > PF0_PMU_PATTERNS

  .SafeTlib_MTL_PMU_ECC_EDC_TST_PF1 :  ALIGN(32)
  {
		/*896 bytes need to be reserved for this section*/
		PROVIDE(LOC_START_PF1_PATTERNS = .);
		KEEP(*(.PF.MTL_PMU_ECC_EDC_TST_PF1*))
		. = ALIGN(32);
  } > PF1_PMU_PATTERNS
  
 /* Temporary trap table located to RAM, used to safe trap handling when PmuEccEdcTst is executing. */
  .SafeTlib_PMUECCEDCTST_TVT_RAMCODE :
  {
		LOC_START_PmuEccEdcTst_tvt_RAM_RUNCODE = ABSOLUTE (.);
		*(.SafeTlib_PMUECCEDCTST_TVT_RAMCODE*)
		. = ALIGN(256);
		LOC_END_PmuEccEdcTst_tvt_RAM_RUNCODE = ABSOLUTE (.);
		LOC_START_PmuEccEdcTst_tvt_PFLASHCODE = LOADADDR(.SafeTlib_PMUECCEDCTST_TVT_RAMCODE); 
		LOC_END_PmuEccEdcTst_tvt_PFLASHCODE = LOC_START_PmuEccEdcTst_tvt_PFLASHCODE + SIZEOF(.SafeTlib_PMUECCEDCTST_TVT_RAMCODE);
  } > PSPR0_SafeTlib_PMU AT > PF0_SafeTlib_Code

  /* 
   *store helper functions located to RAM, used to read the patterns in the PFLASH with 
   *erroneours pages which could make the PFLASH temporarily inaccessible. 
   */
  .SafeTlib_PFLASH_MON_ECCEDC_RAMCODE :
  {
		LOC_START_PflashMon_EccEdc_RAM_RUNCODE = ABSOLUTE (.);
		*(.SafeTlib_PFLASH_MON_ECCEDC_RAMCODE*)
		. = ALIGN(4);
		LOC_END_PflashMon_EccEdc_RAM_RUNCODE = ABSOLUTE (.);
		LOC_START_PflashMon_EccEdc_PFLASHCODE = LOADADDR(.SafeTlib_PFLASH_MON_ECCEDC_RAMCODE);
		LOC_END_PflashMon_EccEdc_PFLASHCODE = LOC_START_PflashMon_EccEdc_PFLASHCODE + SIZEOF(.SafeTlib_PFLASH_MON_ECCEDC_RAMCODE);
  } > PSPR0_SafeTlib_PMU AT > PF0_SafeTlib_Code
  
  /* SafeTlib data no-init */
  .SafeTlib_bss :
  {
		*(.bss.SafeTlib_*) 
  } > CPU1_DMI_DSPR_NEAR

  

  
    /* Code Allocation */
    .bmhd_0 : FLAGS(arl)
    {
        BootModeHeader0 = .;
        KEEP (*(.bmhd_0*))
    } > PFLASH0_BMHD0
    
    /*
     * The startup code should be placed where the CPU expects it after a reset,
     * so we try to locate it first, no matter where it appears in the list of
     * objects and libraries (note: because the wildcard pattern doesn't match
     * directories, we'll try to find crt0.o in various (sub)directories).
     */
    .startup :
    {
        KEEP (*(.startup_code*))
        . = ALIGN(8);
    } > PFLASH0_STARTUP
    
    /*
     * Discard trap and interrupt vector tables which are not generated by OS.
     */
    /DISCARD/ :
    {
        *(.text._trap*)
        *(.text.cpu*trap*)
    }

    /* Section for interrupt table */
    .inttab :
    {
        KEEP (*(.inttab));
        KEEP (*(.*.inttab));
        *(.inttab.osinterrupts)
        *(.inttab.osstubs) /* <- Emitted when the OS is not generating vector table */
        . = ALIGN(8) ;
    } > PFLASH0_TRAP_INT_TAB
    
    .inttab.ostraps :
    {
        PROVIDE(.inttab.ostraps = .);
        KEEP(*(.inttab.ostraps));
    } > PFLASH0_TRAP_INT_TAB

/* For section not allocated by memmap */
    .TIM0_CH2_IRQ_INTVEC_TC0_160 :
    {
        . = ALIGN(8);
        *(.intvec_tc0_160)
        . = ALIGN(8);
    } > PFLASH0_TRAP_INT_TAB 
    
    .TIM0_CH5_IRQ_INTVEC_TC0_200 :
    {
        . = ALIGN(8);
        *(.intvec_tc0_200)
        . = ALIGN(8);
    } > PFLASH0_TRAP_INT_TAB
    
    .TOM0_CH8_IRQ_INTVEC_TC0_199 :
    {
        . = ALIGN(8);
        *(.intvec_tc0_199)
        . = ALIGN(8);
    } > PFLASH0_TRAP_INT_TAB
    
    .TOM2_CH13_IRQ_INTVEC_TC0_198 :
    {
        . = ALIGN(8);
        *(.intvec_tc0_198)
        . = ALIGN(8);
    } > PFLASH0_TRAP_INT_TAB
    
     .INTVEC_TC0_234 :
    {
        . = ALIGN(8);
        *(.intvec_tc0_234)
        . = ALIGN(8);
    } > PFLASH0_TRAP_INT_TAB
    
        .INTVEC_TC0_15 :
    {
        . = ALIGN(8);
        *(.intvec_tc0_15)
        . = ALIGN(8);
    } > PFLASH0_TRAP_INT_TAB
    
    .FLS_AC_ERASE_SOURCE : ALIGN(4)
    {
        PROVIDE(FLS_AC_ERASE_SOURCE_START = .);
        KEEP(*(.text.FLS_AC_ERASE_SOURCE))
        PROVIDE(FLS_AC_ERASE_SOURCE_END = .);
    }> PFLASH0_FLS_ERASE

    .FLS_AC_WRITE_SOURCE : ALIGN(4) 
    {
        PROVIDE(FLS_AC_WRITE_SOURCE_START = .);
        KEEP(*(.text.FLS_AC_WRITE_SOURCE))
        PROVIDE(FLS_AC_WRITE_SOURCE_END = .);
    }> PFLASH0_FLS_WRITE
    
    .FLSLOADERRAMCODE :
    {
        PROVIDE(__FLSLOADERRAMCODE_start = .);
		
        __FLSLOADERRAMCODE_START = .;
        *(.FLSLOADERRAMCODE)
        *(.FLSLOADERRAMCODE*)
		
        /*PROTECTED REGION END*/
        __FLSLOADERRAMCODE_END = . - 1;
		
        /*PROTECTED REGION END*/	
        PROVIDE(__FLSLOADERRAMCODE_end = .);
        . = ALIGN(8);	
    } > CPU0_PSPR_FLS_DRV AT > PFLASH0_FLS_RES_3

    .FLS_AC_ERASE : ALIGN(4)
    {
        IROM_BASE_ERASE = .;
        *(.FLS_AC_ERASE)
        *(.FLS_AC_ERASE.*)
        . = ALIGN(8);
    } > CPU0_PSPR_FLS_ERASE AT > PFLASH0_FLS_ERASE = 0

    .FLS_AC_WRITE : ALIGN(4)
    {
        IROM_BASE_WRITE = .;
        *(.FLS_AC_WRITE)
        *(.FLS_AC_WRITE.*)
        . = ALIGN(8);
    } > CPU0_PSPR_FLS_WRITE AT > PFLASH0_FLS_WRITE = 0
    
    .CPU0_PSPR_PROGRAM : ALIGN(4)
    {
        *(.CPU0_PSPR_PRG)
        . = ALIGN(8);
    } > CPU0_PSPR AT > PFLASH0_CPU0_PRIVATE

    .internalcode :
    {
        PROVIDE(__internalcode_start = .);
        
        /* PROTECTED REGION ID(Protection: iROM .internalcode.begin) ENABLED START */
        /* Protection-Area for your own LDF-Code */
        /* PROTECTED REGION END */      
        KEEP(*(.internalcode)) /* Internal Code */ 
        KEEP(*(.internalcode*))
        
        /* PROTECTED REGION ID(Protection: iROM .internalcode) ENABLED START */
        /* Protection-Area for your own LDF-Code */
        /* PROTECTED REGION END */
        
        PROVIDE(__internalcode_end = .);
        . = ALIGN(8); 
    } > CPU2_PSPR AT > PFLASH0_CPU2_PRIVATE
    
INCLUDE Core0_Code.ld

    .RODATA_CALIB : ALIGN(4)
    {
        PROVIDE(__RODATA_CALIB_START = .);
        *(.rodata.Calib_bool*)
        *(.rodata.Calib_8*)
        *(.rodata.Calib_16*)
        *(.rodata.Calib_32*)
        *(.rodata.CPU1_Calib_32*)
        *(.rodata.Calib_unspec*)
        *(.caldata*)
        . = ALIGN(4);
        PROVIDE(__RODATA_CALIB_END = .);
        LONG(0x5A5A5A5A)
        LONG(0xA5A5A5A5)
    } > PFLASH0_CALIB = 0xFF
    
  /*     .RODATA_CPU1_CALIB : ALIGN(4)
    {
        PROVIDE(__RODATA_CPU1_CALIB_START = .);  
           
        . = ALIGN(4);
        PROVIDE(__RODATA_CPU1_CALIB_END = .);
        
    } > PFLASH0_CALIB_FS
    */
    .RODATA_CALIB_RES : ALIGN(4)
    {
        LONG(-1); /* SDA pointer - short data */
        LONG(-1);   
    } > PFLASH0_CALIB_RES_232
  
    .RODATA : ALIGN(4)
    {
        PROVIDE(__RODATA_START = .);
        *(.rodata.*bool*)
        *(.rodata.*8*)
        *(.rodata.*16*)
        *(.rodata.*32*)
        *(.rodata.*unspec*)
        *(.rodata.a*)
        *(.rodata*)
        PROVIDE(__RODATA_END = .);
    } > PFLASH0_CONST

INCLUDE Core1_Code.ld
INCLUDE Core2_Code.ld
INCLUDE Shared_Code.ld

    .DEFAULT_CODE : FLAGS(axl)
    {
        PROVIDE(__DEFAULT_CODE_start = .);
        *(.text.defaultcode)
        *(.text.*)
        *(.gnu.linkonce.t.*)
        KEEP(*(.init))  /* Code executed before calling main */
        KEEP(*(.init*))
        KEEP(*(.fini))  /* Code executed before exiting program */
        KEEP(*(.fini*))
        *(.eh_frame)    /* Exception handling frame for C++ exceptions */
        *(.eh_frame*)
        KEEP(*(.ctors)) /* Section for constructors */
        KEEP(*(.ctors*))
        KEEP(*(.dtors)) /* Section for destructors */
        KEEP(*(.dtors*))
        . = ALIGN(8);
        PROVIDE(__DEFAULT_CODE_end = .);
    } > PFLASH0_CPU0_PRIVATE

    /* Locating the data */
    .DEFAULT_DATA :
    {
        *(.data.default_unspec*)
        *(.data.default_bool*)
        *(.data.default_8*)
        *(.data.default_16*)
        *(.data.default_32*)
        *(.data.Shared.DEFAULT_RAM_8BIT.ubOutputBuf) 
		*(.data)
        . = ALIGN(8);
    } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE

    .DEFAULT_BSS :
    {
        *(.bss.default_unspec*)
        *(.bss.default_bool*)
        *(.bss.default_8*)
        *(.bss.default_16*)
        *(.bss.default_32*)
        *(.bss)
        *(.bss.a*)
        *(.bss.bootfixram)
        *(.bss.Lmu*) 
        . = ALIGN(8);
    } > CPU0_DSPR

INCLUDE Core0_Data.ld
INCLUDE Core1_Data.ld
INCLUDE Core2_Data.ld
INCLUDE Shared_Data.ld

    /* Initialized sdata section */
    .CPU0_PRIVATE_SDATA :
    {
        __CPU0_SMALL_DATA = . + 0x8000;
        KEEP(*(.sdata.CPU0.Private*))
        *(.sdata)
        *(.sdata*)
        *(.gnu.linkonce.s.*)
        __CPU0_SMALL_DATA_end = .;
    } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE

    .CPU1_PRIVATE_SDATA :
    {
        __CPU1_SMALL_DATA = . + 0x8000;
        KEEP(*(.sdata.CPU1.Private*))
        __CPU1_SMALL_DATA_end = .;
    } > CPU1_DSPR AT > PFLASH0_CPU1_PRIVATE
  
    .CPU2_PRIVATE_SDATA :
    {
        __CPU2_SMALL_DATA = . + 0x8000;
        KEEP(*(.sdata.CPU2.Private*))
        __CPU2_SMALL_DATA_end = .;
    } > CPU2_DSPR AT > PFLASH0_CPU2_PRIVATE

    /* Initialized sdata section */
    .CPU0_PRIVATE_SDATA2 :
    {
        __CPU0_SMALL_DATA2 = . + 0x8000;
        KEEP(*(.sdata.rodata.CPU0.Private*))
        *(.sdata.rodata)
        *(.sdata.rodata*)
        *(.gnu.linkonce.sr.*)
        __CPU0_SMALL_DATA2_end = .;
    } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE
    
    .CPU1_PRIVATE_SDATA2 :
    {
        __CPU1_SMALL_DATA2 = . + 0x8000;
        KEEP(*(.sdata.rodata.CPU1.Private*))
        __CPU1_SMALL_DATA2_end = .;
    } > CPU1_DSPR AT > PFLASH0_CPU1_PRIVATE
  
    .CPU2_PRIVATE_SDATA2 :
    {
        __CPU2_SMALL_DATA2 = . + 0x8000;
        KEEP(*(.sdata.rodata.CPU2.Private*))
        __CPU2_SMALL_DATA2_end = .;
    } > CPU2_DSPR AT > PFLASH0_CPU2_PRIVATE

    /* Initialized zdata section */
    .CPU0_PRIVATE_ZDATA :
    {
        PROVIDE(__CPU0_PRIVATE_ZDATA_start = .);
        KEEP(*(.zdata.CPU0.Private*))
        *(.zdata)
        *(.zdata*)
        *(.gnu.linkonce.zb.*)
        PROVIDE(__CPU0_PRIVATE_ZDATA_end = .);
    } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE

    .CPU1_PRIVATE_ZDATA :
    {
        PROVIDE(__CPU1_PRIVATE_ZDATA_start = .);
        KEEP(*(.zdata.CPU1.Private*))
        PROVIDE(__CPU1_PRIVATE_ZDATA_end = .);
    } > CPU1_DSPR AT > PFLASH0_CPU1_PRIVATE

    /* Initialized bit data section */
    .CPU0_PRIVATE_BDATA :
    {
        PROVIDE(__CPU0_PRIVATE_BDATA_start = .);
        KEEP(*(.bdata.CPU0.Private*))
        *(.bdata)
        *(.bdata*)
        PROVIDE(__CPU0_PRIVATE_BDATA_end = .);
    } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE

    .CPU1_PRIVATE_BDATA :
    {
        PROVIDE(__CPU1_PRIVATE_BDATA_start = .);
        KEEP(*(.bdata.CPU1.Private*))
        PROVIDE(__CPU1_PRIVATE_BDATA_end = .);
    } > CPU1_DSPR AT > PFLASH0_CPU1_PRIVATE

    .clear_sec :
    {
        . = ALIGN(8);

        PROVIDE(__cpu0_clear_table = .);
        LONG(0 + ADDR(.CPU0_BSS)); LONG(SIZEOF(.CPU0_BSS));
        LONG(0 + ADDR(.DEFAULT_BSS)); LONG(SIZEOF(.DEFAULT_BSS));
        LONG(0 + ADDR(.TRUSTED_BSS_SHARED)); LONG(SIZEOF(.TRUSTED_BSS_SHARED));

        PROVIDE(__cpu1_clear_table = .);
        LONG(0 + ADDR(.CPU1_BSS)); LONG(SIZEOF(.CPU1_BSS));
    
        PROVIDE(__cpu2_clear_table = .);
        LONG(0 + ADDR(.CPU2_BSS)); LONG(SIZEOF(.CPU2_BSS));

        LONG(-1); LONG(-1);
    } > PFLASH0_CONST

    .copy_sec :
    {
        . = ALIGN(8);

        PROVIDE(__cpu0_copy_table = .);

        LONG(LOADADDR(.CPU0_DATA)); LONG(0 + ADDR(.CPU0_DATA)); LONG(SIZEOF(.CPU0_DATA));
    /*  LONG(LOADADDR(.CPU0_UART_BUFFER)); LONG(0 + ADDR(.CPU0_UART_BUFFER)); LONG(SIZEOF(.CPU0_UART_BUFFER));*/
        LONG(LOADADDR(.CPU0_JUMP_TO_SBL_FLAG)); LONG(0 + ADDR(.CPU0_JUMP_TO_SBL_FLAG)); LONG(SIZEOF(.CPU0_JUMP_TO_SBL_FLAG));
        LONG(LOADADDR(.CPU0_JUMP_TO_CBL_FLAG)); LONG(0 + ADDR(.CPU0_JUMP_TO_CBL_FLAG)); LONG(SIZEOF(.CPU0_JUMP_TO_CBL_FLAG));
        LONG(LOADADDR(.CPU0_DFLS_BUFFER)); LONG(0 + ADDR(.CPU0_DFLS_BUFFER)); LONG(SIZEOF(.CPU0_DFLS_BUFFER));
        LONG(LOADADDR(.DEFAULT_DATA)); LONG(0 + ADDR(.DEFAULT_DATA)); LONG(SIZEOF(.DEFAULT_DATA));
        LONG(LOADADDR(.TRUSTED_DATA_SHARED)); LONG(0 + ADDR(.TRUSTED_DATA_SHARED)); LONG(SIZEOF(.TRUSTED_DATA_SHARED));
        LONG(LOADADDR(.FLSLOADERRAMCODE)); LONG(0 + ADDR(.FLSLOADERRAMCODE)); LONG(SIZEOF(.FLSLOADERRAMCODE));
        LONG(LOADADDR(.FLS_AC_ERASE)); LONG(0 + ADDR(.FLS_AC_ERASE)); LONG(SIZEOF(.FLS_AC_ERASE));
        LONG(LOADADDR(.FLS_AC_WRITE)); LONG(0 + ADDR(.FLS_AC_WRITE)); LONG(SIZEOF(.FLS_AC_WRITE));
        LONG(LOADADDR(.CPU0_PSPR_PROGRAM)); LONG(0 + ADDR(.CPU0_PSPR_PROGRAM)); LONG(SIZEOF(.CPU0_PSPR_PROGRAM));       
        
		LONG(LOADADDR(.SafeTlib_PMUECCEDCTST_TVT_RAMCODE)); 
		LONG(0 + ADDR(.SafeTlib_PMUECCEDCTST_TVT_RAMCODE));
		LONG(SIZEOF(.SafeTlib_PMUECCEDCTST_TVT_RAMCODE));
		LONG(LOADADDR(.SafeTlib_PFLASH_MON_ECCEDC_RAMCODE)); 
		LONG(0 + ADDR(.SafeTlib_PFLASH_MON_ECCEDC_RAMCODE));
		LONG(SIZEOF(.SafeTlib_PFLASH_MON_ECCEDC_RAMCODE));
        LONG(LOADADDR(.SafeTlib_data));      
        LONG(0 + ADDR(.SafeTlib_data)); 
        LONG(SIZEOF(.SafeTlib_data));
/* 	    LONG(-1); 
 	    LONG(-1); 
 	    LONG(-1);*/
        /* LONG(LOADADDR(.RODATA_CALIB)); LONG(0 + ADDR(.RODATA_CALIB)); LONG(SIZEOF(.RODATA_CALIB)); */
        PROVIDE(__cpu1_copy_table = .);
        LONG(LOADADDR(.CPU1_DATA)); LONG(0 + ADDR(.CPU1_DATA)); LONG(SIZEOF(.CPU1_DATA));
	LONG(LOADADDR(.CPU1_UART_BUFFER)); LONG(0 + ADDR(.CPU1_UART_BUFFER)); LONG(SIZEOF(.CPU1_UART_BUFFER));
        PROVIDE(__cpu2_copy_table = .);
        LONG(LOADADDR(.CPU2_DATA)); LONG(0 + ADDR(.CPU2_DATA)); LONG(SIZEOF(.CPU2_DATA));
        LONG(LOADADDR(.internalcode)); LONG(0 + ADDR(.internalcode)); LONG(SIZEOF(.internalcode));
        /* PROTECTED REGION ID(Protection: iROM copy section) ENABLED START */
        /* Protection-Area for your own LDF-Code */
        /* PROTECTED REGION END */
        LONG(-1); LONG(-1); LONG(-1);
        

    } > PFLASH0_CONST

    .shared_clear_sec :
    {
        . = ALIGN(8);

        PROVIDE(__shared_clear_table = .);
        LONG(0 + ADDR(.SHARED_WRITE_BSS)); LONG(SIZEOF(.SHARED_WRITE_BSS));
        LONG(0 + ADDR(.SHARED_BSS)); LONG(SIZEOF(.SHARED_BSS));
        LONG(-1); LONG(-1);
    } > PFLASH0_CONST

    .shared_copy_sec :
    {
        . = ALIGN(8);

        PROVIDE(__shared_copy_table = .);
        LONG(LOADADDR(.SHARED_WRITE_DATA)); LONG(0 + ADDR(.SHARED_WRITE_DATA)); LONG(SIZEOF(.SHARED_WRITE_DATA));
        LONG(LOADADDR(.SHARED_DATA)); LONG(0 + ADDR(.SHARED_DATA)); LONG(SIZEOF(.SHARED_DATA));
        LONG(-1); LONG(-1); LONG(-1);
    } > PFLASH0_CONST

    .Code_Cpl_marker 0x8013FF00 :
    {
        _CODE_CPL_MARKER_START = .;
        LONG(0xCAFEBEEF)
        . += 248;
        LONG(0xFADEFACE)
    } > PFLASH0_SHARED_CODE

    .cpu0_csa :
    {
        . = ALIGN(64);
        __CPU0_CSA_BEGIN = .;
        . += __CSA_SIZE;
        __CPU0_CSA_END = .;
    } > CPU0_DSPR_CSA

    .cpu0_istack :
    {
        . =  ALIGN(8);
        . += __ISTACK_SIZE;
        __CPU0_ISTACK = .;
    } > CPU0_DSPR_STACK

    .cpu0_ustack :
    {
        . =  ALIGN(8);
        . += __USTACK_SIZE;
        __CPU0_USTACK = .;
    } > CPU0_DSPR_STACK

    .cpu1_csa :
    {
        . = ALIGN(64);
        __CPU1_CSA_BEGIN = .;
        . += __CSA_SIZE;
        . = ALIGN(64);
        __CPU1_CSA_END = .;
    } > CPU1_DSPR_CSA
    
    .cpu1_istack :
    {
        . =  ALIGN(8);
        . += __ISTACK_SIZE;
        __CPU1_ISTACK = .;
    } > CPU1_DSPR_STACK

    .cpu1_ustack :
    {
        . =  ALIGN(8);
        . += __USTACK_SIZE;
        __CPU1_USTACK = .;
    } > CPU1_DSPR_STACK
 
    .cpu2_csa :
    {
        . = ALIGN(64);
        __CPU2_CSA_BEGIN = .;
        . += __CSA_SIZE;
        . = ALIGN(64);
        __CPU2_CSA_END = .;
    } > CPU2_DSPR_CSA
    
    .cpu2_istack :
    {
        . =  ALIGN(8);
        . += __ISTACK_SIZE;
        __CPU2_ISTACK = .;
    } > CPU2_DSPR_STACK

    .cpu2_ustack :
    {
        . =  ALIGN(8);
        . += __USTACK_SIZE;
        __CPU2_USTACK = .;
    } > CPU2_DSPR_STACK
}
