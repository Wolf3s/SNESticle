
#ifndef _SNPPUCOLOR_H
#define _SNPPUCOLOR_H

#define SNPPUCOLOR_NUM (0x8000)

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct 
{
	float	fBrightness;
	float	fIQAngle;
	float	fMaxExcursion;
}SNPPUColorCalibT;

Uint32 SNPPUColorConvert15to32(Uint16 uColor15);
void SNPPUColorCalibrate(const SNPPUColorCalibT *pCalib);
void SNPPUColorSetColors(const Uint32 *pColors, Int32 nColors);
Uint32 *SNPPUColorGetPalette();

#ifdef __cplusplus
};
#endif

#endif
