
/***************************************************************************************************
* Includes
***************************************************************************************************/
#include "Xcp_Cbk.h"
#include "Xcp_OverlayMem.h"

/***************************************************************************************************
* Types
***************************************************************************************************/
typedef enum
{
  XCP_MEM_INVALID,
  XCP_MEM_CAL,
  XCP_MEM_RAM,
  XCP_MEM_FLASH
} Xcp_MemType;

typedef struct
{
  uint32 address;
  uint32 length;
  Xcp_MemType memtype;
  boolean readAllowed;
  boolean writeAllowed;
} Xcp_MemAccessCtrl_T;

/* CAL */
#define XCP_MEMACCESS_CAL_ADDR  CALFLASH_START_ADDR
#define XCP_MEMACCESS_CAL_SIZE  CAL_MEM_TOTAL_SIZE


/* System RAM - Exclude RAM for CAL */
#define XCP_MEMACCESS_RAM0_ADDR 0x70000000UL
#define XCP_MEMACCESS_RAM0_SIZE SIZE_KB(112)

/* Local RAM */
#define XCP_MEMACCESS_RAM1_ADDR   0x60000000UL
#define XCP_MEMACCESS_RAM1_SIZE   SIZE_KB(120)

#define XCP_MEMACCESS_RAM2_ADDR   0x50000000UL
#define XCP_MEMACCESS_RAM2_SIZE   SIZE_KB(120)




/***************************************************************************************************
* Variables
***************************************************************************************************/
#define XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Xcp_MemMap.h"
Xcp_MemType Xcp_RequiredAccessMem;
#define XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Xcp_MemMap.h"


#define XCP_START_SEC_CONST_UNSPECIFIED
#include "Xcp_MemMap.h"

static const Xcp_MemAccessCtrl_T Xcp_MemAccessCtrl[] =
{
	{
    XCP_MEMACCESS_CAL_ADDR,
    XCP_MEMACCESS_CAL_SIZE,
    XCP_MEM_CAL,
    TRUE,
    TRUE
  },
  {
    XCP_MEMACCESS_RAM0_ADDR,
    XCP_MEMACCESS_RAM0_SIZE,
    XCP_MEM_RAM,
    TRUE,
    FALSE
  },
  {
    XCP_MEMACCESS_RAM1_ADDR,
    XCP_MEMACCESS_RAM1_SIZE,
    XCP_MEM_RAM,
    TRUE,
    FALSE
  },
  {
	XCP_MEMACCESS_RAM2_ADDR,
	XCP_MEMACCESS_RAM2_SIZE,
	XCP_MEM_RAM,
	TRUE,
	FALSE
  }
};

#define XCP_STOP_SEC_CONST_UNSPECIFIED
#include "Xcp_MemMap.h"

#define NUM_OF_XCP_MEM_SECTIONS (sizeof(Xcp_MemAccessCtrl) / sizeof(Xcp_MemAccessCtrl_T))

/***************************************************************************************************
* Functions
***************************************************************************************************/
/* ------------------------------------------------------------------------ */
/* Begin section for code */

#define XCP_START_SEC_CODE
#include "Xcp_MemMap.h"

boolean XcpAppl_CheckMemAccess(Xcp_AdrPtrConst Address, uint32 Length, boolean readaccess)
{
  boolean accessallowed;
  uint8 memsecidx;

  accessallowed = FALSE;

  for (memsecidx = 0; memsecidx < NUM_OF_XCP_MEM_SECTIONS; memsecidx++)
  {
    if (((uint32)Address >= Xcp_MemAccessCtrl[memsecidx].address)
        && (((uint32)Address + Length) <= (Xcp_MemAccessCtrl[memsecidx].address + Xcp_MemAccessCtrl[memsecidx].length)))
    {
      if (readaccess == TRUE)
      {
        accessallowed = Xcp_MemAccessCtrl[memsecidx].readAllowed;
      }
      else /* writeaccess */
      {
        accessallowed = Xcp_MemAccessCtrl[memsecidx].writeAllowed;
      }

      Xcp_RequiredAccessMem = Xcp_MemAccessCtrl[memsecidx].memtype;

      break;
    }
  }

  return accessallowed;
}

boolean XcpAppl_IsRequiredAccessMemCAL(void)
{
  if (Xcp_RequiredAccessMem == XCP_MEM_CAL)
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

#define XCP_STOP_SEC_CODE
#include "Xcp_MemMap.h"

#define XCP_START_SEC_CALLOUT_CODE
#include "Xcp_MemMap.h"

#if (XCP_MEMORY_READ_PROTECTION == STD_ON)
/**
****************************************************************************************************
Check if is allowed to read from this area
\param[in]  Address       - Memory start address
\param[in]  Length        - Length of reading area
\retval     XCP_NO_ERROR            access granted
\retval     XCP_ERR_ACCESS_DENIED   access denied
\retval     XCP_NO_ACCESS_HIDE      access denied, but correct response is sent with data content 0x00
***************************************************************************************************/
Xcp_ErrorCode XcpAppl_MemReadProtection(Xcp_AdrPtrConst Address, uint8 Length)
{
  /*-----------------------------------------------------------------*/
  /* This function is project specific and shall be totally reworked */
  /*-----------------------------------------------------------------*/

  /* Local variables */
  Xcp_ErrorCode Error;
  boolean checkResult;

  /* Remove when parameter used */
  //XCP_PARAM_UNUSED(Address);
  //XCP_PARAM_UNUSED(Length);

  /* Initial values */
  Error = XCP_NO_ERROR;

  /* Do checks here... */
  checkResult = XcpAppl_CheckMemAccess(Address, Length, TRUE);

  if (checkResult == FALSE)
  {
	  Error = XCP_ERR_ACCESS_DENIED;
  }

  return(Error);
}

# if (XCP_CMD_BUILD_CHECKSUM_AVAILABLE == STD_ON)
/**
****************************************************************************************************
Check if the requested area is allowed to read for Build Checksum
\param[in]  Address       - Memory start address
\param[in]  Length        - Length of reading area
\retval     XCP_NO_ERROR            access granted
\retval     XCP_ERR_ACCESS_DENIED   access denied
\retval     XCP_NO_ACCESS_HIDE      access denied, but correct response is sent with data content 0x00
***************************************************************************************************/
Xcp_ErrorCode XcpAppl_ChecksumProtection(Xcp_AdrPtrConst Address, uint32 Length)
{
  /*-----------------------------------------------------------------*/
  /* This function is project specific and shall be totally reworked */
  /*-----------------------------------------------------------------*/

  /* Local variables */
  Xcp_ErrorCode Error;
  boolean checkResult;

  /* Remove when parameter used */
  //XCP_PARAM_UNUSED(Address);
  //XCP_PARAM_UNUSED(Length);

  /* Initial values */
  Error = XCP_NO_ERROR;

  /* Do checks here... */
  checkResult = XcpAppl_CheckMemAccess(Address, Length, TRUE);

  if (checkResult == FALSE)
  {
	  Error = XCP_ERR_ACCESS_DENIED;
  }

  return(Error);
}
# endif /* (XCP_CMD_BUILD_CHECKSUM_AVAILABLE == STD_ON) */
#endif /* (XCP_MEMORY_READ_PROTECTION == STD_ON) */


#if (XCP_MEMORY_WRITE_PROTECTION == STD_ON)
/**
****************************************************************************************************
Check if is allowed to write to this area
\param[in]  Address   Memory start address
\param[in]  Length    Length of reading area
\retval     XCP_NO_ERROR            access granted
\retval     XCP_ERR_ACCESS_DENIED   access denied
***************************************************************************************************/
Xcp_ErrorCode XcpAppl_MemWriteProtection(Xcp_AdrPtrConst Address, uint8 Length)
{
  /*-----------------------------------------------------------------*/
  /* This function is project specific and shall be totally reworked */
  /*-----------------------------------------------------------------*/

  /* Local variables */
  Xcp_ErrorCode Error;
  boolean checkResult;

  /* Remove when parameter used */
  //XCP_PARAM_UNUSED(Address);
  //XCP_PARAM_UNUSED(Length);

  /* Initial values */
  Error = XCP_NO_ERROR;

  /* Do checks here... */
  checkResult = XcpAppl_CheckMemAccess(Address, Length, FALSE);

  if (checkResult == FALSE)
  {
	  Error = XCP_ERR_ACCESS_DENIED;
  }

  return(Error);
}
#endif /* (XCP_MEMORY_WRITE_PROTECTION == STD_ON) */

/* ------------------------------------------------------------------------ */
/* End section for code */

#define XCP_STOP_SEC_CALLOUT_CODE
#include "Xcp_MemMap.h"


