/*
 * File: SWC_SWD.c
 *
 * Code generated for Simulink model 'SWC_SWD'.
 *
 * Model version                  : 1.555
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Jan 12 17:55:55 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWC_SWD.h"
#include "SWC_SWD_private.h"

/* user code (top of source file) */
#include "set_get_data.h"

/* Exported block signals */
float32 VAR_SWD_Spd_f32;               /* '<S13>/Divide' */
float32 VAR_SWD_AgRslvDelta0_f32;      /* '<S12>/Add2' */
float32 VAR_SWD_AgRslvDelta_f32;       /* '<S12>/Switch2' */
float32 VAR_SWD_Tan_f32;               /* '<S6>/Abs2' */
float32 VAR_SWD_AgRslv45_f32;          /* '<S5>/Data Type Conversion1' */
float32 VAR_SWD_AgRslv_f32;            /* '<S5>/Switch' */

/* Exported data definition */
#pragma section ".rodata.Calib_32"

/* Definition for custom storage class: iEDS_Parameter */
const volatile float32 CAL_SWD_AgrslvCompCnt_f32 = 2200.0F;
                           /* Referenced by: '<S5>/CAL_SWD_AgrslvCompCnt_f32' */
const volatile uint8 CAL_SWD_MotorPole_u8 = 4U;
                               /* Referenced by: '<S13>/GLB_TOM_MotorPole_u8' */
const volatile uint16 CAL_SWD_Radian_u16[1025] = { 0U, 64U, 128U, 192U, 256U,
  320U, 384U, 448U, 512U, 576U, 640U, 704U, 768U, 832U, 896U, 960U, 1024U, 1088U,
  1152U, 1216U, 1280U, 1344U, 1408U, 1472U, 1536U, 1600U, 1664U, 1728U, 1792U,
  1855U, 1919U, 1983U, 2047U, 2111U, 2175U, 2239U, 2303U, 2367U, 2431U, 2495U,
  2559U, 2623U, 2686U, 2750U, 2814U, 2878U, 2942U, 3006U, 3070U, 3134U, 3197U,
  3261U, 3325U, 3389U, 3453U, 3517U, 3580U, 3644U, 3708U, 3772U, 3836U, 3899U,
  3963U, 4027U, 4091U, 4154U, 4218U, 4282U, 4346U, 4409U, 4473U, 4537U, 4600U,
  4664U, 4728U, 4791U, 4855U, 4919U, 4982U, 5046U, 5110U, 5173U, 5237U, 5300U,
  5364U, 5427U, 5491U, 5555U, 5618U, 5682U, 5745U, 5809U, 5872U, 5936U, 5999U,
  6063U, 6126U, 6189U, 6253U, 6316U, 6380U, 6443U, 6506U, 6570U, 6633U, 6696U,
  6760U, 6823U, 6886U, 6950U, 7013U, 7076U, 7140U, 7203U, 7266U, 7329U, 7392U,
  7456U, 7519U, 7582U, 7645U, 7708U, 7771U, 7834U, 7897U, 7960U, 8024U, 8087U,
  8150U, 8213U, 8276U, 8339U, 8402U, 8464U, 8527U, 8590U, 8653U, 8716U, 8779U,
  8842U, 8905U, 8967U, 9030U, 9093U, 9156U, 9219U, 9281U, 9344U, 9407U, 9469U,
  9532U, 9595U, 9657U, 9720U, 9783U, 9845U, 9908U, 9970U, 10033U, 10095U, 10158U,
  10220U, 10283U, 10345U, 10407U, 10470U, 10532U, 10595U, 10657U, 10719U, 10782U,
  10844U, 10906U, 10968U, 11030U, 11093U, 11155U, 11217U, 11279U, 11341U, 11403U,
  11465U, 11527U, 11589U, 11651U, 11713U, 11775U, 11837U, 11899U, 11961U, 12023U,
  12085U, 12147U, 12209U, 12270U, 12332U, 12394U, 12456U, 12517U, 12579U, 12641U,
  12702U, 12764U, 12826U, 12887U, 12949U, 13010U, 13072U, 13133U, 13195U, 13256U,
  13317U, 13379U, 13440U, 13501U, 13563U, 13624U, 13685U, 13747U, 13808U, 13869U,
  13930U, 13991U, 14052U, 14113U, 14175U, 14236U, 14297U, 14358U, 14419U, 14479U,
  14540U, 14601U, 14662U, 14723U, 14784U, 14845U, 14905U, 14966U, 15027U, 15087U,
  15148U, 15209U, 15269U, 15330U, 15390U, 15451U, 15511U, 15572U, 15632U, 15693U,
  15753U, 15814U, 15874U, 15934U, 15994U, 16055U, 16115U, 16175U, 16235U, 16295U,
  16356U, 16416U, 16476U, 16536U, 16596U, 16656U, 16716U, 16775U, 16835U, 16895U,
  16955U, 17015U, 17075U, 17134U, 17194U, 17254U, 17313U, 17373U, 17433U, 17492U,
  17552U, 17611U, 17671U, 17730U, 17790U, 17849U, 17908U, 17968U, 18027U, 18086U,
  18145U, 18205U, 18264U, 18323U, 18382U, 18441U, 18500U, 18559U, 18618U, 18677U,
  18736U, 18795U, 18854U, 18913U, 18971U, 19030U, 19089U, 19148U, 19206U, 19265U,
  19324U, 19382U, 19441U, 19499U, 19558U, 19616U, 19674U, 19733U, 19791U, 19850U,
  19908U, 19966U, 20024U, 20083U, 20141U, 20199U, 20257U, 20315U, 20373U, 20431U,
  20489U, 20547U, 20605U, 20663U, 20720U, 20778U, 20836U, 20894U, 20951U, 21009U,
  21067U, 21124U, 21182U, 21239U, 21297U, 21354U, 21412U, 21469U, 21527U, 21584U,
  21641U, 21698U, 21756U, 21813U, 21870U, 21927U, 21984U, 22041U, 22098U, 22155U,
  22212U, 22269U, 22326U, 22383U, 22440U, 22496U, 22553U, 22610U, 22666U, 22723U,
  22780U, 22836U, 22893U, 22949U, 23006U, 23062U, 23118U, 23175U, 23231U, 23287U,
  23344U, 23400U, 23456U, 23512U, 23568U, 23624U, 23680U, 23736U, 23792U, 23848U,
  23904U, 23960U, 24016U, 24071U, 24127U, 24183U, 24238U, 24294U, 24350U, 24405U,
  24461U, 24516U, 24572U, 24627U, 24682U, 24738U, 24793U, 24848U, 24903U, 24959U,
  25014U, 25069U, 25124U, 25179U, 25234U, 25289U, 25344U, 25399U, 25453U, 25508U,
  25563U, 25618U, 25672U, 25727U, 25782U, 25836U, 25891U, 25945U, 26000U, 26054U,
  26109U, 26163U, 26217U, 26272U, 26326U, 26380U, 26434U, 26488U, 26542U, 26596U,
  26650U, 26704U, 26758U, 26812U, 26866U, 26920U, 26974U, 27027U, 27081U, 27135U,
  27188U, 27242U, 27295U, 27349U, 27402U, 27456U, 27509U, 27563U, 27616U, 27669U,
  27722U, 27776U, 27829U, 27882U, 27935U, 27988U, 28041U, 28094U, 28147U, 28200U,
  28253U, 28305U, 28358U, 28411U, 28464U, 28516U, 28569U, 28621U, 28674U, 28726U,
  28779U, 28831U, 28884U, 28936U, 28988U, 29040U, 29093U, 29145U, 29197U, 29249U,
  29301U, 29353U, 29405U, 29457U, 29509U, 29561U, 29613U, 29664U, 29716U, 29768U,
  29820U, 29871U, 29923U, 29974U, 30026U, 30077U, 30129U, 30180U, 30231U, 30283U,
  30334U, 30385U, 30436U, 30487U, 30539U, 30590U, 30641U, 30692U, 30743U, 30793U,
  30844U, 30895U, 30946U, 30997U, 31047U, 31098U, 31149U, 31199U, 31250U, 31300U,
  31351U, 31401U, 31451U, 31502U, 31552U, 31602U, 31653U, 31703U, 31753U, 31803U,
  31853U, 31903U, 31953U, 32003U, 32053U, 32103U, 32153U, 32202U, 32252U, 32302U,
  32351U, 32401U, 32451U, 32500U, 32550U, 32599U, 32648U, 32698U, 32747U, 32796U,
  32846U, 32895U, 32944U, 32993U, 33042U, 33091U, 33140U, 33189U, 33238U, 33287U,
  33336U, 33385U, 33433U, 33482U, 33531U, 33579U, 33628U, 33677U, 33725U, 33774U,
  33822U, 33870U, 33919U, 33967U, 34015U, 34064U, 34112U, 34160U, 34208U, 34256U,
  34304U, 34352U, 34400U, 34448U, 34496U, 34544U, 34591U, 34639U, 34687U, 34735U,
  34782U, 34830U, 34877U, 34925U, 34972U, 35020U, 35067U, 35114U, 35162U, 35209U,
  35256U, 35303U, 35350U, 35398U, 35445U, 35492U, 35539U, 35586U, 35632U, 35679U,
  35726U, 35773U, 35820U, 35866U, 35913U, 35960U, 36006U, 36053U, 36099U, 36146U,
  36192U, 36238U, 36285U, 36331U, 36377U, 36423U, 36470U, 36516U, 36562U, 36608U,
  36654U, 36700U, 36746U, 36792U, 36837U, 36883U, 36929U, 36975U, 37020U, 37066U,
  37112U, 37157U, 37203U, 37248U, 37294U, 37339U, 37384U, 37430U, 37475U, 37520U,
  37565U, 37611U, 37656U, 37701U, 37746U, 37791U, 37836U, 37881U, 37925U, 37970U,
  38015U, 38060U, 38105U, 38149U, 38194U, 38238U, 38283U, 38328U, 38372U, 38416U,
  38461U, 38505U, 38550U, 38594U, 38638U, 38682U, 38726U, 38770U, 38815U, 38859U,
  38903U, 38947U, 38990U, 39034U, 39078U, 39122U, 39166U, 39209U, 39253U, 39297U,
  39340U, 39384U, 39427U, 39471U, 39514U, 39558U, 39601U, 39644U, 39688U, 39731U,
  39774U, 39817U, 39860U, 39904U, 39947U, 39990U, 40033U, 40075U, 40118U, 40161U,
  40204U, 40247U, 40289U, 40332U, 40375U, 40417U, 40460U, 40503U, 40545U, 40587U,
  40630U, 40672U, 40715U, 40757U, 40799U, 40841U, 40884U, 40926U, 40968U, 41010U,
  41052U, 41094U, 41136U, 41178U, 41220U, 41261U, 41303U, 41345U, 41387U, 41428U,
  41470U, 41512U, 41553U, 41595U, 41636U, 41678U, 41719U, 41760U, 41802U, 41843U,
  41884U, 41925U, 41967U, 42008U, 42049U, 42090U, 42131U, 42172U, 42213U, 42254U,
  42295U, 42335U, 42376U, 42417U, 42458U, 42498U, 42539U, 42580U, 42620U, 42661U,
  42701U, 42742U, 42782U, 42822U, 42863U, 42903U, 42943U, 42983U, 43024U, 43064U,
  43104U, 43144U, 43184U, 43224U, 43264U, 43304U, 43344U, 43383U, 43423U, 43463U,
  43503U, 43542U, 43582U, 43622U, 43661U, 43701U, 43740U, 43780U, 43819U, 43859U,
  43898U, 43937U, 43976U, 44016U, 44055U, 44094U, 44133U, 44172U, 44211U, 44250U,
  44289U, 44328U, 44367U, 44406U, 44445U, 44484U, 44522U, 44561U, 44600U, 44638U,
  44677U, 44716U, 44754U, 44793U, 44831U, 44870U, 44908U, 44946U, 44985U, 45023U,
  45061U, 45099U, 45137U, 45176U, 45214U, 45252U, 45290U, 45328U, 45366U, 45404U,
  45441U, 45479U, 45517U, 45555U, 45593U, 45630U, 45668U, 45706U, 45743U, 45781U,
  45818U, 45856U, 45893U, 45930U, 45968U, 46005U, 46042U, 46080U, 46117U, 46154U,
  46191U, 46228U, 46265U, 46303U, 46340U, 46377U, 46413U, 46450U, 46487U, 46524U,
  46561U, 46598U, 46634U, 46671U, 46708U, 46744U, 46781U, 46817U, 46854U, 46890U,
  46927U, 46963U, 47000U, 47036U, 47072U, 47109U, 47145U, 47181U, 47217U, 47253U,
  47289U, 47325U, 47361U, 47397U, 47433U, 47469U, 47505U, 47541U, 47577U, 47613U,
  47648U, 47684U, 47720U, 47755U, 47791U, 47826U, 47862U, 47898U, 47933U, 47968U,
  48004U, 48039U, 48075U, 48110U, 48145U, 48180U, 48215U, 48251U, 48286U, 48321U,
  48356U, 48391U, 48426U, 48461U, 48496U, 48531U, 48566U, 48600U, 48635U, 48670U,
  48705U, 48739U, 48774U, 48809U, 48843U, 48878U, 48912U, 48947U, 48981U, 49015U,
  49050U, 49084U, 49119U, 49153U, 49187U, 49221U, 49255U, 49290U, 49324U, 49358U,
  49392U, 49426U, 49460U, 49494U, 49528U, 49562U, 49595U, 49629U, 49663U, 49697U,
  49730U, 49764U, 49798U, 49831U, 49865U, 49899U, 49932U, 49966U, 49999U, 50032U,
  50066U, 50099U, 50132U, 50166U, 50199U, 50232U, 50265U, 50299U, 50332U, 50365U,
  50398U, 50431U, 50464U, 50497U, 50530U, 50563U, 50596U, 50628U, 50661U, 50694U,
  50727U, 50759U, 50792U, 50825U, 50857U, 50890U, 50923U, 50955U, 50988U, 51020U,
  51052U, 51085U, 51117U, 51150U, 51182U, 51214U, 51246U, 51279U, 51311U, 51343U,
  51375U, 51407U, 51439U, 51471U } ;
                           /* Referenced by: '<S5>/Direct Lookup Table (n-D)' */

#pragma section
#pragma section ".data.CPU1_32"
/* Block states (default storage) */
DW_SWC_SWD_T SWC_SWD_DW;

/* Real-time model */
RT_MODEL_SWC_SWD_T SWC_SWD_M_;
RT_MODEL_SWC_SWD_T *const SWC_SWD_M = &SWC_SWD_M_;
#pragma section
/* Outputs for atomic system: '<S3>/AgRslvCalc' */
#pragma section ".text.CPU1_Code" ax
void SWC_SWD_AgRslvCalc(void)
{
  float32 rtb_MultiportSwitch;

  /* Switch: '<S5>/Switch2' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S5>/Constant2'
   *  Product: '<S5>/Divide1'
   *  RelationalOperator: '<S10>/Compare'
   */
  if (VAR_SWD_Tan_f32 >= 1.0F) {
    rtb_MultiportSwitch = 1.0F / VAR_SWD_Tan_f32;
  } else {
    rtb_MultiportSwitch = VAR_SWD_Tan_f32;
  }

  /* End of Switch: '<S5>/Switch2' */

  /* DataTypeConversion: '<S5>/Data Type Conversion1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant11'
   *  Constant: '<S5>/Constant6'
   *  Gain: '<S5>/Gain'
   *  LookupNDDirect: '<S5>/Direct Lookup Table (n-D)'
   *  Product: '<S5>/Divide'
   *
   * About '<S5>/Direct Lookup Table (n-D)':
   *  1-dimensional Direct Look-Up returning a Scalar,
   *
   *     Remove protection against out-of-range input in generated code: 'on'
   */
  VAR_SWD_AgRslv45_f32 = (float32)CAL_SWD_Radian_u16[(sint32)(1024.0F *
    rtb_MultiportSwitch)] * 180.0F / GLB_SWD_pi_f32 / 65535.0F;

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Constant: '<S5>/Constant10'
   *  Constant: '<S5>/Constant3'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S5>/Constant7'
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/Constant9'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  Inport: '<Root>/L2Sampling_RslvCos'
   *  Inport: '<Root>/L2Sampling_RslvSin'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Sum: '<S5>/Add'
   *  Sum: '<S5>/Add1'
   *  Sum: '<S5>/Add2'
   *  Sum: '<S5>/Add3'
   *  Sum: '<S5>/Add5'
   *  Sum: '<S5>/Add6'
   *  Sum: '<S5>/Add7'
   *  Sum: '<S5>/Add8'
   */
  switch ((sint32)(((uint32)((get_L2Sampling_RslvCos() >= 0.0F) << 1) +
                    (get_L2Sampling_RslvSin() >= 0.0F)) + ((VAR_SWD_Tan_f32 >=
             1.0F) << 2))) {
   case 0:
    rtb_MultiportSwitch = VAR_SWD_AgRslv45_f32 + 180.0F;
    break;

   case 1:
    rtb_MultiportSwitch = 180.0F - VAR_SWD_AgRslv45_f32;
    break;

   case 2:
    rtb_MultiportSwitch = 360.0F - VAR_SWD_AgRslv45_f32;
    break;

   case 3:
    rtb_MultiportSwitch = VAR_SWD_AgRslv45_f32;
    break;

   case 4:
    rtb_MultiportSwitch = 270.0F - VAR_SWD_AgRslv45_f32;
    break;

   case 5:
    rtb_MultiportSwitch = VAR_SWD_AgRslv45_f32 + 90.0F;
    break;

   case 6:
    rtb_MultiportSwitch = VAR_SWD_AgRslv45_f32 + 270.0F;
    break;

   default:
    rtb_MultiportSwitch = 90.0F - VAR_SWD_AgRslv45_f32;
    break;
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

  /* Sum: '<S5>/Add11' incorporates:
   *  Constant: '<S5>/CAL_SWD_AgrslvCompCnt_f32'
   *  Constant: '<S5>/GLB_SWD_CircAge_f32'
   *  Constant: '<S5>/GLB_SWD_MotorPole_u8'
   *  Constant: '<S5>/GLB_SWD_Sixty_f32'
   *  Constant: '<S5>/const'
   *  Product: '<S5>/Divide2'
   *  Product: '<S5>/Divide3'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  VAR_SWD_AgRslv_f32 = get_SWD_Spd() * CAL_SWD_AgrslvCompCnt_f32 * (float32)
    ((uint8)GLB_SWD_MotorPole_u8) * GLB_SWD_CircAge_f32 / GLB_SWD_Sixty_f32 *
    1.0E-8F + rtb_MultiportSwitch;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/GLB_TOM_CircAge_f1'
   *  RelationalOperator: '<S5>/Relational Operator'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  Sum: '<S5>/Add9'
   *  Switch: '<S5>/Switch3'
   */
  if (GLB_SWD_CircAge_f32 <= VAR_SWD_AgRslv_f32) {
    VAR_SWD_AgRslv_f32 -= GLB_SWD_CircAge_f32;
  } else {
    if (VAR_SWD_AgRslv_f32 <= 0.0F) {
      /* Switch: '<S5>/Switch3' incorporates:
       *  Constant: '<S5>/GLB_TOM_CircAge_f2'
       *  Sum: '<S5>/Add10'
       */
      VAR_SWD_AgRslv_f32 += GLB_SWD_CircAge_f32;
    }
  }

  /* End of Switch: '<S5>/Switch' */
}

/* Output and update for atomic system: '<S3>/TanCalc' */
void SWC_SWD_TanCalc(void)
{
  float32 tmp;

  /* Switch: '<S6>/Switch1' incorporates:
   *  Abs: '<S6>/Abs1'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Inport: '<Root>/L2Sampling_RslvCos'
   *  RelationalOperator: '<S11>/Compare'
   */
  if (fabsf(get_L2Sampling_RslvCos()) <= 0.0001F) {
    tmp = 0.0001F;
  } else {
    tmp = get_L2Sampling_RslvCos();
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Abs: '<S6>/Abs2' incorporates:
   *  Inport: '<Root>/L2Sampling_RslvSin'
   *  Product: '<S6>/Divide'
   */
  VAR_SWD_Tan_f32 = fabsf(get_L2Sampling_RslvSin() / tmp);
}

/* Output and update for atomic system: '<S4>/AgRslvDeltaCalc' */
void SWC_SWD_AgRslvDeltaCalc(void)
{
  float32 rtb_Divide_f;

  /* Sum: '<S12>/Add2' incorporates:
   *  UnitDelay: '<S12>/Unit Delay'
   */
  VAR_SWD_AgRslvDelta0_f32 = VAR_SWD_AgRslv_f32 - SWC_SWD_DW.UnitDelay_DSTATE;

  /* Product: '<S12>/Divide' incorporates:
   *  Constant: '<S12>/GLB_TOM_CircAge_f5'
   *  Constant: '<S12>/GLB_TOM_CircAge_f6'
   */
  rtb_Divide_f = GLB_SWD_CircAge_f32 * GLB_SWD_OneHalf_f32;

  /* Switch: '<S12>/Switch2' incorporates:
   *  Constant: '<S12>/GLB_TOM_CircAge_f1'
   *  Gain: '<S12>/Gain1'
   *  RelationalOperator: '<S12>/Relational Operator2'
   *  RelationalOperator: '<S12>/Relational Operator3'
   *  Sum: '<S12>/Add3'
   *  Switch: '<S12>/Switch3'
   */
  if (VAR_SWD_AgRslvDelta0_f32 > rtb_Divide_f) {
    VAR_SWD_AgRslvDelta_f32 = VAR_SWD_AgRslvDelta0_f32 - GLB_SWD_CircAge_f32;
  } else if (VAR_SWD_AgRslvDelta0_f32 < -rtb_Divide_f) {
    /* Switch: '<S12>/Switch3' incorporates:
     *  Constant: '<S12>/GLB_TOM_CircAge_f2'
     *  Sum: '<S12>/Add4'
     */
    VAR_SWD_AgRslvDelta_f32 = VAR_SWD_AgRslvDelta0_f32 + GLB_SWD_CircAge_f32;
  } else {
    /* Switch: '<S12>/Switch3' */
    VAR_SWD_AgRslvDelta_f32 = VAR_SWD_AgRslvDelta0_f32;
  }

  /* End of Switch: '<S12>/Switch2' */

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  SWC_SWD_DW.UnitDelay_DSTATE = VAR_SWD_AgRslv_f32;
}

/* Output and update for atomic system: '<S4>/SpdCalc' */
void SWC_SWD_SpdCalc(void)
{
  int_T idxDelay;
  float32 rtb_Add7_k;

  /* Sum: '<S13>/Add7' incorporates:
   *  Delay: '<S13>/Delay1'
   *  Delay: '<S13>/Delay10'
   *  Delay: '<S13>/Delay2'
   *  Delay: '<S13>/Delay3'
   *  Delay: '<S13>/Delay4'
   *  Delay: '<S13>/Delay5'
   *  Delay: '<S13>/Delay6'
   *  Delay: '<S13>/Delay7'
   *  Delay: '<S13>/Delay9'
   */
  rtb_Add7_k = ((((((((VAR_SWD_AgRslvDelta_f32 + SWC_SWD_DW.Delay1_DSTATE) +
                      SWC_SWD_DW.Delay10_DSTATE[0]) + SWC_SWD_DW.Delay9_DSTATE[0])
                    + SWC_SWD_DW.Delay7_DSTATE[0]) + SWC_SWD_DW.Delay6_DSTATE[0])
                  + SWC_SWD_DW.Delay5_DSTATE[0]) + SWC_SWD_DW.Delay4_DSTATE[0])
                + SWC_SWD_DW.Delay3_DSTATE[0]) + SWC_SWD_DW.Delay2_DSTATE[0];

  /* Delay: '<S13>/Delay12' incorporates:
   *  Delay: '<S13>/Delay1'
   */
  SWC_SWD_DW.Delay1_DSTATE = SWC_SWD_DW.Delay12_DSTATE[0];

  /* Product: '<S13>/Divide' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant10'
   *  Constant: '<S13>/GLB_TOM_MotorPole_u8'
   *  Delay: '<S13>/Delay1'
   *  Delay: '<S13>/Delay11'
   *  Delay: '<S13>/Delay13'
   *  Delay: '<S13>/Delay14'
   *  Delay: '<S13>/Delay15'
   *  Delay: '<S13>/Delay16'
   *  Delay: '<S13>/Delay17'
   *  Delay: '<S13>/Delay18'
   *  Delay: '<S13>/Delay8'
   *  Gain: '<S13>/Gain4'
   *  Sum: '<S13>/Add6'
   */
  VAR_SWD_Spd_f32 = (((((((((rtb_Add7_k + SWC_SWD_DW.Delay8_DSTATE) +
    SWC_SWD_DW.Delay11_DSTATE[0]) + SWC_SWD_DW.Delay18_DSTATE[0]) +
    SWC_SWD_DW.Delay17_DSTATE[0]) + SWC_SWD_DW.Delay16_DSTATE[0]) +
                        SWC_SWD_DW.Delay15_DSTATE[0]) +
                       SWC_SWD_DW.Delay14_DSTATE[0]) +
                      SWC_SWD_DW.Delay13_DSTATE[0]) + SWC_SWD_DW.Delay1_DSTATE) *
    0.166666672F / 100.0F / (float32)CAL_SWD_MotorPole_u8 / 0.0001024F;

  /* Update for Delay: '<S13>/Delay1' */
  SWC_SWD_DW.Delay1_DSTATE = VAR_SWD_AgRslvDelta_f32;

  /* Update for Delay: '<S13>/Delay10' */
  SWC_SWD_DW.Delay10_DSTATE[0] = SWC_SWD_DW.Delay10_DSTATE[1];
  SWC_SWD_DW.Delay10_DSTATE[1] = VAR_SWD_AgRslvDelta_f32;

  /* Update for Delay: '<S13>/Delay9' */
  SWC_SWD_DW.Delay9_DSTATE[0] = SWC_SWD_DW.Delay9_DSTATE[1];
  SWC_SWD_DW.Delay9_DSTATE[1] = SWC_SWD_DW.Delay9_DSTATE[2];
  SWC_SWD_DW.Delay9_DSTATE[2] = VAR_SWD_AgRslvDelta_f32;

  /* Update for Delay: '<S13>/Delay7' */
  SWC_SWD_DW.Delay7_DSTATE[0] = SWC_SWD_DW.Delay7_DSTATE[1];
  SWC_SWD_DW.Delay7_DSTATE[1] = SWC_SWD_DW.Delay7_DSTATE[2];
  SWC_SWD_DW.Delay7_DSTATE[2] = SWC_SWD_DW.Delay7_DSTATE[3];
  SWC_SWD_DW.Delay7_DSTATE[3] = VAR_SWD_AgRslvDelta_f32;

  /* Update for Delay: '<S13>/Delay6' */
  SWC_SWD_DW.Delay6_DSTATE[0] = SWC_SWD_DW.Delay6_DSTATE[1];
  SWC_SWD_DW.Delay6_DSTATE[1] = SWC_SWD_DW.Delay6_DSTATE[2];
  SWC_SWD_DW.Delay6_DSTATE[2] = SWC_SWD_DW.Delay6_DSTATE[3];
  SWC_SWD_DW.Delay6_DSTATE[3] = SWC_SWD_DW.Delay6_DSTATE[4];
  SWC_SWD_DW.Delay6_DSTATE[4] = VAR_SWD_AgRslvDelta_f32;

  /* Update for Delay: '<S13>/Delay5' */
  for (idxDelay = 0; idxDelay < 5; idxDelay++) {
    SWC_SWD_DW.Delay5_DSTATE[idxDelay] = SWC_SWD_DW.Delay5_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay5_DSTATE[5] = VAR_SWD_AgRslvDelta_f32;

  /* End of Update for Delay: '<S13>/Delay5' */

  /* Update for Delay: '<S13>/Delay4' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    SWC_SWD_DW.Delay4_DSTATE[idxDelay] = SWC_SWD_DW.Delay4_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay4_DSTATE[6] = VAR_SWD_AgRslvDelta_f32;

  /* End of Update for Delay: '<S13>/Delay4' */

  /* Update for Delay: '<S13>/Delay3' */
  for (idxDelay = 0; idxDelay < 7; idxDelay++) {
    SWC_SWD_DW.Delay3_DSTATE[idxDelay] = SWC_SWD_DW.Delay3_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay3_DSTATE[7] = VAR_SWD_AgRslvDelta_f32;

  /* End of Update for Delay: '<S13>/Delay3' */

  /* Update for Delay: '<S13>/Delay2' */
  for (idxDelay = 0; idxDelay < 8; idxDelay++) {
    SWC_SWD_DW.Delay2_DSTATE[idxDelay] = SWC_SWD_DW.Delay2_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay2_DSTATE[8] = VAR_SWD_AgRslvDelta_f32;

  /* End of Update for Delay: '<S13>/Delay2' */

  /* Update for Delay: '<S13>/Delay8' */
  SWC_SWD_DW.Delay8_DSTATE = rtb_Add7_k;

  /* Update for Delay: '<S13>/Delay11' */
  SWC_SWD_DW.Delay11_DSTATE[0] = SWC_SWD_DW.Delay11_DSTATE[1];
  SWC_SWD_DW.Delay11_DSTATE[1] = rtb_Add7_k;

  /* Update for Delay: '<S13>/Delay18' */
  SWC_SWD_DW.Delay18_DSTATE[0] = SWC_SWD_DW.Delay18_DSTATE[1];
  SWC_SWD_DW.Delay18_DSTATE[1] = SWC_SWD_DW.Delay18_DSTATE[2];
  SWC_SWD_DW.Delay18_DSTATE[2] = rtb_Add7_k;

  /* Update for Delay: '<S13>/Delay17' */
  SWC_SWD_DW.Delay17_DSTATE[0] = SWC_SWD_DW.Delay17_DSTATE[1];
  SWC_SWD_DW.Delay17_DSTATE[1] = SWC_SWD_DW.Delay17_DSTATE[2];
  SWC_SWD_DW.Delay17_DSTATE[2] = SWC_SWD_DW.Delay17_DSTATE[3];
  SWC_SWD_DW.Delay17_DSTATE[3] = rtb_Add7_k;

  /* Update for Delay: '<S13>/Delay16' */
  SWC_SWD_DW.Delay16_DSTATE[0] = SWC_SWD_DW.Delay16_DSTATE[1];
  SWC_SWD_DW.Delay16_DSTATE[1] = SWC_SWD_DW.Delay16_DSTATE[2];
  SWC_SWD_DW.Delay16_DSTATE[2] = SWC_SWD_DW.Delay16_DSTATE[3];
  SWC_SWD_DW.Delay16_DSTATE[3] = SWC_SWD_DW.Delay16_DSTATE[4];
  SWC_SWD_DW.Delay16_DSTATE[4] = rtb_Add7_k;

  /* Update for Delay: '<S13>/Delay15' */
  for (idxDelay = 0; idxDelay < 5; idxDelay++) {
    SWC_SWD_DW.Delay15_DSTATE[idxDelay] = SWC_SWD_DW.Delay15_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay15_DSTATE[5] = rtb_Add7_k;

  /* End of Update for Delay: '<S13>/Delay15' */

  /* Update for Delay: '<S13>/Delay14' */
  for (idxDelay = 0; idxDelay < 6; idxDelay++) {
    SWC_SWD_DW.Delay14_DSTATE[idxDelay] = SWC_SWD_DW.Delay14_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay14_DSTATE[6] = rtb_Add7_k;

  /* End of Update for Delay: '<S13>/Delay14' */

  /* Update for Delay: '<S13>/Delay13' */
  for (idxDelay = 0; idxDelay < 7; idxDelay++) {
    SWC_SWD_DW.Delay13_DSTATE[idxDelay] = SWC_SWD_DW.Delay13_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay13_DSTATE[7] = rtb_Add7_k;

  /* End of Update for Delay: '<S13>/Delay13' */

  /* Update for Delay: '<S13>/Delay12' */
  for (idxDelay = 0; idxDelay < 8; idxDelay++) {
    SWC_SWD_DW.Delay12_DSTATE[idxDelay] = SWC_SWD_DW.Delay12_DSTATE[idxDelay + 1];
  }

  SWC_SWD_DW.Delay12_DSTATE[8] = rtb_Add7_k;

  /* End of Update for Delay: '<S13>/Delay12' */
}

/* Model step function for TID1 */
void SWC_SWD_100us(void)               /* Explicit Task: SWC_SWD_100us */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/SWC_SWD_100us' incorporates:
   *  SubSystem: '<Root>/SWC_SWD_100us_sys'
   */
  /* Outputs for Atomic SubSystem: '<S3>/TanCalc' */
  SWC_SWD_TanCalc();

  /* End of Outputs for SubSystem: '<S3>/TanCalc' */

  /* Outputs for Atomic SubSystem: '<S3>/AgRslvCalc' */
  SWC_SWD_AgRslvCalc();

  /* End of Outputs for SubSystem: '<S3>/AgRslvCalc' */

  /* Outputs for Atomic SubSystem: '<S4>/AgRslvDeltaCalc' */
  SWC_SWD_AgRslvDeltaCalc();

  /* End of Outputs for SubSystem: '<S4>/AgRslvDeltaCalc' */

  /* Outputs for Atomic SubSystem: '<S4>/SpdCalc' */
  SWC_SWD_SpdCalc();

  /* End of Outputs for SubSystem: '<S4>/SpdCalc' */

  /* SignalConversion: '<S1>/Signal Conversion1' */
  set_SWD_Spd(VAR_SWD_Spd_f32);

  /* SignalConversion: '<S1>/Signal Conversion2' */
  set_SWD_AgRslv(VAR_SWD_AgRslv_f32);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/SWC_SWD_100us' */
}

/* Model initialize function */
void SWC_SWD_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void SWC_SWD_terminate(void)
{
  /* (no terminate code required) */
}
#pragma section
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
