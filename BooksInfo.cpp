// BooksInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCLibrary.h"
#include "BooksInfo.h"
#include "FileHelp.h"

// CBooksInfo

IMPLEMENT_DYNCREATE(CBooksInfo, CFormView)

CBooksInfo::CBooksInfo()
	: CFormView(IDD_BOOKSINFO)
{

}

CBooksInfo::~CBooksInfo()
{
}

void CBooksInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}

BEGIN_MESSAGE_MAP(CBooksInfo, CFormView)
END_MESSAGE_MAP()


// CBooksInfo 诊断

#ifdef _DEBUG
void CBooksInfo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CBooksInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CBooksInfo 消息处理程序


void CBooksInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_listctrl.SetExtendedStyle(m_listctrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString files[] = { _T("BOOK ID"),_T("BOOK Name"),_T("BOOK NUM") };
	for (int i = 0; i < sizeof(files)/sizeof(files[0]); i++)
	{
		m_listctrl.InsertColumn(i, files[i], LVCFMT_CENTER, 100);
	}
	CFileHelp file;
	file.ReadFile();
	CString str;
	int i = 0;
	for (list<info>::iterator it = file.m_list.begin(); it!=file.m_list.end(); ++it)
	{
		str.Format(_T("%d"), it->id);
		m_listctrl.InsertItem(i, str);
		int col = 1;
		str.Format(_T("%s"), (CString)it->name.c_str());
		m_listctrl.SetItemText(i, col++, str);
		str.Format(_T("%d"), it->num);
		m_listctrl.SetItemText(i, col++, str);
		i++;
	}
	UpdateData(FALSE);
}
