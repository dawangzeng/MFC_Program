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
	//读取用户名
	void ReadPasswd(CString &name,CString &pwd);
	//写入文件
	void WriteFile();
	//读取文件内容
	void ReadFile();
	//修改文件
	void ModifyFile();
	void ChangePwd(string name,string pwd);
	list<info> m_list;

	
};

