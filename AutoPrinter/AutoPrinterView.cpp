
// AutoPrinterView.cpp : CAutoPrinterView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "AutoPrinter.h"
#endif

#include "AutoPrinterDoc.h"
#include "AutoPrinterView.h" 


#include "GB2312.h"
#include "ASCII_16X16.h"

#include "PrintingAnalzye.h"

#include "CWavAnalyzing.h"
#include "BasicOperation.h"
#include "CPrinterView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CWavAnalyzing m_WavAnalyzing;
// CAutoPrinterView
IMPLEMENT_DYNCREATE(CAutoPrinterView, CView)

	BEGIN_MESSAGE_MAP(CAutoPrinterView, CView)
		// ��׼��ӡ����
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAutoPrinterView::OnFilePrintPreview)
		ON_WM_CONTEXTMENU()
		ON_WM_RBUTTONUP()
		ON_WM_LBUTTONDOWN()
		ON_WM_CHAR()
		ON_WM_CREATE()
	END_MESSAGE_MAP()
	// CAutoPrinterView ����/����

	CAutoPrinterView::CAutoPrinterView()
	{

		start = 1471;
		// TODO: �ڴ˴���ӹ������
	}

	CAutoPrinterView::~CAutoPrinterView()
	{
	}

	BOOL CAutoPrinterView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: �ڴ˴�ͨ���޸�
		//  CREATESTRUCT cs ���޸Ĵ��������ʽ

		return CView::PreCreateWindow(cs);
	}

	// CAutoPrinterView ����

	void CAutoPrinterView::OnDraw(CDC* /*pDC*/)
	{
		CAutoPrinterDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	}


	// CAutoPrinterView ��ӡ


	void CAutoPrinterView::OnFilePrintPreview()
	{
#ifndef SHARED_HANDLERS
		AFXPrintPreview(this);
#endif
	}

	BOOL CAutoPrinterView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// Ĭ��׼��
		return DoPreparePrinting(pInfo);
	}

	void CAutoPrinterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
	}

	void CAutoPrinterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: ��Ӵ�ӡ����е��������
	}

	void CAutoPrinterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
	{
		ClientToScreen(&point);
		OnContextMenu(this, point);
	}

	void CAutoPrinterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
	{
#ifndef SHARED_HANDLERS
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
	}


	// CAutoPrinterView ���

#ifdef _DEBUG
	void CAutoPrinterView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CAutoPrinterView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CAutoPrinterDoc* CAutoPrinterView::GetDocument() const // �ǵ��԰汾��������
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAutoPrinterDoc)));
		return (CAutoPrinterDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CAutoPrinterView ��Ϣ�������


	void CAutoPrinterView::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		CString cs;
		char cinfo[] = "����";
		cs.Format(L"start:%d, %x�� %x %x�� %x  %x�� %x", start, cinfo[0], cinfo[1],cinfo[2], cinfo[3],cinfo[4], cinfo[5]);//�� 1427
		MessageBox(cs);
		CView::OnLButtonDown(nFlags, point);
	}


	void scaleBitmap(int* original, int origHeight, int origWidth, int* scaled, float scaleFactor) {
		int newHeight = (int)(origHeight * scaleFactor);
		int newWidth = (int)(origWidth * scaleFactor);

		// Perform nearest neighbor scaling
		for (int i = 0; i < newHeight; i++) {
			for (int j = 0; j < newWidth; j++) {
				// Map back to the original pixel using the scale factor
				int origX = (int)(i / scaleFactor);
				int origY = (int)(j / scaleFactor);

				// Assign the corresponding pixel
				*(scaled + i * newWidth + j) = *(original + origX * origWidth + origY);
			}
		}

		// Output the scaled matrix (optional, can be returned or used elsewhere)
		for (int i = 0; i < newHeight; i++) {
			for (int j = 0; j < newWidth; j++) {
				printf("%d ", *(scaled + i * newWidth + j));
			}
			printf("\n");
		}
	}

	void DrawScaledCharacter(HDC dc, _WORD16x16 word, int k, float scaleFactor) {
		for (int i = 0; i < _WORD2312::hor; i++)  // Loop through the font matrix rows
		{
			BYTE bt = (word.Word[i]) & 0xff;  // Get the lower 8 bits
			BYTE bt1 = (word.Word[i] >> 8) & 0xff;  // Get the upper 8 bits

			// First part of the character (bt1)
			for (int j = 0; j < 8; j++) {
				if (bt1 & (1 << j)) {  // If the j-th bit is set
					for (int m = 0; m < scaleFactor; m++)  // Scale height
					{
						for (int n = 0; n < scaleFactor; n++)  // Scale width
						{
							::SetPixel(dc,
								(int)(scaleFactor * (16 * k + 200 - j) + n),
								(int)(200 + i * scaleFactor + m),
								0);  // Set black pixel
						}
					}
				}
			}

			// Second part of the character (bt)
			for (int j = 0; j < 8; j++) {
				if (bt & (1 << j)) {  // If the j-th bit is set
					for (int m = 0; m < scaleFactor; m++)  // Scale height
					{
						for (int n = 0; n < scaleFactor; n++)  // Scale width
						{
							::SetPixel(dc,
								(int)(scaleFactor * (16 * k + 192 - j) + n),
								(int)(200 + i * scaleFactor + m),
								0);  // Set black pixel
						}
					}
				}
			}
		}
	}

	void DisplayScaledText(HDC dc, char* cString, float scaleFactor, _WORD16x16* GB2312_Font) {
		for (int k = 0; k < 10; k++) {
			UINT Get = (cString[0 + k * 2] & 0xff) << 8 | (cString[1 + k * 2] & 0xff);
			UINT high = (Get >> 8) - 0xA1;
			UINT low = (Get & 0xff) - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;

			int start = resultCal;
			_WORD16x16 word = GB2312_Font[start];

			// Call the drawing function for each character
			DrawScaledCharacter(dc, word, k, scaleFactor);
		}
	}
	void CAutoPrinterView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		switch (nChar)
		{
		case '1':
			_Format_Info("2123123asdf΢��ɨһɨ�·��Ķ�ά�룬���");
			_Format_Info("���ǵļ���\r\n��ϣ������Ұ��\r\n  123qwe@#$");
			break;
		case 'a':
			start = 0;
			break;
		case 'm':
		{
			HDC dc;
			dc = ::GetDC(m_hWnd);
			_WORD16x16 word;
			start--;
			word = ((_WORD16x16*)GB2312_Font)[start];
			for (int i = 0; i < _WORD2312::hor; i++)
			{
				BYTE bt = (word.Word[i]) & 0xff;
				BYTE bt1 = (word.Word[i] >> 8) & 0xff;
				for (int j = 0; j < 8; j++)
				{
					::SetPixel(dc, 200 - j, 200 + i, bt1 & (1 << j) ? 0 : 0xffffff);
				}
				for (int j = 0; j < 8; j++)
				{
					::SetPixel(dc, 200 - j - 8, 200 + i, bt & (1 << j) ? 0 : 0xffffff);
				}
			}
			//start ++;
			::DeleteDC(dc);
		}
		break;
		case 'x':
		{
			HDC dc;
			dc = ::GetDC(m_hWnd);
			_WORD16x16 word;
			char cString[] = "�ٺٴ�Һã�������������";

			//for (int k = 0; k < 10; k++)
			//{
			//	UINT Get = (cString[0 + k * 2] & 0xff) << 8 | (cString[1 + k * 2] & 0xff);
			//	UINT high = (Get >> 8) - 0xA1;
			//	UINT low = (Get & 0xff) - 0xA1;
			//	UINT delta = 6 * 16 - 2;
			//	UINT resultCal = high * delta + low;
			//
			//	start = resultCal;
			//	word = ((_WORD16x16*)GB2312_Font)[start];
			//	for (int i = 0; i < _WORD2312::hor; i++)
			//	{
			//		BYTE bt = (word.Word[i]) & 0xff;
			//		BYTE bt1 = (word.Word[i] >> 8) & 0xff;
			//		for (int j = 0; j < 8; j++)
			//		{
			//			
			//			::SetPixel(dc, 16 * k + 200 - j, 200 + i, bt1 & (1 << j) ? 0 : 0xffffff);
			//		}
			//		for (int j = 0; j < 8; j++)
			//		{
			//			::SetPixel(dc, 16 * k + 200 - j - 8, 200 + i, bt & (1 << j) ? 0 : 0xffffff);
			//		}
			//	}
			//}

			float scaleFactor = 0.8;  // Scaling factor, adjust as needed

			DisplayScaledText(dc, cString, scaleFactor, (_WORD16x16*)GB2312_Font);
			::DeleteDC(dc);
		}
		break;
		case 't':
		{

		}
			break;
		case 'k':
		{
			HDC dc;
			dc = ::GetDC(m_hWnd);
			_WORD16x16 word;
			char cString[] = "��";
			UINT Get = (cString[0] & 0xff) << 8 | (cString[1] & 0xff);
			UINT high = (Get >> 8) - 0xA1;
			UINT low = (Get & 0xff) - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;

			start = resultCal;
			word = ((_WORD16x16*)GB2312_Font)[start];
			for (int i = 0; i < _WORD2312::hor; i++)
			{
				BYTE bt = (word.Word[i]) & 0xff;
				BYTE bt1 = (word.Word[i] >> 8) & 0xff;
				for (int j = 0; j < 8; j++)
				{
					::SetPixel(dc, 200 - j, 200 + i, bt1 & (1 << j) ? 0 : 0xffffff);
				}
				for (int j = 0; j < 8; j++)
				{
					::SetPixel(dc, 200 - j - 8, 200 + i, bt & (1 << j) ? 0 : 0xffffff);
				}
			}
			//start ++;
			::DeleteDC(dc);
		}
		break;
		case ' ':
		{
			HDC dc;
			dc = ::GetDC(m_hWnd);
			_WORD16x16 word;
			int  enable = 1;
#ifndef decdec
			//while(enable)
			{
				start++;
				word = ((_WORD16x16*)GB2312_Font)[start];
				//if((282752 - 256) / 32 <= start)
				//{
				//	MessageBox(L"last");
				//	break;
				//}
				//for(int i = 0; i < 16; i ++)
				//{
				//	if(word.Word[i] != 0)
				//		enable = 0; break;
				//}

			}
#else
			int plus = 43807;
			char cString[] = "��";
			UINT Get = (cString[0] & 0xff) << 8 | (cString[1] & 0xff);
			UINT high = (Get >> 8) - 0xA1;
			UINT low = Get & 0xff - 0xA1;
			UINT delta = 6 * 16 - 2;
			UINT resultCal = high * delta + low;

			start = resultCal;
			word = ((_WORD16x16*)GB2312_Font)[start];
#endif
			for (int i = 0; i < _WORD2312::hor; i++)
			{
				BYTE bt = (word.Word[i]) & 0xff;
				BYTE bt1 = (word.Word[i] >> 8) & 0xff;
				for (int j = 0; j < 8; j++)
				{
					::SetPixel(dc, 200 - j, 200 + i, bt1 & (1 << j) ? 0 : 0xffffff);
				}
				for (int j = 0; j < 8; j++)
				{
					::SetPixel(dc, 200 - j - 8, 200 + i, bt & (1 << j) ? 0 : 0xffffff);
				}
			}
			//start ++;
			::DeleteDC(dc);
		}
		break;
		case 'p':
		{
			::MessageBoxA(0, _WIFI_PRINTER_DESCIPTION, 0, 0);
			char string[2000], cTemp[256];
			int len = strlen(_WIFI_PRINTER_DESCIPTION);
			string[0] = 0;
			sprintf(cTemp, "%d", len);
			::MessageBoxA(0, cTemp, 0, 0);
			for (int i = 0; i < len; i++)
			{
				sprintf(cTemp, "0x%02x, ", _WIFI_PRINTER_DESCIPTION[i] & 0xff);
				strcat(string, cTemp);
			}

			::MessageBoxA(0, string, 0, 0);
			CBasicOperation::SaveFile_InPath(L"xx.txt", (BYTE*)string, strlen(string));

		}
			break;
		}
		CView::OnChar(nChar, nRepCnt, nFlags);
	}


	void  CAutoPrinterView::TCPCreatThread(void)
	{

		m_pThread_TCP =
			AfxBeginThread(TCPThreadProc,this, THREAD_PRIORITY_NORMAL, 0,CREATE_SUSPENDED, NULL );

		if ( m_pThread_TCP)
		{
			m_pThread_TCP->m_bAutoDelete = FALSE;
			m_pThread_TCP->ResumeThread();
		}




		/*   */
	}

	UINT TCPThreadProc(LPVOID pm)
	{
		while(1)
		{
			_PrintThread();

			::Sleep(10);
		}
		return 1;
	}

	int CAutoPrinterView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CView::OnCreate(lpCreateStruct) == -1)
			return -1;
		_Init_FontBuffer();
		PRINTING_ExchangeData(0, TransformClass, 0);  
		TCPCreatThread();
		// TODO:  �ڴ������ר�õĴ�������
		dc_Get = ::GetDC(m_hWnd);
		m_WavAnalyzing._CreateDialog();
		m_WavAnalyzing.dc = ::GetDC(m_hWnd);
		return 0;
	}


	int CALLBACK CAutoPrinterView::TransformClass(int *pInfo) //par   
	{


		return 1;

	}
