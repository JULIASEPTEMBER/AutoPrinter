#pragma once
#include "afxdialogex.h"


struct _RIFF_chunk {
	//以'RIFF'为标识
	//Size是整个文件的长度减去ID和Size的长度
	//Type是WAVE表示后面需要两个子块：Format区块和Data区块
	char ID[4], Size[4], Type[4];
};
struct _Format_chunk {
	//以'fmt '为标识
	//Size表示该区块数据的长度（不包含ID和Size的长度）
	//AudioFormat表示Data区块存储的音频数据的格式，PCM音频数据的值为1
	//NumChannels表示音频数据的声道数，1：单声道，2：双声道
	//SampleRate表示音频数据的采样率
	//ByteRate每秒数据字节数 = SampleRate * NumChannels * BitsPerSample / 8
	//BlockAlign每个采样所需的字节数 = NumChannels * BitsPerSample / 8
	//BitsPerSample每个采样存储的bit数，8：8bit，16：16bit，32：32bit
	char ID[4], Size[4], AudioFormat[2], NumChannels[2], SampleRate[4], ByteRate[4], BlockAlign[2], BitsPerSample[2];
};
struct _Data_chunk {
	//以'data'为标识
	//Size表示音频数据的长度，N = ByteRate * seconds
	//后续为音频数据
	char ID[4], Size[4], data;
};
struct _8bit_SingleChannel {
	char data;
};
struct _8bit_DoubleChannel {
	char dataLeft, dataRight;
};
struct _16bit_SingleChannel {
	char dataLeftL, dataLeftH;
};
struct _16bit_DoubleChannel {/////
	char dataLeftL, dataLeftH, dataRightL, dataRightH;
};
struct _WAV_HEADER {
	_RIFF_chunk riff;
	_Format_chunk format; 
};
// CWavAnalyzing 对话框


class CWavAnalyzing : public CDialogEx
{
	DECLARE_DYNAMIC(CWavAnalyzing)

public:
	CWavAnalyzing(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWavAnalyzing();

	// 对话框数据 
	enum { IDD = IDD_DIALOG_WAV };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void _GetFile();
	//create dialog
	void _CreateDialog();
	// path
	CEdit m_Edit_Path;
	afx_msg void OnBnClickedButtonOpen();
	CEdit m_Output; 
	//analyzing 
	void _AnalyzeWaveFile(BYTE* bt, UINT nLen);
	//format to main string
	void _FormatString(char* output, char* desc, char* address, int count);
	virtual void OnOK();
	void _DataAnalyze(char* Output, char* cInfo, int nLen);
	HDC dc;
	void _PrintWaveToTarget(int i, int voltage);
};
