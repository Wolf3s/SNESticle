#ifndef _FILE_H
#define _FILE_H

#ifdef __cplusplus
extern "C" {
#endif

Bool FileReadMem(const Char *pFilePath, void *pMem, size_t nBytes);
Bool FileWriteMem(const Char *pFilePath, void *pMem, size_t nBytes);

Bool FileExists(const Char *pFilePath);

#ifdef __cplusplus 
};
#endif 


#endif

