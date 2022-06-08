/* Data section for Trusted Os Application on Core 1 */

  .CPU2_DATA : ALIGN(4)
  {
    __CPU2_DATA_START = .;
    *(.data.CPU2_unspec*)
    *(.data.CPU2_bool*)
    *(.data.CPU2_8*)
    *(.data.CPU2_16*)
    *(.data.CPU2_32*)
  } > CPU2_DSPR  AT > PFLASH0_CPU2_PRIVATE

  .CPU2_BSS : ALIGN(4)
  {
	*(.bss.CPU2_unspec*)
    *(.bss.CPU2_bool*)
    *(.bss.CPU2_8*)
    *(.bss.CPU2_16*)
    *(.bss.CPU2_32*)
    *(.bss.a1.Dsadc_DriverState*)
	__CPU2_DATA_END = .;
  } > CPU2_DSPR