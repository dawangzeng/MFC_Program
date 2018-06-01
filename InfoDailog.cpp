// InfoDailog.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCLibrary.h"
#include "InfoDailog.h"
#include "FileHelp.h"

// CInfoDailog

IMPLEMENT_DYNCREATE(CInfoDailog, CFormView)

CInfoDailog::CInfoDailog()
	: CFormView(IDD_USERINFO)
	, m_loginuser(_T(""))
	, m_name(_T(""))
	, m_newPwd(_T(""))
	, m_surePwd(_T(""))
{

}

CInfoDailog::~CInfoDailog()
{
}

void CInfoDailog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_loginuser);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPwd);
	DDX_Text(pDX, IDC_EDIT4, m_surePwd);
}

BEGIN_MESSAGE_MAP(CInfoDailog, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CInfoDailog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CInfoDailog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CInfoDailog 诊断

#ifdef _DEBUG
void CInfoDailog::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfoDailog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInfoDailog 消息处理程序


void CInfoDailog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CFileHelp file;
	CString name, pwd;
	file.ReadPasswd(name, pwd);
	m_loginuser = CString(TEXT("管理员"));
	m_name = name;
	UpdateData(FALSE);

}


void CInfoDailog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("密码不能为空"));
		m_newPwd = TEXT("");
		m_surePwd = TEXT("");
		UpdateData(FALSE);
		return;
	}
	CString name, pwd;
	CFileHelp file;
	file.ReadPasswd(name, pwd);

	if (pwd == m_newPwd)
	{
		MessageBox(TEXT("密码与原密码相同"));
		m_newPwd = TEXT("");
		m_surePwd = TEXT("");
		UpdateData(FALSE);
		return;
	}
	if (m_newPwd != m_surePwd)
	{
		MessageBox(TEXT("两次输入密码不一致"));
		m_newPwd = TEXT("");
		m_surePwd = TEXT("");
		UpdateData(FALSE);
		return;
	}
	CStringA nametmp, pwdtmp;
	nametmp = name;
	pwdtmp = m_newPwd;

	file.ChangePwd(string(nametmp.GetBuffer()), string(pwdtmp.GetBuffer()));
	MessageBox(TEXT("修改密码成功"));
	m_newPwd = TEXT("");
	m_surePwd = TEXT("");
	UpdateData(FALSE);
}


void CInfoDailog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_newPwd = TEXT("");
	m_surePwd = TEXT("");
	UpdateData(FALSE);
}
