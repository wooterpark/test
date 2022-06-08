/*
 * File: SWC_MPC.c
 *
 * Code generated for Simulink model 'SWC_MPC'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jan 26 11:54:33 2021
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_MPC.h"
#include "SWC_MPC_private.h"
#include "look1_iflf_binlcapw.h"
#include "look1_iflf_binlcpw.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlcapw.h"
#include "look2_iflf_binlcpw.h"
#include "look2_iflf_binlxpw.h"

/* Exported block signals */
float32 GLB_MPC_idAct_f32;
float32 GLB_MPC_iqAct_f32;
float32 VAR_MPC_TrqMon_f32;            /* '<S17>/Switch' */
float32 VAR_MPC_CofRandomPwm_f32;      /* '<S14>/CofRpwm_table' */
float32 VAR_MPC_frqPwmVF_f32;          /* '<S18>/VFTable' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_MPC_CofUdc_f32 = 0.0F;
                                 /* Referenced by: '<S17>/CAL_MPC_CofUdc_f32' */

/* 扭矩监控电压补偿系数 */
const volatile float32 CAL_MPC_IsCutOffFrq_f32 = 100.0F;
                            /* Referenced by: '<S15>/CAL_MPC_IsCutOffFrq_f32' */
const volatile float32 CAL_MPC_LdSubLqCAx_af32[18] = { 0.0F, 30.0F, 50.0F, 90.0F,
  130.0F, 170.0F, 210.0F, 250.0F, 290.0F, 330.0F, 370.0F, 410.0F, 450.0F, 490.0F,
  530.0F, 570.0F, 610.0F, 650.0F } ;   /* Referenced by:
                                        * '<S6>/LdSubLqGen'
                                        * '<S6>/LdSubLqMot'
                                        */

const volatile float32 CAL_MPC_LdSubLqCAy_af32[15] = { 0.0F, 30.0F, 50.0F, 90.0F,
  130.0F, 170.0F, 210.0F, 250.0F, 290.0F, 330.0F, 370.0F, 410.0F, 450.0F, 490.0F,
  530.0F } ;                           /* Referenced by:
                                        * '<S6>/LdSubLqGen'
                                        * '<S6>/LdSubLqMot'
                                        */

const volatile float32 CAL_MPC_LdSubLqCAzGen_af32[270] = { -0.000220739F,
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
  -0.000114106F, -0.000116502F, -0.000118898F, -0.000121294F } ;/* Referenced by: '<S6>/LdSubLqGen' */

const volatile float32 CAL_MPC_LdSubLqCAzMot_af32[270] = { -0.000220739F,
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
  -9.00032E-5F, -8.94846E-5F, -8.89661E-5F, -8.84476E-5F } ;/* Referenced by: '<S6>/LdSubLqMot' */

const volatile float32 CAL_MPC_Ld_f32 = 0.0001F;
                                      /* Referenced by: '<S6>/CAL_MPC_Ld_f32' */
const volatile float32 CAL_MPC_Lq_f32 = 0.00025F;
                                      /* Referenced by: '<S6>/CAL_MPP_Lq_f32' */
const volatile float32 CAL_MPC_MtpaTableX_Trq_af32[15] = { 0.0F, 12.9F, 30.15F,
  50.0F, 71.9F, 94.7F, 118.4F, 141.6F, 165.2F, 188.7F, 211.8F, 234.8F, 256.0F,
  278.5F, 295.0F } ;              /* Referenced by: '<S19>/MPC_MtpaTable_Trq' */

const volatile float32 CAL_MPC_MtpaTableY_isd_af32[15] = { 0.0F, -12.9409F,
  -42.2617F, -74.9998F, -105.983498F, -143.393707F, -192.8358F, -229.620193F,
  -267.651703F, -318.197388F, -365.676208F, -408.728912F, -452.82489F, -497.928F,
  -536.229797F } ;                /* Referenced by: '<S19>/MPC_MtpaTable_Trq' */

const volatile float32 CAL_MPC_MtpvTableX_Udc_af32[8] = { 0.0F, 100.0F, 280.0F,
  320.0F, 350.0F, 450.0F, 480.0F, 500.0F } ;/* Referenced by:
                                             * '<S19>/MTPV_Gen'
                                             * '<S19>/MTPV_Mot'
                                             */

const volatile float32 CAL_MPC_MtpvTableY_N_af32[19] = { 0.0F, 100.0F, 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F,
  10000.0F, 11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F, 16500.0F
} ;                                    /* Referenced by:
                                        * '<S19>/MTPV_Gen'
                                        * '<S19>/MTPV_Mot'
                                        */

const volatile float32 CAL_MPC_MtpvTableZ_idGen_af32[152] = { -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -540.0F, -540.0F, -540.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -597.600464F, -597.600464F, -597.600464F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -640.0F, -640.0F, -640.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -660.0F, -660.0F, -660.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -670.0F, -670.0F, -670.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -670.0F, -670.0F, -670.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -640.0F, -640.0F, -640.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -610.0F, -610.0F, -610.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -595.0F, -591.5F, -591.5F, -591.5F, -591.5F, -650.0F,
  -650.0F, -650.0F, -565.0F, -578.8F, -578.8F, -578.8F, -578.8F, -650.0F,
  -650.0F, -650.0F, -565.0F, -559.9F, -559.9F, -559.9F, -559.9F, -650.0F,
  -650.0F, -650.0F, -565.0F, -550.9F, -550.9F, -550.9F, -550.9F, -650.0F,
  -650.0F, -650.0F, -550.0F, -531.6F, -531.6F, -531.6F, -531.6F, -650.0F,
  -650.0F, -650.0F, -495.0F, -531.6F, -531.6F, -531.6F, -531.6F } ;/* Referenced by: '<S19>/MTPV_Gen' */

const volatile float32 CAL_MPC_MtpvTableZ_idMot_af32[152] = { -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -525.0F, -525.0F, -525.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -540.0F, -540.0F, -540.0F, -650.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -597.600464F, -597.600464F, -597.600464F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -640.0F, -640.0F, -640.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -660.0F, -660.0F, -660.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -670.0F, -670.0F, -670.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -670.0F, -670.0F, -670.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -640.0F, -640.0F, -640.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -610.0F, -610.0F, -610.0F, -650.0F, -650.0F, -650.0F,
  -650.0F, -650.0F, -595.0F, -591.5F, -591.5F, -591.5F, -591.5F, -650.0F,
  -650.0F, -650.0F, -565.0F, -578.8F, -578.8F, -578.8F, -578.8F, -650.0F,
  -650.0F, -650.0F, -565.0F, -559.9F, -559.9F, -559.9F, -559.9F, -650.0F,
  -650.0F, -650.0F, -565.0F, -550.9F, -550.9F, -550.9F, -550.9F, -650.0F,
  -650.0F, -650.0F, -550.0F, -531.6F, -531.6F, -531.6F, -531.6F, -650.0F,
  -650.0F, -650.0F, -495.0F, -531.6F, -531.6F, -531.6F, -531.6F } ;/* Referenced by: '<S19>/MTPV_Mot' */

const volatile float32 CAL_MPC_OmbwTableX_Spd_af32[11] = { 0.0F, 1000.0F,
  2000.0F, 2500.0F, 3000.0F, 4000.0F, 6000.0F, 8000.0F, 12000.0F, 14000.0F,
  16000.0F } ;                       /* Referenced by: '<S19>/MPC_Ombw_Table' */

const volatile float32 CAL_MPC_OmbwTableY_Ombw_af32[11] = { 1000.0F, 1000.0F,
  1000.0F, 1250.0F, 1250.0F, 800.0F, 500.0F, 500.0F, 500.0F, 500.0F, 500.0F } ;
                                     /* Referenced by: '<S19>/MPC_Ombw_Table' */

const volatile float32 CAL_MPC_Psi_f32 = 0.0485F;
                                     /* Referenced by: '<S7>/CAL_MPC_Psi_f32' */
const volatile float32 CAL_MPC_Rcmp_f32 = 0.0F;
                                   /* Referenced by: '<S17>/CAL_MPC_Rcmp_f32' */

/* 扭矩监控电阻补偿 */
const volatile float32 CAL_MPC_Rs_f32 = 0.006F;
                                      /* Referenced by: '<S8>/CAL_MPC_Rs_f32' */
const volatile float32 CAL_MPC_RvTableX_Spd_af32[11] = { 0.0F, 1000.0F, 2000.0F,
  2500.0F, 3000.0F, 4000.0F, 6000.0F, 8000.0F, 12000.0F, 14000.0F, 16000.0F } ;/* Referenced by: '<S19>/MPC_Rv_Table' */

const volatile float32 CAL_MPC_RvTableY_Rv_af32[11] = { 1000.0F, 1000.0F,
  1000.0F, 1250.0F, 1250.0F, 800.0F, 500.0F, 500.0F, 500.0F, 500.0F, 500.0F } ;/* Referenced by: '<S19>/MPC_Rv_Table' */

const volatile float32 CAL_MPC_TrqMechCutOffFrq_f32 = 100.0F;
                        /* Referenced by: '<S9>/CAL_MPC_TrqMechCutOffFrq_f32' */
const volatile float32 CAL_MPC_cofRpwm_Y_af32[17] = { 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F }
;                                     /* Referenced by: '<S14>/CofRpwm_table' */

/* 随机PWM频率系数查表X轴转速 */
const volatile boolean CAL_MPC_flgDesOrAct_b = 0;
                               /* Referenced by: '<S6>/CAL_MPC_flgDesOrAct_b' */
const volatile boolean CAL_MPC_flgUseLdSubLq_b = 0;
                             /* Referenced by: '<S6>/CAL_MPC_flgUseLdSubLq_b' */
const volatile boolean CAL_MPC_flgUseLdq_b = 0;
                                 /* Referenced by: '<S6>/CAL_MPC_flgUseLdq_b' */
const volatile boolean CAL_MPC_flgUseRs_b = 1;
                                  /* Referenced by: '<S8>/CAL_MPC_flgUseRs_b' */
const volatile float32 CAL_MPC_frqPwmVFTableX_Is_af32[11] = { 0.0F, 50.0F,
  100.0F, 150.0F, 200.0F, 250.0F, 300.0F, 350.0F, 400.0F, 450.0F, 500.0F } ;/* Referenced by: '<S18>/VFTable' */

/* 变载频查表X轴相电流幅值 */
const volatile float32 CAL_MPC_frqPwmVFTableY_VoltModuRate_af32[13] = { 0.0F,
  0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F, 1.03F, 1.1F } ;/* Referenced by: '<S18>/VFTable' */

/* 变载频查表Y轴电压调制度 */
const volatile float32 CAL_MPC_frqPwmVFTableZ_Frq_af32[143] = { 2000.0F, 2000.0F,
  5000.0F, 6000.0F, 6500.0F, 6500.0F, 6500.0F, 6500.0F, 6500.0F, 6500.0F,
  8075.0F, 9229.0F, 10186.0F, 2000.0F, 2000.0F, 5000.0F, 6000.0F, 6500.0F,
  6500.0F, 6500.0F, 6500.0F, 6500.0F, 6500.0F, 8075.0F, 9229.0F, 10186.0F,
  2000.0F, 2000.0F, 5000.0F, 6000.0F, 6500.0F, 6500.0F, 6500.0F, 6500.0F,
  6500.0F, 6500.0F, 8026.0F, 9547.0F, 10537.0F, 2000.0F, 2000.0F, 5000.0F,
  6000.0F, 6500.0F, 7500.0F, 7500.0F, 7500.0F, 7500.0F, 7500.0F, 8042.0F,
  9525.0F, 10513.0F, 2000.0F, 2000.0F, 5000.0F, 6500.0F, 7000.0F, 7500.0F,
  7500.0F, 8000.0F, 8000.0F, 8000.0F, 8829.0F, 9229.0F, 10186.0F, 2000.0F,
  2428.0F, 5500.0F, 6500.0F, 7000.0F, 7500.0F, 7500.0F, 8000.0F, 8500.0F,
  9423.0F, 11036.0F, 11536.0F, 12048.0F, 2000.0F, 2301.0F, 4500.0F, 6500.0F,
  7000.0F, 7500.0F, 7500.0F, 7500.0F, 8000.0F, 8927.0F, 10455.0F, 10929.0F,
  12048.0F, 2000.0F, 2217.0F, 4500.0F, 6000.0F, 6500.0F, 6542.0F, 6542.0F,
  6542.0F, 7210.0F, 8603.0F, 10076.0F, 10533.0F, 11625.0F, 2000.0F, 2159.0F,
  4500.0F, 6000.0F, 6000.0F, 6500.0F, 6500.0F, 6500.0F, 7019.0F, 8376.0F,
  9810.0F, 10254.0F, 11317.0F, 2000.0F, 2115.0F, 4500.0F, 6000.0F, 6000.0F,
  6240.0F, 6240.0F, 6240.0F, 6878.0F, 8207.0F, 9612.0F, 10048.0F, 11089.0F,
  2000.0F, 2082.0F, 4000.0F, 4962.0F, 5763.0F, 6141.0F, 6141.0F, 6141.0F,
  6769.0F, 8076.0F, 9459.0F, 9888.0F, 10913.0F } ;/* Referenced by: '<S18>/VFTable' */

/* 变载频查表Z轴载频频率 */
const volatile float32 CAL_MPC_idActCutOffFrq_f32 = 100.0F;
                         /* Referenced by: '<S15>/CAL_MPC_idActCutOffFrq_f32' */
const volatile float32 CAL_MPC_iqActCutOffFrq_f32 = 100.0F;
                         /* Referenced by: '<S15>/CAL_MPC_iqActCutOffFrq_f32' */
const volatile float32 CAL_MPC_isdFFTableX_Spd_af32[17] = { 0.0F, 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F,
  10000.0F, 11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                 /* Referenced by: '<S19>/MPC_isdFFTable_isd' */

const volatile float32 CAL_MPC_isdFFTableX_Udc_af32[8] = { 0.0F, 100.0F, 280.0F,
  320.0F, 350.0F, 450.0F, 480.0F, 500.0F } ;
                              /* Referenced by: '<S19>/MPC_isdFFTable_UdcCof' */

const volatile float32 CAL_MPC_isdFFTableY_Trq_af32[17] = { 0.0F, 20.0F, 40.0F,
  60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F, 180.0F, 200.0F, 220.0F, 240.0F,
  260.0F, 280.0F, 300.0F, 320.0F } ;
                                 /* Referenced by: '<S19>/MPC_isdFFTable_isd' */

const volatile float32 CAL_MPC_isdFFTableY_UdcCof_af32[8] = { 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                              /* Referenced by: '<S19>/MPC_isdFFTable_UdcCof' */

const volatile float32 CAL_MPC_isdFFTableZ_isd_af32[289] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -30.0F, -60.0F, -81.0F,
  -108.0F, -133.5F, -159.0F, -29.68F, -29.68F, -29.68F, -29.68F, -29.68F,
  -29.68F, -29.68F, -29.68F, -29.68F, -39.1F, -69.0F, -95.0F, -119.0F, -139.0F,
  -157.0F, -171.0F, -190.0F, -60.94F, -60.94F, -60.94F, -60.94F, -60.94F,
  -60.94F, -60.94F, -60.94F, -78.5F, -113.0F, -143.0F, -172.0F, -200.0F, -220.0F,
  -240.0F, -260.0F, -280.0F, -90.22F, -90.22F, -90.22F, -90.22F, -90.22F,
  -90.22F, -90.22F, -106.0F, -149.0F, -187.0F, -223.5F, -257.0F, -292.0F,
  -320.0F, -350.0F, -380.0F, -410.0F, -120.3F, -120.3F, -120.3F, -120.3F,
  -120.3F, -120.3F, -120.3F, -168.9F, -219.0F, -264.0F, -309.0F, -355.0F,
  -407.0F, -407.3F, -442.0F, -480.0F, -514.0F, -147.0F, -147.0F, -147.0F,
  -147.0F, -147.0F, -147.0F, -168.0F, -231.5F, -290.0F, -347.0F, -410.0F,
  -436.0F, -493.5F, -497.8F, -538.5F, -583.8F, -514.0F, -178.66F, -178.66F,
  -178.66F, -178.66F, -178.66F, -178.66F, -224.5F, -297.0F, -368.0F, -445.0F,
  -483.5F, -522.5F, -589.1F, -588.3F, -538.5F, -583.8F, -514.0F, -204.2F,
  -204.2F, -204.2F, -204.2F, -204.2F, -204.2F, -281.5F, -367.0F, -459.0F,
  -513.4F, -570.0F, -609.0F, -589.1F, -588.3F, -538.5F, -583.8F, -514.0F,
  -240.5F, -240.5F, -240.5F, -240.5F, -240.5F, -240.5F, -341.5F, -442.0F,
  -598.0F, -593.6F, -570.0F, -609.0F, -589.1F, -588.3F, -538.5F, -583.8F,
  -514.0F, -283.2F, -283.2F, -283.2F, -283.2F, -283.2F, -283.2F, -403.0F,
  -540.0F, -651.5F, -673.9F, -570.0F, -609.0F, -589.1F, -588.3F, -538.5F,
  -583.8F, -514.0F, -317.9F, -317.9F, -317.9F, -317.9F, -317.9F, -341.0F,
  -472.0F, -590.9F, -651.5F, -673.9F, -570.0F, -609.0F, -589.1F, -588.3F,
  -538.5F, -583.8F, -514.0F, -357.0F, -357.0F, -357.0F, -357.0F, -357.0F,
  -391.0F, -556.0F, -661.7F, -651.5F, -673.9F, -570.0F, -609.0F, -589.1F,
  -588.3F, -538.5F, -583.8F, -514.0F, -394.5F, -394.5F, -394.5F, -394.5F,
  -394.5F, -450.0F, -603.9F, -661.7F, -651.5F, -673.9F, -570.0F, -609.0F,
  -589.1F, -588.3F, -538.5F, -583.8F, -514.0F, -437.4F, -437.4F, -437.4F,
  -437.4F, -437.4F, -522.0F, -667.0F, -661.7F, -651.5F, -673.9F, -570.0F,
  -609.0F, -589.1F, -588.3F, -538.5F, -583.8F, -514.0F, -455.0F, -455.0F,
  -455.0F, -455.0F, -455.0F, -548.0F, -667.0F, -661.7F, -651.5F, -673.9F,
  -570.0F, -609.0F, -589.1F, -588.3F, -538.5F, -583.8F, -514.0F, -488.6F,
  -488.6F, -488.6F, -488.6F, -488.6F, -606.0F, -667.0F, -661.7F, -651.5F,
  -673.9F, -570.0F, -609.0F, -589.1F, -588.3F, -538.5F, -583.8F, -514.0F,
  -522.0F, -522.0F, -522.0F, -522.0F, -522.0F, -606.0F, -667.0F, -661.7F,
  -651.5F, -673.9F, -570.0F, -609.0F, -589.1F, -588.3F, -538.5F, -583.8F,
  -514.0F } ;                    /* Referenced by: '<S19>/MPC_isdFFTable_isd' */

const volatile float32 CAL_MPC_nCofRpwm_X_af32[17] = { 0.0F, 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                      /* Referenced by: '<S14>/CofRpwm_table' */

/* 随机PWM频率系数查表Y轴频率系数值 */
const volatile float32 CAL_MPC_nSetTrqMonMin_f32 = 1000.0F;
                          /* Referenced by: '<S36>/CAL_MPC_nSetTrqMonMin_f32' */

/* 扭矩监控转速计算阈值 */
const volatile float32 CAL_MPC_nTrqMonMax_f32 = 1500.0F;
                             /* Referenced by: '<S36>/CAL_MPC_nTrqMonMax_f32' */

/* 开启扭矩监控转速滞环上限值阈值 */
const volatile float32 CAL_MPC_nTrqMonMin_f32 = 1000.0F;
                             /* Referenced by: '<S36>/CAL_MPC_nTrqMonMin_f32' */

/* 开启扭矩监控转速滞环下限阈值 */
const volatile float32 CAL_MPC_tCpnBwdGenTableX_n_af32[16] = { 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                   /* Referenced by: '<S31>/1-D Lookup Table' */

/* 后退发电查表开管时间补偿X轴速度 */
const volatile float32 CAL_MPC_tCpnBwdGenTableY_tCpn_af32[16] = { 1.0F, 1.0F,
  1.1F, 0.7F, 0.7F, 1.0F, 0.8F, 0.8F, 0.7F, 0.7F, 0.7F, 0.4F, 0.2F, 0.0F, -0.3F,
  -0.6F } ;                        /* Referenced by: '<S31>/1-D Lookup Table' */

/* 后退发电查表开管时间补偿Y轴修正时间 */
const volatile float32 CAL_MPC_tCpnBwdMotTableX_n_af32[16] = { 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                   /* Referenced by: '<S32>/1-D Lookup Table' */

/* 后退电动查表开管时间补偿X轴速度 */
const volatile float32 CAL_MPC_tCpnBwdMotTableY_tCpn_af32[16] = { 1.0F, 1.0F,
  1.1F, 0.9F, 1.2F, 1.3F, 1.3F, 1.3F, 1.0F, 1.0F, 1.0F, 0.8F, 0.7F, 0.3F, 0.1F,
  -0.1F } ;                        /* Referenced by: '<S32>/1-D Lookup Table' */

/* 后退电动查表开管时间补偿Y轴修正时间 */
const volatile float32 CAL_MPC_tCpnFwdGenTableX_n_af32[16] = { 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                   /* Referenced by: '<S34>/1-D Lookup Table' */

/* 前进发电查表开管时间补偿X轴速度 */
const volatile float32 CAL_MPC_tCpnFwdGenTableY_tCpn_af32[16] = { 1.1F, 1.1F,
  1.1F, 1.1F, 0.9F, 1.0F, 1.0F, 0.9F, 0.85F, 0.8F, 0.2F, 0.2F, 0.2F, -0.2F,
  -0.4F, -0.9F } ;                 /* Referenced by: '<S34>/1-D Lookup Table' */

/* 前进发电查表开管时间补偿Y轴修正时间 */
const volatile float32 CAL_MPC_tCpnFwdMotTableX_n_af32[16] = { 1000.0F, 2000.0F,
  3000.0F, 4000.0F, 5000.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F,
  11000.0F, 12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                   /* Referenced by: '<S35>/1-D Lookup Table' */

/* 前进电动查表开管时间补偿X轴速度 */
const volatile float32 CAL_MPC_tCpnFwdMotTableY_tCpn_af32[16] = { 1.1F, 1.1F,
  1.1F, 1.1F, 1.3F, 1.5F, 1.5F, 1.5F, 1.5F, 1.3F, 1.0F, 0.9F, 0.6F, 0.4F, 0.3F,
  0.0F } ;                         /* Referenced by: '<S35>/1-D Lookup Table' */

/* 前进电动查表开管时间补偿Y轴修正时间 */
const volatile float32 CAL_MPC_udActCutOffFrq_f32 = 100.0F;
                         /* Referenced by: '<S15>/CAL_MPC_udActCutOffFrq_f32' */
const volatile float32 CAL_MPC_uqActCutOffFrq_f32 = 100.0F;
                         /* Referenced by: '<S15>/CAL_MPC_uqActCutOffFrq_f32' */

#pragma section

/* Block states (default storage) */
DW_SWC_MPC_T SWC_MPC_DW;

/* Model step function for TID1 */
void SWC_MPC_2ms(void)                 /* Explicit Task: RE_SWC_MPC_2ms */
{
  float32 tmpRead;
  float32 tmpRead_0;
  float32 tmpRead_1;
  float32 tmpRead_2;
  float32 rtb_Divide_o3;
  float32 rtb_TmpSignalConversionAtRP__jh;
  float32 rtb_Abs;
  float32 rtb_Abs1;
  float32 rtb_TmpSignalConversionAtRP_S_o;
  uint8 rtb_TmpSignalConversionAtRP_S_p;
  float32 rtb_TmpSignalConversionAtRP_SWC;
  float32 Switch4;
  float32 Switch;
  float32 Switch3;
  float32 Switch_d;

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Product: '<S22>/Divide' incorporates:
   *  Constant: '<S15>/CAL_MPC_idActCutOffFrq_f32'
   *  Constant: '<S15>/PRV_CalFltFrq_2ms_1'
   */
  rtb_Abs1 = PRV_CalFltFrq_2ms / CAL_MPC_idActCutOffFrq_f32;

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S27>/UpperRelop'
   *  Switch: '<S27>/Switch2'
   */
  if (rtb_Abs1 < 1.0F) {
    rtb_Abs1 = 1.0F;
  }

  /* End of Switch: '<S27>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Inport: '<Root>/RP_SWC_MCF_MCF_isd' */
  Rte_Read_RP_SWC_MCF_MCF_isd(&Switch3);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Product: '<S22>/Divide1' incorporates:
   *  Constant: '<S22>/2'
   *  Constant: '<S22>/Constant2'
   *  Product: '<S22>/Product2'
   *  Sum: '<S22>/Add'
   */
  rtb_Abs1 /= MPC_GLB_pi_f32 * 2.0F + rtb_Abs1;

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S22>/One'
   *  Product: '<S22>/Product'
   *  Product: '<S22>/Product1'
   *  Sum: '<S22>/Subtract1'
   *  UnitDelay: '<S22>/Unit Delay'
   */
  SWC_MPC_DW.UnitDelay_DSTATE = (1.0F - rtb_Abs1) * Switch3 + rtb_Abs1 *
    SWC_MPC_DW.UnitDelay_DSTATE;

  /* Abs: '<S6>/Abs' */
  rtb_Abs = fabsf(SWC_MPC_DW.UnitDelay_DSTATE);

  /* Product: '<S23>/Divide' incorporates:
   *  Constant: '<S15>/CAL_MPC_iqActCutOffFrq_f32'
   *  Constant: '<S15>/PRV_CalFltFrq_2ms_2'
   */
  rtb_Abs1 = PRV_CalFltFrq_2ms / CAL_MPC_iqActCutOffFrq_f32;

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   *  RelationalOperator: '<S28>/UpperRelop'
   *  Switch: '<S28>/Switch2'
   */
  if (rtb_Abs1 < 1.0F) {
    rtb_Abs1 = 1.0F;
  }

  /* End of Switch: '<S28>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Inport: '<Root>/RP_SWC_MCF_MCF_isq' */
  Rte_Read_RP_SWC_MCF_MCF_isq(&Switch);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Product: '<S23>/Divide1' incorporates:
   *  Constant: '<S23>/2'
   *  Constant: '<S23>/Constant2'
   *  Product: '<S23>/Product2'
   *  Sum: '<S23>/Add'
   */
  rtb_Abs1 /= MPC_GLB_pi_f32 * 2.0F + rtb_Abs1;

  /* Sum: '<S23>/Sum1' incorporates:
   *  Constant: '<S23>/One'
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   *  Sum: '<S23>/Subtract1'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  SWC_MPC_DW.UnitDelay_DSTATE_e = (1.0F - rtb_Abs1) * Switch + rtb_Abs1 *
    SWC_MPC_DW.UnitDelay_DSTATE_e;

  /* Abs: '<S6>/Abs1' */
  rtb_Abs1 = fabsf(SWC_MPC_DW.UnitDelay_DSTATE_e);

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/CAL_MPC_Ld_f32'
   *  Constant: '<S6>/CAL_MPC_flgUseLdq_b'
   *  Constant: '<S6>/CAL_MPP_Lq_f32'
   *  Lookup_n-D: '<S6>/2D_LdTable'
   *  Lookup_n-D: '<S6>/2D_LqTable'
   *  Switch: '<S6>/Switch3'
   */
  if (CAL_MPC_flgUseLdq_b) {
    Switch = CAL_MPC_Ld_f32;
    Switch3 = CAL_MPC_Lq_f32;
  } else {
    Switch = look2_iflf_binlcpw(rtb_Abs, rtb_Abs1, rtCP_uD_LdTable_bp01Data,
      rtCP_uD_LdTable_bp02Data, rtCP_uD_LdTable_tableData,
      rtCP_uD_LdTable_maxIndex, 19U);
    Switch3 = look2_iflf_binlcpw(rtb_Abs, rtb_Abs1, rtCP_uD_LqTable_bp01Data,
      rtCP_uD_LqTable_bp02Data, rtCP_uD_LqTable_tableData,
      rtCP_uD_LqTable_maxIndex, 19U);
  }

  /* End of Switch: '<S6>/Switch' */

  /* Switch: '<S6>/Switch2' incorporates:
   *  Abs: '<S6>/Abs2'
   *  Abs: '<S6>/Abs3'
   *  Constant: '<S6>/CAL_MPC_flgDesOrAct_b'
   *  Inport: '<Root>/RP_SWC_MCF_MCF_idDes'
   *  Inport: '<Root>/RP_SWC_MCF_MCF_iqDes'
   *  Switch: '<S6>/Switch5'
   */
  if (CAL_MPC_flgDesOrAct_b) {
    Rte_Read_RP_SWC_MCF_MCF_idDes(&Switch4);
    rtb_Abs = fabsf(Switch4);
    Rte_Read_RP_SWC_MCF_MCF_iqDes(&rtb_Divide_o3);
    rtb_Abs1 = fabsf(rtb_Divide_o3);
  }

  /* End of Switch: '<S6>/Switch2' */

  /* SignalConversion generated from: '<S1>/RP_SWC_TPC_TPC_stMotorMod_read' incorporates:
   *  Inport: '<Root>/RP_SWC_TPC_TPC_stMotorMod'
   */
  Rte_Read_RP_SWC_TPC_TPC_stMotorMod(&rtb_TmpSignalConversionAtRP_S_p);

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/CAL_MPC_flgUseLdSubLq_b'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S6>/Relational Operator'
   *  RelationalOperator: '<S6>/Relational Operator1'
   *  Sum: '<S6>/Add'
   *  Switch: '<S6>/Switch1'
   */
  if (CAL_MPC_flgUseLdSubLq_b) {
    Switch4 = Switch - Switch3;
  } else if ((rtb_TmpSignalConversionAtRP_S_p == 1) ||
             (rtb_TmpSignalConversionAtRP_S_p == 3)) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Lookup_n-D: '<S6>/LdSubLqMot'
     */
    Switch4 = look2_iflf_binlcpw(rtb_Abs, rtb_Abs1, ((const float32 *)
      &(CAL_MPC_LdSubLqCAx_af32[0])), ((const float32 *)
      &(CAL_MPC_LdSubLqCAy_af32[0])), ((const float32 *)
      &(CAL_MPC_LdSubLqCAzMot_af32[0])), rtCP_LdSubLqMot_maxIndex, 18U);
  } else {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Lookup_n-D: '<S6>/LdSubLqGen'
     */
    Switch4 = look2_iflf_binlcpw(rtb_Abs, rtb_Abs1, ((const float32 *)
      &(CAL_MPC_LdSubLqCAx_af32[0])), ((const float32 *)
      &(CAL_MPC_LdSubLqCAy_af32[0])), ((const float32 *)
      &(CAL_MPC_LdSubLqCAzGen_af32[0])), rtCP_LdSubLqGen_maxIndex, 18U);
  }

  /* End of Switch: '<S6>/Switch4' */

  /* Product: '<S9>/Product2' incorporates:
   *  Constant: '<S7>/CAL_MPC_Psi_f32'
   *  Constant: '<S9>/MPC_GLB_MotorPole_u8'
   *  Constant: '<S9>/TorqueCalculationFactor'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Sum: '<S9>/Add'
   */
  rtb_Divide_o3 = (SWC_MPC_DW.UnitDelay_DSTATE * Switch4 *
                   SWC_MPC_DW.UnitDelay_DSTATE_e + SWC_MPC_DW.UnitDelay_DSTATE_e
                   * CAL_MPC_Psi_f32) * (float32)((uint8)MPC_GLB_MotorPole_u8) *
    1.5F;

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<S9>/CAL_MPC_TrqMechCutOffFrq_f32'
   *  Constant: '<S9>/PRV_CalFltFrq_10ms_3'
   */
  rtb_Abs1 = PRV_CalFltFrq_2ms / CAL_MPC_TrqMechCutOffFrq_f32;

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S13>/UpperRelop'
   *  Switch: '<S13>/Switch2'
   */
  if (rtb_Abs1 < 0.0F) {
    rtb_Abs1 = 0.0F;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Product: '<S12>/Divide1' incorporates:
   *  Constant: '<S12>/2'
   *  Constant: '<S12>/Constant2'
   *  Product: '<S12>/Product2'
   *  Sum: '<S12>/Add'
   */
  rtb_Abs1 /= MPC_GLB_pi_f32 * 2.0F + rtb_Abs1;

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S12>/One'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Subtract1'
   *  UnitDelay: '<S12>/Unit Delay'
   */
  SWC_MPC_DW.UnitDelay_DSTATE_er = (1.0F - rtb_Abs1) * rtb_Divide_o3 + rtb_Abs1 *
    SWC_MPC_DW.UnitDelay_DSTATE_er;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Divide_o3 > 350.0F) {
    rtb_Abs1 = 350.0F;
  } else if (rtb_Divide_o3 < -350.0F) {
    rtb_Abs1 = -350.0F;
  } else {
    rtb_Abs1 = rtb_Divide_o3;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Saturate: '<S9>/Saturation1' incorporates:
   *  UnitDelay: '<S12>/Unit Delay'
   */
  if (SWC_MPC_DW.UnitDelay_DSTATE_er > 350.0F) {
    rtb_Divide_o3 = 350.0F;
  } else if (SWC_MPC_DW.UnitDelay_DSTATE_er < -350.0F) {
    rtb_Divide_o3 = -350.0F;
  } else {
    rtb_Divide_o3 = SWC_MPC_DW.UnitDelay_DSTATE_er;
  }

  /* Outport: '<Root>/PP_SWC_MPC_MPC_TrqMechFlt' incorporates:
   *  Saturate: '<S9>/Saturation1'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_TrqMechFlt(rtb_Divide_o3);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/CAL_MPC_Rs_f32'
   *  Constant: '<S8>/CAL_MPC_flgUseRs_b'
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_tStrrTempFlt'
   *  Lookup_n-D: '<S8>/Rs_TempStr_Tab'
   */
  if (CAL_MPC_flgUseRs_b) {
    Switch_d = CAL_MPC_Rs_f32;
  } else {
    Rte_Read_RP_SWC_HSPF_HSPF_tStrrTempFlt(&Switch_d);
    Switch_d = look1_iflf_binlcpw(Switch_d, rtCP_Rs_TempStr_Tab_bp01Data,
      rtCP_Rs_TempStr_Tab_tableData, 22U);
  }

  /* End of Switch: '<S8>/Switch' */

  /* Product: '<S24>/Divide' incorporates:
   *  Constant: '<S15>/CAL_MPC_udActCutOffFrq_f32'
   *  Constant: '<S15>/PRV_CalFltFrq_2ms_3'
   */
  rtb_Divide_o3 = PRV_CalFltFrq_2ms / CAL_MPC_udActCutOffFrq_f32;

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S24>/Constant'
   *  RelationalOperator: '<S29>/UpperRelop'
   *  Switch: '<S29>/Switch2'
   */
  if (rtb_Divide_o3 < 1.0F) {
    rtb_Divide_o3 = 1.0F;
  }

  /* End of Switch: '<S29>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Inport: '<Root>/RP_SWC_MCF_MCF_udDes' */
  Rte_Read_RP_SWC_MCF_MCF_udDes(&tmpRead_0);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Product: '<S24>/Divide1' incorporates:
   *  Constant: '<S24>/2'
   *  Constant: '<S24>/Constant2'
   *  Product: '<S24>/Product2'
   *  Sum: '<S24>/Add'
   */
  rtb_Divide_o3 /= MPC_GLB_pi_f32 * 2.0F + rtb_Divide_o3;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Constant: '<S24>/One'
   *  Product: '<S24>/Product'
   *  Product: '<S24>/Product1'
   *  Sum: '<S24>/Subtract1'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  SWC_MPC_DW.UnitDelay_DSTATE_i = (1.0F - rtb_Divide_o3) * tmpRead_0 +
    rtb_Divide_o3 * SWC_MPC_DW.UnitDelay_DSTATE_i;

  /* Product: '<S25>/Divide' incorporates:
   *  Constant: '<S15>/CAL_MPC_uqActCutOffFrq_f32'
   *  Constant: '<S15>/PRV_CalFltFrq_2ms_4'
   */
  rtb_Divide_o3 = PRV_CalFltFrq_2ms / CAL_MPC_uqActCutOffFrq_f32;

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S30>/UpperRelop'
   *  Switch: '<S30>/Switch2'
   */
  if (rtb_Divide_o3 < 1.0F) {
    rtb_Divide_o3 = 1.0F;
  }

  /* End of Switch: '<S30>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Inport: '<Root>/RP_SWC_MCF_MCF_uqDes' */
  Rte_Read_RP_SWC_MCF_MCF_uqDes(&tmpRead_1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Product: '<S25>/Divide1' incorporates:
   *  Constant: '<S25>/2'
   *  Constant: '<S25>/Constant2'
   *  Product: '<S25>/Product2'
   *  Sum: '<S25>/Add'
   */
  rtb_Divide_o3 /= MPC_GLB_pi_f32 * 2.0F + rtb_Divide_o3;

  /* Sum: '<S25>/Sum1' incorporates:
   *  Constant: '<S25>/One'
   *  Product: '<S25>/Product'
   *  Product: '<S25>/Product1'
   *  Sum: '<S25>/Subtract1'
   *  UnitDelay: '<S25>/Unit Delay'
   */
  SWC_MPC_DW.UnitDelay_DSTATE_b = (1.0F - rtb_Divide_o3) * tmpRead_1 +
    rtb_Divide_o3 * SWC_MPC_DW.UnitDelay_DSTATE_b;

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_uDcLnk_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_uDcLnk'
   */
  Rte_Read_RP_SWC_MCF_MCF_uDcLnk(&rtb_TmpSignalConversionAtRP_SWC);

  /* SignalConversion generated from: '<S1>/RP_SWC_MCF_MCF_Is_read' incorporates:
   *  Inport: '<Root>/RP_SWC_MCF_MCF_Is'
   */
  Rte_Read_RP_SWC_MCF_MCF_Is(&rtb_TmpSignalConversionAtRP__jh);

  /* Product: '<S20>/Divide' incorporates:
   *  Constant: '<S15>/CAL_MPC_IsCutOffFrq_f32'
   *  Constant: '<S15>/PRV_CalFltFrq_2ms'
   */
  rtb_Divide_o3 = PRV_CalFltFrq_2ms / CAL_MPC_IsCutOffFrq_f32;

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S26>/UpperRelop'
   *  Switch: '<S26>/Switch2'
   */
  if (rtb_Divide_o3 < 1.0F) {
    rtb_Divide_o3 = 1.0F;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Product: '<S20>/Divide1' incorporates:
   *  Constant: '<S20>/2'
   *  Constant: '<S20>/Constant2'
   *  Product: '<S20>/Product2'
   *  Sum: '<S20>/Add'
   */
  rtb_Divide_o3 /= MPC_GLB_pi_f32 * 2.0F + rtb_Divide_o3;

  /* Sum: '<S20>/Sum1' incorporates:
   *  Constant: '<S20>/One'
   *  Product: '<S20>/Product'
   *  Product: '<S20>/Product1'
   *  Sum: '<S20>/Subtract1'
   *  UnitDelay: '<S20>/Unit Delay'
   */
  SWC_MPC_DW.UnitDelay_DSTATE_l = (1.0F - rtb_Divide_o3) *
    rtb_TmpSignalConversionAtRP__jh + rtb_Divide_o3 *
    SWC_MPC_DW.UnitDelay_DSTATE_l;

  /* SignalConversion generated from: '<S1>/RP_SWC_HSPF_HSPF_nSlowFlt_read' incorporates:
   *  Inport: '<Root>/RP_SWC_HSPF_HSPF_nSlowFlt'
   */
  Rte_Read_RP_SWC_HSPF_HSPF_nSlowFlt(&rtb_TmpSignalConversionAtRP_S_o);

  /* Abs: '<S36>/Abs1' incorporates:
   *  Abs: '<S19>/Abs1'
   *  Abs: '<S36>/Abs'
   *  Abs: '<S5>/Abs'
   *  Switch: '<S17>/Switch'
   */
  tmpRead_0 = fabsf(rtb_TmpSignalConversionAtRP_S_o);

  /* Switch: '<S36>/Switch2' incorporates:
   *  Abs: '<S36>/Abs1'
   *  Constant: '<S36>/CAL_MPC_nTrqMonMax_f32'
   *  Constant: '<S36>/CAL_MPC_nTrqMonMin_f32'
   *  Constant: '<S36>/Constant4'
   *  RelationalOperator: '<S36>/Relational Operator2'
   *  RelationalOperator: '<S36>/Relational Operator3'
   *  UnitDelay: '<S36>/Unit Delay'
   */
  if (tmpRead_0 >= CAL_MPC_nTrqMonMax_f32) {
    SWC_MPC_DW.UnitDelay_DSTATE_lj = true;
  } else {
    SWC_MPC_DW.UnitDelay_DSTATE_lj = ((tmpRead_0 > CAL_MPC_nTrqMonMin_f32) &&
      SWC_MPC_DW.UnitDelay_DSTATE_lj);
  }

  /* End of Switch: '<S36>/Switch2' */

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/CAL_MPC_CofUdc_f32'
   *  Constant: '<S17>/CAL_MPC_Rcmp_f32'
   *  Constant: '<S17>/Constant'
   *  Gain: '<S17>/Gain'
   *  Gain: '<S17>/Gain1'
   *  Gain: '<S17>/Gain2'
   *  Product: '<S17>/Divide'
   *  Product: '<S17>/Divide1'
   *  Product: '<S17>/Product'
   *  Product: '<S17>/Product1'
   *  Product: '<S17>/Product2'
   *  Product: '<S17>/Product3'
   *  Sum: '<S17>/Add'
   *  Sum: '<S17>/Add1'
   *  Sum: '<S17>/Add2'
   *  Sum: '<S17>/Add3'
   *  UnitDelay: '<S24>/Unit Delay'
   *  UnitDelay: '<S25>/Unit Delay'
   *  UnitDelay: '<S36>/Unit Delay'
   */
  if (SWC_MPC_DW.UnitDelay_DSTATE_lj) {
    /* Sqrt: '<S21>/Sqrt' incorporates:
     *  Product: '<S21>/Product'
     *  Product: '<S21>/Product1'
     *  Sum: '<S21>/Add'
     *  UnitDelay: '<S24>/Unit Delay'
     *  UnitDelay: '<S25>/Unit Delay'
     */
    tmpRead_1 = sqrtf(SWC_MPC_DW.UnitDelay_DSTATE_i *
                      SWC_MPC_DW.UnitDelay_DSTATE_i +
                      SWC_MPC_DW.UnitDelay_DSTATE_b *
                      SWC_MPC_DW.UnitDelay_DSTATE_b);

    /* Saturate: '<S17>/Saturation' */
    if (tmpRead_1 > 10000.0F) {
      tmpRead_1 = 10000.0F;
    } else {
      if (tmpRead_1 < 0.0001F) {
        tmpRead_1 = 0.0001F;
      }
    }

    /* End of Saturate: '<S17>/Saturation' */

    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S36>/CAL_MPC_nSetTrqMonMin_f32'
     *  RelationalOperator: '<S36>/Relational Operator'
     */
    if (tmpRead_0 <= CAL_MPC_nSetTrqMonMin_f32) {
      /* Switch: '<S36>/Switch1' incorporates:
       *  Constant: '<S36>/Constant1'
       *  Gain: '<S36>/Gain3'
       *  RelationalOperator: '<S36>/Relational Operator1'
       */
      if (rtb_TmpSignalConversionAtRP_S_o < 0.0F) {
        rtb_Divide_o3 = -CAL_MPC_nSetTrqMonMin_f32;
      } else {
        rtb_Divide_o3 = CAL_MPC_nSetTrqMonMin_f32;
      }

      /* End of Switch: '<S36>/Switch1' */
    } else {
      rtb_Divide_o3 = rtb_TmpSignalConversionAtRP_S_o;
    }

    /* End of Switch: '<S36>/Switch' */
    VAR_MPC_TrqMon_f32 = ((SWC_MPC_DW.UnitDelay_DSTATE *
      SWC_MPC_DW.UnitDelay_DSTATE_i + SWC_MPC_DW.UnitDelay_DSTATE_e *
      SWC_MPC_DW.UnitDelay_DSTATE_b) * 1.5F * (1.0F -
      rtb_TmpSignalConversionAtRP_SWC * CAL_MPC_CofUdc_f32 / tmpRead_1) -
                          SWC_MPC_DW.UnitDelay_DSTATE_l *
                          SWC_MPC_DW.UnitDelay_DSTATE_l * (Switch_d +
      CAL_MPC_Rcmp_f32) * 1.5F) / rtb_Divide_o3 * 9.55F;
  } else {
    VAR_MPC_TrqMon_f32 = rtb_Abs1;
  }

  /* Lookup_n-D: '<S14>/CofRpwm_table' */
  VAR_MPC_CofRandomPwm_f32 = look1_iflf_binlcpw(tmpRead_0, ((const float32 *)
    &(CAL_MPC_nCofRpwm_X_af32[0])), ((const float32 *)&(CAL_MPC_cofRpwm_Y_af32[0])),
    16U);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_CofRandomPwm' incorporates:
   *  Sum: '<S14>/Add'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_CofRandomPwm(VAR_MPC_CofRandomPwm_f32);

  /* SwitchCase: '<S16>/Switch Case' */
  switch (rtb_TmpSignalConversionAtRP_S_p) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S16>/FwdMot_1' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_MPC_MPC_dtCorFac' incorporates:
     *  Abs: '<S16>/Abs'
     *  Lookup_n-D: '<S35>/1-D Lookup Table'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_dtCorFac(look1_iflf_binlcapw(fabsf
      (rtb_TmpSignalConversionAtRP_S_o), ((const float32 *)
      &(CAL_MPC_tCpnFwdMotTableX_n_af32[0])), ((const float32 *)
      &(CAL_MPC_tCpnFwdMotTableY_tCpn_af32[0])), 15U));

    /* End of Outputs for SubSystem: '<S16>/FwdMot_1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S16>/BwdGen_2' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_MPC_MPC_dtCorFac' incorporates:
     *  Abs: '<S16>/Abs'
     *  Lookup_n-D: '<S31>/1-D Lookup Table'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_dtCorFac(look1_iflf_binlcapw(fabsf
      (rtb_TmpSignalConversionAtRP_S_o), ((const float32 *)
      &(CAL_MPC_tCpnBwdGenTableX_n_af32[0])), ((const float32 *)
      &(CAL_MPC_tCpnBwdGenTableY_tCpn_af32[0])), 15U));

    /* End of Outputs for SubSystem: '<S16>/BwdGen_2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S16>/BwdMot_3' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_MPC_MPC_dtCorFac' incorporates:
     *  Abs: '<S16>/Abs'
     *  Lookup_n-D: '<S32>/1-D Lookup Table'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_dtCorFac(look1_iflf_binlcapw(fabsf
      (rtb_TmpSignalConversionAtRP_S_o), ((const float32 *)
      &(CAL_MPC_tCpnBwdMotTableX_n_af32[0])), ((const float32 *)
      &(CAL_MPC_tCpnBwdMotTableY_tCpn_af32[0])), 15U));

    /* End of Outputs for SubSystem: '<S16>/BwdMot_3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S16>/FwdGen_4' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_MPC_MPC_dtCorFac' incorporates:
     *  Abs: '<S16>/Abs'
     *  Lookup_n-D: '<S34>/1-D Lookup Table'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_dtCorFac(look1_iflf_binlcapw(fabsf
      (rtb_TmpSignalConversionAtRP_S_o), ((const float32 *)
      &(CAL_MPC_tCpnFwdGenTableX_n_af32[0])), ((const float32 *)
      &(CAL_MPC_tCpnFwdGenTableY_tCpn_af32[0])), 15U));

    /* End of Outputs for SubSystem: '<S16>/FwdGen_4' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S16>/FwdGen_1' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Outport: '<Root>/PP_SWC_MPC_MPC_dtCorFac' incorporates:
     *  Constant: '<S33>/Constant'
     *  SignalConversion generated from: '<S33>/tiLockDyc'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_dtCorFac(0.6F);

    /* End of Outputs for SubSystem: '<S16>/FwdGen_1' */
    break;
  }

  /* End of SwitchCase: '<S16>/Switch Case' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Inport: '<Root>/RP_SWC_TDC_TDC_TrqDes' */
  Rte_Read_RP_SWC_TDC_TDC_TrqDes(&tmpRead_2);

  /* Inport: '<Root>/RP_SWC_MCF_MCF_VoltModuRate' */
  Rte_Read_RP_SWC_MCF_MCF_VoltModuRate(&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Lookup_n-D: '<S18>/VFTable' incorporates:
   *  Constant: '<S18>/Constant'
   *  Inport: '<Root>/RP_SWC_MCF_MCF_VoltModuRate'
   *  Product: '<S18>/Divide'
   */
  VAR_MPC_frqPwmVF_f32 = look2_iflf_binlcapw(tmpRead,
    rtb_TmpSignalConversionAtRP__jh / MPC_GLB_SqrtTwo_f32, ((const float32 *)
    &(CAL_MPC_frqPwmVFTableY_VoltModuRate_af32[0])), ((const float32 *)
    &(CAL_MPC_frqPwmVFTableX_Is_af32[0])), ((const float32 *)
    &(CAL_MPC_frqPwmVFTableZ_Frq_af32[0])), rtCP_VFTable_maxIndex, 13U);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_frqPwmVF' incorporates:
   *  Sum: '<S18>/Add'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_frqPwmVF(VAR_MPC_frqPwmVF_f32);

  /* Abs: '<S19>/Abs' */
  rtb_Divide_o3 = fabsf(tmpRead_2);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_isdMTPA' incorporates:
   *  Lookup_n-D: '<S19>/MPC_MtpaTable_Trq'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_isdMTPA(look1_iflf_binlxpw(rtb_Divide_o3, ((
    const float32 *)&(CAL_MPC_MtpaTableX_Trq_af32[0])), ((const float32 *)
    &(CAL_MPC_MtpaTableY_isd_af32[0])), 14U));

  /* Outport: '<Root>/PP_SWC_MPC_MPC_OmBw' incorporates:
   *  Lookup_n-D: '<S19>/MPC_Ombw_Table'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_OmBw(look1_iflf_binlcapw(tmpRead_0, ((const
    float32 *)&(CAL_MPC_OmbwTableX_Spd_af32[0])), ((const float32 *)
    &(CAL_MPC_OmbwTableY_Ombw_af32[0])), 10U));

  /* Outport: '<Root>/PP_SWC_MPC_MPC_Rv' incorporates:
   *  Lookup_n-D: '<S19>/MPC_Rv_Table'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_Rv(look1_iflf_binlcapw(tmpRead_0, ((const
    float32 *)&(CAL_MPC_RvTableX_Spd_af32[0])), ((const float32 *)
    &(CAL_MPC_RvTableY_Rv_af32[0])), 10U));

  /* Lookup_n-D: '<S19>/MPC_isdFFTable_isd' */
  rtb_Divide_o3 = look2_iflf_binlxpw(tmpRead_0, rtb_Divide_o3, ((const float32 *)
    &(CAL_MPC_isdFFTableX_Spd_af32[0])), ((const float32 *)
    &(CAL_MPC_isdFFTableY_Trq_af32[0])), ((const float32 *)
    &(CAL_MPC_isdFFTableZ_isd_af32[0])), rtCP_MPC_isdFFTable_isd_maxInde, 17U);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_isdFF' incorporates:
   *  Lookup_n-D: '<S19>/MPC_isdFFTable_UdcCof'
   *  Product: '<S19>/Product'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_isdFF(look1_iflf_binlxpw
    (rtb_TmpSignalConversionAtRP_SWC, ((const float32 *)
    &(CAL_MPC_isdFFTableX_Udc_af32[0])), ((const float32 *)
    &(CAL_MPC_isdFFTableY_UdcCof_af32[0])), 7U) * rtb_Divide_o3);

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  Logic: '<S19>/Logical Operator'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   */
  if ((rtb_TmpSignalConversionAtRP_S_p == 1) || (rtb_TmpSignalConversionAtRP_S_p
       == 3)) {
    /* Outport: '<Root>/PP_SWC_MPC_MPC_isdMTPV' incorporates:
     *  Lookup_n-D: '<S19>/MTPV_Mot'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_isdMTPV(look2_iflf_binlxpw
      (rtb_TmpSignalConversionAtRP_SWC, tmpRead_0, ((const float32 *)
      &(CAL_MPC_MtpvTableX_Udc_af32[0])), ((const float32 *)
      &(CAL_MPC_MtpvTableY_N_af32[0])), ((const float32 *)
      &(CAL_MPC_MtpvTableZ_idMot_af32[0])), rtCP_MTPV_Mot_maxIndex, 8U));
  } else {
    /* Outport: '<Root>/PP_SWC_MPC_MPC_isdMTPV' incorporates:
     *  Lookup_n-D: '<S19>/MTPV_Gen'
     */
    (void) Rte_Write_PP_SWC_MPC_MPC_isdMTPV(look2_iflf_binlxpw
      (rtb_TmpSignalConversionAtRP_SWC, tmpRead_0, ((const float32 *)
      &(CAL_MPC_MtpvTableX_Udc_af32[0])), ((const float32 *)
      &(CAL_MPC_MtpvTableY_N_af32[0])), ((const float32 *)
      &(CAL_MPC_MtpvTableZ_idGen_af32[0])), rtCP_MTPV_Gen_maxIndex, 8U));
  }

  /* End of Switch: '<S19>/Switch' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Outport: '<Root>/PP_SWC_MPC_MPC_LdSubLq' */
  (void) Rte_Write_PP_SWC_MPC_MPC_LdSubLq(Switch4);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_Ld' */
  (void) Rte_Write_PP_SWC_MPC_MPC_Ld(Switch);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_Lq' */
  (void) Rte_Write_PP_SWC_MPC_MPC_Lq(Switch3);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_Rs' */
  (void) Rte_Write_PP_SWC_MPC_MPC_Rs(Switch_d);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_TrqMech' */
  (void) Rte_Write_PP_SWC_MPC_MPC_TrqMech(rtb_Abs1);

  /* RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* Outport: '<Root>/PP_SWC_MPC_MPC_Psi' incorporates:
   *  Constant: '<S7>/CAL_MPC_Psi_f32'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_Psi(CAL_MPC_Psi_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */

  /* Outport: '<Root>/PP_SWC_MPC_MPC_IsFlt' */
  (void) Rte_Write_PP_SWC_MPC_MPC_IsFlt(SWC_MPC_DW.UnitDelay_DSTATE_l);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_isdFlt' */
  (void) Rte_Write_PP_SWC_MPC_MPC_isdFlt(SWC_MPC_DW.UnitDelay_DSTATE);

  /* Outport: '<Root>/PP_SWC_MPC_MPC_isqFlt' */
  (void) Rte_Write_PP_SWC_MPC_MPC_isqFlt(SWC_MPC_DW.UnitDelay_DSTATE_e);
  GLB_MPC_idAct_f32 = SWC_MPC_DW.UnitDelay_DSTATE;
  GLB_MPC_iqAct_f32 = SWC_MPC_DW.UnitDelay_DSTATE_e;
}

/* Model initialize function */
void SWC_MPC_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' incorporates:
   *  SubSystem: '<Root>/RE_SWC_MPC_2ms_sys'
   */
  /* SystemInitialize for Outport: '<Root>/PP_SWC_MPC_MPC_Psi' incorporates:
   *  Constant: '<S7>/CAL_MPC_Psi_f32'
   */
  (void) Rte_Write_PP_SWC_MPC_MPC_Psi(CAL_MPC_Psi_f32);

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/RE_SWC_MPC_2ms' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
