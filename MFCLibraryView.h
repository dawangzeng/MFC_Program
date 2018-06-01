
// MFCLibraryView.h : CMFCLibraryView ��Ľӿ�
//

#pragma once


class CMFCLibraryView : public CView
{
protected: // �������л�����
	CMFCLibraryView();
	DECLARE_DYNCREATE(CMFCLibraryView)

// ����
public:
	CMFCLibraryDoc* GetDocument() const;

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
	virtual ~CMFCLibraryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCLibraryView.cpp �еĵ��԰汾
inline CMFCLibraryDoc* CMFCLibraryView::GetDocument() const
   { return reinterpret_cast<CMFCLibraryDoc*>(m_pDocument); }
#endif

