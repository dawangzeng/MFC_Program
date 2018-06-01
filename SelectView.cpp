// SelectView.cpp : ʵ���ļ�
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


// CSelectView ���

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


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//��ȡ���ؼ�
	m_ctrl = &GetTreeCtrl();
	// TODO: �ڴ����ר�ô����/����û���
	//׼��ͼƬ�б�
	HICON icon1 = AfxGetApp()->LoadIconW(ICON1_USER);
	HICON icon2 = AfxGetApp()->LoadIconW(ICON_SHOW);
	HICON icon3 = AfxGetApp()->LoadIconW(ICON_ADD);
	HICON icon4 = AfxGetApp()->LoadIconW(ICON_DELETE);

	//ͼƬ�б������ͼ��뵽ͼƬ�б���
	m_list.Create(55, 55, ILC_COLOR32, 4, 4);
	m_list.Add(icon1);
	m_list.Add(icon2);
	m_list.Add(icon3);
	m_list.Add(icon4);
	m_ctrl->SetImageList(&m_list, TVSIL_NORMAL);
	//������ڵ�
	m_ctrl->InsertItem(TEXT("��¼��Ϣ"), 0, 0, NULL);
	m_ctrl->InsertItem(TEXT("ͼ����"), 1, 1, NULL);
	m_ctrl->InsertItem(TEXT("��ӿ��"), 2, 2, NULL);
	m_ctrl->InsertItem(TEXT("ɾ�����"), 3, 3, NULL);
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HTREEITEM item = m_ctrl->GetSelectedItem();//��ȡ����ѡ�Ľڵ�

	//��ȡ�ڵ���Ϣ
	CString str = m_ctrl->GetItemText(item);

	if (str == TEXT("��¼��Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(),VM_A, (WPARAM)VM_A, (LPARAM)0);
	}
	else if (str == TEXT("ͼ����"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), VM_B, (WPARAM)VM_B, (LPARAM)0);
	}
	else if (str == TEXT("��ӿ��"))
	{
		
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), VM_C, (WPARAM)VM_C, (LPARAM)0);
	}
	else 
	{
		
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), VM_D, (WPARAM)VM_D, (LPARAM)0);
	}
}
