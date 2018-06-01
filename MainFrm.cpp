
// MainFrm.cpp : CMainFrame 类的实现
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
	//MESSAGE 响应的是自定义消息
	ON_MESSAGE(VM_A,OnMychange)
	ON_MESSAGE(VM_B,OnMychange)
	ON_MESSAGE(VM_C,OnMychange)
	ON_MESSAGE(VM_D,OnMychange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));


	//设置icon
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(ICON_LOGIN));
	//设置标题
	SetTitle(TEXT("1.0"));
	MoveWindow(0, 0, 800, 500);

	CenterWindow();

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	//静态拆分
	m_split.CreateStatic(this, 1, 2);

	//创建视图
	m_split.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);
	m_split.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(600, 500), pContext);


	return TRUE;
}

LRESULT CMainFrame::OnMychange(WPARAM wParam, LPARAM lParam)
{
	//创建一个CCREATCONTEXT对象
	CCreateContext context;
	
	//判断消息
	if (VM_A == wParam)
	{
		//消息处理机制
		//创建新的视图
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
