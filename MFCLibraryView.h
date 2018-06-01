
// MFCLibraryView.h : CMFCLibraryView 类的接口
//

#pragma once


class CMFCLibraryView : public CView
{
protected: // 仅从序列化创建
	CMFCLibraryView();
	DECLARE_DYNCREATE(CMFCLibraryView)

// 特性
public:
	CMFCLibraryDoc* GetDocument() const;

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
	virtual ~CMFCLibraryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCLibraryView.cpp 中的调试版本
inline CMFCLibraryDoc* CMFCLibraryView::GetDocument() const
   { return reinterpret_cast<CMFCLibraryDoc*>(m_pDocument); }
#endif

