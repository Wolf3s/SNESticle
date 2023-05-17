#ifndef _POSIXIO_H
#define _POSIXO_H

#include "dataio.h"

class CPosixFile
{
public:
	CPosixFile();
	~CPosixFile();
/*
	int Access(const char* filename, Int32 accessMode);
*/
	int Open(const char* filename, Int32 flags, Int32 pMode);
	int Close(Int32 fileHandle);
	int Read(Int32 filehandle, void* dstbuf, Uint32 maxcharcount);
	int Write(Int32 filehandle, const void *dstbuf, Uint32 maxcharcount);
	long Seek(Int32 filehandle, long offset, Int32 origin);
	long Tell(Int32 filehandle);
};

class CPosixIO : public CDataIO, CPosixFile
{
	int m_fd;
	CPosixFile* m_file;
public:
	CPosixIO();
	virtual ~CPosixIO();
	virtual Bool Open(const char* filename, Int32 pmode);
	virtual size_t Read(void* pBuffer, Uint32 nBytes);
	virtual Uint8* ReadPtr(Int32 nBytes) = 0;
	virtual size_t Write(const void* pBuffer, Uint32 nBytes);
	virtual int Seek(Int32 iPos, Int32 Whence);
	virtual size_t GetPos();
	virtual void Close();
};



#endif