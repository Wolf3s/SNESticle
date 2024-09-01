
#ifndef _LLNETSOCKET_H
#define _LLNETSOCKET_H


#include <tamtypes.h>
#include <stdlib.h>
#include <sifrpc.h>
//#include <kernel.h>
#include <stdio.h>
#include <sifcmd.h>
#include <sifrpc.h>
#include <sysmem.h>
#include <ps2ip.h>

#ifndef closesocket
#define closesocket disconnect
#endif

#ifndef SOCKET
#define SOCKET int
#endif

typedef struct
{
	unsigned char  sin_len;
	unsigned char  sin_family;
	unsigned short sin_port;
	unsigned int   sin_addr;
	char           sin_zero[8];
} NetSocketAddrT;


#endif
