/* Data section for Trusted Os Application on Core 1 */

  .CPU1_DATA : ALIGN(4)
  {
    __CPU1_DATA_START = .;
    *(.data.CPU1_unspec*)
    *(.data.CPU1_bool*)
    *(.data.CPU1_8*)
    *(.data.CPU1_16*)
    *(.data.CPU1_32*)
  } > CPU1_DSPR  AT > PFLASH0_CPU1_PRIVATE
  .CPU1_UART_BUFFER : ALIGN(8)
  {
      PROVIDE(__CPU1_UART_BUFFER_START = .);
      *(.data.FIFO_UART_BUFFER)
      PROVIDE(__CPU1_UART_BUFFER_END = .);
  } > CPU1_DSPR_UART_BUFFER AT > PFLASH0_CPU1_PRIVATE
  .CPU1_BSS : ALIGN(4)
  {
	*(.bss.CPU1_unspec*)
    *(.bss.CPU1_bool*)
    *(.bss.CPU1_8*)
    *(.bss.CPU1_16*)
    *(.bss.CPU1_32*)
    *(.bss.a1.Dsadc_DriverState*)
	__CPU1_DATA_END = .;
  } > CPU1_DSPR
  
    /* Reserve for RDC Buffer */
  .CPU1_RDC_BUFFER : ALIGN(8)
  {
      PROVIDE(__CPU0_RDC_BUFFER_START = .);
      *(.data.FIFO_RDC_COS_BUFFER)
      *(.data.FIFO_RDC_COSLo_BUFFER)
      *(.data.FIFO_RDC_SIN_BUFFER)
      *(.data.FIFO_RDC_SINLo_BUFFER)
      PROVIDE(__CPU0_RDC_BUFFER_END = .);
  } > CPU1_DSPR_RDC_BUFFER AT > PFLASH0_CPU1_PRIVATE
  