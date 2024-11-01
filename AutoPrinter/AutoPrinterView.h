
// AutoPrinterView.h : CAutoPrinterView ��Ľӿ�
//

#pragma once


class CAutoPrinterView : public CView
{
protected: // �������л�����
	CAutoPrinterView();
	DECLARE_DYNCREATE(CAutoPrinterView)

// ����
public:
	CAutoPrinterDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CAutoPrinterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	int start;

	CWinThread* m_pThread_TCP;
	void TCPCreatThread(void);
	friend UINT TCPThreadProc(LPVOID pm);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	static int CALLBACK TransformClass(int *pInfo); //par

};

#define _WIFI_PRINTER_DESCIPTION "��ӭʹ�ü��ƴ�ӡ��\r\n\
�豸��ţ�%s\r\n\
������˾���룺%s\r\n\
��Ʒ���ţ�%s\r\n\
����������%s\r\n\
�������ڣ�%s\r\n\
����汾��%s\r\n\
�ͷ��绰��%s\r\n\
������ַ:���������Žֵ�\r\n\
Wi-Fi ���ƣ�\r\n\
%s\r\n\
���룺\r\n\
%s\r\n\
���˵���     �����ء�"
#ifndef _DEBUG  // AutoPrinterView.cpp �еĵ��԰汾
inline CAutoPrinterDoc* CAutoPrinterView::GetDocument() const
   { return reinterpret_cast<CAutoPrinterDoc*>(m_pDocument); }
#endif

