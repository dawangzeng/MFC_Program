#include "stdafx.h"
#include "FileHelp.h"

using namespace std;
CFileHelp::CFileHelp()
{
	
}


CFileHelp::~CFileHelp()
{
}

void CFileHelp::ReadPasswd(CString & name, CString & pwd)
{
	ifstream ifs;
	ifs.open(_F_LOGIN);
	char buff[1024] = { 0 };
	ifs.getline(buff, sizeof(buff));
	name = (CString)buff;
	ifs.getline(buff, sizeof(buff));
	pwd = (CString)buff;
	
	ifs.close();

}

void CFileHelp::WriteFile()
{
	
	if (!m_list.empty())
	{
		ofstream ofs(_F_DATA);
		m_list.remove_if([](info elem) {return elem.num <= 0; });
		ofs << "BOOK ID" << " " << "BOOK Name" << " " << "BOOK Num" << endl;
		for (list<info>::iterator it = m_list.begin(); it != m_list.end(); ++it)
		{
			ofs << it->id << " ";
			ofs << it->name << " ";
			ofs << it->num << endl;
		}
		ofs.close();
	}
}

void CFileHelp::ReadFile()
{
	char buff[1024] = { 0 };
	//个数
	int count = 0;
	//清空链表
	m_list.clear();
	//读取文件内容
	ifstream ifs(_F_DATA);
	ifs.getline(buff, 1024);
	while (!ifs.eof())
	{
		struct info msg;
		int count = 0;
		ifs.getline(buff, sizeof(buff));
		char *str = strtok(buff, " ");
		if (str != NULL)
		{
			msg.id = atoi(str);
		}
		else
			break;
		str = strtok(NULL, " ");
		msg.name = str;
		str = strtok(NULL, " ");
		msg.num = atoi(str);
		m_list.push_back(msg);

	}
	ifs.close();
}

void CFileHelp::ModifyFile()
{

}

void CFileHelp::ChangePwd(string name,string pwd)
{
	ofstream ofs(_F_LOGIN);
	ofs << name << endl;
	ofs << pwd << endl;
	ofs.close();
}
