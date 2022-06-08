#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2014)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  $FILENAME   : SafeWdgCD_Cfg.mak $                                        **
#*                                                                            **
#*  $CC VERSION : \main\3 $                                                  **
#*                                                                            **
#*  $DATE       : 2014-07-09 $                                               **
#*                                                                            ** 
#*  AUTHOR    : SafeTlib Team                                                 **
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file defines safety lib WDG CD modules delivery ON/OFF** 
#*         - Based on this delivery type values modules will be compiled      **
#*                                                                            ** 
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      ** 
#*                                                                            ** 
#******************************************************************************/ 
#
SAFEWDGEXTCIC_DELIVERY = OFF
SAFEWDGASCLIN_DELIVERY = OFF

SAFEWDGEXTTLF_DELIVERY = OFF
SAFEWDGQSPI_DELIVERY = OFF




SAFEWDGEXTALIVE_DELIVERY = OFF
SAFEWDGINT_DELIVERY = ON
SAFEWDGIF_DELIVERY = ON
