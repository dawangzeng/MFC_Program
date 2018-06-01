
// MFCLibraryView.cpp : CMFCLibraryView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCLibrary.h"
#endif

#include "MFCLibraryDoc.h"
#include "MFCLibraryView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCLibraryView

IMPLEMENT_DYNCREATE(CMFCLibraryView, CView)

BEGIN_MESSAGE_MAP(CMFCLibraryView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCLibraryView ����/����

CMFCLibraryView::CMFCLibraryView()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCLibraryView::~CMFCLibraryView()
{
}

BOOL CMFCLibraryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCLibraryView ����

void CMFCLibraryView::OnDraw(CDC* /*pDC*/)
{
	CMFCLibraryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFCLibraryView ��ӡ

BOOL CMFCLibraryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFCLibraryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFCLibraryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFCLibraryView ���

#ifdef _DEBUG
void CMFCLibraryView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCLibraryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCLibraryDoc* CMFCLibraryView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCLibraryDoc)));
	return (CMFCLibraryDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCLibraryView ��Ϣ�������
