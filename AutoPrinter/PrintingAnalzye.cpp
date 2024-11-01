#include "stdafx.h"
#include "PrintingAnalzye.h"
#include "ASCII_16X16.h"
#include "GB2312.h"


_printing _pinfo;
PLCIDECALLBACK Funname;
HDC dc_Get;

void _Init_FontBuffer()
{
	for(int i = 0; i < sizeof(_printing); i ++)
	{
		((BYTE*)&_pinfo)[i] = 0;
	}
	//read file to print 
	_pinfo.nFlag = _FLAG_WAIT;
}


int _Format_Info(char* info)
{
	if(_FLAG_WAIT == _pinfo.nFlag)
	{
		strcpy(_pinfo.string, info);
		_pinfo.nLenString = strlen(info);
		_pinfo.nFlag = _FLAG_BUSY;
		return 1;
	}
	return 0;
}


void _PrintThread()
{
	switch(_pinfo.nFlag)
	{
		case _FLAG_INIT:
			break;
		case _FLAG_WAIT:  
			break;
		case _FLAG_BUSY:
			_Printing_Proc(); 
				_pinfo.nFlag = _FLAG__END; 
			break;
		case _FLAG__END:
			_ShowDC();
			_pinfo.nFlag = _FLAG_WAIT;
			break;
	}
}


int CALLBACK PRINTING_ExchangeData(int hhv, PLCIDECALLBACK pFC, void *pParam)// 
{
	Funname = pFC;                     // 
	return 0;
}


//printing 
void _Printing_Proc()
{
	//MessageBoxA(0, _pinfo.string, 0, 0);
	struct _RECTFILL{
		char cinfo[32];
	};
	_RECTFILL* pSheet = (_RECTFILL*)ascii_table_16_16_0000;
	_RECTFILL* pFill;
	char* pLetter = _pinfo.string;
	int hor = 16;

	for(int i = 0; i < _pinfo.nLenString; i ++)
	{
		if((((*pLetter) & 0x80)))
		{
			{
#ifndef dfec
				_WORD16x16 word; 
				{
					UINT Get = (pLetter[0] & 0xff) << 8 | (pLetter[1] & 0xff);
					UINT high = (Get >> 8) - 0xA1;
					UINT low = (Get & 0xff) - 0xA1;
					UINT delta = 6 * 16 - 2;
					UINT resultCal = high * delta + low, start; 

					start = resultCal;
					word = ((_WORD16x16*)GB2312_Font)[start];
					pFill = (_RECTFILL*) & word;
					//for(int i = 0; i < ASCIILEN / 2; i ++)
					//{  
					//		_pinfo.row[hor][0] |= pFill->cinfo[i * 2 + 1]; 
					//		_pinfo.row[hor][1] |= pFill->cinfo[i * 2 + 0]; 
					//	hor ++;
					//}
					int partSheet = 0;
					for (int j = 0; j < 16; j++)
					{
						if (j < 8)
							partSheet = 1;
						else
							partSheet = 0;
						_pinfo.row[hor + j][0] = 0;
						_pinfo.row[hor + j][1] = 0;
						for (int k = 0; k < 16; k++)
						{
							if (k < 8)
								_pinfo.row[hor - j][0] |= ((pFill->cinfo[2 * k + partSheet] & (1 << j % 8))) ? (1 << k % 8) : 0;
							else
								_pinfo.row[hor - j][1] |= ((pFill->cinfo[2 * k + partSheet] & (1 << j % 8))) ? (1 << k % 8) : 0;
						}
					}
				}
#endif
				hor += _ASCWIDTH;
				pLetter += 2;
			}
		}
		else
		{
			pFill = &((_RECTFILL*)pSheet)[(*pLetter)];  
			//for(int i = 0; i < ASCIILEN / 2; i ++)
			//{  
			//		_pinfo.row[hor][0] |= pFill->cinfo[i * 2 + 1]; 
			//		_pinfo.row[hor][1] |= pFill->cinfo[i * 2 + 0]; 
			//	hor ++;
			//}
			int partSheet = 0;
			for(int j = 0; j < 16; j ++)
			{
				if(j < 8)
					partSheet = 1;
				else 
					partSheet = 0;
				_pinfo.row[hor + j][0] = 0;
				_pinfo.row[hor + j][1] = 0;
				for(int k = 0; k < 16; k ++)
				{
					if(k < 8)
						_pinfo.row[hor - j][0] |= ((pFill->cinfo[2 * k + partSheet] & (1 << j % 8))) ? (1 << k % 8) : 0;
					else
						_pinfo.row[hor - j][1] |= ((pFill->cinfo[2 * k + partSheet] & (1 << j % 8))) ? (1 << k % 8) : 0;
				}
			}
			hor += _ASCWIDTH;
			pLetter += 1;
		}

	}
}


//show in dc
void _ShowDC()
{
	for(int k = 0; k < 2; k ++)
	{
		for(int i = 0; i < _VERMAX / 2; i ++)
		{
			for(int j = 0; j < _HORMAX; j ++)
			{
				
				::SetPixel(dc_Get, 100 + j, 100 + i + k * 8, _pinfo.row[j][k] & (1 << i) ? 0x0 : 0xffffff);
			}
		}
	}
	::MoveToEx(dc_Get, 100, 100, 0);
	::LineTo(dc_Get, 1000, 1000);
}



