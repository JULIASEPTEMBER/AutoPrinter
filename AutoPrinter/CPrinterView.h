#pragma once
#include <vector>
class CPrinterView
{
	void _LoadLib(HWND hWnd);
	BYTE* file;
	void _FormatInfo();
	HWND m_hWnd;
	static const int fontHeight = 16, fontWidth = 16;
};

