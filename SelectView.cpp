// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCLibrary.h"
#include "SelectView.h"
#include "MainFrm.h"

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//获取树控件
	m_ctrl = &GetTreeCtrl();
	// TODO: 在此添加专用代码和/或调用基类
	//准备图片列表
	HICON icon1 = AfxGetApp()->LoadIconW(ICON1_USER);
	HICON icon2 = AfxGetApp()->LoadIconW(ICON_SHOW);
	HICON icon3 = AfxGetApp()->LoadIconW(ICON_ADD);
	HICON icon4 = AfxGetApp()->LoadIconW(ICON_DELETE);

	//图片列表创建，和加入到图片列表中
	m_list.Create(55, 55, ILC_COLOR32, 4, 4);
	m_list.Add(icon1);
	m_list.Add(icon2);
	m_list.Add(icon3);
	m_list.Add(icon4);
	m_ctrl->SetImageList(&m_list, TVSIL_NORMAL);
	//添加树节点
	m_ctrl->InsertItem(TEXT("登录信息"), 0, 0, NULL);
	m_ctrl->InsertItem(TEXT("图书库存"), 1, 1, NULL);
	m_ctrl->InsertItem(TEXT("添加库存"), 2, 2, NULL);
	m_ctrl->InsertItem(TEXT("删除库存"), 3, 3, NULL);
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM item = m_ctrl->GetSelectedItem();//获取现在选的节点

	//获取节点信息
	CString str = m_ctrl->GetItemText(item);

	if (str == TEXT("登录信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),VM_A, (WPARAM)VM_A, (LPARAM)0);
	}
	else if (str == TEXT("图书库存"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), VM_B, (WPARAM)VM_B, (LPARAM)0);
	}
	else if (str == TEXT("添加库存"))
	{
		
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), VM_C, (WPARAM)VM_C, (LPARAM)0);
	}
	else 
	{
		
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), VM_D, (WPARAM)VM_D, (LPARAM)0);
	}
}
