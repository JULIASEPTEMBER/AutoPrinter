#include "stdafx.h"
#include "CPrinterView.h"
#include "BasicOperation.h"
#include "GB2312BOLDREGULAR.H"

BYTE info[300000];
char stringOutput[1000000];
void CPrinterView::_LoadLib(HWND hWnd, POINT pt, char* font, char* string)
{
	HANDLE hFile;
	UINT nSize;
	DWORD dw;
	file = info;
	//hFile = ::CreateFile(L"hzk16s", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	hFile = ::CreateFileA(font, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	nSize = ::GetFileSize(hFile, 0);
	::ReadFile(hFile, file, nSize, &dw, 0);
	_FormatInfo(hWnd, string, (char*)file, pt);
	::CloseHandle(hFile);


}
void CPrinterView::_FormatInfo(HWND m_hWnd, char* cString, char* font, POINT pt)
{
	HDC dc = ::GetDC(m_hWnd);
	char* bytebeg;
	int wantpixel;
	int siglesize = fontHeight * fontWidth / 8;

	{
		UINT Get = 0xa4a0;
		UINT high = (Get >> 8) - 0xA1;
		UINT low = (Get & 0xff) - 0xA1;
		UINT delta = 6 * 16 - 2;
		UINT resultCal = high * delta + low;
		resultCal = high * delta + low;
	}

	for (int i = 0; i < strlen(cString); i++)
	{

		if (cString[i] & 0x80)
		{
			UINT Get = (cString[i + 0] & 0xff) << 8 | (cString[i + 1] & 0xff);
			UINT high = (Get >> 8) - 0xA1;
			UINT low = (Get & 0xff) - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;


			for (int y = 0; y < fontHeight; ++y) {
				for (int x = 0; x < fontWidth; ++x) {
					bytebeg = (char*)&font[(resultCal)*siglesize];
					wantpixel = y * fontWidth + x;
					::SetPixel(dc, pt.x + (i / 2 * fontWidth + x) % (50 * 16), pt.y + ((int)(i / 2 / 50) * 16) + y, getpixelStateInseries((char*)bytebeg, wantpixel) ? 0 : 0xffffff);

				}
			}
			i += 1;
		}
		else
		{

			UINT startAscii = cString[i + 0] - 0x20;

			UINT Get = 0xa3a0;
			UINT high = (Get >> 8) - 0xA1;
			UINT low = (Get & 0xff) - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;
			resultCal += startAscii;
			for (int y = 0; y < fontHeight; ++y) {
				for (int x = 0; x < fontWidth; ++x) {
					bytebeg = (char*)&font[(resultCal)*siglesize];
					wantpixel = y * fontWidth + x;
					::SetPixel(dc, pt.x + (i * fontWidth + x) % (50 * 16), pt.y + ((int)(i / 50) * 16) + y, getpixelStateInseries(bytebeg, wantpixel) ? 0 : 0xffffff);

				}
			}

		}
	}
}


int CPrinterView::getpixelStateInseries(char* pointer, int bit)
{
	return pointer[bit / 8] & (1 << (7 - bit % 8)) ? 1 : 0;
}


void CPrinterView::outputFontInText(char* font, char* as)
{

	HANDLE hFile;
	UINT nSize;
	DWORD dw;
	int fileWritePlace = 0;
	int RowCountItem = 0, nRowCountItemMax = 32;//one letter a line

	file = info;

	//hFile = ::CreateFile(L"hzk16s", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	hFile = ::CreateFileA(font, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	nSize = ::GetFileSize(hFile, 0);
	::ReadFile(hFile, file, nSize, &dw, 0);
	::CloseHandle(hFile);
	sprintf(stringOutput + fileWritePlace, "static const unsigned char %s_Def[%d] = {\r\n", as, nSize);
	fileWritePlace += strlen(stringOutput + fileWritePlace);
	for (int i = 0; i < nSize; i++)
	{
		sprintf(stringOutput + fileWritePlace, "0x%02x", file[i]);
		fileWritePlace += strlen(stringOutput + fileWritePlace);
		if (i != nSize - 1)
		{
			sprintf(stringOutput + fileWritePlace, ", ");
			fileWritePlace += strlen(stringOutput + fileWritePlace);
		}
		else
		{
			sprintf(stringOutput + fileWritePlace, "};");
			fileWritePlace += strlen(stringOutput + fileWritePlace);
		}

		RowCountItem++;
		if (RowCountItem == nRowCountItemMax)
		{

			sprintf(stringOutput + fileWritePlace, "\r\n");
			fileWritePlace += strlen(stringOutput + fileWritePlace);
			RowCountItem = 0;
		}
	}
	char info[100];
	sprintf(info, "%s.txt", as);
	//hFile = ::CreateFile(L"hzk16s", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	hFile = ::CreateFileA(info, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
	nSize = ::GetFileSize(hFile, 0);
	::WriteFile(hFile, stringOutput, fileWritePlace, &dw, 0);

	::CloseHandle(hFile);
}


void CPrinterView::_SetUpDotMatrix(int* nPos, char* font, int height, int width, char* DotMatix, char* string)
{
	int nLen = strlen(string);
	//index gb2312

	int Get, high, low, delta, resultCal;

	BYTE* bytebeg;
	int wantpixel;
	int siglesize = fontHeight * fontWidth / 8;

	for (int i = 0; i < nLen; i++)
	{
		Get = (string[i * 2 + 0] & 0xff) << 8 | (string[i * 2 + 1] & 0xff);
		high = (Get >> 8) - 0xA1;
		low = (Get & 0xff) - 0xA1;
		delta = 6 * 16 - 2;
		resultCal = high * delta + low;

		for (int y = 0; y < fontHeight; ++y) {
			for (int x = 0; x < fontWidth; ++x) {
				bytebeg = (BYTE*)&font[(resultCal)*siglesize];
				wantpixel = y * fontWidth + x;
				//DotMatix[]

				//::SetPixel(dc, pt.x + (i * fontWidth + x) % (50 * 16), pt.y + ((int)(i / 50) * 16) + y, getpixelStateInseries(bytebeg, wantpixel) ? 0 : 0xffffff);

			}
		}

	}



}
void _TranslateFormatInGb2312(_UnCompiled* rslt, stateString_FORMAT* ori)
{

	rslt->TextX = (ori->param[0] & 0xff) + ((ori->param[1]  << 8) & 0x300);
	rslt->lettercount = (ori->param[1] >> 2) & 0x3f;
	rslt->width = ori->param[2] & 0xf;
	rslt->height = (ori->param[2] >> 4) & 0xf;
	rslt->width *= 8;
	rslt->height *= 8;
}

/// <summary>
/// create printing proc from a server format txt
/// </summary>
/// <param name="path"></param>
void CPrinterView::_StringWithFont(HWND hd)
{
	CBasicOperation::ReadFile_InPath(L"path.ojulia", info, nLen);
	char* monitor, * piece, * get;
	get = (char*)info;
	monitor = new char[10000];
	monitor[0] = 0;
	piece = new char[2560];
	int state = 0;
	int xpos, ypos = 0, lastposx = 0, lastheight = 0, wantpixel, resultCal = 0, siglesize = fontHeight * fontWidth / 8;
	stateString_FORMAT getHead;
	HDC dc = ::GetDC(hd);
	char* byteBeg;
	int lastWidth;

	for (int i = 0; i < nLen; )
	{
		switch (state)
		{
		case 0:
			//if (!get[i] && get[i + 1])
			//{
			//	ypos += lastheight;
			//	i += 3;
			//	lastposx = 999;
			//	break;
			//}
			_TranslateFormatInGb2312(&m_FontGlobal, (stateString_FORMAT*)(get + i));
			sprintf(piece, "\r\ntxtX:%d, lettercount:%d, width:%d, height:%d\r\n"
				, m_FontGlobal.TextX
				, m_FontGlobal.lettercount
				, m_FontGlobal.width
				, m_FontGlobal.height
			);
			strcat(monitor, piece);
			state++;
			i += 3;
			xpos = m_FontGlobal.TextX;
			if (m_FontGlobal.TextX <= lastposx)
			{
				ypos += fontWidth;
			}
			lastheight = m_FontGlobal.height;

			if (m_FontGlobal.lettercount == 0)
			{
				ypos += fontWidth;
				state = 0;
			}
			break;
		case 1:
		{
			for (int j = 0; j < m_FontGlobal.lettercount; j++)
			{
				sprintf(piece, "%02x, %02x, ", *(get + i + j * 2 + 0) & 0xff, *(get + i + j * 2 + 1) & 0xff);
				strcat(monitor, piece);
				resultCal = (((*(get + i + j * 2 + 0) & 0x3f) << 8) & 0xff00) + (*(get + i + j * 2 + 1) & 0xff);
				if (*(get + i + j * 2 + 0) & 0xff & _STRINGFONTBOLD)
				{
					byteBeg = (char*)&GB2312_BOLD_Def[(resultCal)*siglesize];
				}
				else
					byteBeg = (char*)&GB2312_REGULAR_Def[(resultCal)*siglesize];
				for (int y = 0; y < fontWidth; ++y) {
					for (int x = 0; x < fontWidth; ++x) {
						wantpixel = y * fontWidth + x;
						::SetPixel(dc, xpos + x, ypos + y, getpixelStateInseries(byteBeg, wantpixel) ? 0 : 0xffffff);
					}
				}
				if(*(get + i + j * 2 + 0) & _STRINGFONTASCI)
					xpos += m_FontGlobal.width / 2;
				else
					xpos += m_FontGlobal.width;

				lastposx = xpos;
			}
			state = 0;
			i += m_FontGlobal.lettercount * 2;
			break;

		}
		}

	}
	monitor;
	delete piece;
	delete monitor;
}
//qr <QR></QR>
//bold <FB></FB>
//32*24 <FH></FH>
//24*32 <FW></FW>
//48*24 <FH2></FH2>
//24*48 <FW2></FW2>
//32*32 <FS></FS>
//48*48 <FS2></FS2>
//TAB \t
//RETURN \r,\n,\r\n
//BMP <BMP></BMP>
//NEXT_PAGE <MF></MF>
//64*64 <FS3></FS3>
//96*96 <FS4></FS4>
//128*128 <FS5></FS5>
//192*192 <FS6></FS6>
//384*384 <FS7></FS7>
//RIGHT <RA></RA>
//CENTER <center></center>
//LEFTRIGHT <LR></LR>
//RIGHT <right></right>
