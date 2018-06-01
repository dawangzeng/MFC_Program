// AddDailog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCLibrary.h"
#include "AddDailog.h"
#include "FileHelp.h"

// CAddDailog

IMPLEMENT_DYNCREATE(CAddDailog, CFormView)

CAddDailog::CAddDailog()
	: CFormView(IDD_ADD)
	, m_num1(0)
	, m_name2(_T(""))
	, m_num2(0)
	, m_count(0)
{

}

CAddDailog::~CAddDailog()
{
}

void CAddDailog::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_name2);
	DDX_Text(pDX, IDC_EDIT5, m_num2);
	DDX_Text(pDX, IDC_EDIT6, m_count);
}

BEGIN_MESSAGE_MAP(CAddDailog, CFormView)
//	ON_EN_CHANGE(IDC_EDIT1, &CAddDailog::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDailog::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddDailog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddDailog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddDailog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAddDailog::OnBnClickedButton5)
END_MESSAGE_MAP()


// CAddDailog ���

#ifdef _DEBUG
void CAddDailog::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDailog::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDailog ��Ϣ�������


void CAddDailog::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CFileHelp file;
	file.ReadFile();
	// TODO: �ڴ����ר�ô����/����û���
	for (list<info>::iterator it = file.m_list.begin(); it != file.m_list.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();

	m_num1 = 0;
	m_num2 = 0;
	m_name2 = CString(TEXT(""));
	UpdateData(FALSE);
}




void CAddDailog::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);
	CFileHelp file;
	file.ReadFile();
	for (list<info>::iterator it = file.m_list.begin(); it != file.m_list.end(); it++)
	{
		if (str == (CString)it->name.c_str())
		{
			m_count = it->num;
			break;
		}
	}
	UpdateData(FALSE);
}


void CAddDailog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//�ж����ݺϷ���
	if (m_num1 <= 0)
	{
		MessageBox(TEXT("��Ӹ���Ҫ����0"));
		m_num1 = 0;
		UpdateData(FALSE);
	}
	int index = m_combo.GetCurSel();
	CString str;
	m_combo.GetLBText(index, str);
	CFileHelp file;
	file.ReadFile();
	for (list<info>::iterator it = file.m_list.begin(); it != file.m_list.end(); it++)
	{
		if (str == (CString)it->name.c_str())
		{
			it->num += m_num1;
			m_count = it->num;
			break;
		}
	}
	MessageBox(TEXT("��ӳɹ�"));
	m_num1 = 0;
	UpdateData(FALSE);
	file.WriteFile();
}


void CAddDailog::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();
	m_num1 = 0;
	UpdateData(FALSE);
}


void CAddDailog::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//�ж����ݺϷ���
	if (m_name2.IsEmpty() || m_num2 <= 0)
	{
		MessageBox(TEXT("�����������"));
		m_name2 = TEXT(" ");
		m_num2 = 0;
		UpdateData(FALSE);
		return;
	}
	CFileHelp file;
	file.ReadFile();
	struct info msg;
	msg.id = file.m_list.size() + 1;
	CStringA temp;
	temp = m_name2;
	msg.name = (string)temp.GetBuffer();
	msg.num = m_num2;
	file.m_list.push_back(msg);
	file.WriteFile();

	MessageBox(TEXT("ͼ����ӳɹ�"));
	m_combo.InsertString(0, m_name2);
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();

	m_name2.Empty();
	m_num2 = 0;
	UpdateData(FALSE);
}


void CAddDailog::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_name2.Empty();
	m_num2 = 0;
	UpdateData(FALSE);
}
