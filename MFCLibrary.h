
// MFCLibrary.h : MFCLibrary Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCLibraryApp:
// �йش����ʵ�֣������ MFCLibrary.cpp
//

class CMFCLibraryApp : public CWinApp
{
public:
	CMFCLibraryApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCLibraryApp theApp;
