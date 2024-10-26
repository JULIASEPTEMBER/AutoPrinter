#include "stdafx.h"
#include "CPrinterView.h"


BYTE info[300000];
void CPrinterView::_LoadLib(HWND hWnd)
{
	HANDLE hFile;
	UINT nSize;
	DWORD dw;
	m_hWnd = hWnd;
	file = info;
	hFile = ::CreateFile(L"HZK16C", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	nSize = :: GetFileSize(hFile, 0);
	::ReadFile(hFile, file, nSize, &dw, 0);


}
void CPrinterView::_FormatInfo()
{

	HDC dc = ::GetDC(m_hWnd);
	for (int i = 0; i < 100; i++)
	{
		for (int y = 0; y < fontHeight; ++y) {
			for (int x = 0; x < fontWidth; ++x) {
				::SetPixel(dc, )

			}
		}
	}
}