// InfoDailog.cpp : ʵ���ļ�
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


// CInfoDailog ���

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


// CInfoDailog ��Ϣ�������


void CInfoDailog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CFileHelp file;
	CString name, pwd;
	file.ReadPasswd(name, pwd);
	m_loginuser = CString(TEXT("����Ա"));
	m_name = name;
	UpdateData(FALSE);

}


void CInfoDailog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_newPwd.IsEmpty() || m_surePwd.IsEmpty())
	{
		MessageBox(TEXT("���벻��Ϊ��"));
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
		MessageBox(TEXT("������ԭ������ͬ"));
		m_newPwd = TEXT("");
		m_surePwd = TEXT("");
		UpdateData(FALSE);
		return;
	}
	if (m_newPwd != m_surePwd)
	{
		MessageBox(TEXT("�����������벻һ��"));
		m_newPwd = TEXT("");
		m_surePwd = TEXT("");
		UpdateData(FALSE);
		return;
	}
	CStringA nametmp, pwdtmp;
	nametmp = name;
	pwdtmp = m_newPwd;

	file.ChangePwd(string(nametmp.GetBuffer()), string(pwdtmp.GetBuffer()));
	MessageBox(TEXT("�޸�����ɹ�"));
	m_newPwd = TEXT("");
	m_surePwd = TEXT("");
	UpdateData(FALSE);
}


void CInfoDailog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_newPwd = TEXT("");
	m_surePwd = TEXT("");
	UpdateData(FALSE);
}
