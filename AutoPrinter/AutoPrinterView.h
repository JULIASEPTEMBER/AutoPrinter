
// AutoPrinterView.h : CAutoPrinterView 类的接口
//

#pragma once


class CAutoPrinterView : public CView
{
protected: // 仅从序列化创建
	CAutoPrinterView();
	DECLARE_DYNCREATE(CAutoPrinterView)

// 特性
public:
	CAutoPrinterDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CAutoPrinterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#define _WIFI_PRINTER_DESCIPTION "欢迎使用键科打印机\r\n\
设备编号：%s\r\n\
生产公司代码：%s\r\n\
产品批号：%s\r\n\
购买渠道：%s\r\n\
出厂日期：%s\r\n\
软件版本：%s\r\n\
客服电话：%s\r\n\
工厂地址:宝安区新桥街道\r\n\
Wi-Fi 名称：\r\n\
%s\r\n\
密码：\r\n\
%s\r\n\
【菜单】     【返回】"
#ifndef _DEBUG  // AutoPrinterView.cpp 中的调试版本
inline CAutoPrinterDoc* CAutoPrinterView::GetDocument() const
   { return reinterpret_cast<CAutoPrinterDoc*>(m_pDocument); }
#endif

