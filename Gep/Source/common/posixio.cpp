#ifdef _MSC_VER
#include <io.h>
#include <direct.h>
#else
#include <unistd.h>
#include <dirent.h>
#endif
#include <fcntl.h>

#include "types.h"
#include "posixio.h"

CPosixFile::CPosixFile()
{
	
}

CPosixFile::~CPosixFile()
{
	Close(NULL);
}
/*
int CPosixFile::Access(const char* filename, Int32 accessMode)
{
#ifdef _MSC_VER
	return _access(filename, accessMode);
#else
	retunr access(filename, accessMode);
#endif
}
*/
int CPosixFile::Open(const char* filename, Int32 flags, Int32 Pmode)
{
#ifdef _MSC_VER
	return _open(filename, flags, Pmode);
#else
	return open(filename, flags, Pmode);
#endif
}

int CPosixFile::Close(Int32 FileHandle)
{
#ifdef _MSC_VER
	return _close(FileHandle);
#else
	return close(FileHandle);
#endif
}

int CPosixFile::Read(Int32 filehandle, void* dstbuf, Uint32 maxcharcount)
{
#ifdef _MSC_VER
	return _read(filehandle, dstbuf, maxcharcount);
#else
	return read(filehandle, dstbuf, maxcharcount)
#endif
}

int CPosixFile::Write(Int32 filehandle, const void* dstbuf, Uint32 maxcharcount)
{
#ifdef _MSC_VER
	return _write(filehandle, dstbuf, maxcharcount);
#else
	return write(filehandle, dstbuf, maxcharcount);
#endif
}

long CPosixFile::Seek(Int32 filehandle, long offset, Int32 origin)
{
#ifdef _MSC_VER
#ifdef _WIN64
	return static_cast<long>(_lseeki64(filehandle, offset, origin));
#else
	return _lseek(filehandle, offset, origin);
#endif
#else
	return lseek(filehandle, offset, origin);
#endif
}

long CPosixFile::Tell(Int32 filehandle)
{
#ifdef _MSC_VER
#ifdef _WIN64
	return static_cast<long>(_telli64(filehandle));
#else
	return _tell(filehandle);
#endif
#else
	return tell(filehandle);
#endif
}

CPosixIO::CPosixIO()
{
	m_fd = NULL;
	m_file = NULL;
}

CPosixIO::~CPosixIO()
{
	Close();
}

Bool CPosixIO::Open(const char* filename, Int32 pMode)
{
	Close();
	m_fd = m_file->Open(filename, _O_RDWR, pMode);
	return m_fd ? TRUE : FALSE;
}

size_t CPosixIO::Read(void* pBuffer, Uint32 nBytes)
{
	return m_file->Read(m_fd, pBuffer, nBytes);
}

size_t CPosixIO::Write(const void* pBuffer, Uint32 nBytes)
{
	return m_file->Write(m_fd, &pBuffer, nBytes);
}

int CPosixIO::Seek(Int32 iPos, Int32 Whence)
{
	return m_file->Seek(iPos, sizeof(iPos), Whence);
}

size_t CPosixIO::GetPos()
{
	return m_file->Tell(m_fd);
}

void CPosixIO::Close()
{
	m_file->Close(m_fd);
}