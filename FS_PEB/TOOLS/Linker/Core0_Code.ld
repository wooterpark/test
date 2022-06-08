/* Code section for Os Application on Core 0 */

  .CPU0_CODE : ALIGN(4)
  {
    __CPU0_CODE_START = .;
    *(.text.cstart)
    *(.text.CPU0_Code)
	  *Fee*.o (.text*)
	  *MemIf*.o (.text*)
    __CPU0_CODE_END = .;
  } > PFLASH0_CPU0_PRIVATE

  /* Code accessed by Trusted-with-Protectin OsApp */
  .TRUSTED_CODE_SHARED : ALIGN(4)
  {
  __TRUSTED_CODE_SHARED_START = .;
    *(.text.SharedTrusted_Code)
  __TRUSTED_CODE_SHARED_END = .;
  } > PFLASH0_CPU0_PRIVATE