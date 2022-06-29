/********************************************************************************************

TENTATIVE DEFINITIONS

MESSAGES:
=========
:0632  [U] Tentative definition of '%s' with internal linkage cannot have unknown size.
:2021  This tentative definition is interpreted as a declaration. Is this intended ?
:2022  A tentative definition is being used. Is it appropriate to include an explicit initializer ?
:1306  Multiple tentative definitions of '%s'. This is not allowed in C++.


ISO:C99 6.9.2 External object definitions
=========================================
Semantics

1 If the declaration of an identifier for an object has file scope and an initializer, the
  declaration is an external definition for the identifier.

2 A declaration of an identifier for an object that has file scope without an initializer, and
  without a storage-class specifier or with the storage-class specifier static, constitutes a
  tentative definition. If a translation unit contains one or more tentative definitions for an
  identifier, and the translation unit contains no external definition for that identifier, then
  the behavior is exactly as if the translation unit contains a file scope declaration of that
  identifier, with the composite type as of the end of the translation unit, with an initializer
  equal to 0.

3 If the declaration of an identifier for an object is a tentative definition and has internal
  linkage, the declared type shall not be an incomplete type.

********************************************************************************************/
#pragma PRQA_MESSAGES_OFF 1277,2017,3120,3198,3207,3210,3211,3224,3337,3408,3447,3603,3684


int ga;                                       /* 2021      */
int ga = 1;                                   /*           */

int gb = 1;                                   /*           */
int gb;                                       /* 2021      */

int gc;                                       /* 2022      */

extern int gd;                                /*           */
extern int gd;                                /*           */

extern int ge;                                /*           */
int ge;                                       /* 2022      */

int gf;                                       /* 2022      */
int gf;                                       /* 2021 1306 */
int gf;                                       /* 2021 1306 */

int gg;                                       /* 2021      */
int gg;                                       /* 2021 1306 */
int gg;                                       /* 2021 1306 */
int gg = 1;                                   /*           */

extern int gh;                                /*           */
extern int gh = 1;                            /*           */



static int sab[];                             /* 2022 0632 */

static int sa;                                /* 2021      */
static int sa = 1;                            /*           */

static int sb = 1;                            /*           */
static int sb;                                /* 2021      */

static int sc;                                /* 2022      */

static int sd;                                /* 2022      */
static int sd;                                /* 2021 1306 */

static int sf;                                /* 2022      */
static int sf;                                /* 2021 1306 */
static int sf;                                /* 2021 1306 */

static int sg;                                /* 2021      */
static int sg;                                /* 2021 1306 */
static int sg;                                /* 2021 1306 */
static int sg = 1;                            /*           */




static int xa;                                /* 2021      */
extern int xa = 1;                            /*           */

static int xb = 1;                            /*           */
extern int xb;                                /*           */

static int xc;                                /* 2022      */

static int xd;                                /* 2022      */
extern int xd;                                /*           */

static int xf;                                /* 2022      */
extern int xf;                                /*           */
extern int xf;                                /*           */

static int xg;                                /* 2021      */
extern int xg;                                /*           */
extern int xg;                                /*           */
extern int xg = 1;                            /*           */
