/* Data section for Shared data on LMU RAM, Read & Write access */
  .SHARED_WRITE_DATA : ALIGN(4)
  {
	__SHARED_WRITE_DATA_START = .;
    *(.data.Rte_unspec*)
    *(.data.Rte_bool*)
    *(.data.Rte_8*)
    *(.data.Rte_16*)
    *(.data.Rte_32*)   
    *(.data.Shared_unspec*)
    *(.data.Shared_bool*)
    *(.data.Shared_8*)
    *(.data.Shared_16*)
    *(.data.Shared_32*)  
  } > CPU2_DSPR_SHARE_DATA AT > PFLASH0_SHARED_CODE
  
  .SHARED_WRITE_BSS : ALIGN(4)
  {
	*(.bss.Rte_unspec*)
    *(.bss.Rte_bool*)
    *(.bss.Rte_8*)
    *(.bss.Rte_16*)
    *(.bss.Rte_32*)   
    *(.bss.Shared_unspec*)
    *(.bss.Shared_bool*)
    *(.bss.Shared_8*)
    *(.bss.Shared_16*)
    *(.bss.Shared_32*)   
  	*(.bss.*.Os_IocData)
	__SHARED_WRITE_DATA_END = .;
  } > CPU2_DSPR_SHARE_DATA
  
  /* Shared data among partitions, Untrusted Partition only has Read access */
  .SHARED_DATA : ALIGN(4)
  {
    __SHARED_DATA_START = .;
    *(.data.Shared_RO_unspec*)
    *(.data.Shared_RO_bool*)
    *(.data.Shared_RO_8*)
    *(.data.Shared_RO_16*)
    *(.data.Shared_RO_32*)  
    *(.data.*.Os*)
  } > CPU2_DSPR_SHARE_DATA AT > PFLASH0_SHARED_CODE
  
  .SHARED_BSS : ALIGN(4)
  {
    *(.bss.Shared_RO_unspec*)
    *(.bss.Shared_RO_bool*)
    *(.bss.Shared_RO_8*)
    *(.bss.Shared_RO_16*)
    *(.bss.Shared_RO_32*) 
	__SHARED_DATA_END = .;
  } > CPU2_DSPR_SHARE_DATA
  
