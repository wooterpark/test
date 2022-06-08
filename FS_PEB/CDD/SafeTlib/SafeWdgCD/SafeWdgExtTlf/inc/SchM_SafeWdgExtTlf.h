/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : SchM_SafeWdgExtTlf.h $                                     **
**                                                                            **
**   $CC VERSION : \main\1 $                                                  **
**                                                                            **
**   $DATE       : 2015-07-17 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  AUTHOR    : SafeTlib Team                                                 **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - SchM configuration of the SafeWdgExtTlf driver           **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
#ifndef SCHM_SAFEWDGEXTTLF_H
#define SCHM_SAFEWDGEXTTLF_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Mcal_TcLib.h"


/*******************************************************************************
**                     MACRO FUNCTIONS                                        **
*******************************************************************************/

#define SchM_Enter_SafeWdgExtTlf_ACCESS_001() \
do \
{ \
  Mcal_DisableAllInterrupts(); \
} \
while (0)
 

#define SchM_Exit_SafeWdgExtTlf_ACCESS_001() \
do \
{ \
  Mcal_EnableAllInterrupts(); \
} \
while (0)

#define SchM_Enter_SafeWdgExtTlf_ACCESS_002() \
do \
{ \
  Mcal_DisableAllInterrupts(); \
} \
while (0)
 

#define SchM_Exit_SafeWdgExtTlf_ACCESS_002() \
do \
{ \
  Mcal_EnableAllInterrupts(); \
} \
while (0)

#define SchM_Enter_SafeWdgExtTlf_ACCESS_003() \
do \
{ \
  Mcal_DisableAllInterrupts(); \
} \
while (0)
 

#define SchM_Exit_SafeWdgExtTlf_ACCESS_003() \
do \
{ \
  Mcal_EnableAllInterrupts(); \
} \
while (0)

#define SchM_Enter_SafeWdgExtTlf_ACCESS_004() \
do \
{ \
  Mcal_DisableAllInterrupts(); \
} \
while (0)
 

#define SchM_Exit_SafeWdgExtTlf_ACCESS_004() \
do \
{ \
  Mcal_EnableAllInterrupts(); \
} \
while (0)

#define SchM_Enter_SafeWdgExtTlf_ACCESS_005() \
do \
{ \
  Mcal_DisableAllInterrupts(); \
} \
while (0)
 

#define SchM_Exit_SafeWdgExtTlf_ACCESS_005() \
do \
{ \
  Mcal_EnableAllInterrupts(); \
} \
while (0)  
/*******************************************************************************
**                      Typedefs                                              **
*******************************************************************************/


/*******************************************************************************
**                      Enumerations                                          **
*******************************************************************************/


/*******************************************************************************
**                   Structure Definitions                                    **
*******************************************************************************/


/*******************************************************************************
**                   Exported Functions                                       **
*******************************************************************************/


/*******************************************************************************
**                   Imported Post-Build Data from Configuration files        **
*******************************************************************************/


#endif /* SchM_SafeWdgExtTlf.h */


