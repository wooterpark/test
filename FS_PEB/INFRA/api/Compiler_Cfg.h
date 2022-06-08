/*
 * This is Compiler_Cfg.h for target platform: TriCoreHighTec/TC27xC
 */

/* [COMPILER054] [COMPILER055] */
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/*
 * Compiler_Cfg.c is normally a system-wide header file.
 * Typically the system integrator will take the settings
 * from each module and construct this by hand.
 * The contents of "Os_Compiler_Cfg.h" can be used by
 * the system integrator for this purpose.
 */
#include <Os_Compiler_Cfg.h>

#ifndef PARAM_UNUSED
    #define PARAM_UNUSED(param) if ((param) != 0) {}
#endif

#endif /* COMPILER_CFG_H */
