#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include<list>
using namespace std;
#define _F_LOGIN "./user.ini"
#define _F_DATA "./data.txt"
struct info {
	int id;
	string name;
	int num;
};
class CFileHelp
{
public:
	CFileHelp();
	~CFileHelp();
	//��ȡ�û���
	void ReadPasswd(CString &name,CString &pwd);
	//д���ļ�
	void WriteFile();
	//��ȡ�ļ�����
	void ReadFile();
	//�޸��ļ�
	void ModifyFile();
	void ChangePwd(string name,string pwd);
	list<info> m_list;

	
};

