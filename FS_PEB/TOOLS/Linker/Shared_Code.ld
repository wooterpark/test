/* Shared code section */

  .SHARED_CODE : ALIGN(4)
  {
    PROVIDE(__SHARED_CODE_START = .);
    *(.text.Shared_Code)
    *(.text.RTE_Code)
	*(.text.Os*)          
	*(.text) /* some assembly code of OS */   
	
    PROVIDE(__SHARED_CODE_END = .);
    . = ALIGN(4);
  } > PFLASH0_SHARED_CODE