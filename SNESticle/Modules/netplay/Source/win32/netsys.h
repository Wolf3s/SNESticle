
#ifndef _NETSYS_H
#define _NETSYS_H

// ugh
#include <windows.h>
#include <winsock.h>

typedef struct
{
	unsigned char  sin_len;
	unsigned char  sin_family;
	unsigned short sin_port;
	unsigned int   sin_addr;
	char           sin_zero[8];
} NetSocketAddrT;

typedef HANDLE NetSysSemaT;
typedef int NetSysThreadT;

#define NETSYS_THREAD_INVALID (-1)

NetSysSemaT NetSysNewSema(int initcount);
void NetSysDeleteSema(NetSysSemaT sema);
int NetSysWaitSema(NetSysSemaT sema);
int NetSysSignalSema(NetSysSemaT sema);

NetSysThreadT NetSysThreadStart(void *pThreadFunc, int priority, void *arg);
int NetSysGetSystemTime(void);


#endif
