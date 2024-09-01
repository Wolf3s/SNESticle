
/*H********************************************************************

	types.h

	Description:

		Standard data type definitions

	Notes:
		None


********************************************************************H*/

#ifndef _TYPES_H
#define _TYPES_H

#include <assert.h>
#include <stdbool.h>
#include "gepdefs.h"

#ifndef ASSERT
#define ASSERT assert
#endif 

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE  (!FALSE)
#endif

// standard data types

typedef unsigned char	Uint8;
typedef signed char		Int8;
typedef unsigned short	Uint16;
typedef signed short	Int16;
typedef unsigned int	Uint32;
typedef signed int		Int32;
typedef char			Char;
typedef bool            Bool;
typedef float			Float32;
typedef double			Float64;
#ifdef _EE
typedef unsigned long long Uint64;
#else
typedef unsigned long int Uint64;
#endif
typedef signed long int   Int64;

typedef unsigned int      Uint128 __attribute__(( mode(TI) ));

typedef Uint8 BYTE;
typedef Uint16 WORD;
typedef Uint32 DWORD;
typedef Int32 LONG;

#define _ALIGN(__align) __attribute__((aligned(__align)))
#define _INLINE inline

#endif


