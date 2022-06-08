/* Data section for Os Application on Core 0 */

  .CPU0_DATA : ALIGN(4)
  {
    __CPU0_DATA_START = .;
    *(.data.CPU0_unspec*)
    *(.data.CPU0_bool*)
    *(.data.CPU0_8*)
    *(.data.CPU0_16*)
    *(.data.CPU0_32*)
    *(.data.a1*)
    *(.data.a2*)
    *(.data.a4*)
    . = ALIGN(4);
	*Fee_CyclicCall.o(.data*)
	. = ALIGN(4);
   } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE

  .CPU0_BSS : ALIGN(4)
  {
    *(.bss.CPU0_unspec*)
    *(.bss.CPU0_bool*)
    *(.bss.CPU0_8*)
    *(.bss.CPU0_16*)
    *(.bss.CPU0_32*)
	. = ALIGN(4);
  	*Fee.o (.bss*)
	*Fee_AsyncRead.o (.bss*)
	*Fee_AsyncWrite.o (.bss*)
	*Fee_CyclicCall.o (.bss*)
	*Fee_Init.o (.bss*)
	*Fee_Invalidate.o (.bss*)
	*Eru_Irq.o (.bss*)
	*Gtm_Irq.o (.bss*)
	*Mcal_Trap.o (.bss*)
	*NvM_SWC.o (.bss*)
    . = ALIGN(4);
	__CPU0_DATA_END = .;
  } > CPU0_DSPR
  
  .CPU0_DATA_LIBDNK_C : ALIGN(4)
  {
      *xfvalues.o(.data)
      *xvalues.o(.data)
  } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE
  
  /* Reserve for UART RX Buffer 
  .CPU0_UART_BUFFER : ALIGN(8)
  {
      PROVIDE(__CPU0_UART_BUFFER_START = .);
      *(.data.FIFO_UART_BUFFER)
      PROVIDE(__CPU0_UART_BUFFER_END = .);
  } > CPU0_DSPR_UART_BUFFER AT > PFLASH0_CPU0_PRIVATE
  */
  /* Reserve for Jump to SBL Flag */
  .CPU0_JUMP_TO_SBL_FLAG (0x7001AC10) : ALIGN(4)
  {
      KEEP(*(.data.JumpToSBL_Flag))
  } > CPU0_DSPR_FBL_FLAG AT > PFLASH0_CPU0_PRIVATE

    /* Reserve for Jump to CBL Flag */
  .CPU0_JUMP_TO_CBL_FLAG (0x7001AC18) : ALIGN(4)
  {
      KEEP(*(.data.JumpToCBL_Flag))
  } > CPU0_DSPR_FBL_FLAG AT > PFLASH0_CPU0_PRIVATE

    /* Reserve for DFls Buffer */
  .CPU0_DFLS_BUFFER : ALIGN(8)
  {
      PROVIDE(__CPU0_DFLS_BUFFER_START = .);
      *(.data.DFLS_UPDATE_BUFFER)
      PROVIDE(__CPU0_DFLS_BUFFER_END = .);
  } > CPU0_DSPR_FR_DFLS_BUFFER AT > PFLASH0_CPU0_PRIVATE

  /* Data accessed by Trusted-with-Protection OsApp */
  .TRUSTED_DATA_SHARED : ALIGN(4)
  {
	__TRUSTED_DATA_SHARED_START = .;
	*(.data.SharedTrusted_unspec*)
    *(.data.SharedTrusted_bool*)
    *(.data.SharedTrusted_8*)
    *(.data.SharedTrusted_16*)
    *(.data.SharedTrusted_32*)
  } > CPU0_DSPR AT > PFLASH0_CPU0_PRIVATE

  .TRUSTED_BSS_SHARED : ALIGN(4)
  {
    *(.bss.SharedTrusted_unspec*)
    *(.bss.SharedTrusted_bool*)
    *(.bss.SharedTrusted_8*)
    *(.bss.SharedTrusted_16*)
    *(.bss.SharedTrusted_32*)
	__TRUSTED_DATA_SHARED_END = .;
  } > CPU0_DSPR

      .FLS_SECTOR_BACKUP : ALIGN(4)
  {
  	FBL_SECTOR_BACKUP_START = .;
  } > CPU0_FLS_SECTOR_BACKUP
	
  /* Flash0 Application Program Flag */
  .FLASH0_APP_PROG_FLAG :
  {
      KEEP(*(.FLASH0_APP_INTEG_FLAG))
  } > PFLASH0_APP_PROG_FLAG
