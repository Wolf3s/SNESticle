#ifndef _BMPFILE_H
#define _BMPFILE_H

class CSurface;
struct PaletteT;

Bool BMPWriteFile(char *pFileName, CSurface *pSurface, PaletteT *pPalette);
Bool BMPReadFile(char *pFileName, CSurface *pSurface);


#endif
