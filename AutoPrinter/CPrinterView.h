#pragma once
#include <vector>
class CPrinterView
{
public:
	void _LoadLib(HWND hWnd, POINT pt, char* font, char* string);
	BYTE* file;
	void _FormatInfo(HWND m_hWnd, char* cString, char* font, POINT pt);
	static const int fontHeight = 16, fontWidth = 16;
	static const int block;
	int getpixelStateInseries(BYTE* pointer, int bit);
	//save font as target file path
	void outputFontInText(char* font, char* as);
	void _SetUpDotMatrix(int* nPos, char* font, int height, int width
		, char* DotMatix, char* string);

	struct dataFont {
		static const char Font_ = 0;
		char font, length, data;
	};
	void _StringWithFont(char* path);
};

