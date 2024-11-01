#pragma once
#include <vector>
struct stateString_FORMAT {
	char param[3];
};
struct _UnCompiled {
	static const int default_TextX = 0
		, default_lettercount = 0
		, default_width = 24
		, default_height = 24
		, default_Regular = 0
		, default_font_df = 0
		, default_font_ct = 1
		, default_font_lf = 2
		, default_font_rt = 3
		, default_font_lr = 4
		;

	int TextX;
	int lettercount;
	int width;
	int height;
	int bold;
	int font;
	int RowBeg;
};

#define _DOT_PER_ROW   380
#define _STRINGFONTBOLD   0X80
#define _STRINGFONTASCI   0X40
#define _STRINGFONT_BEG   0X20
#define _FontNormalHeight 16
class CPrinterView
{
public:
	void _LoadLib(HWND hWnd, POINT pt, char* font, char* string);
	BYTE* file;
	UINT nLen;
	void _FormatInfo(HWND m_hWnd, char* cString, char* font, POINT pt);
	static const int fontHeight = 16, fontWidth = 16;
	static const int block;
	int getpixelStateInseries(char* pointer, int bit);
	//save font as target file path
	void outputFontInText(char* font, char* as);
	void _SetUpDotMatrix(int* nPos, char* font, int height, int width
		, char* DotMatix, char* string);

	struct dataFont {
		static const char Font_ = 0;
		char font, length, data;
	};
	_UnCompiled m_FontGlobal;
	void _StringWithFont(HWND hd);
	
	struct _Printbuffer{
	char setbit[_DOT_PER_ROW * 2];
	int nHeight;
	int begY;
	}_currentLine;

	//x is real y without scaling with maximum FONT_HEIGHT
	void _SetDotMatrixInStandardStorage(int x, int y, int Pix);
	//simulate printer
	void _Simulation_AutoPrint(HDC dc, _Printbuffer* printBuf);
	

};

