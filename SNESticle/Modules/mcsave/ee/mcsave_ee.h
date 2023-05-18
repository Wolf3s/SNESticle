

#ifndef _MCSAVE_EE_H
#define _MCSAVE_EE_H

#define	MCSAVE_IRX		0xB0D1DCD
#define MCSAVE_PUTS		0x01
#define	MCSAVE_INIT		0x02
#define MCSAVE_STORE	0x03
#define MCSAVE_QUIT		0x04
#define MCSAVE_DREAD	0x05


void MCSave_Puts(char *format, ...);
int MCSave_Init(int MaxSize);
int MCSave_Write(char *pPath, char *pData, int nBytes);
int MCSave_WriteSync(int bSync, int *pResult);
void MCSave_Shutdown();
int MCSave_IsInitialized();
#ifdef PS2_EE
int MCSave_Dread(int fd, io_dirent_t *dir);
#else
int MCSave_Dread(int fd, fio_dirent_t *dir);
#endif
#endif // _MCSAVE_H
