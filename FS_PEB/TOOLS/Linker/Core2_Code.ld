/* Code section for Os Application on Core 1 */

  .CPU2_CODE : ALIGN(4)
  {
    __CPU2_CODE_START = .;
    *(.text.CPU2_Code)
    __CPU2_CODE_END = .;
  } > PFLASH0_CPU2_PRIVATE