#pragma once
#include "afxwin.h"



// CAddDailog ������ͼ

class CAddDailog : public CFormView
{
	DECLARE_DYNCREATE(CAddDailog)

protected:
	CAddDailog();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAddDailog();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
private:
	int m_num1;
	CString m_name2;
	int m_num2;
	int m_count;
public:
	virtual void OnInitialUpdate();
//	afx_msg void OnEnChangeEdit1();
	
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};


