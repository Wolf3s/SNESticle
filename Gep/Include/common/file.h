#ifndef _FILE_H
#define _FILE_H

#ifdef __cplusplus
extern "C" {
#endif

Bool FileReadMem(char *pFilePath, void *pMem, size_t nBytes);
Bool FileWriteMem(char *pFilePath, void *pMem, size_t nBytes);

Bool FileExists(char *pFilePath);

#ifdef __cplusplus 
};
#endif 


#endif

