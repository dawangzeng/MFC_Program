#pragma once
#include "afxwin.h"



// CDelDialog 窗体视图

class CDelDialog : public CFormView
{
	DECLARE_DYNCREATE(CDelDialog)

protected:
	CDelDialog();           // 动态创建所使用的受保护的构造函数
	virtual ~CDelDialog();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_conbo;
	int m_num;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo1();
private:
	int m_count;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


