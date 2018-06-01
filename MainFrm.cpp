
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "MFCLibrary.h"

#include "MainFrm.h"
#include "DisplayView.h"
#include "SelectView.h"
#include "InfoDailog.h"
#include "BooksInfo.h"
#include "AddDailog.h"
#include "DelDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	//MESSAGE ��Ӧ�����Զ�����Ϣ
	ON_MESSAGE(VM_A,OnMychange)
	ON_MESSAGE(VM_B,OnMychange)
	ON_MESSAGE(VM_C,OnMychange)
	ON_MESSAGE(VM_D,OnMychange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));


	//����icon
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(ICON_LOGIN));
	//���ñ���
	SetTitle(TEXT("1.0"));
	MoveWindow(0, 0, 800, 500);

	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//��̬���
	m_split.CreateStatic(this, 1, 2);

	//������ͼ
	m_split.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);
	m_split.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);


	return TRUE;
}

LRESULT CMainFrame::OnMychange(WPARAM wParam, LPARAM lParam)
{
	//����һ��CCREATCONTEXT����
	CCreateContext context;
	
	//�ж���Ϣ
	if (VM_A == wParam)
	{
		//��Ϣ�������
		//�����µ���ͼ
		context.m_pNewViewClass = RUNTIME_CLASS(CInfoDailog);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_split.GetPane(0, 1);

		m_split.DeleteView(0, 1);
		m_split.CreateView(0, 1, RUNTIME_CLASS(CInfoDailog), CSize(600, 500), &context);
		CInfoDailog *newInfo = (CInfoDailog*)m_split.GetPane(0, 1);
		
		m_split.RecalcLayout();
		newInfo->OnInitialUpdate();
		m_split.SetActivePane(0, 1);

	}
	else if (VM_B == wParam)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CBooksInfo);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_split.GetPane(0, 1);

		m_split.DeleteView(0, 1);
		m_split.CreateView(0, 1, RUNTIME_CLASS(CBooksInfo), CSize(600, 500), &context);
		CBooksInfo   *newInfo = (CBooksInfo*)m_split.GetPane(0, 1);

		m_split.RecalcLayout();
		newInfo->OnInitialUpdate();
		m_split.SetActivePane(0, 1);
	}
	else if (VM_C == wParam)
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CAddDailog);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_split.GetPane(0, 1);

		m_split.DeleteView(0, 1);
		m_split.CreateView(0, 1, RUNTIME_CLASS(CAddDailog), CSize(600, 500), &context);
		CAddDailog *newInfo = (CAddDailog*)m_split.GetPane(0, 1);

		m_split.RecalcLayout();
		newInfo->OnInitialUpdate();
		m_split.SetActivePane(0, 1);
	}
	else
	{
		context.m_pNewViewClass = RUNTIME_CLASS(CDelDialog);
		context.m_pCurrentFrame = this;
		context.m_pLastView = (CFormView *)m_split.GetPane(0, 1);

		m_split.DeleteView(0, 1);
		m_split.CreateView(0, 1, RUNTIME_CLASS(CDelDialog), CSize(600, 500), &context);
		CDelDialog *newInfo = (CDelDialog*)m_split.GetPane(0, 1);

		m_split.RecalcLayout();
		newInfo->OnInitialUpdate();
		m_split.SetActivePane(0, 1);
	}

	return 0;
}
