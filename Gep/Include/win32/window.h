
#ifndef _WINDOW_H
#define _WINDOW_H

#include <windows.h>
#include "types.h"

class CGepWin
{
private:
	HWND	m_hWnd;
	Bool	m_bActive;

	HWND	m_hWndStatus;
	Uint32  m_uStatusHeight;

	Bool	RegisterClass(HINSTANCE hInstance, char *pClassName, LPCSTR pMenuName);

protected:
	virtual void OnMenuCommand(Uint32 uCmd);
	virtual void OnPaint();
	virtual void OnDestroy();
	virtual void SetActive(Bool bActive);
	virtual void OnSize(Uint32 uWidth, Uint32 uHeight);
	virtual void OnVScroll(Int32 nScrollCode, Int32 nPos);
	virtual void OnKeyUp(Uint32 uScanCode, Uint32 uVirtKey);
	virtual void OnKeyDown(Uint32 uScanCode, Uint32 uVirtKey);

public:
	CGepWin();
	~CGepWin();

	virtual LRESULT OnMessage(UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual void Process();

	void Create(char *pClassName, char *pAppName, Uint32 uStyle, LPCSTR pMenuName);
	void ShowWindow(int iCmdShow);
	void Destroy();

	void SetTitle(char *pTitle);
	void SetSize(Int32 Width, Int32 Height);
	HWND GetWnd() {return m_hWnd;}

	void CreateStatusBar();
	void DestroyStatusBar();
	Bool HasStatusBar() {return m_hWndStatus ? TRUE : FALSE;}
	Uint32 GetStatusHeight() {return m_uStatusHeight;}
	void SetStatusText(Int32 iPart, char *pStr);

	Bool IsActive() {return m_bActive;}
};

#endif
