/* To disable the Crossbar MPU, comment the #define with "/*" not "//" */
#ifndef _RBA_MPU_SFTY_LINKER_H_
#define _RBA_MPU_SFTY_LINKER_H_

/* CORE 0 addresses */  
__RAM0_MPU_SFTY_SECTION0_START		= 0x7000D000;//CSA STACK START
/*protected    asw_stack1*/
/*protected    asw_csa1*/
__RAM0_MPU_SFTY_SECTION0_END		= 0x70012FFF;//CSA STACK END



/* CORE 1 addresses */    
__RAM1_MPU_SFTY_SECTION0_START   	= 0x60018800;//CSA STACK START
/*protected    DMA Buffer*/
/*protected    short addressing BMW B0 (FAR_OS_APP_1B0)*/
/*protected    short addressing BMW B1 (FAR_OS_APP_1B1)*/
/*protected    short addressing ZF  C0 (FAR_OS_APP_1C0)*/
__RAM1_MPU_SFTY_SECTION0_END 		= 0x6001DFFF; /* __REL_OS_APP_1C0_END; */



/* CORE 2 addresses */  
__RAM2_MPU_SFTY_SECTION0_START		= 0x50018100;//TEST
/*protected    asw_stack1*/
/*protected    asw_csa1*/
__RAM2_MPU_SFTY_SECTION0_END		= 0x5001Dfff;//CSA STACK END

#if 0

_. = ASSERT (((__RAM0_MPU_SFTY_SECTION0_START < __RAM0_MPU_SFTY_SECTION0_END) && ((__RAM0_MPU_SFTY_SECTION0_START & 0x0000001F) == 0x0) && (((__RAM0_MPU_SFTY_SECTION0_END + 1) & 0x0000001F) == 0x0)),
                "rbe_CddMonHw_Mpu_Sfty_Linker.h: Functional Safety Configuration Error, SftyMpu Section, the RAM0 SECTN0 label is not correctly set, the 32bit align must be abided by!!");  
_. = ASSERT (((__RAM1_MPU_SFTY_SECTION0_START < __RAM1_MPU_SFTY_SECTION0_END) && ((__RAM1_MPU_SFTY_SECTION0_START & 0x0000001F) == 0x0) && (((__RAM1_MPU_SFTY_SECTION0_END + 1) & 0x0000001F) == 0x0)),
                "rbe_CddMonHw_Mpu_Sfty_Linker.h: Functional Safety Configuration Error, SftyMpu Section, the RAM1 SECTN0 label is not correctly set, the 32bit align must be abided by!!"); 
_. = ASSERT (((__RAM2_MPU_SFTY_SECTION0_START < __RAM2_MPU_SFTY_SECTION0_END) && ((__RAM2_MPU_SFTY_SECTION0_START & 0x0000001F) == 0x0) && (((__RAM2_MPU_SFTY_SECTION0_END + 1) & 0x0000001F) == 0x0)),
                "rbe_CddMonHw_Mpu_Sfty_Linker.h: Functional Safety Configuration Error, SftyMpu Section, the RAM2 SECTN0 label is not correctly set, the 32bit align must be abided by!!"); 


_. = ASSERT (((__RAM1_MPU_SFTY_SECTION1_START < __RAM1_MPU_SFTY_SECTION1_END) && ((__RAM1_MPU_SFTY_SECTION1_START & 0x0000001F) == 0x0) && (((__RAM1_MPU_SFTY_SECTION1_END + 1) & 0x0000001F) == 0x0)),
                "rbe_CddMonHw_Mpu_Sfty_Linker.h: Functional Safety Configuration Error, SftyMpu Section, the RAM1 SECTN1 label is not correctly set, the 32bit align must be abided by!!"); 

_. = ASSERT (((__RAM1_MPU_SFTY_SECTION2_START < __RAM1_MPU_SFTY_SECTION2_END) && ((__RAM1_MPU_SFTY_SECTION2_START & 0x0000001F) == 0x0) && (((__RAM1_MPU_SFTY_SECTION2_END + 1) & 0x0000001F) == 0x0)),
                "rbe_CddMonHw_Mpu_Sfty_Linker.h: Functional Safety Configuration Error, SftyMpu Section, the RAM1 SECTN2 label is not correctly set, the 32bit align must be abided by!!"); 


	/*** DEFAULT CONFIGURATION ***/
	
	/* CORE 0 addresses */  
	__RAM0_MPU_SFTY_SECTION0_START		= __RAM0_START;
	__RAM0_MPU_SFTY_SECTION0_END		= __RAM0_END;

	/* CORE 1 addresses */    
	__RAM1_MPU_SFTY_SECTION0_START   	= __PRAM1_FREE_END;
	/* Inversion of the end and the start to create a failure in the initialization 
	and thus having Xbar protection all open */
	__RAM1_MPU_SFTY_SECTION0_END 		= __RAM1_START; 

	__RAM1_MPU_SFTY_SECTION1_START   	= __RAM1_START;
	__RAM1_MPU_SFTY_SECTION1_END 		= __PRAM1_FREE_END; 

	__RAM1_MPU_SFTY_SECTION2_START   	= __RAM1_START; 
	__RAM1_MPU_SFTY_SECTION2_END 		= __PRAM1_FREE_END; 

	/* CORE 2 addresses */  
	__RAM2_MPU_SFTY_SECTION0_START		= __RAM2_START;
	__RAM2_MPU_SFTY_SECTION0_END		= __RAM2_END;
#endif


#endif

