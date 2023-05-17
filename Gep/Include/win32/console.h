
/*!

    \File    console.h

    \Description
	    Description

    \Notes
	    None.

    \Copyright
	    (c) 2004 Icer Addis

*/


#ifndef _console_h
#define _console_h

/*-- Include files -------------------------------------------------------------------------------*/


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*-- Preprocessor Definitions --------------------------------------------------------------------*/

enum ConE
{
	CON_STANDARD,
	CON_WARNING,
	CON_ERROR,
	CON_DEBUG,
	CON_NUM
};

/*-- Type Definitions ----------------------------------------------------------------------------*/

/*-- Variables -----------------------------------------------------------------------------------*/

/*-- Functions -----------------------------------------------------------------------------------*/


void ConInit();
void ConShutdown();

void ConPuts(enum ConE eCon, const char *pString);
void ConPrint(const char *pFormat, ...);
void ConPrintf(const char *pFormat, ...);
void ConWarning(const char *pFormat, ...);
void ConError(const char *pFormat, ...);
void ConDebug(const char *pFormat, ...);
void ConRedirect(const char *pFileName);

void ConStdin(char *pStr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // _console_h




#ifndef _CONSOLE_H
#define _CONSOLE_H


#endif
