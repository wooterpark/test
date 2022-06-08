#/******************************************************************************
#** Copyright (C) Infineon Technologies (2013)                                **
#**                                                                           **
#** All rights reserved.                                                      **
#**                                                                           **
#** This document contains proprietary information belonging to Infineon      **
#** Technologies. Passing on and copying of this document, and communication  **
#** of its contents is not permitted without prior written authorization.     **
#**                                                                           **
#*******************************************************************************
#**  FILENAME  : SafeWdgCD.mak                                                **
#**                                                                           **
#**  VERSION   : 0.0.1                                                        **
#**                                                                           **
#**  DATE      : 2013-09-18                                                   **
#**                                                                           **
#**  VARIANT   : VariantPB                                                    **
#**                                                                           **
#**  PLATFORM  : Infineon AURIX                                               **
#**                                                                           **
#**  COMPILER  : Tasking                                                      **
#**                                                                           **
#**  AUTHOR    : SafeTlib Team                                                **
#**                                                                           **
#**  VENDOR    : Infineon Technologies                                        **
#**                                                                           **
#**  TRACEABILITY:                                                            **
#**                                                                           **
#**  DESCRIPTION  : Makefile for SafeTlibCD                                   **
#**                                                                           **
#**  SPECIFICATION(S) :                                                       **
#**                                                                           **
#**  MAY BE CHANGED BY USER [Yes/No]: No                                      **
#**                                                                           **
#******************************************************************************/
#
#/******************************************************************************
#**                      Author(s) Identity                                   **
#*******************************************************************************
#**                                                                           **
#** Initials     Name                                                         **
#** --------------------------------------------------------------------------**
#** BM           Basheer Mohaideen                                            **
#******************************************************************************/
#
#
#/******************************************************************************
#**                      Revision Control History                             **
#******************************************************************************/
#/*
# * V0.0.1: 2013-09-18, BM : Initial Version. 
# *                           Makefile for SafeWdgCD
# *
# */

### SafeWdgCD Objects Directory
SAFEWDG_OBJDIR = $(APPL_BASE_DIR)/debug/TC$(STL_TARGET)x/$(COMPILER_CHOICE_TP)
ifeq ($(UVP_TEST_AUTO),1)
SAFEWDG_OBJDIR = $(BASE_PATH)../obj
endif

include $(SAFEWDG_BASE_DIR)/SafeWdgCD_Cfg.mak 
include $(COMMON)/Compiler_Options_windriver.mak

### SafeWdgCD object files
ifeq ($(SAFEWDGIF_DELIVERY),ON)
SAFEWDG_OBJ = $(SAFEWDG_OBJDIR)/SafeWdgIf.o $(SAFEWDG_OBJDIR)/SafeWdgIf_PBCfg.o
endif
ifeq ($(SAFEWDGINT_DELIVERY),ON)
SAFEWDG_OBJ += $(SAFEWDG_OBJDIR)/SafeWdgInt.o $(SAFEWDG_OBJDIR)/SafeWdgInt_PBCfg.o
endif
	
ifeq ($(SAFEWDGEXTCIC_DELIVERY),ON)
SAFEWDG_OBJ += $(SAFEWDG_OBJDIR)/SafeWdgExtCic.o $(SAFEWDG_OBJDIR)/SafeWdgExtCic_PBCfg.o	
endif
ifeq ($(SAFEWDGASCLIN_DELIVERY),ON)
SAFEWDG_OBJ += $(SAFEWDG_OBJDIR)/SafeWdgAscLin.o $(SAFEWDG_OBJDIR)/SafeWdgAscLin_PBCfg.o
endif

ifeq ($(SAFEWDGEXTTLF_DELIVERY),ON)
SAFEWDG_OBJ += $(SAFEWDG_OBJDIR)/SafeWdgExtTlf.o $(SAFEWDG_OBJDIR)/SafeWdgExtTlf_PBCfg.o
ifeq ($(SAFEWDGQSPI_DELIVERY),ON)
SAFEWDG_OBJ += $(SAFEWDG_OBJDIR)/SafeWdgQspi.o $(SAFEWDG_OBJDIR)/SafeWdgQspi_PBCfg.o
endif
endif

all: $(SAFEWDG_LIB)/SafeWdgCD.a



PHONY: clean
clean:
	@-rm -f $(SAFEWDG_OBJ)
	@-rm -f $(SAFEWDG_OBJDIR)/*.src
	@-rm -f $(SAFETLIBCD_OBJDIR)/*.sym
    	

$(SAFEWDG_LIB)/SafeWdgCD.a : $(SAFEWDG_OBJ)
	@echo Creating archive SafeWdgCD.a
	@$(ARTC) $(OPT_ARTC) $(SAFEWDG_LIB)/SafeWdgCD.a $(SAFEWDG_OBJ)
		
		
### SAFE WATCHDOG INTERFACE
$(SAFEWDG_OBJDIR)/SafeWdgIf.o: $(SAFEWDG_IF_DIR)/src/SafeWdgIf.c
	@echo Compiling $(SAFEWDG_IF_DIR)/src/SafeWdgIf.c
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgIf.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(SAFEWDG_IF_DIR)/src/SafeWdgIf.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgIf.ers
	
$(SAFEWDG_OBJDIR)/SafeWdgIf_PBCfg.o: $(CONFIG_DIR)/src/SafeWdgIf_PBCfg.c
	@echo Compiling $(CONFIG_DIR)/src/SafeWdgIf_PBCfg.c
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgIf_PBCfg.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(CONFIG_DIR)/src/SafeWdgIf_PBCfg.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgIf_PBCfg.ers

	
### INTERNAL SAFE WATCHDOG
$(SAFEWDG_OBJDIR)/SafeWdgInt.o: $(SAFEWDG_INT_DIR)/src/SafeWdgInt.c
	@echo Compiling $(SAFEWDG_INT_DIR)/src/SafeWdgInt.c
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgInt.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(SAFEWDG_INT_DIR)/src/SafeWdgInt.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgInt.ers
	
$(SAFEWDG_OBJDIR)/SafeWdgInt_PBCfg.o: $(CONFIG_DIR)/src/SafeWdgInt_PBCfg.c
	@echo Compiling $(CONFIG_DIR)/src/SafeWdgInt_PBCfg.c
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgInt_PBCfg.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(CONFIG_DIR)/src/SafeWdgInt_PBCfg.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgInt_PBCfg.ers

### EXTERNAL CIC SAFE WATCHDOG
$(SAFEWDG_OBJDIR)/SafeWdgExtCic.o: $(SAFEWDG_EXTCIC_DIR)/src/SafeWdgExtCic.c
	@echo Compiling "$(SAFEWDG_EXTCIC_DIR)/src/SafeWdgExtCic.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgExtCic.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(SAFEWDG_EXTCIC_DIR)/src/SafeWdgExtCic.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgExtCic.ers
	
$(SAFEWDG_OBJDIR)/SafeWdgExtCic_PBCfg.o: $(CONFIG_DIR)/src/SafeWdgExtCic_PBCfg.c
	@echo Compiling "$(CONFIG_DIR)/src/SafeWdgExtCic_PBCfg.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgExtCic_PBCfg.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(CONFIG_DIR)/src/SafeWdgExtCic_PBCfg.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgExtCic_PBCfg.ers	

### EXTERNAL TLF SAFE WATCHDOG
$(SAFEWDG_OBJDIR)/SafeWdgExtTlf.o: $(SAFEWDG_EXTTLF_DIR)/src/SafeWdgExtTlf.c
	@echo Compiling "$(SAFEWDG_EXTTLF_DIR)/src/SafeWdgExtTlf.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgExtTlf.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(SAFEWDG_EXTTLF_DIR)/src/SafeWdgExtTlf.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgExtTlf.ers
	
$(SAFEWDG_OBJDIR)/SafeWdgExtTlf_PBCfg.o: $(CONFIG_DIR)/src/SafeWdgExtTlf_PBCfg.c
	@echo Compiling "$(CONFIG_DIR)/src/SafeWdgExtTlf_PBCfg.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgExtTlf_PBCfg.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(CONFIG_DIR)/src/SafeWdgExtTlf_PBCfg.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgExtTlf_PBCfg.ers

### ASCLIN SPI DRIVER FOR EXT WATCHDOG
$(SAFEWDG_OBJDIR)/SafeWdgAscLin.o: $(SAFEWDG_ASCLIN_DIR)/src/SafeWdgAscLin.c
	@echo Compiling "$(SAFEWDG_ASCLIN_DIR)/src/SafeWdgAscLin.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgAscLin.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(SAFEWDG_ASCLIN_DIR)/src/SafeWdgAscLin.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgAscLin.ers
	
$(SAFEWDG_OBJDIR)/SafeWdgAscLin_PBCfg.o: $(CONFIG_DIR)/src/SafeWdgAscLin_PBCfg.c
	@echo Compiling "$(CONFIG_DIR)/src/SafeWdgAscLin_PBCfg.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgAscLin_PBCfg.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(CONFIG_DIR)/src/SafeWdgAscLin_PBCfg.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgAscLin_PBCfg.ers	
	
### QSPI DRIVER FOR EXT TLF WATCHDOG
$(SAFEWDG_OBJDIR)/SafeWdgQspi.o: $(SAFEWDG_QSPI_DIR)/src/SafeWdgQspi.c
	@echo Compiling "$(SAFEWDG_QSPI_DIR)/src/SafeWdgQspi.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgQspi.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(SAFEWDG_QSPI_DIR)/src/SafeWdgQspi.c  
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgQspi.ers
	
$(SAFEWDG_OBJDIR)/SafeWdgQspi_PBCfg.o: $(CONFIG_DIR)/src/SafeWdgQspi_PBCfg.c
	@echo Compiling "$(CONFIG_DIR)/src/SafeWdgQspi_PBCfg.c"
	@$(CCTC) -o $(SAFEWDG_OBJDIR)/SafeWdgQspi_PBCfg.o $(STD_OPT_SWDG) $(OBJ_CREATION) $(CONFIG_DIR)/src/SafeWdgQspi_PBCfg.c  -I$(SWDGM_BASE_DIR)"./UpperLayer/SafeWdgM/inc"
	@-rm -f $(SAFEWDG_OBJDIR)/SafeWdgQspi_PBCfg.ers
