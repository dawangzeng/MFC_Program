#pragma once



// CInfoDailog 窗体视图

class CInfoDailog : public CFormView
{
	DECLARE_DYNCREATE(CInfoDailog)

protected:
	CInfoDailog();           // 动态创建所使用的受保护的构造函数
	virtual ~CInfoDailog();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERINFO };
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
	CString m_loginuser;
	CString m_name;
	CString m_newPwd;
	CString m_surePwd;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


