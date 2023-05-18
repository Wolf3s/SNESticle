

#ifndef _SNMASK_H
#define _SNMASK_H


#ifdef __cplusplus
extern "C"
{
#endif

union SNMaskT 
{
	Uint8   uMask8[32];
	Uint32  uMask32[8];
    Uint64  uMask64[4];
	#if CODE_PLATFORM == CODE_PS2
	Uint128 uMask128[2];
	#endif
} _ALIGN(16);


void SNMaskRange(union SNMaskT* pMask, Uint32 uLeft, Uint32 uRight, Bool bInvert);
void SNMaskRight(union SNMaskT* pMask, Int32 iPos);
void SNMaskLeft(union SNMaskT* pMask, Int32 iPos);

void SNMaskSHR(union SNMaskT* pDestMask, const Uint8* pSrcMask, Int32 nBits);
void SNMaskSHL(union SNMaskT* pDestMask, const Uint8* pSrcMask, Int32 nBits);

void SNMaskClear(union SNMaskT* pDest);
void SNMaskSet(union SNMaskT* pDest);
void SNMaskCopy(union SNMaskT* pDest, const union SNMaskT* pSrc);

void SNMaskNOT(union SNMaskT* pDest, const union SNMaskT* pSrc);
void SNMaskAND(union SNMaskT* pDest, const union SNMaskT* pSrcA, const union SNMaskT* pSrcB);
void SNMaskANDN(union SNMaskT* pDest, const union SNMaskT* pSrcA, const union SNMaskT* pSrcB);
void SNMaskOR(union SNMaskT* pDest, const union SNMaskT* pSrcA, const union SNMaskT* pSrcB);
void SNMaskXOR(union SNMaskT* pDest, const union SNMaskT* pSrcA, const union SNMaskT* pSrcB);
void SNMaskXNOR(union SNMaskT* pDest, const union SNMaskT* pSrcA, const union SNMaskT* pSrcB);

void SNMaskBool(union SNMaskT* pDest, const union SNMaskT* pSrc, Bool bVal);

#ifdef __cplusplus
};
#endif

#endif
