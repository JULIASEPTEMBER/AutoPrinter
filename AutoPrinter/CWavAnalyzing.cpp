// CWavAnalyzing.cpp: 实现文件
//
#include "stdafx.h"
#include "AutoPrinter.h"
#include "afxdialogex.h"
#include "CWavAnalyzing.h"
#include "BasicOperation.h"

// CWavAnalyzing 对话框

char outputInfo[20000000];
char getInfo[2000000];
char cFormat[1000000];
UINT nLen;


IMPLEMENT_DYNAMIC(CWavAnalyzing, CDialogEx)

CWavAnalyzing::CWavAnalyzing(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_WAV, pParent)
{
	outputInfo[0] = 0;
}

CWavAnalyzing::~CWavAnalyzing()
{
}

void CWavAnalyzing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PATH, m_Edit_Path);
	DDX_Control(pDX, IDC_EDIT_OUTPUT, m_Output);
}


BEGIN_MESSAGE_MAP(CWavAnalyzing, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CWavAnalyzing::OnBnClickedButtonOpen)
END_MESSAGE_MAP()


// CWavAnalyzing 消息处理程序


void CWavAnalyzing::_GetFile()
{
	nLen = 0;
}


//create dialog
void CWavAnalyzing::_CreateDialog()
{
	CDialog::Create(CWavAnalyzing::IDD);
	ShowWindow(SW_SHOW);
}


void CWavAnalyzing::OnBnClickedButtonOpen()
{
	WCHAR wcPath[256];
	m_Edit_Path.GetWindowTextW(wcPath, 256);
	wcscat(wcPath, L".WAV");
	nLen = 0;
	CBasicOperation::ReadFile_InPath(wcPath, (BYTE*)getInfo, nLen);
	_AnalyzeWaveFile((BYTE*)getInfo, nLen);
	// TODO: 在此添加控件通知处理程序代码
}


//analyzing 
void CWavAnalyzing::_AnalyzeWaveFile(BYTE* bt, UINT nLen)
{
	_WAV_HEADER* pHeader;
	pHeader = (_WAV_HEADER*)bt;
	outputInfo[0] = 0;
	_FormatString(outputInfo, "_RIFF_chunk::ID", pHeader->riff.ID, 4);
	_FormatString(outputInfo, "_RIFF_chunk::Size", pHeader->riff.Size, 4);
	_FormatString(outputInfo, "_RIFF_chunk::Type", pHeader->riff.Type, 4);
	_FormatString(outputInfo, "_Format_chunk::ID", pHeader->format.ID, 4);
	_FormatString(outputInfo, "_Format_chunk::Size", pHeader->format.Size, 4);
	_FormatString(outputInfo, "_Format_chunk::AudioFormat", pHeader->format.AudioFormat, 2);
	_FormatString(outputInfo, "_Format_chunk::NumChannels", pHeader->format.NumChannels, 2);
	_FormatString(outputInfo, "_Format_chunk::SampleRate", pHeader->format.SampleRate, 4);
	_FormatString(outputInfo, "_Format_chunk::ByteRate", pHeader->format.ByteRate, 4);
	_FormatString(outputInfo, "_Format_chunk::BlockAlign", pHeader->format.BlockAlign, 2);
	_FormatString(outputInfo, "_Format_chunk::BitsPerSample", pHeader->format.BitsPerSample, 2);

	_Data_chunk* pData = 0;
	for (int i = 0; i < nLen; i++)
	{
		if ((int)strstr((char*)(&bt[i]), "data") == (int)(&bt[i]))
		{

			pData = (_Data_chunk*)(&bt[i]);
			break;
		}

	}

	_FormatString(outputInfo, "_Data_chunk::ID", pData->ID, 4);
	_FormatString(outputInfo, "_Data_chunk::Size", pData->Size, 4);

	_DataAnalyze(outputInfo, &pData->data, *(int*)&pData->Size);

	WCHAR* wc;
	UINT nLen_Wc;
	wc = new WCHAR[strlen(outputInfo) * 2];

	CBasicOperation::c2w(wc, nLen_Wc, outputInfo);
	wc[nLen_Wc] = 0;
	m_Output.SetWindowTextW(wc);
	delete wc;


}


//format to main string
void CWavAnalyzing::_FormatString(char* output, char* desc, char* address, int count)
{

	char temp[200];
	strcat(output, desc);
	strcat(output, "  ");

	for (int i = 0; i < count; i++)
	{
		sprintf(temp, "(d:%d-x:%x-c:%c)", (*(address + i)) & 0xff, (*(address + i)) & 0xff,
			(((*(address + i)) & 0xff) > 0x20 && ((*(address + i)) & 0xff) < 0x80) ? (*(address + i)) & 0xff : ' ');
		strcat(output, temp);
	}
	strcat(output, "\r\n");
}


void CWavAnalyzing::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
}


void CWavAnalyzing::_DataAnalyze(char* Output, char* cInfo, int nLen)
{
	int Voltage[2], lastVol[2];
	float outputWave[2];
	char temp[100];
	int max = 0, min = 0;
	int keep = 0, maxkeep = 0, lenFormat = 0;
	int charstringlength = 0;
	_16bit_DoubleChannel* pGet;
	pGet = (_16bit_DoubleChannel*)cInfo;
	Voltage[0] = 0;
	lastVol[0] = 1;
	::MoveToEx(dc, 10, 500, 0);

	//for (int i = 0; i < nLen; i++)
	for (int i = 0; i < nLen; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Voltage[j] = (0x00ff & pGet[i].dataLeftL) | ((pGet[i].dataLeftH << 8) & 0xff00);
			if (Voltage[j] & 0x8000)
				Voltage[j] |= 0xffff0000;
			outputWave[j] = (float)Voltage[j] / 150;
			Voltage[j] = (int)(((float)Voltage[j] * 127.0f) / 32765);
			Voltage[j] += 128;
		}

		if (max < Voltage[0])
			max = Voltage[0];
		if (min > Voltage[0])
			min = Voltage[0];

		if (Voltage[0] != lastVol[0] )
		{
			if (Voltage[0] != Voltage[1])
				i = i;
			if ((lenFormat % 8) == 0)
				strcat(Output, "\r\n");
#ifndef dec
			if (keep > 255)
			{
				int nPeriod;
				nPeriod = keep / 255;

				sprintf(temp, " 0x%02x, 0x%02x,", 255, Voltage[0]);
				charstringlength += 2;
				strcat(Output, temp);

				sprintf(temp, "  0x%02x,0x%02x, 0x%02x, 0x%02x,", keep & 0xff, 
					(keep >> 8) & 0xff, (keep >> 16) & 0xff, (keep >> 24) & 0xff);
				charstringlength += 4;
				//strcat(Output, temp);

				for (int j = 0; j < nPeriod; j++)
				{
					//sprintf(temp, " %02x, %02x,", 255, Voltage[0]);
					//strcat(Output, temp);
				}
				//sprintf(temp, " 0x%02x, 0x%02x,", 255, Voltage[0]);
				// 
				// ///tail num
				//sprintf(temp, " 0x%02x, 0x%02x,", keep % 255, Voltage[0]);
				//strcat(Output, temp);
			}
			else
			{
				sprintf(temp, " 0x%02x, 0x%02x,", keep, Voltage[0]);
				charstringlength += 2;
				strcat(Output, temp);
			}
#endif
			_PrintWaveToTarget(i, (int)2 * outputWave[0]);
			if (keep > maxkeep)
				maxkeep = keep;
			keep = 0;
			lenFormat++;

			lastVol[0] = Voltage[0];
		}
		keep++;
	}
	sprintf(temp, "max:%d|min:%d | maxkeep:%d | totallen:%d | fileWaveSignal:%d, outputStringLen:%d",
		max, min, maxkeep, lenFormat * 2, nLen, charstringlength);
	strcat(Output, temp);
}


void CWavAnalyzing::_PrintWaveToTarget(int i, int voltage)
{
	float x, y;
	float fLeft = 10, fBottom = 500, fScale = 0.08, xShift = -0;
	x = i;
	y = voltage;
	::LineTo(dc, (int)(x * fScale) + fLeft + xShift, (int)(fBottom - y));
	//::SetPixel(dc, (int)(x * fScale) + fLeft, (int)(fBottom - y), 0);

}
