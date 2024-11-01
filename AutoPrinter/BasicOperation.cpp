// BasicOperation.cpp : 实现文件
//

#include "stdafx.h"
#include "BasicOperation.h" 


// CBasicOperation
 
	CBasicOperation::CBasicOperation()
{

}

CBasicOperation::~CBasicOperation()
{
}
 



// CBasicOperation 消息处理程序





void CBasicOperation::SaveFile_InPath(WCHAR* csPath, BYTE* bt, UINT nLen)
{
#ifdef WINMFC_STYLE 
	//////////////////////////////////////
	CString csSend;

	WCHAR ccPath[255], ccDirectory[255];
	UINT nLenccDirectory;
	GetCurrentDirectory(255, ccPath);
	csSend = ccPath;

	csSend += "\\";
	csSend += csPath;
	wcscpy(ccDirectory, csSend);
	nLenccDirectory = sizeof(ccDirectory)/ sizeof(WCHAR);
	for(int i = nLenccDirectory  - 1 ;i > -1 ;i --) 
	{
		if(ccDirectory[i] == '\\')
		{
			ccDirectory[i] = 0;
			break;
		}
	}
	nLenccDirectory = sizeof(ccDirectory);
	for(int i = 0 ;i < nLenccDirectory ; i ++) 
	{
		if(ccDirectory[i] == '\\')
		{
			ccDirectory[i] = 0;
			if(!FolderPathExist(ccDirectory))
				CreateFolderPath(ccDirectory);
			ccDirectory[i] = '\\';

		}
	}
	if(!FolderPathExist(ccDirectory))
		if(!CreateFolderPath(ccDirectory))
			::MessageBox(0, L"Failed", L"Failed" ,0);
	/////////////////////////////////////////////////////////////
	DWORD dw;	
	HANDLE hFile;	   																 
	::DeleteFile(csSend);
	hFile = ::CreateFile(csSend, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  

	::WriteFile(hFile,  bt, nLen, &dw, 0);  
	::CloseHandle(hFile);
#endif
	
	DWORD dw;	
	HANDLE hFile;	   																 
	::DeleteFileW(csPath);
	hFile = ::CreateFileW(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);  

	::WriteFile(hFile,  bt, nLen, &dw, 0);  
	::CloseHandle(hFile);
	//	csoutput += L"存储文件成功" ;
	//	m_output.SetWindowTextW(csoutput);

}


void CBasicOperation::ReadFile_InPath(WCHAR* csPath, BYTE* bt, UINT &nLen)
{

#ifdef WINMFC_STYLE 
	//////////////////////////////////////
	CString csSend;

	WCHAR ccPath[255], ccDirectory[255];
	UINT nLenccDirectory;
	GetCurrentDirectory(255, ccPath);
	csSend = ccPath;

	csSend += L"\\";
	csSend += csPath;
	//////////////////////////////////////

	DWORD dw;
	HANDLE hFile;
	hFile = ::CreateFile(csSend, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL); 
	nLen = ::GetFileSize(hFile, NULL) ;
	if(nLen == 0)
	{
		::CloseHandle(hFile);

		return ;
	}
	::ReadFile(hFile,  bt, nLen , &dw, 0); 

	::CloseHandle(hFile);
	//---
#endif
	DWORD dw;
	HANDLE hFile;
	hFile = ::CreateFileW(csPath, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL); 
	nLen = ::GetFileSize(hFile, NULL) ;
	if(nLen == 0)
	{
		::CloseHandle(hFile);

		return ;
	}
	::ReadFile(hFile,  bt, nLen , &dw, 0); 

	::CloseHandle(hFile);
}


void CBasicOperation::c2w(wchar_t *pwstr,size_t &len,const char *str)

{

	if(str)

	{

		size_t nu = strlen(str);

		size_t n =(size_t)MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,NULL,0);

		//if(n>=len)n=len-1;

		MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,pwstr,(int)n);

		pwstr[n]=0;
		len = n;
	}

}


int CBasicOperation::w2c(char *pcstr,const wchar_t *pwstr, size_t& len)

{
	int nlength=wcslen(pwstr);

	//获取转换后的长度
	int nbytes = WideCharToMultiByte( 0, // specify the code page used to perform the conversion
		0,         // no special flags to handle unmapped characters
		pwstr,     // wide character string to convert
		nlength,   // the number of wide characters in that string
		NULL,      // no output buffer given, we just want to know how long it needs to be
		0,

		NULL,      // no replacement character given
		NULL );    // we don't want to know if a character didn't make it through the translation

	// make sure the buffer is big enough for this, making it larger if necessary
	/*if(nbytes>len)   nbytes=len;
	else*/ len = nbytes;
	// 通过以上得到的结果，转换unicode 字符为ascii 字符
	WideCharToMultiByte( 0, // specify the code page used to perform the conversion
		0,         // no special flags to handle unmapped characters
		pwstr,   // wide character string to convert
		nlength,   // the number of wide characters in that string
		pcstr, // put the output ascii characters at the end of the buffer
		nbytes,                           // there is at least this much space there
		NULL,      // no replacement character given
		NULL ); 
	return len ; 
}


CString CBasicOperation::GetComState(WCHAR* csPath)
{
#ifndef WINMFC_STYLE 
	CString csComSet;

	BYTE bt[100];
	WCHAR wc[100];
	UINT nLen;
	ReadFile_InPath(csPath, bt, nLen);
	bt[nLen] = 0;
	c2w(wc, nLen, (char*)bt);
	int com;
	com = _wtoi(wc);
	if(com == 0)
	{
		//MessageBox(L"badinitVariable: Error");
		return L"";
	}
	else if(com >= 10)
		csComSet.Format(L"\\\\.\\com%d", com);
	else
		csComSet.Format(L"com%d", com);
	return csComSet;
#endif
	return 0;
}


int CBasicOperation::fArrayStrFind(WCHAR*wcBf,int nLen1,  WCHAR *wcCtr, int nLen2 )
{
	int i,m ,rx;
	UINT nBl,nCn;
	nBl  =nLen1;
	nCn=nLen2;

	static int countThis;
	countThis ++;
	rx=0;
	for(i=0;i<(int)nBl-(int)nCn;i++)
	{ 	
	if(wcBf[i] == wcCtr[0])
	{ 	rx=1;	for(m=1;m<(int)nCn;m++)	{	if( wcBf[i+m]!=wcCtr[m]){	rx=0;	break;	}}}
	if(rx)			break;
	}	return rx;	
}

 

 

 

 




BOOL CBasicOperation::FolderPathExist(WCHAR* strPath)
{
	WIN32_FIND_DATA wfd;
	BOOL bValue = FALSE;
	HANDLE hFind = ::FindFirstFile(strPath, &wfd);
	if( (hFind != INVALID_HANDLE_VALUE) && (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
	{
		bValue = TRUE;
	}
	::FindClose(hFind);
	return bValue;
}


BOOL CBasicOperation::CreateFolderPath(WCHAR* strPath)
{
	SECURITY_ATTRIBUTES attrib;
	attrib.bInheritHandle = FALSE;
	attrib.lpSecurityDescriptor = NULL;
	attrib.nLength = sizeof(SECURITY_ATTRIBUTES);
	return ::CreateDirectory(strPath, &attrib);
}


UINT CBasicOperation::TransformToHex(WCHAR* csInput, BYTE* Result, UINT& nLen)
{
#ifdef WINMFC_STYLE 

	WCHAR* wcIpt;
	UINT nLength;
	BYTE Get[2];
	CString csKeyWords;
	UINT nLenKey;
	UINT Found;
	csKeyWords = L" 0123456789ABCDEFabcdef";
	nLenKey = csKeyWords.GetLength();
	WCHAR wcKey[30];
	wcscpy(wcKey, csKeyWords);


	nLength = csInput.GetLength();
	if(!nLength)return 0;
	wcIpt = new WCHAR[nLength + 1];
	wcscpy(wcIpt, csInput);
	wcIpt[nLength] = 0;


	nLen = 0;
	for(int i = 0 ;i < nLength; i ++)
	{
		Found = 0;

		for(int j = 0; j < nLenKey; j ++)
		{
			if(wcKey[j] == wcIpt[i])
				Found = j + 1;
		}

		if (!Found){delete wcIpt;return 0;}

		if(Found == 1)continue;

		{
			if(TransformSingleToHex(wcIpt[i], Get + 0) &&
				TransformSingleToHex(wcIpt[i + 1], Get + 1))
			{
				Result[nLen] = Get[0] << 4 | Get[1];
				i ++;
			}
		}
		nLen ++;
	}


	delete wcIpt;
	return 1;
#endif
	return 1;
}


int CBasicOperation::TransformSingleToHex(WCHAR wc, BYTE* btResult) 
{
	switch(wc)
	{
	case '0': btResult[0] =  0; return 1;
	case '1': btResult[0] =  1; return 1;
	case '2': btResult[0] =  2; return 1;
	case '3': btResult[0] =  3; return 1;
	case '4': btResult[0] =  4; return 1;
	case '5': btResult[0] =  5; return 1;
	case '6': btResult[0] =  6; return 1;
	case '7': btResult[0] =  7; return 1;
	case '8': btResult[0] =  8; return 1;
	case '9': btResult[0] =  9; return 1;
	case 'a': btResult[0] = 10; return 1;
	case 'b': btResult[0] = 11; return 1;
	case 'c': btResult[0] = 12; return 1;
	case 'd': btResult[0] = 13; return 1;
	case 'e': btResult[0] = 14; return 1;
	case 'f': btResult[0] = 15; return 1;
	case 'A': btResult[0] = 10; return 1;
	case 'B': btResult[0] = 11; return 1;
	case 'C': btResult[0] = 12; return 1;
	case 'D': btResult[0] = 13; return 1;
	case 'E': btResult[0] = 14; return 1;
	case 'F': btResult[0] = 15; return 1;
	}
	return 0;
}


int CBasicOperation::GetIntFromEdit(CEdit* edit)
{
	CString cs;
	edit->GetWindowTextW(cs);
	return _wtoi(cs);

}


void CBasicOperation::SetIntFromEdit(CEdit* edit, int info)
{
	CString cs;
	cs.Format(L"%d", info);
	edit->SetWindowTextW(cs);
}