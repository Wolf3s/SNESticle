
#ifndef _EMUSHELL_H
#define _EMUSHELL_H

#include "emusys.h"
#include "emurom.h"

#define EMUSHELL_MAX_SYSTEMS (8)

struct EmuShellSysT
{
	Emu::System	*pSystem;
	Emu::Rom		*pRom;
	Emu::Rom		*pBios;
};

class CEmuShell
{
protected:
	Emu::System  	*m_pSystem;		// current active system
	Emu::Rom  		*m_pRom;		// current active rom
	Emu::Rom  		*m_pBios;		// current active bios

	Uint32			m_nMaxSaveChars;
    Char 			m_RomName[256];		// base rom filename "Super Mario World"
	Char			m_SaveName[256];    // save filename "Super Mar001"

	// list of registered systems
	Int32			m_nSystems;
	EmuShellSysT	m_Systems[EMUSHELL_MAX_SYSTEMS];

public:
	CEmuShell();
	virtual ~CEmuShell();
	virtual Bool LoadRom(Char *pRomFile, Uint8 *pBuffer, Uint32 nBufferBytes);
	virtual void UnloadRom();

	void LoadState();
	void SaveState();

	EmuShellSysT *FindSysByExt(char *pExt);

	EmuShellSysT *RegisterSystem(Emu::System *pSystem, Emu::Rom *pRom, Emu::Rom *pBios);

	void SetRomFileName(Char *pFileName);
	Char *GetRomName() {return m_RomName;}
	Char *GetSaveName() {return m_SaveName;}
	int ReadFileData(Uint8 *pBuffer, Int32 nBufferBytes, char *pRomFile, Bool bCompressed);
};

#endif
