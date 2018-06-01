// DelDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCLibrary.h"
#include "DelDialog.h"
#include "FileHelp.h"

// CDelDialog

IMPLEMENT_DYNCREATE(CDelDialog, CFormView)

CDelDialog::CDelDialog()
	: CFormView(IDD_DELETE)
	, m_num(0)
	, m_count(0)
{

}

CDelDialog::~CDelDialog()
{
}

void CDelDialog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_conbo);
	DDX_Text(pDX, IDC_EDIT1, m_num);
	DDX_Text(pDX, IDC_EDIT2, m_count);
}

BEGIN_MESSAGE_MAP(CDelDialog, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDelDialog::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDelDialog ���

#ifdef _DEBUG
void CDelDialog::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDialog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDialog ��Ϣ�������


void CDelDialog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CFileHelp file;
	file.ReadFile();

	for (list<info>::iterator it = file.m_list.begin(); it != file.m_list.end(); it++)
	{
		m_conbo.AddString((CString)it->name.c_str());
	}
	m_conbo.SetCurSel(0);
	OnCbnSelchangeCombo1();
	UpdateData(FALSE);


}


void CDelDialog::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int index = m_conbo.GetCurSel();
	CString str;
	m_conbo.GetLBText(index, str);
	CFileHelp file;
	file.ReadFile();
	for (list<info>::iterator it = file.m_list.begin(); it != file.m_list.end(); ++it)
	{
		if (str == (CString)it->name.c_str())
		{
			m_count = it->num;
			break;
		}
	}
	UpdateData(FALSE);


}


void CDelDialog::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_num <= 0)
	{
		MessageBox(TEXT("ͼ����������С��0"));
		m_num = 0;
		UpdateData(FALSE);
		return;
	}
	if (m_num > m_count)
	{
		MessageBox(TEXT("ɾ���������ܴ��ڿ������"));
		m_num = 0;
		UpdateData(FALSE);
		return;
	}
	CFileHelp file;
	file.ReadFile();
	int index = m_conbo.GetCurSel();
	CString str;
	m_conbo.GetLBText(index, str);
	for (list<info>::iterator it = file.m_list.begin(); it != file.m_list.end(); ++it)
	{
		if (str == (CString)it->name.c_str())
		{
			it->num -= m_num;
			m_count = it->num;
			MessageBox(TEXT("ͼ��ɾ���ɹ�"));
			break;
		}
	}
	m_num = 0;
	file.WriteFile();
	UpdateData(FALSE);
}


void CDelDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_num = 0;
	UpdateData(FALSE);
}
