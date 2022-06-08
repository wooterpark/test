#include "Platform_Types.h"
#include "Std_Types.h"

boolean ComAppl_EvalChk_XOR8(const uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen, uint8* checksumPtr);
uint8 ComAppl_GenChk_XOR8(uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen);
boolean ComAppl_EvalChk_Add8(const uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen, uint8* checksumPtr);
uint8 ComAppl_GenChk_Add8(uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen);
boolean ComAppl_EvalChk_ComCrc(const uint8* pduPtr, uint8 pduLen,uint8 sigStartbit, uint8 sigLen, uint8* checksumPtr);  //add by wq
uint8 Com_CRC(uint8* BuffPtr); //add by wq
extern uint8  VAR_CheckSumValue_u8;
