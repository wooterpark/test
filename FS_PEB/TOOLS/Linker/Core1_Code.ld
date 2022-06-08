/* Code section for Os Application on Core 1 */

  .CPU1_CODE : ALIGN(4)
  {
    __CPU1_CODE_START = .;
    *(.text.CPU1_Code)
    __CPU1_CODE_END = .;
  } > PFLASH0_CPU1_PRIVATE