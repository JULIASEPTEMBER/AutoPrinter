
#include "stdafx.h"

#define _FLAG_INIT   0
#define _FLAG_WAIT   1
#define _FLAG_BUSY   2
#define _FLAG__END   3
#define _HORMAX 300
#define _VERMAX  16
#define _ASCWIDTH  16

struct _printing{
	int nFlag;
	char string[10000];
	int nLenString;
	char row[_HORMAX][2];
};

extern HDC dc_Get;


//comparing list 
extern void _Init_FontBuffer();
//format information to buffer
extern int _Format_Info(char* info);
//print bmp from sram
extern void _PrintThread();
//printing info
extern _printing _pinfo;

//exchange 
extern int CALLBACK PRINTING_ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam); 

//function 
extern PLCIDECALLBACK Funname;

//printing 
extern void _Printing_Proc();

//show in dc
extern void _ShowDC();



