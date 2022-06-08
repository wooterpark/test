/*
 * File: SWC_TCF.c
 *
 * Code generated for Simulink model 'SWC_TCF'.
 *
 * Model version                  : 1.604
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed May 25 19:51:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_TCF.h"
#include "SWC_TCF_private.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlcpw.h"
#include "look2_iflf_binlxpw.h"

/* user code (top of source file) */
#include "set_get_data.h"
#include "L2Sample_FS.h"

/* Exported block signals */
float32 VAR_L2Sampling_DycUMon_f32;    /* '<S1>/Signal Conversion4' */
float32 VAR_L2Sampling_DycVMon_f32;    /* '<S1>/Signal Conversion5' */
float32 VAR_L2Sampling_DycWMon_f32;    /* '<S1>/Signal Conversion6' */
float32 VAR_HSPF_StrrTempFlt_f32;      /* '<S1>/Signal Conversion7' */
float32 VAR_TCF_CurrAgTrqTubeH1_f32;   /* '<S31>/Add2' */
float32 VAR_TCF_CurrAgTrqTubeL1_f32;   /* '<S31>/Add3' */
float32 VAR_TCF_PwrTrqfltcomp_f32;     /* '<S31>/Switch' */
float32 VAR_TCF_PwrTrqTubeH1_f32;      /* '<S31>/Add' */
float32 VAR_TCF_PwrTrqTubeL1_f32;      /* '<S31>/Add1' */
float32 VAR_TCF_BlendTrq_f32;          /* '<S30>/TubeSelector2' */
float32 VAR_TCF_PwrTrqCompCof_f32;     /* '<S22>/Switch' */
float32 VAR_TCF_PwrTrqNoflt_f32;       /* '<S22>/Product2' */
float32 VAR_TCF_PwrTrqflt_f32;         /* '<S22>/Saturation1' */
float32 VAR_TCF_Ploss_f32;             /* '<S21>/Switch' */
float32 VAR_TCF_PwrInputNoflt_f32;     /* '<S20>/Add4' */
float32 VAR_TCF_PwrInputflt_f32;       /* '<S20>/Saturation1' */
float32 VAR_TCF_IsNoflt_f32;           /* '<S19>/Sqrt' */
float32 VAR_TCF_Isflt_f32;             /* '<S19>/Saturation1' */
float32 VAR_TCF_LdsubLq_f32;           /* '<S9>/Switch' */
float32 VAR_TCF_idAct_f32;             /* '<S8>/Add2' */
float32 VAR_TCF_iqAct_f32;             /* '<S8>/Add3' */
float32 VAR_TCF_CurrAgTrqNoComp_f32;   /* '<S7>/Product2' */
float32 VAR_TCF_CurrAgTrqflt_f32;      /* '<S7>/Saturation1' */
uint8 VAR_TCF_nDir_u8;                 /* '<S14>/Switch' */
uint8 VAR_TCF_TrqDir_u8;               /* '<S13>/Switch' */
uint8 VAR_TCF_MotorMode_u8;            /* '<S12>/Merge' */
boolean VAR_TCF_TrqCalcMonRslt_b;      /* '<S30>/TubeSelector2' */
boolean VAR_TCF_TrqCalcErr_b;          /* '<S29>/Logical Operator' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_TCF_AgTrqTubeCAy_af32[18] = { 30.0F, 30.0F, 30.0F,
  30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 40.0F, 40.0F, 40.0F, 40.0F,
  40.0F, 40.0F, 40.0F, 40.0F } ;   /* Referenced by: '<S31>/1-D Lookup Table' */

const volatile float32 CAL_TCF_HiSpdDirStop_f32 = 10.0F;
                           /* Referenced by: '<S14>/CAL_TOM_HiSpdDirStop_f32' */
const volatile float32 CAL_TCF_HiTrqDirStop_f32 = 3.0F;
                           /* Referenced by: '<S13>/CAL_TOM_HiTrqDirStop_f32' */
const volatile float32 CAL_TCF_IsCutOffFrq_f32 = 20.0F;
                            /* Referenced by: '<S19>/CAL_TCF_IsCutOffFrq_f32' */
const volatile float32 CAL_TCF_IsPwrLosCAx_af32[35] = { 0.0F, 20.0F, 40.0F,
  60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 220.0F, 240.0F,
  260.0F, 280.0F, 300.0F, 320.0F, 340.0F, 360.0F, 380.0F, 400.0F, 420.0F, 440.0F,
  460.0F, 480.0F, 500.0F, 520.0F, 540.0F, 560.0F, 580.0F, 600.0F, 620.0F, 640.0F,
  660.0F, 680.0F } ;                   /* Referenced by: '<S21>/IS_N_Ploss_T' */

const volatile float32 CAL_TCF_LdSubLqCAzGen_af32[270] = { -0.000220739F,
  -0.000512963F, -0.00043F, -0.000374691F, -0.000349145F, -0.000325817F,
  -0.000314021F, -0.000299333F, -0.000290613F, -0.000284007F, -0.000263814F,
  -0.000243496F, -0.000260123F, -0.000254762F, -0.00023239F, -0.000210234F,
  -0.000201002F, -0.000189487F, -0.000220739F, -0.000512963F, -0.00043F,
  -0.000374691F, -0.000349145F, -0.000325817F, -0.000314021F, -0.000299333F,
  -0.000290613F, -0.000284007F, -0.000263814F, -0.000243496F, -0.000260123F,
  -0.000254762F, -0.00023239F, -0.000210234F, -0.000201002F, -0.000189487F,
  -0.000244207F, -0.000438889F, -0.000383333F, -0.000327778F, -0.000324359F,
  -0.000310784F, -0.000297619F, -0.000288667F, -0.000279885F, -0.000271212F,
  -0.000271622F, -0.000254878F, -0.000249259F, -0.000239116F, -0.000236792F,
  -0.000212573F, -0.000204098F, -0.000195641F, -0.000247531F, -0.000389506F,
  -0.000344815F, -0.000319136F, -0.000304986F, -0.000296405F, -0.000284921F,
  -0.000277852F, -0.00026954F, -0.000263244F, -0.000255806F, -0.000248013F,
  -0.000239547F, -0.000232842F, -0.000225402F, -0.000212508F, -0.000204948F,
  -0.00019661F, -0.000250855F, -0.000374786F, -0.000327436F, -0.000302991F,
  -0.000290631F, -0.000287858F, -0.000273321F, -0.000265487F, -0.000258046F,
  -0.000252797F, -0.000244872F, -0.000239118F, -0.000231823F, -0.000224411F,
  -0.000217634F, -0.000208659F, -0.000200862F, -0.00019071F, -0.000233007F,
  -0.000337582F, -0.000302549F, -0.000282462F, -0.000271719F, -0.000264879F,
  -0.000251307F, -0.000250314F, -0.000244523F, -0.000239542F, -0.000233519F,
  -0.000227714F, -0.000221416F, -0.000215546F, -0.000209267F, -0.000201978F,
  -0.000194519F, -0.000187399F, -0.00020873F, -0.000298677F, -0.000269683F,
  -0.00025388F, -0.000247192F, -0.000242717F, -0.000236924F, -0.000232349F,
  -0.000227668F, -0.000224122F, -0.000219198F, -0.000214266F, -0.000208624F,
  -0.000204389F, -0.000198547F, -0.000192133F, -0.000190593F, -0.000179304F,
  -0.000178889F, -0.000256667F, -0.000234F, -0.000224815F, -0.000220769F,
  -0.000218235F, -0.000213492F, -0.0002124F, -0.00020977F, -0.000207172F,
  -0.000203514F, -0.00019878F, -0.00019563F, -0.000191905F, -0.000187358F,
  -0.000184386F, -0.000181413F, -0.000178441F, -0.000141954F, -0.000216667F,
  -0.000203563F, -0.000196743F, -0.000195889F, -0.000195098F, -0.000192693F,
  -0.000191747F, -0.000190666F, -0.000190369F, -0.000187496F, -0.000184202F,
  -0.000181239F, -0.000178525F, -0.00017481F, -0.000172121F, -0.000169433F,
  -0.000166744F, -0.000108923F, -0.000176263F, -0.000173434F, -0.00017211F,
  -0.000172378F, -0.000173113F, -0.000170924F, -0.000172263F, -0.000171839F,
  -0.000171671F, -0.000170584F, -0.000168354F, -0.000166633F, -0.00016478F,
  -0.000162064F, -0.000161075F, -0.000159223F, -0.00015737F, -8.15315E-5F,
  -0.000141592F, -0.000142613F, -0.000149299F, -0.000151871F, -0.000153498F,
  -0.00015236F, -0.000155009F, -0.000154753F, -0.000155378F, -0.000154651F,
  -0.000153735F, -0.000152583F, -0.000151618F, -0.000150277F, -0.000149124F,
  -0.000147971F, -0.000146818F, -4.729E-5F, -0.000102846F, -0.000116992F,
  -0.000127778F, -0.000132864F, -0.000135557F, -0.00013645F, -0.00013852F,
  -0.000139319F, -0.000139677F, -0.000139629F, -0.000139788F, -0.000139286F,
  -0.000138618F, -0.000138283F, -0.000137782F, -0.00013728F, -0.000136779F,
  -1.41975E-5F, -6.7284E-5F, -9.0E-5F, -0.000108436F, -0.000116097F,
  -0.000118192F, -0.000121076F, -0.000121852F, -0.000124457F, -0.000125533F,
  -0.000126476F, -0.00012579F, -0.000126461F, -0.000124418F, -0.000123732F,
  -0.000123046F, -0.00012236F, -0.000121674F, -3.03244E-5F, -3.07256E-5F,
  -6.53741E-5F, -8.9607E-5F, -9.91889E-5F, -0.000103461F, -0.00010643F,
  -0.000110354F, -0.000111201F, -0.00011308F, -0.000114368F, -0.000114659F,
  -0.000116946F, -0.000118234F, -0.000119523F, -0.000120812F, -0.0001221F,
  -0.000123389F, 4.95807E-5F, 7.65199E-6F, -4.06918E-5F, -7.18728E-5F,
  -8.43493E-5F, -9.11395E-5F, -9.4145E-5F, -9.75723E-5F, -9.97289E-5F,
  -0.000102125F, -0.000104521F, -0.000106917F, -0.000109313F, -0.000111709F,
  -0.000114106F, -0.000116502F, -0.000118898F, -0.000121294F } ;/* Referenced by: '<S9>/LdSubLqGen_L2' */

const volatile float32 CAL_TCF_LdSubLqCAzMot_af32[270] = { -0.000220739F,
  -0.000229336F, -0.000237934F, -0.000246531F, -0.000255128F, -0.000263725F,
  -0.000242593F, -0.000248222F, -0.000238889F, -0.000245286F, -0.000259309F,
  -0.000239431F, -0.000239136F, -0.000235488F, -0.00023239F, -0.000235575F,
  -0.000221038F, -0.000232222F, -0.000220739F, -0.000229336F, -0.000237934F,
  -0.000246531F, -0.000255128F, -0.000263725F, -0.000242593F, -0.000248222F,
  -0.000238889F, -0.000245286F, -0.000259309F, -0.000239431F, -0.000239136F,
  -0.000235488F, -0.00023239F, -0.000235575F, -0.000221038F, -0.000232222F,
  -0.000244207F, -0.000244207F, -0.000241111F, -0.000264815F, -0.000255128F,
  -0.000257843F, -0.000256349F, -0.000255333F, -0.000251149F, -0.00025101F,
  -0.000248198F, -0.000241057F, -0.000237407F, -0.000237075F, -0.000227358F,
  -0.000227193F, -0.000219945F, -0.000214103F, -0.000247531F, -0.000247531F,
  -0.000252222F, -0.000273868F, -0.0002651F, -0.000263725F, -0.000258466F,
  -0.000257111F, -0.000252299F, -0.000249214F, -0.000246797F, -0.000238979F,
  -0.000234198F, -0.000232842F, -0.000222257F, -0.000215107F, -0.000210716F,
  -0.000204017F, -0.000250855F, -0.000250855F, -0.000263333F, -0.000267379F,
  -0.000266963F, -0.000257692F, -0.000255006F, -0.000250103F, -0.000246552F,
  -0.000243473F, -0.000236556F, -0.000234115F, -0.00022641F, -0.000221272F,
  -0.000216425F, -0.000211583F, -0.000204435F, -0.000197286F, -0.000233007F,
  -0.000233007F, -0.000241765F, -0.000244336F, -0.000243816F, -0.000244694F,
  -0.00024057F, -0.000238157F, -0.000233705F, -0.000231224F, -0.00022504F,
  -0.000222692F, -0.000216405F, -0.000212145F, -0.000207788F, -0.00020129F,
  -0.000195966F, -0.000190642F, -0.00020873F, -0.00020873F, -0.000218889F,
  -0.000223898F, -0.000222161F, -0.000223109F, -0.00022294F, -0.000220286F,
  -0.000218363F, -0.000215224F, -0.000211476F, -0.000207491F, -0.000204744F,
  -0.000200826F, -0.000195702F, -0.00019088F, -0.00018617F, -0.000181459F,
  -0.000178889F, -0.000178889F, -0.000187333F, -0.000195185F, -0.000199744F,
  -0.000202941F, -0.000203016F, -0.000201733F, -0.000200345F, -0.000196667F,
  -0.000195946F, -0.000193577F, -0.000189852F, -0.000187551F, -0.000183711F,
  -0.000179357F, -0.000175003F, -0.000170649F, -0.000141954F, -0.000141954F,
  -0.000156437F, -0.000169285F, -0.000175995F, -0.000180223F, -0.000180651F,
  -0.000181862F, -0.000180163F, -0.00017992F, -0.000178487F, -0.000177054F,
  -0.000174725F, -0.000173598F, -0.000170147F, -0.000167282F, -0.000164416F,
  -0.00016155F, -0.000108923F, -0.000108923F, -0.00013202F, -0.000149663F,
  -0.000154895F, -0.000159447F, -0.000161785F, -0.000162566F, -0.000164699F,
  -0.000161111F, -0.000161439F, -0.000161826F, -0.000160909F, -0.000159318F,
  -0.000157871F, -0.000156425F, -0.000154978F, -0.000153532F, -8.15315E-5F,
  -8.15315E-5F, -0.000106577F, -0.000127277F, -0.000133853F, -0.000139984F,
  -0.000143779F, -0.000145459F, -0.000147297F, -0.000145141F, -0.00014552F,
  -0.000146155F, -0.000145976F, -0.000145459F, -0.000144941F, -0.000144424F,
  -0.000143907F, -0.00014339F, -4.729E-5F, -4.729E-5F, -8.28455E-5F,
  -0.000105194F, -0.00011848F, -0.000124558F, -0.000127158F, -0.00012974F,
  -0.00013245F, -0.00012896F, -0.000132487F, -0.000131757F, -0.000132331F,
  -0.000132147F, -0.000131963F, -0.00013178F, -0.000131596F, -0.000131413F,
  -1.41975E-5F, -1.41975E-5F, -5.51852E-5F, -8.95062E-5F, -0.000100427F,
  -0.000107298F, -0.00011261F, -0.000116519F, -0.000118327F, -0.000117452F,
  -0.000118969F, -0.000120009F, -0.000119877F, -0.000119744F, -0.000119612F,
  -0.000119479F, -0.000119347F, -0.000119214F, -3.03244E-5F, -3.03244E-5F,
  -4.90058E-5F, -6.76871E-5F, -8.63684E-5F, -9.46579E-5F, -9.93035E-5F,
  -0.000102735F, -0.000105454F, -0.000104319F, -0.000105451F, -0.000107773F,
  -0.000110095F, -0.000112417F, -0.000114739F, -0.000117061F, -0.000119383F,
  -0.000121705F, 4.95807E-5F, 4.95807E-5F, -1.1761E-5F, -5.44025E-5F,
  -7.22545E-5F, -8.13356E-5F, -8.68074E-5F, -9.06541E-5F, -9.31143E-5F,
  -9.25958E-5F, -9.20772E-5F, -9.15587E-5F, -9.10402E-5F, -9.05217E-5F,
  -9.00032E-5F, -8.94846E-5F, -8.89661E-5F, -8.84476E-5F } ;/* Referenced by: '<S9>/LdSubLqMot_L2' */

const volatile float32 CAL_TCF_LdSubLqIdCAx_af32[18] = { 0.0F, 30.0F, 50.0F,
  90.0F, 130.0F, 170.0F, 210.0F, 250.0F, 290.0F, 330.0F, 370.0F, 410.0F, 450.0F,
  490.0F, 530.0F, 570.0F, 610.0F, 650.0F } ;/* Referenced by:
                                             * '<S9>/LdSubLqGen_L2'
                                             * '<S9>/LdSubLqMot_L2'
                                             */

const volatile float32 CAL_TCF_LdSubLqIqCAy_af32[15] = { 0.0F, 30.0F, 50.0F,
  90.0F, 130.0F, 170.0F, 210.0F, 250.0F, 290.0F, 330.0F, 370.0F, 410.0F, 450.0F,
  490.0F, 530.0F } ;                   /* Referenced by:
                                        * '<S9>/LdSubLqGen_L2'
                                        * '<S9>/LdSubLqMot_L2'
                                        */

const volatile float32 CAL_TCF_LoSpdDirStop_f32 = -10.0F;
                           /* Referenced by: '<S14>/CAL_TOM_LoSpdDirStop_f32' */
const volatile float32 CAL_TCF_LoTrqDirStop_f32 = -3.0F;
                           /* Referenced by: '<S13>/CAL_TOM_LoTrqDirStop_f32' */
const volatile uint8 CAL_TCF_MotorPole_u8 = 4U;
                                   /* Referenced by: '<S7>/CAL_TOM_GLB_Pn_u8' */
const volatile float32 CAL_TCF_NPwrLosCAy_af32[16] = { 0.0F, 500.0F, 1500.0F,
  2500.0F, 3500.0F, 4500.0F, 5500.0F, 6500.0F, 7500.0F, 8500.0F, 9500.0F,
  10500.0F, 11500.0F, 12500.0F, 13500.0F, 14500.0F } ;/* Referenced by: '<S21>/IS_N_Ploss_T' */

const volatile float32 CAL_TCF_Psi_f32 = 0.0485F;
                                     /* Referenced by: '<S7>/CAL_TOM_Psi_f32' */
const volatile float32 CAL_TCF_PwrCompaElectCAz_af32[792] = { 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 0.8333F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  0.9524F, 0.8741F, 0.8889F, 0.9091F, 0.9091F, 0.9524F, 1.0F, 1.0F, 1.0F,
  0.9091F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  0.9091F, 0.8824F, 0.8621F, 0.8824F, 0.8955F, 0.9231F, 0.9524F, 0.9524F, 1.0F,
  0.8824F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  0.8889F, 0.8421F, 0.8386F, 0.8696F, 0.8696F, 0.9009F, 0.9195F, 0.9412F,
  0.9412F, 0.8889F, 1.0F, 0.9524F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 0.8771F, 0.8186F, 0.8299F, 0.8596F, 0.8611F, 0.8837F, 0.8996F, 0.9203F,
  0.9317F, 0.8942F, 0.957F, 0.9388F, 0.9762F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 0.8235F, 0.8046F, 0.8274F, 0.8537F, 0.8642F, 0.875F, 0.8974F, 0.9091F,
  0.915F, 0.8861F, 0.9333F, 0.915F, 0.9655F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 0.8247F, 0.8F, 0.8205F, 0.8511F, 0.8602F, 0.8791F, 0.8889F, 0.9091F,
  0.9302F, 0.8791F, 0.9091F, 0.9091F, 1.0F, 0.9877F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 0.813F, 0.7905F, 0.8264F, 0.8475F, 0.8547F, 0.8772F, 0.8811F,
  0.9009F, 0.9259F, 0.8696F, 0.9174F, 0.9524F, 0.9804F, 0.9901F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 0.8029F, 0.7407F, 0.8271F, 0.8397F, 0.8594F, 0.88F,
  0.8907F, 0.9091F, 0.9244F, 0.9016F, 0.9244F, 0.9649F, 0.9821F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8039F, 0.7962F, 0.8236F, 0.8476F, 0.8563F,
  0.8493F, 0.8918F, 0.9094F, 0.9225F, 0.9171F, 0.9154F, 0.9654F, 0.9881F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.7955F, 0.7932F, 0.826F, 0.8434F, 0.8589F,
  0.8805F, 0.8974F, 0.918F, 0.9333F, 0.9396F, 0.9211F, 0.9655F, 0.9859F, 0.9929F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8021F, 0.7958F, 0.8264F, 0.8523F,
  0.8596F, 0.8824F, 0.8929F, 0.9119F, 0.9202F, 0.9375F, 0.9494F, 0.974F, 0.9868F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8374F, 0.8019F, 0.8293F, 0.8586F,
  0.8673F, 0.8854F, 0.8947F, 0.9189F, 0.9189F, 0.9091F, 0.9497F, 0.977F, 0.9884F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8F, 0.8126F, 0.8257F, 0.8612F,
  0.8612F, 0.8889F, 0.9F, 0.9137F, 0.9326F, 0.9045F, 0.9677F, 0.973F, 0.9945F,
  1.0112F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8065F, 0.8147F, 0.8368F,
  0.8734F, 0.9607F, 0.9009F, 0.905F, 0.9132F, 0.8989F, 0.885F, 0.9901F, 0.9804F,
  1.0101F, 1.0309F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8077F, 0.8155F,
  0.8367F, 0.8642F, 0.875F, 0.8936F, 0.8974F, 0.917F, 0.9251F, 0.9013F, 0.9859F,
  0.9813F, 1.0096F, 1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8196F,
  0.8212F, 0.8344F, 0.8646F, 0.8705F, 0.9F, 0.901F, 0.8815F, 0.9399F, 0.8894F,
  0.9836F, 0.9889F, 1.0168F, 1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  0.8163F, 0.8219F, 0.8421F, 0.8618F, 0.8727F, 0.8824F, 0.9074F, 0.8791F,
  0.9562F, 0.9125F, 1.0F, 1.0F, 1.0268F, 1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 0.821F, 0.75757575F, 0.84175086F, 0.863557875F, 0.872600377F,
  0.89445436F, 0.9009009F, 0.883392215F, 0.963391125F, 0.92592591F, 1.0F, 1.0F,
  1.0268F, 1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8236F, 0.8128F,
  0.8426F, 0.8662F, 0.8679F, 0.8894F, 0.9006F, 0.8967F, 0.9637F, 0.943F, 1.0F,
  1.0F, 1.0268F, 1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8235F,
  0.79411763F, 0.848484874F, 0.853658557F, 0.880503118F, 0.883280754F,
  0.888888896F, 0.909090936F, 0.933333337F, 0.9333F, 1.0F, 1.0F, 1.0268F,
  1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 0.8169F, 0.804597676F,
  0.810055852F, 0.860534132F, 0.878787875F, 0.886850178F, 0.892307699F,
  0.920634925F, 0.966666639F, 1.0F, 1.0F, 1.0F, 1.0268F, 1.0194F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 0.8115F, 0.826666653F, 0.840108395F, 0.853994489F,
  0.878186941F, 0.88319087F, 0.895953774F, 0.923076928F, 0.966666639F, 1.0F,
  1.0F, 1.0F, 1.0268F, 1.0194F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                                /* Referenced by: '<S22>/PwrTrqSpdCompaElect' */

const volatile float32 CAL_TCF_PwrCompaIsCAy_af32[24] = { 0.0F, 30.0F, 60.0F,
  90.0F, 120.0F, 150.0F, 180.0F, 210.0F, 240.0F, 270.0F, 300.0F, 330.0F, 360.0F,
  390.0F, 420.0F, 450.0F, 480.0F, 510.0F, 540.0F, 570.0F, 600.0F, 630.0F, 660.0F,
  690.0F } ;                           /* Referenced by:
                                        * '<S22>/PwrTrqSpdCompaElect'
                                        * '<S22>/PwrTrqSpdCompaGen'
                                        */

const volatile float32 CAL_TCF_PwrCompaSpdCAx_af32[33] = { 0.0F, 500.0F, 1000.0F,
  1500.0F, 2000.0F, 2500.0F, 3000.0F, 3500.0F, 4000.0F, 4500.0F, 5000.0F,
  5500.0F, 6000.0F, 6500.0F, 7000.0F, 7500.0F, 8000.0F, 8500.0F, 9000.0F,
  9500.0F, 10000.0F, 10500.0F, 11000.0F, 11500.0F, 12000.0F, 12500.0F, 13000.0F,
  13500.0F, 14000.0F, 14500.0F, 15000.0F, 15500.0F, 16000.0F } ;/* Referenced by:
                                                                 * '<S22>/PwrTrqSpdCompaElect'
                                                                 * '<S22>/PwrTrqSpdCompaGen'
                                                                 */

const volatile float32 CAL_TCF_PwrInputCutOffFrq_f32 = 20.0F;
                      /* Referenced by: '<S20>/CAL_TCF_PwrInputCutOffFrq_f32' */
const volatile float32 CAL_TCF_PwrLossCAz_af32[560] = { 1.0F, 52.0F, 107.0F,
  164.0F, 226.0F, 292.0F, 364.0F, 443.0F, 530.0F, 625.0F, 730.0F, 844.0F, 968.0F,
  1104.0F, 1250.0F, 1408.0F, 1577.0F, 1758.0F, 1951.0F, 2156.0F, 2373.0F,
  2602.0F, 2841.0F, 3092.0F, 3354.0F, 3626.0F, 3907.0F, 4198.0F, 4497.0F,
  4804.0F, 5117.0F, 5437.0F, 5761.0F, 6089.0F, 6420.0F, 90.0F, 154.0F, 222.0F,
  293.0F, 370.0F, 453.0F, 542.0F, 639.0F, 744.0F, 859.0F, 983.0F, 1117.0F,
  1262.0F, 1418.0F, 1585.0F, 1763.0F, 1953.0F, 2155.0F, 2368.0F, 2593.0F,
  2829.0F, 3077.0F, 3335.0F, 3605.0F, 3884.0F, 4173.0F, 4471.0F, 4778.0F,
  5092.0F, 5413.0F, 5741.0F, 6073.0F, 6409.0F, 6749.0F, 7090.0F, 346.0F, 334.0F,
  348.0F, 387.0F, 449.0F, 532.0F, 633.0F, 752.0F, 885.0F, 1032.0F, 1192.0F,
  1363.0F, 1543.0F, 1732.0F, 1930.0F, 2134.0F, 2344.0F, 2561.0F, 2783.0F,
  3010.0F, 3242.0F, 3479.0F, 3721.0F, 3969.0F, 4222.0F, 4481.0F, 4746.0F,
  5019.0F, 5300.0F, 5590.0F, 5890.0F, 6202.0F, 6526.0F, 6864.0F, 7218.0F, 370.0F,
  408.0F, 464.0F, 537.0F, 624.0F, 726.0F, 841.0F, 968.0F, 1106.0F, 1255.0F,
  1413.0F, 1581.0F, 1758.0F, 1943.0F, 2137.0F, 2339.0F, 2549.0F, 2767.0F,
  2994.0F, 3229.0F, 3474.0F, 3727.0F, 3991.0F, 4266.0F, 4552.0F, 4850.0F,
  5161.0F, 5487.0F, 5828.0F, 6186.0F, 6562.0F, 6957.0F, 7374.0F, 7813.0F,
  8276.0F, 416.0F, 503.0F, 594.0F, 690.0F, 792.0F, 902.0F, 1019.0F, 1145.0F,
  1280.0F, 1426.0F, 1581.0F, 1748.0F, 1925.0F, 2114.0F, 2314.0F, 2526.0F,
  2749.0F, 2983.0F, 3229.0F, 3485.0F, 3752.0F, 4028.0F, 4314.0F, 4608.0F,
  4911.0F, 5220.0F, 5536.0F, 5856.0F, 6181.0F, 6508.0F, 6837.0F, 7166.0F,
  7494.0F, 7819.0F, 8140.0F, 512.0F, 616.0F, 718.0F, 820.0F, 925.0F, 1033.0F,
  1148.0F, 1270.0F, 1402.0F, 1543.0F, 1696.0F, 1862.0F, 2040.0F, 2233.0F,
  2439.0F, 2659.0F, 2894.0F, 3142.0F, 3405.0F, 3680.0F, 3969.0F, 4269.0F,
  4579.0F, 4900.0F, 5228.0F, 5563.0F, 5903.0F, 6246.0F, 6589.0F, 6932.0F,
  7270.0F, 7602.0F, 7925.0F, 8235.0F, 8530.0F, 691.0F, 756.0F, 835.0F, 926.0F,
  1031.0F, 1147.0F, 1275.0F, 1415.0F, 1565.0F, 1727.0F, 1900.0F, 2083.0F,
  2277.0F, 2482.0F, 2697.0F, 2922.0F, 3159.0F, 3406.0F, 3664.0F, 3933.0F,
  4213.0F, 4506.0F, 4810.0F, 5127.0F, 5457.0F, 5800.0F, 6157.0F, 6529.0F,
  6916.0F, 7318.0F, 7737.0F, 8172.0F, 8626.0F, 9099.0F, 9591.0F, 797.0F, 888.0F,
  982.0F, 1080.0F, 1185.0F, 1296.0F, 1415.0F, 1544.0F, 1683.0F, 1834.0F, 1996.0F,
  2172.0F, 2361.0F, 2564.0F, 2782.0F, 3014.0F, 3263.0F, 3526.0F, 3806.0F,
  4102.0F, 4413.0F, 4741.0F, 5084.0F, 5442.0F, 5816.0F, 6204.0F, 6607.0F,
  7023.0F, 7452.0F, 7893.0F, 8345.0F, 8808.0F, 9280.0F, 9760.0F, 10248.0F,
  1046.0F, 1064.0F, 1111.0F, 1182.0F, 1276.0F, 1390.0F, 1522.0F, 1671.0F,
  1834.0F, 2010.0F, 2198.0F, 2397.0F, 2607.0F, 2827.0F, 3057.0F, 3297.0F,
  3549.0F, 3811.0F, 4086.0F, 4375.0F, 4679.0F, 4999.0F, 5339.0F, 5699.0F,
  6083.0F, 6493.0F, 6933.0F, 7405.0F, 7913.0F, 8461.0F, 9053.0F, 9693.0F,
  10386.0F, 11136.0F, 11950.0F, 1175.0F, 1228.0F, 1293.0F, 1372.0F, 1465.0F,
  1572.0F, 1694.0F, 1831.0F, 1983.0F, 2150.0F, 2333.0F, 2533.0F, 2748.0F,
  2981.0F, 3230.0F, 3497.0F, 3780.0F, 4082.0F, 4401.0F, 4739.0F, 5095.0F,
  5469.0F, 5861.0F, 6273.0F, 6703.0F, 7153.0F, 7622.0F, 8110.0F, 8617.0F,
  9145.0F, 9691.0F, 10258.0F, 10844.0F, 11450.0F, 12076.0F, 1313.0F, 1361.0F,
  1425.0F, 1504.0F, 1600.0F, 1712.0F, 1842.0F, 1990.0F, 2156.0F, 2340.0F,
  2544.0F, 2766.0F, 3007.0F, 3268.0F, 3548.0F, 3847.0F, 4165.0F, 4502.0F,
  4858.0F, 5232.0F, 5625.0F, 6035.0F, 6463.0F, 6907.0F, 7368.0F, 7844.0F,
  8335.0F, 8840.0F, 9358.0F, 9889.0F, 10431.0F, 10984.0F, 11547.0F, 12117.0F,
  12695.0F, 1451.0F, 1495.0F, 1554.0F, 1631.0F, 1726.0F, 1839.0F, 1973.0F,
  2126.0F, 2301.0F, 2496.0F, 2714.0F, 2953.0F, 3214.0F, 3498.0F, 3803.0F,
  4130.0F, 4479.0F, 4848.0F, 5238.0F, 5648.0F, 6076.0F, 6523.0F, 6988.0F,
  7468.0F, 7964.0F, 8473.0F, 8994.0F, 9527.0F, 10068.0F, 10617.0F, 11172.0F,
  11730.0F, 12291.0F, 12850.0F, 13407.0F, 2687.0F, 2252.0F, 1976.0F, 1835.0F,
  1807.0F, 1872.0F, 2011.0F, 2209.0F, 2451.0F, 2723.0F, 3016.0F, 3320.0F,
  3628.0F, 3935.0F, 4239.0F, 4537.0F, 4830.0F, 5120.0F, 5412.0F, 5711.0F,
  6026.0F, 6367.0F, 6745.0F, 7174.0F, 7669.0F, 8248.0F, 8930.0F, 9736.0F,
  10689.0F, 11814.0F, 13138.0F, 14689.0F, 16498.0F, 18596.0F, 21019.0F, 1826.0F,
  1805.0F, 1826.0F, 1884.0F, 1977.0F, 2104.0F, 2262.0F, 2449.0F, 2664.0F,
  2905.0F, 3170.0F, 3460.0F, 3772.0F, 4107.0F, 4463.0F, 4842.0F, 5242.0F,
  5664.0F, 6109.0F, 6577.0F, 7069.0F, 7586.0F, 8130.0F, 8702.0F, 9304.0F,
  9937.0F, 10605.0F, 11309.0F, 12051.0F, 12836.0F, 13665.0F, 14543.0F, 15472.0F,
  16456.0F, 17500.0F, 1788.0F, 1855.0F, 1941.0F, 2047.0F, 2175.0F, 2326.0F,
  2500.0F, 2700.0F, 2925.0F, 3176.0F, 3453.0F, 3757.0F, 4089.0F, 4447.0F,
  4832.0F, 5245.0F, 5683.0F, 6148.0F, 6637.0F, 7152.0F, 7690.0F, 8250.0F,
  8832.0F, 9434.0F, 10054.0F, 10692.0F, 11345.0F, 12011.0F, 12688.0F, 13375.0F,
  14069.0F, 14768.0F, 15468.0F, 16168.0F, 16865.0F, 1513.0F, 1692.0F, 1878.0F,
  2074.0F, 2281.0F, 2503.0F, 2740.0F, 2995.0F, 3269.0F, 3564.0F, 3880.0F,
  4219.0F, 4583.0F, 4970.0F, 5383.0F, 5822.0F, 6286.0F, 6776.0F, 7292.0F,
  7833.0F, 8399.0F, 8989.0F, 9603.0F, 10240.0F, 10898.0F, 11576.0F, 12273.0F,
  12987.0F, 13717.0F, 14459.0F, 15213.0F, 15975.0F, 16744.0F, 17516.0F, 18289.0F
} ;                                    /* Referenced by: '<S21>/IS_N_Ploss_T' */

const volatile float32 CAL_TCF_PwrTrqCalcSpdThrH_f32 = 1100.0F;/* Referenced by: '<S6>/Relay' */
const volatile float32 CAL_TCF_PwrTrqCalcSpdThrL_f32 = 1000.0F;/* Referenced by: '<S6>/Relay' */
const volatile float32 CAL_TCF_PwrTrqTubeCAy_af32[18] = { 200.0F, 100.0F, 50.0F,
  30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 40.0F, 40.0F, 40.0F, 40.0F,
  50.0F, 50.0F, 50.0F, 50.0F } ; /* Referenced by: '<S31>/Cal_PowerTrqTube_T' */

const volatile uint8 CAL_TCF_SpeedCtlMode_u8 = 7U;
                             /* Referenced by: '<S6>/CAL_TOM_SpeedCtlMode_u8' */
const volatile float32 CAL_TCF_TempStrMax_f32 = 180.0F;
                             /* Referenced by: '<S21>/CAL_TOM_TempStrMax_f32' */
const volatile float32 CAL_TCF_TempStrMin_f32 = -30.0F;
                             /* Referenced by: '<S21>/CAL_TOM_TempStrMin_f32' */
const volatile float32 CAL_TCF_TempStrPlossFact_f32 = 0.00312F;
                       /* Referenced by: '<S21>/CAL_TOM_TempStrPlossFact_f32' */
const volatile sint16 CAL_TCF_TrqCalcMonCountTrh_s16 = 100;
                           /* Referenced by: '<S5>/CAL_TOM_HiTrqMonDebTrh_s5' */
const volatile sint16 CAL_TCF_TrqCalcMonDebTrh_s16 = 50;
                           /* Referenced by: '<S5>/CAL_TOM_HiTrqMonDebTrh_s4' */
const volatile boolean CAL_TCF_TrqCalcMonErrRst_b = 0;
                             /* Referenced by: '<S5>/CAL_TOM_TrqMonErrRst_b2' */
const volatile sint16 CAL_TCF_TrqInvalid_s16 = 32767;
                                      /* Referenced by: '<S30>/TubeSelector2' */
const volatile float32 CAL_TCF_TrqMechCutOffFrq_f32 = 20.0F;/* Referenced by:
                                                             * '<S7>/CAL_TCF_TrqMechCutOffFrq_f32'
                                                             * '<S22>/CAL_TCF_TrqMechCutOffFrq_f32'
                                                             */
const volatile float32 CAL_TCF_TrqTubeNCAx_af32[18] = { 0.0F, 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F, 16001.0F } ;/* Referenced by:
                                                                      * '<S31>/1-D Lookup Table'
                                                                      * '<S31>/Cal_PowerTrqTube_T'
                                                                      */

const volatile boolean CAL_TCF_flgUsePlossCompa_b = 1;
                         /* Referenced by: '<S21>/CAL_TOM_flgUsePlossCompa_b' */
const volatile uint16 PRV_CalFltFrq_1ms = 1000U;/* Referenced by:
                                                 * '<S7>/PRV_CalFltFrq_1ms'
                                                 * '<S20>/PRV_CalFltFrq_1ms'
                                                 * '<S22>/PRV_CalFltFrq_1ms'
                                                 */
const volatile uint16 PRV_IsCalFltFrq_1ms = 1000U;
                                /* Referenced by: '<S19>/PRV_IsCalFltFrq_1ms' */

#pragma section

/* Block signals (default storage) */
B_SWC_TCF_T SWC_TCF_B;

/* Block states (default storage) */
DW_SWC_TCF_T SWC_TCF_DW;

/* Real-time model */
RT_MODEL_SWC_TCF_T SWC_TCF_M_;
RT_MODEL_SWC_TCF_T *const SWC_TCF_M = &SWC_TCF_M_;

/* Output and update for atomic system: '<S3>/CurrAgTrqCalc' */
void SWC_TCF_CurrAgTrqCalc(void)
{
  float32 rtb_Divide;

  /* Product: '<S7>/Product2' incorporates:
   *  Constant: '<S7>/CAL_TOM_GLB_Pn_u8'
   *  Constant: '<S7>/CAL_TOM_Psi_f32'
   *  Constant: '<S7>/TorqueCalculationFactor'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Sum: '<S7>/Add'
   */
  VAR_TCF_CurrAgTrqNoComp_f32 = (VAR_TCF_LdsubLq_f32 * VAR_TCF_idAct_f32 *
    VAR_TCF_iqAct_f32 + VAR_TCF_iqAct_f32 * CAL_TCF_Psi_f32) * (float32)
    CAL_TCF_MotorPole_u8 * 1.5F;

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/CAL_TCF_TrqMechCutOffFrq_f32'
   *  Constant: '<S7>/PRV_CalFltFrq_1ms'
   */
  rtb_Divide = (float32)PRV_CalFltFrq_1ms / CAL_TCF_TrqMechCutOffFrq_f32;

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S11>/UpperRelop'
   *  Switch: '<S11>/Switch2'
   */
  if (rtb_Divide < 0.0F) {
    rtb_Divide = 0.0F;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Product: '<S7>/Divide1' incorporates:
   *  Sum: '<S7>/Add1'
   */
  rtb_Divide /= rtb_Divide + SWC_TCF_ConstB.Product5_k;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Constant: '<S7>/One'
   *  Product: '<S7>/Product3'
   *  Product: '<S7>/Product4'
   *  Sum: '<S7>/Subtract1'
   *  UnitDelay: '<S7>/Unit Delay'
   */
  SWC_TCF_DW.UnitDelay_DSTATE_ct = (1.0F - rtb_Divide) *
    VAR_TCF_CurrAgTrqNoComp_f32 + rtb_Divide * SWC_TCF_DW.UnitDelay_DSTATE_ct;

  /* Saturate: '<S7>/Saturation1' incorporates:
   *  UnitDelay: '<S7>/Unit Delay'
   */
  if (SWC_TCF_DW.UnitDelay_DSTATE_ct > 500.0F) {
    VAR_TCF_CurrAgTrqflt_f32 = 500.0F;
  } else if (SWC_TCF_DW.UnitDelay_DSTATE_ct < -500.0F) {
    VAR_TCF_CurrAgTrqflt_f32 = -500.0F;
  } else {
    VAR_TCF_CurrAgTrqflt_f32 = SWC_TCF_DW.UnitDelay_DSTATE_ct;
  }

  /* End of Saturate: '<S7>/Saturation1' */
}

/* Output and update for atomic system: '<S3>/IdIqCalc' */
void SWC_TCF_IdIqCalc(void)
{
  float32 rtb_Product1_pi;
  float32 rtb_LookupSinTable;
  float32 rtb_LookupCosTable;
  float32 rtb_Divide;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/ClarkTransformCoefficient'
   *  Constant: '<S8>/ClarkTransformCoefficient1'
   *  Inport: '<Root>/TRSP_iU'
   *  Inport: '<Root>/TRSP_iV'
   *  Inport: '<Root>/TRSP_iW'
   *  Product: '<S8>/Product'
   *  Sum: '<S8>/Add'
   */
  rtb_Product1_pi = ((2.0F * get_TRSP_iU() - get_TRSP_iV()) - get_TRSP_iW()) *
    0.33333F;

  /* Product: '<S8>/Divide1' incorporates:
   *  Constant: '<S8>/CAL_TOM_GLB_CircAge_f32'
   *  Constant: '<S8>/CAL_TOM_GLB_DigtValue_u16'
   *  Inport: '<Root>/TRSP_AgRtr'
   */
  rtb_LookupSinTable = get_TRSP_AgRtr() * (float32)((uint16)
    GLB_TCF_DigtValue_u16) / GLB_TCF_CircAge_f32;

  /* LookupNDDirect: '<S8>/LookupCosTable' incorporates:
   *  LookupNDDirect: '<S8>/LookupSinTable'
   *
   * About '<S8>/LookupCosTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   *
   * About '<S8>/LookupSinTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (rtb_LookupSinTable > 4095.0F) {
    rtb_LookupCosTable = 4095.0F;
    rtb_LookupSinTable = 4095.0F;
  } else {
    if (rtb_LookupSinTable < 0.0F) {
      rtb_LookupCosTable = 0.0F;
    } else {
      rtb_LookupCosTable = rtb_LookupSinTable;
    }

    if (rtb_LookupSinTable < 0.0F) {
      rtb_LookupSinTable = 0.0F;
    }
  }

  rtb_LookupCosTable = rtCP_LookupCosTable_table[(sint32)rtb_LookupCosTable];

  /* End of LookupNDDirect: '<S8>/LookupCosTable' */

  /* LookupNDDirect: '<S8>/LookupSinTable'
   *
   * About '<S8>/LookupSinTable':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  rtb_LookupSinTable = rtCP_LookupSinTable_table[(sint32)rtb_LookupSinTable];

  /* Product: '<S8>/Divide' incorporates:
   *  Constant: '<S8>/ClarkTransformCoefficient1'
   *  Constant: '<S8>/SqrtThree_f32'
   *  Inport: '<Root>/TRSP_iV'
   *  Inport: '<Root>/TRSP_iW'
   *  Sum: '<S8>/Add1'
   */
  rtb_Divide = (get_TRSP_iV() - get_TRSP_iW()) * 0.33333F * 1.73205101F;

  /* Sum: '<S8>/Add2' incorporates:
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   */
  VAR_TCF_idAct_f32 = rtb_LookupCosTable * rtb_Product1_pi + rtb_LookupSinTable *
    rtb_Divide;

  /* Sum: '<S8>/Add3' incorporates:
   *  Product: '<S8>/Product4'
   *  Product: '<S8>/Product5'
   */
  VAR_TCF_iqAct_f32 = rtb_LookupCosTable * rtb_Divide - rtb_LookupSinTable *
    rtb_Product1_pi;
}

/* Output and update for atomic system: '<S3>/LdsubLqCalc' */
void SWC_TCF_LdsubLqCalc(void)
{
  /* Switch: '<S9>/Switch' incorporates:
   *  Abs: '<S9>/Abs'
   *  Abs: '<S9>/Abs1'
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/Constant1'
   *  Logic: '<S9>/Logical Operator'
   *  Lookup_n-D: '<S9>/LdSubLqGen_L2'
   *  Lookup_n-D: '<S9>/LdSubLqMot_L2'
   *  RelationalOperator: '<S9>/Relational Operator'
   *  RelationalOperator: '<S9>/Relational Operator1'
   */
  if ((VAR_TCF_MotorMode_u8 == ((uint8)GLB_TCF_FwELect_u8)) ||
      (VAR_TCF_MotorMode_u8 == ((uint8)GLB_TCF_BwELect_u8))) {
    VAR_TCF_LdsubLq_f32 = look2_iflf_binlcpw(fabsf(VAR_TCF_idAct_f32), fabsf
      (VAR_TCF_iqAct_f32), ((const float32 *)&(CAL_TCF_LdSubLqIdCAx_af32[0])),
      ((const float32 *)&(CAL_TCF_LdSubLqIqCAy_af32[0])), ((const float32 *)
      &(CAL_TCF_LdSubLqCAzMot_af32[0])), rtCP_LdSubLqMot_L2_maxIndex, 18U);
  } else {
    VAR_TCF_LdsubLq_f32 = look2_iflf_binlcpw(fabsf(VAR_TCF_idAct_f32), fabsf
      (VAR_TCF_iqAct_f32), ((const float32 *)&(CAL_TCF_LdSubLqIdCAx_af32[0])),
      ((const float32 *)&(CAL_TCF_LdSubLqIqCAy_af32[0])), ((const float32 *)
      &(CAL_TCF_LdSubLqCAzGen_af32[0])), rtCP_LdSubLqGen_L2_maxIndex, 18U);
  }

  /* End of Switch: '<S9>/Switch' */
}

/* Outputs for atomic system: '<S3>/MotorModeJdg' */
void SWC_TCF_MotorModeJdg(void)
{
  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/CAL_TOM_HiSpdDirStop_f32'
   *  Constant: '<S14>/CAL_TOM_LoSpdDirStop_f32'
   *  Constant: '<S14>/GLB_TOM_MotorBw_u8'
   *  Constant: '<S14>/GLB_TOM_MotorStop_u8'
   *  Inport: '<Root>/SWD_Spd'
   *  Logic: '<S14>/Logical Operator'
   *  RelationalOperator: '<S14>/Relational Operator'
   *  RelationalOperator: '<S14>/Relational Operator1'
   *  RelationalOperator: '<S14>/Relational Operator2'
   *  Switch: '<S14>/Switch1'
   */
  if ((get_SWD_Spd() >= CAL_TCF_LoSpdDirStop_f32) && (get_SWD_Spd() <=
       CAL_TCF_HiSpdDirStop_f32)) {
    VAR_TCF_nDir_u8 = ((uint8)GLB_TCF_MotorStop_u8);
  } else if (get_SWD_Spd() > CAL_TCF_HiSpdDirStop_f32) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/GLB_TOM_MotorFw_u8'
     */
    VAR_TCF_nDir_u8 = ((uint8)GLB_TCF_MotorFw_u8);
  } else {
    VAR_TCF_nDir_u8 = ((uint8)GLB_TCF_MotorBw_u8);
  }

  /* End of Switch: '<S14>/Switch' */

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/CAL_TOM_HiTrqDirStop_f32'
   *  Constant: '<S13>/CAL_TOM_LoTrqDirStop_f32'
   *  Constant: '<S13>/GLB_TOM_NegvTrq_u8'
   *  Constant: '<S13>/GLB_TpcCod_ZeroTrq_u8'
   *  Logic: '<S13>/Logical Operator'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator2'
   *  Switch: '<S13>/Switch1'
   *  UnitDelay: '<S13>/UnitDelay'
   */
  if ((VAR_TCF_CurrAgTrqflt_f32 >= CAL_TCF_LoTrqDirStop_f32) &&
      (VAR_TCF_CurrAgTrqflt_f32 <= CAL_TCF_HiTrqDirStop_f32)) {
    VAR_TCF_TrqDir_u8 = ((uint8)GLB_TCF_ZeroTrq_u8);
  } else if (VAR_TCF_CurrAgTrqflt_f32 > CAL_TCF_HiTrqDirStop_f32) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/GLB_TOM_PosvTrq_u8'
     */
    VAR_TCF_TrqDir_u8 = ((uint8)GLB_TCF_PosvTrq_u8);
  } else {
    VAR_TCF_TrqDir_u8 = ((uint8)GLB_TCF_NegvTrq_u8);
  }

  /* End of Switch: '<S13>/Switch' */

  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/GLB_TOM_MotorBw_u8'
   *  Constant: '<S12>/GLB_TOM_MotorFw_u8'
   *  Constant: '<S12>/GLB_TOM_NegvTrq_u8'
   *  Constant: '<S12>/GLB_TOM_PosvTrq_u8'
   */
  if ((VAR_TCF_nDir_u8 == ((uint8)GLB_TCF_MotorBw_u8)) && (VAR_TCF_TrqDir_u8 ==
       ((uint8)GLB_TCF_PosvTrq_u8))) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Merge' incorporates:
     *  Constant: '<S16>/GLB_TOM_BwELect_u8'
     *  SignalConversion generated from: '<S16>/Out1'
     */
    VAR_TCF_MotorMode_u8 = ((uint8)GLB_TCF_BwELect_u8);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem1' */
  } else if ((VAR_TCF_nDir_u8 == ((uint8)GLB_TCF_MotorFw_u8)) &&
             (VAR_TCF_TrqDir_u8 == ((uint8)GLB_TCF_NegvTrq_u8))) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Merge' incorporates:
     *  Constant: '<S17>/GLB_TOM_FwGene_u8'
     *  SignalConversion generated from: '<S17>/Out1'
     */
    VAR_TCF_MotorMode_u8 = ((uint8)GLB_TCF_FwGene_u8);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem2' */
  } else if ((VAR_TCF_nDir_u8 != ((uint8)GLB_TCF_MotorBw_u8)) &&
             (VAR_TCF_TrqDir_u8 != ((uint8)GLB_TCF_NegvTrq_u8))) {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Merge' incorporates:
     *  Constant: '<S15>/GLB_TOM_FwELect_u8'
     *  SignalConversion generated from: '<S15>/Out1'
     */
    VAR_TCF_MotorMode_u8 = ((uint8)GLB_TCF_FwELect_u8);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Merge' incorporates:
     *  Constant: '<S18>/GLB_TOM_BwGene_u8'
     *  SignalConversion generated from: '<S18>/Out1'
     */
    VAR_TCF_MotorMode_u8 = ((uint8)GLB_TCF_BwGene_u8);

    /* End of Outputs for SubSystem: '<S12>/If Action Subsystem3' */
  }

  /* End of If: '<S12>/If' */
}

/* Output and update for atomic system: '<S4>/IsCalc' */
void SWC_TCF_IsCalc(void)
{
  float32 rtb_Divide1_d;
  float32 rtb_UnitDelay_m;
  float32 rtb_Product2_f;

  /* Product: '<S19>/Divide1' incorporates:
   *  Constant: '<S19>/CAL_TCF_IsCutOffFrq_f32'
   *  Constant: '<S19>/PRV_IsCalFltFrq_1ms'
   */
  rtb_Divide1_d = (float32)PRV_IsCalFltFrq_1ms / CAL_TCF_IsCutOffFrq_f32;

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S19>/Constant'
   *  RelationalOperator: '<S23>/UpperRelop'
   *  Switch: '<S23>/Switch2'
   */
  if (rtb_Divide1_d < 0.0F) {
    rtb_Divide1_d = 0.0F;
  }

  /* End of Switch: '<S23>/Switch' */

  /* Product: '<S19>/Divide2' incorporates:
   *  Sum: '<S19>/Add3'
   */
  rtb_Divide1_d /= rtb_Divide1_d + SWC_TCF_ConstB.Product6;

  /* Product: '<S19>/Product1' incorporates:
   *  Constant: '<S19>/ClarkTransformCoefficient'
   *  Constant: '<S19>/ClarkTransformCoefficient1'
   *  Inport: '<Root>/TRSP_iU'
   *  Inport: '<Root>/TRSP_iV'
   *  Inport: '<Root>/TRSP_iW'
   *  Product: '<S19>/Product'
   *  Sum: '<S19>/Add'
   */
  rtb_UnitDelay_m = ((2.0F * get_TRSP_iU() - get_TRSP_iV()) - get_TRSP_iW()) *
    0.33333F;

  /* Product: '<S19>/Product2' */
  rtb_Product2_f = rtb_UnitDelay_m * rtb_UnitDelay_m;

  /* Product: '<S19>/Divide' incorporates:
   *  Constant: '<S19>/ClarkTransformCoefficient1'
   *  Constant: '<S19>/SqrtThree_f32'
   *  Inport: '<Root>/TRSP_iV'
   *  Inport: '<Root>/TRSP_iW'
   *  Sum: '<S19>/Add1'
   */
  rtb_UnitDelay_m = (get_TRSP_iV() - get_TRSP_iW()) * 1.73205101F * 0.33333F;

  /* Sqrt: '<S19>/Sqrt' incorporates:
   *  Product: '<S19>/Product3'
   *  Sum: '<S19>/Add2'
   */
  VAR_TCF_IsNoflt_f32 = sqrtf(rtb_UnitDelay_m * rtb_UnitDelay_m + rtb_Product2_f);

  /* Sum: '<S19>/Sum1' incorporates:
   *  Constant: '<S19>/One'
   *  Product: '<S19>/Product4'
   *  Product: '<S19>/Product5'
   *  Sum: '<S19>/Subtract1'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  SWC_TCF_DW.UnitDelay_DSTATE_c = (1.0F - rtb_Divide1_d) * VAR_TCF_IsNoflt_f32 +
    rtb_Divide1_d * SWC_TCF_DW.UnitDelay_DSTATE_c;

  /* Saturate: '<S19>/Saturation1' incorporates:
   *  UnitDelay: '<S19>/Unit Delay'
   */
  if (SWC_TCF_DW.UnitDelay_DSTATE_c > 1000.0F) {
    VAR_TCF_Isflt_f32 = 1000.0F;
  } else if (SWC_TCF_DW.UnitDelay_DSTATE_c < 0.0F) {
    VAR_TCF_Isflt_f32 = 0.0F;
  } else {
    VAR_TCF_Isflt_f32 = SWC_TCF_DW.UnitDelay_DSTATE_c;
  }

  /* End of Saturate: '<S19>/Saturation1' */
}

/* Output and update for atomic system: '<S4>/PinputCalc' */
void SWC_TCF_PinputCalc(void)
{
  float32 rtb_Divide1_m;

  /* Product: '<S20>/Divide1' incorporates:
   *  Constant: '<S20>/CAL_TCF_PwrInputCutOffFrq_f32'
   *  Constant: '<S20>/PRV_CalFltFrq_1ms'
   */
  rtb_Divide1_m = (float32)PRV_CalFltFrq_1ms / CAL_TCF_PwrInputCutOffFrq_f32;

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S24>/UpperRelop'
   *  Switch: '<S24>/Switch2'
   */
  if (rtb_Divide1_m < 0.0F) {
    rtb_Divide1_m = 0.0F;
  }

  /* End of Switch: '<S24>/Switch' */

  /* Product: '<S20>/Divide2' incorporates:
   *  Sum: '<S20>/Add5'
   */
  rtb_Divide1_m /= rtb_Divide1_m + SWC_TCF_ConstB.Product8;

  /* Sum: '<S20>/Add4' incorporates:
   *  Constant: '<S20>/Constant2'
   *  Inport: '<Root>/L2Com_HiPrecVolt'
   *  Inport: '<Root>/TRSP_iU'
   *  Inport: '<Root>/TRSP_iV'
   *  Inport: '<Root>/TRSP_iW'
   *  Product: '<S20>/Product'
   *  Product: '<S20>/Product1'
   *  Product: '<S20>/Product2'
   *  Product: '<S20>/Product3'
   *  Product: '<S20>/Product4'
   *  Product: '<S20>/Product5'
   *  Sum: '<S20>/Add1'
   *  Sum: '<S20>/Add2'
   *  Sum: '<S20>/Add3'
   */
  VAR_TCF_PwrInputNoflt_f32 = ((VAR_L2Sampling_DycUMon_f32 - 0.5F) *
    get_L2Com_HiPrecVolt() * get_TRSP_iU() + (VAR_L2Sampling_DycVMon_f32 - 0.5F)
    * get_L2Com_HiPrecVolt() * get_TRSP_iV()) + (VAR_L2Sampling_DycWMon_f32 -
    0.5F) * get_L2Com_HiPrecVolt() * get_TRSP_iW();

  /* Sum: '<S20>/Sum1' incorporates:
   *  Constant: '<S20>/One'
   *  Product: '<S20>/Product6'
   *  Product: '<S20>/Product7'
   *  Sum: '<S20>/Subtract1'
   *  UnitDelay: '<S20>/Unit Delay'
   */
  SWC_TCF_DW.UnitDelay_DSTATE_p = (1.0F - rtb_Divide1_m) *
    VAR_TCF_PwrInputNoflt_f32 + rtb_Divide1_m * SWC_TCF_DW.UnitDelay_DSTATE_p;

  /* Saturate: '<S20>/Saturation1' incorporates:
   *  UnitDelay: '<S20>/Unit Delay'
   */
  if (SWC_TCF_DW.UnitDelay_DSTATE_p > 200000.0F) {
    VAR_TCF_PwrInputflt_f32 = 200000.0F;
  } else if (SWC_TCF_DW.UnitDelay_DSTATE_p < -200000.0F) {
    VAR_TCF_PwrInputflt_f32 = -200000.0F;
  } else {
    VAR_TCF_PwrInputflt_f32 = SWC_TCF_DW.UnitDelay_DSTATE_p;
  }

  /* End of Saturate: '<S20>/Saturation1' */
}

/* Output and update for atomic system: '<S4>/PlossCalc' */
void SWC_TCF_PlossCalc(void)
{
  float32 rtb_Switch1_h;
  float32 tmp;

  /* Abs: '<S21>/Abs' incorporates:
   *  Inport: '<Root>/SWD_Spd'
   */
  rtb_Switch1_h = fabsf(get_SWD_Spd());

  /* Switch: '<S21>/Switch1' incorporates:
   *  Constant: '<S21>/Constant2'
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S25>/Compare'
   */
  if (rtb_Switch1_h <= 0.01F) {
    rtb_Switch1_h = 0.01F;
  }

  /* End of Switch: '<S21>/Switch1' */

  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/CAL_TOM_TempStrPlossFact_f32'
   *  Constant: '<S21>/CAL_TOM_flgUsePlossCompa_b'
   *  Constant: '<S21>/Constant1'
   *  Lookup_n-D: '<S21>/IS_N_Ploss_T'
   *  Product: '<S21>/Product'
   *  Product: '<S21>/Product2'
   *  Sum: '<S21>/Add'
   */
  if (CAL_TCF_flgUsePlossCompa_b) {
    /* Switch: '<S26>/Switch2' incorporates:
     *  Constant: '<S21>/CAL_TOM_TempStrMax_f32'
     *  Constant: '<S21>/CAL_TOM_TempStrMin_f32'
     *  RelationalOperator: '<S26>/LowerRelop1'
     *  RelationalOperator: '<S26>/UpperRelop'
     *  Switch: '<S26>/Switch'
     */
    if (VAR_HSPF_StrrTempFlt_f32 > CAL_TCF_TempStrMax_f32) {
      tmp = CAL_TCF_TempStrMax_f32;
    } else if (VAR_HSPF_StrrTempFlt_f32 < CAL_TCF_TempStrMin_f32) {
      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S21>/CAL_TOM_TempStrMin_f32'
       */
      tmp = CAL_TCF_TempStrMin_f32;
    } else {
      tmp = VAR_HSPF_StrrTempFlt_f32;
    }

    /* End of Switch: '<S26>/Switch2' */
    VAR_TCF_Ploss_f32 = (1.0F - CAL_TCF_TempStrPlossFact_f32 * tmp) *
      look2_iflf_binlxpw(VAR_TCF_Isflt_f32, rtb_Switch1_h, ((const float32 *)
      &(CAL_TCF_IsPwrLosCAx_af32[0])), ((const float32 *)
      &(CAL_TCF_NPwrLosCAy_af32[0])), ((const float32 *)
      &(CAL_TCF_PwrLossCAz_af32[0])), rtCP_IS_N_Ploss_T_maxIndex, 35U);
  } else {
    VAR_TCF_Ploss_f32 = look2_iflf_binlxpw(VAR_TCF_Isflt_f32, rtb_Switch1_h, ((
      const float32 *)&(CAL_TCF_IsPwrLosCAx_af32[0])), ((const float32 *)
      &(CAL_TCF_NPwrLosCAy_af32[0])), ((const float32 *)
      &(CAL_TCF_PwrLossCAz_af32[0])), rtCP_IS_N_Ploss_T_maxIndex, 35U);
  }

  /* End of Switch: '<S21>/Switch' */
}

/* Output and update for atomic system: '<S4>/PwrTrqCalc' */
void SWC_TCF_PwrTrqCalc(void)
{
  float32 rtb_Divide1_c;

  /* Abs: '<S22>/Abs' incorporates:
   *  Inport: '<Root>/SWD_Spd'
   */
  rtb_Divide1_c = fabsf(get_SWD_Spd());

  /* Switch: '<S22>/Switch' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Constant: '<S22>/Constant3'
   *  Constant: '<S27>/Constant'
   *  Delay: '<S22>/Delay'
   *  Logic: '<S22>/Logical Operator'
   *  Lookup_n-D: '<S22>/PwrTrqSpdCompaElect'
   *  Lookup_n-D: '<S22>/PwrTrqSpdCompaGen'
   *  RelationalOperator: '<S22>/Relational Operator'
   *  RelationalOperator: '<S22>/Relational Operator1'
   *  RelationalOperator: '<S27>/Compare'
   *  Switch: '<S22>/Switch2'
   */
  if ((SWC_TCF_DW.Delay_DSTATE == ((uint8)GLB_TCF_FwELect_u8)) ||
      (SWC_TCF_DW.Delay_DSTATE == ((uint8)GLB_TCF_BwELect_u8))) {
    /* Switch: '<S22>/Switch2' incorporates:
     *  Constant: '<S22>/Constant4'
     *  Constant: '<S27>/Constant'
     *  RelationalOperator: '<S27>/Compare'
     */
    if (rtb_Divide1_c <= 0.01F) {
      rtb_Divide1_c = 0.01F;
    }

    VAR_TCF_PwrTrqCompCof_f32 = look2_iflf_binlxpw(rtb_Divide1_c,
      VAR_TCF_Isflt_f32, ((const float32 *)&(CAL_TCF_PwrCompaSpdCAx_af32[0])),
      ((const float32 *)&(CAL_TCF_PwrCompaIsCAy_af32[0])), ((const float32 *)
      &(CAL_TCF_PwrCompaElectCAz_af32[0])), rtCP_PwrTrqSpdCompaElect_maxInd, 33U);
  } else {
    if (rtb_Divide1_c <= 0.01F) {
      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S22>/Constant4'
       */
      rtb_Divide1_c = 0.01F;
    }

    VAR_TCF_PwrTrqCompCof_f32 = look2_iflf_binlxpw(rtb_Divide1_c,
      VAR_TCF_Isflt_f32, ((const float32 *)&(CAL_TCF_PwrCompaSpdCAx_af32[0])),
      ((const float32 *)&(CAL_TCF_PwrCompaIsCAy_af32[0])),
      rtCP_PwrTrqSpdCompaGen_tableDat, rtCP_PwrTrqSpdCompaGen_maxIndex, 33U);
  }

  /* End of Switch: '<S22>/Switch' */

  /* Product: '<S22>/Product2' incorporates:
   *  Constant: '<S22>/60div2PI'
   *  Inport: '<Root>/SWD_Spd'
   *  Product: '<S22>/Divide'
   *  Product: '<S22>/Product1'
   *  Sum: '<S22>/Add'
   */
  VAR_TCF_PwrTrqNoflt_f32 = (VAR_TCF_PwrInputflt_f32 - VAR_TCF_Ploss_f32) /
    get_SWD_Spd() * 9.55F * VAR_TCF_PwrTrqCompCof_f32;

  /* Product: '<S22>/Divide1' incorporates:
   *  Constant: '<S22>/CAL_TCF_TrqMechCutOffFrq_f32'
   *  Constant: '<S22>/PRV_CalFltFrq_1ms'
   */
  rtb_Divide1_c = (float32)PRV_CalFltFrq_1ms / CAL_TCF_TrqMechCutOffFrq_f32;

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S28>/UpperRelop'
   *  Switch: '<S28>/Switch2'
   */
  if (rtb_Divide1_c < 0.0F) {
    rtb_Divide1_c = 0.0F;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Product: '<S22>/Divide2' incorporates:
   *  Sum: '<S22>/Add1'
   */
  rtb_Divide1_c /= rtb_Divide1_c + SWC_TCF_ConstB.Product5;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S22>/One'
   *  Product: '<S22>/Product3'
   *  Product: '<S22>/Product4'
   *  Sum: '<S22>/Subtract1'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  SWC_TCF_DW.UnitDelay_DSTATE = (1.0F - rtb_Divide1_c) * VAR_TCF_PwrTrqNoflt_f32
    + rtb_Divide1_c * SWC_TCF_DW.UnitDelay_DSTATE;

  /* Saturate: '<S22>/Saturation1' incorporates:
   *  UnitDelay: '<S22>/Unit Delay'
   */
  if (SWC_TCF_DW.UnitDelay_DSTATE > 500.0F) {
    VAR_TCF_PwrTrqflt_f32 = 500.0F;
  } else if (SWC_TCF_DW.UnitDelay_DSTATE < -500.0F) {
    VAR_TCF_PwrTrqflt_f32 = -500.0F;
  } else {
    VAR_TCF_PwrTrqflt_f32 = SWC_TCF_DW.UnitDelay_DSTATE;
  }

  /* End of Saturate: '<S22>/Saturation1' */

  /* Update for Delay: '<S22>/Delay' */
  SWC_TCF_DW.Delay_DSTATE = VAR_TCF_MotorMode_u8;
}

/* Output and update for atomic system: '<S5>/Debouncer' */
void SWC_TCF_Debouncer(boolean rtu_BooleanIN, boolean rtu_Rst, sint16
  rtu_CountTrh, sint16 rtu_DebTrh, boolean *rty_OutLock, DW_Debouncer_SWC_TCF_T *
  localDW)
{
  boolean rtb_RelationalOperator_a;

  /* Switch: '<S29>/Switch1' incorporates:
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  localDW->UnitDelay1_DSTATE = ((!rtu_Rst) && localDW->UnitDelay1_DSTATE);

  /* Outputs for Enabled SubSystem: '<S29>/Subsystem' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  /* Delay: '<S29>/Delay1' */
  if (localDW->Delay1_DSTATE) {
    /* Sum: '<S33>/Add' incorporates:
     *  Constant: '<S33>/Constant'
     *  Delay: '<S33>/Delay'
     */
    localDW->Delay_DSTATE++;

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/Constant1'
     *  Delay: '<S33>/Delay'
     *  RelationalOperator: '<S33>/Relational Operator'
     */
    if (localDW->Delay_DSTATE >= rtu_CountTrh) {
      localDW->Delay_DSTATE = 0;
    }

    /* End of Switch: '<S33>/Switch' */
  }

  /* End of Outputs for SubSystem: '<S29>/Subsystem' */

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S32>/Constant'
   *  Delay: '<S29>/Delay2'
   *  Delay: '<S33>/Delay'
   *  RelationalOperator: '<S32>/Compare'
   */
  if (localDW->Delay_DSTATE == 0) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S29>/Switch2' */

  /* Sum: '<S29>/Add' incorporates:
   *  Delay: '<S29>/Delay2'
   */
  localDW->Delay2_DSTATE += rtu_BooleanIN;

  /* RelationalOperator: '<S29>/Relational Operator' */
  rtb_RelationalOperator_a = (localDW->Delay2_DSTATE >= rtu_DebTrh);

  /* Logic: '<S29>/Logical Operator' incorporates:
   *  UnitDelay: '<S29>/Unit Delay1'
   */
  *rty_OutLock = (rtb_RelationalOperator_a || localDW->UnitDelay1_DSTATE);

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Delay: '<S29>/Delay2'
   */
  if (rtb_RelationalOperator_a) {
    localDW->Delay2_DSTATE = 0;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Logic: '<S29>/Logical Operator1' incorporates:
   *  Delay: '<S29>/Delay1'
   */
  localDW->Delay1_DSTATE = (localDW->Delay1_DSTATE || rtu_BooleanIN);

  /* Update for UnitDelay: '<S29>/Unit Delay1' */
  localDW->UnitDelay1_DSTATE = *rty_OutLock;
}

/* Output and update for atomic system: '<S5>/TrqBlend' */
void SWC_TCF_TrqBlend(void)
{
  /* Chart: '<S30>/TubeSelector2' */
  if (VAR_TCF_PwrTrqTubeL1_f32 >= VAR_TCF_CurrAgTrqTubeH1_f32) {
    /* SignalConversion generated from: '<S30>/TubeSelector2' */
    VAR_TCF_BlendTrq_f32 = CAL_TCF_TrqInvalid_s16;
    VAR_TCF_TrqCalcMonRslt_b = true;
  } else if (VAR_TCF_CurrAgTrqTubeL1_f32 >= VAR_TCF_PwrTrqTubeH1_f32) {
    /* SignalConversion generated from: '<S30>/TubeSelector2' */
    VAR_TCF_BlendTrq_f32 = CAL_TCF_TrqInvalid_s16;
    VAR_TCF_TrqCalcMonRslt_b = true;
  } else if (VAR_TCF_PwrTrqTubeH1_f32 >= VAR_TCF_CurrAgTrqTubeH1_f32) {
    if (VAR_TCF_PwrTrqTubeL1_f32 >= VAR_TCF_CurrAgTrqTubeL1_f32) {
      /* SignalConversion generated from: '<S30>/TubeSelector2' */
      VAR_TCF_BlendTrq_f32 = (VAR_TCF_PwrTrqTubeL1_f32 +
        VAR_TCF_CurrAgTrqTubeH1_f32) / 2.0F;
    } else {
      /* SignalConversion generated from: '<S30>/TubeSelector2' */
      VAR_TCF_BlendTrq_f32 = (VAR_TCF_CurrAgTrqTubeH1_f32 +
        VAR_TCF_CurrAgTrqTubeL1_f32) / 2.0F;
    }

    VAR_TCF_TrqCalcMonRslt_b = false;
  } else {
    if (VAR_TCF_CurrAgTrqTubeL1_f32 >= VAR_TCF_PwrTrqTubeL1_f32) {
      /* SignalConversion generated from: '<S30>/TubeSelector2' */
      VAR_TCF_BlendTrq_f32 = (VAR_TCF_CurrAgTrqTubeL1_f32 +
        VAR_TCF_PwrTrqTubeH1_f32) / 2.0F;
    } else {
      /* SignalConversion generated from: '<S30>/TubeSelector2' */
      VAR_TCF_BlendTrq_f32 = (VAR_TCF_PwrTrqTubeH1_f32 +
        VAR_TCF_PwrTrqTubeL1_f32) / 2.0F;
    }

    VAR_TCF_TrqCalcMonRslt_b = false;
  }

  /* End of Chart: '<S30>/TubeSelector2' */
}

/* Output and update for atomic system: '<S5>/TrqTube' */
void SWC_TCF_TrqTube(void)
{
  float32 rtb_Cal_PowerTrqTube_T;
  float32 rtb_uDLookupTable;

  /* Abs: '<S31>/Abs' incorporates:
   *  Inport: '<Root>/SWD_Spd'
   */
  rtb_Cal_PowerTrqTube_T = fabsf(get_SWD_Spd());

  /* Lookup_n-D: '<S31>/1-D Lookup Table' */
  rtb_uDLookupTable = look1_iflf_binlxpw(rtb_Cal_PowerTrqTube_T, ((const float32
    *)&(CAL_TCF_TrqTubeNCAx_af32[0])), ((const float32 *)
    &(CAL_TCF_AgTrqTubeCAy_af32[0])), 17U);

  /* Sum: '<S31>/Add2' */
  VAR_TCF_CurrAgTrqTubeH1_f32 = VAR_TCF_CurrAgTrqflt_f32 + rtb_uDLookupTable;

  /* Sum: '<S31>/Add3' */
  VAR_TCF_CurrAgTrqTubeL1_f32 = VAR_TCF_CurrAgTrqflt_f32 - rtb_uDLookupTable;

  /* Lookup_n-D: '<S31>/Cal_PowerTrqTube_T' */
  rtb_Cal_PowerTrqTube_T = look1_iflf_binlxpw(rtb_Cal_PowerTrqTube_T, ((const
    float32 *)&(CAL_TCF_TrqTubeNCAx_af32[0])), ((const float32 *)
    &(CAL_TCF_PwrTrqTubeCAy_af32[0])), 17U);

  /* Switch: '<S31>/Switch' */
  if (SWC_TCF_B.LogicalOperator) {
    VAR_TCF_PwrTrqfltcomp_f32 = VAR_TCF_PwrTrqflt_f32;
  } else {
    VAR_TCF_PwrTrqfltcomp_f32 = VAR_TCF_CurrAgTrqflt_f32;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Sum: '<S31>/Add' */
  VAR_TCF_PwrTrqTubeH1_f32 = VAR_TCF_PwrTrqfltcomp_f32 + rtb_Cal_PowerTrqTube_T;

  /* Sum: '<S31>/Add1' */
  VAR_TCF_PwrTrqTubeL1_f32 = VAR_TCF_PwrTrqfltcomp_f32 - rtb_Cal_PowerTrqTube_T;
}

/* Model step function for TID1 */
void SWC_TCF_1ms(void)                 /* Explicit Task: SWC_TCF_1ms */
{
  boolean rtb_RelationalOperator2_en;
  float32 rtb_Relay;

  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_TCF_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_TCF_1ms_sys'
   */
  /* Outputs for Atomic SubSystem: '<S1>/TrqCalcEnable' */
  /* Abs: '<S6>/Abs' incorporates:
   *  Inport: '<Root>/SWD_Spd'
   */
  rtb_Relay = fabsf(get_SWD_Spd());

  /* Relay: '<S6>/Relay' */
  SWC_TCF_DW.Relay_Mode = ((rtb_Relay >= CAL_TCF_PwrTrqCalcSpdThrH_f32) ||
    ((rtb_Relay > CAL_TCF_PwrTrqCalcSpdThrL_f32) && SWC_TCF_DW.Relay_Mode));

  /* RelationalOperator: '<S6>/Relational Operator2' incorporates:
   *  Constant: '<S6>/CAL_TOM_SpeedCtlMode_u8'
   *  Inport: '<Root>/L2Com_ModeReq'
   */
  rtb_RelationalOperator2_en = (get_L2Com_ModeReq() != CAL_TCF_SpeedCtlMode_u8);

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Relay: '<S6>/Relay'
   */
  SWC_TCF_B.LogicalOperator = (rtb_RelationalOperator2_en &&
    SWC_TCF_DW.Relay_Mode);

  /* End of Outputs for SubSystem: '<S1>/TrqCalcEnable' */

  /* Outputs for Enabled SubSystem: '<S1>/CurrAgTrqCalcProc' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  if (rtb_RelationalOperator2_en) {
    /* Outputs for Atomic SubSystem: '<S3>/IdIqCalc' */
    SWC_TCF_IdIqCalc();

    /* End of Outputs for SubSystem: '<S3>/IdIqCalc' */

    /* Outputs for Atomic SubSystem: '<S3>/MotorModeJdg' */
    SWC_TCF_MotorModeJdg();

    /* End of Outputs for SubSystem: '<S3>/MotorModeJdg' */

    /* Outputs for Atomic SubSystem: '<S3>/LdsubLqCalc' */
    SWC_TCF_LdsubLqCalc();

    /* End of Outputs for SubSystem: '<S3>/LdsubLqCalc' */

    /* Outputs for Atomic SubSystem: '<S3>/CurrAgTrqCalc' */
    SWC_TCF_CurrAgTrqCalc();

    /* End of Outputs for SubSystem: '<S3>/CurrAgTrqCalc' */
  }

  /* End of Outputs for SubSystem: '<S1>/CurrAgTrqCalcProc' */

  /* SignalConversion: '<S1>/Signal Conversion2' */
  set_TCF_TrqDir(VAR_TCF_TrqDir_u8);

  /* SignalConversion: '<S1>/Signal Conversion3' */
  set_TCF_nDir(VAR_TCF_nDir_u8);

  /* SignalConversion: '<S1>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/L2Sampling_DycU_Mon'
   */
  VAR_L2Sampling_DycUMon_f32 = get_L2Sampling_DycU_Mon();

  /* SignalConversion: '<S1>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/L2Sampling_DycV_Mon'
   */
  VAR_L2Sampling_DycVMon_f32 = get_L2Sampling_DycV_Mon();

  /* SignalConversion: '<S1>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/L2Sampling_DycW_Mon'
   */
  VAR_L2Sampling_DycWMon_f32 = get_L2Sampling_DycW_Mon();

  /* SignalConversion: '<S1>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/HSPF_StrrTempFlt'
   */
  VAR_HSPF_StrrTempFlt_f32 = get_HSPF_StrrTempFlt();

  /* Outputs for Enabled SubSystem: '<S1>/PwrTrqCalcProc' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (SWC_TCF_B.LogicalOperator) {
    /* Outputs for Atomic SubSystem: '<S4>/IsCalc' */
    SWC_TCF_IsCalc();

    /* End of Outputs for SubSystem: '<S4>/IsCalc' */

    /* Outputs for Atomic SubSystem: '<S4>/PinputCalc' */
    SWC_TCF_PinputCalc();

    /* End of Outputs for SubSystem: '<S4>/PinputCalc' */

    /* Outputs for Atomic SubSystem: '<S4>/PlossCalc' */
    SWC_TCF_PlossCalc();

    /* End of Outputs for SubSystem: '<S4>/PlossCalc' */

    /* Outputs for Atomic SubSystem: '<S4>/PwrTrqCalc' */
    SWC_TCF_PwrTrqCalc();

    /* End of Outputs for SubSystem: '<S4>/PwrTrqCalc' */
  }

  /* End of Outputs for SubSystem: '<S1>/PwrTrqCalcProc' */

  /* Outputs for Enabled SubSystem: '<S1>/TrqBlendProc' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtb_RelationalOperator2_en) {
    /* Outputs for Atomic SubSystem: '<S5>/TrqTube' */
    SWC_TCF_TrqTube();

    /* End of Outputs for SubSystem: '<S5>/TrqTube' */

    /* Outputs for Atomic SubSystem: '<S5>/TrqBlend' */
    SWC_TCF_TrqBlend();

    /* End of Outputs for SubSystem: '<S5>/TrqBlend' */

    /* Outputs for Atomic SubSystem: '<S5>/Debouncer' */
    /* Constant: '<S5>/CAL_TOM_TrqMonErrRst_b2' incorporates:
     *  Constant: '<S5>/CAL_TOM_HiTrqMonDebTrh_s4'
     *  Constant: '<S5>/CAL_TOM_HiTrqMonDebTrh_s5'
     */
    SWC_TCF_Debouncer(VAR_TCF_TrqCalcMonRslt_b, CAL_TCF_TrqCalcMonErrRst_b,
                      CAL_TCF_TrqCalcMonCountTrh_s16,
                      CAL_TCF_TrqCalcMonDebTrh_s16, &VAR_TCF_TrqCalcErr_b,
                      &SWC_TCF_DW.Debouncer);

    /* End of Outputs for SubSystem: '<S5>/Debouncer' */
  }

  /* End of Outputs for SubSystem: '<S1>/TrqBlendProc' */

  /* SignalConversion: '<S1>/Signal Conversion1' */
  set_TCF_TrqCalcErr(VAR_TCF_TrqCalcErr_b);

  /* SignalConversion: '<S1>/Signal Conversion' */
  set_TCF_BlendTrq(VAR_TCF_BlendTrq_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TCF_1ms' */
}

/* Model initialize function */
void SWC_TCF_initialize(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TCF_1ms' incorporates:
   *  SubSystem: '<Root>/SWC_TCF_1ms_sys'
   */
  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion' */
  set_TCF_BlendTrq(VAR_TCF_BlendTrq_f32);

  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion1' */
  set_TCF_TrqCalcErr(VAR_TCF_TrqCalcErr_b);

  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion2' */
  set_TCF_TrqDir(VAR_TCF_TrqDir_u8);

  /* SystemInitialize for SignalConversion: '<S1>/Signal Conversion3' */
  set_TCF_nDir(VAR_TCF_nDir_u8);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/SWC_TCF_1ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
