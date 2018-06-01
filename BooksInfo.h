#pragma once
#include "afxcmn.h"

#include<string>

// CBooksInfo 窗体视图

class CBooksInfo : public CFormView
{
	DECLARE_DYNCREATE(CBooksInfo)

protected:
	CBooksInfo();           // 动态创建所使用的受保护的构造函数
	virtual ~CBooksInfo();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOKSINFO };
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
	CListCtrl m_listctrl;
public:
	virtual void OnInitialUpdate();
};


