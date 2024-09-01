/*#include <sys/stat.h>*/
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "file.h"

Bool FileReadMem(const Char *pFilePath, void *pMem, size_t nBytes)
{
	FILE *pFile;
	pFile = fopen(pFilePath, "rb");
	if (pFile)
	{
		size_t nReadBytes;
		nReadBytes = fread(pMem, 1, nBytes, pFile);
		fclose(pFile);
		return (nBytes == nReadBytes);
	}
	
	return FALSE;
}

Bool FileWriteMem(const Char *pFilePath, void *pMem, size_t nBytes)
{
	FILE *pFile;
	size_t nWriteBytes;

	pFile = fopen(pFilePath, "wb");
	if (pFile)
	{
		nWriteBytes = fwrite(pMem, 1, nBytes, pFile);
		fclose(pFile);
		return (nBytes == nWriteBytes);
	}

	return FALSE;
}

Bool FileExists(const Char *pFilePath)
{
	FILE *pFile;

	pFile = fopen(pFilePath, "rb");
	if (pFile)
	{
		fclose(pFile);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

