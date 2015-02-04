#include <direct.h>
#include "CmdMkdir.h"

CmdMkdir::~CmdMkdir(){}

bool CmdMkdir::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 2, "md") == 0)
	{
		m_cmdName = "md";
		m_param = strCmd.substr(2);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}
	else if (strCmd.compare(0, 5, "mkdir") == 0)
	{
		m_cmdName = "mkdir";
		m_param = strCmd.substr(5);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdMkdir::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"创建目录。"<<endl<<endl;
		cout<<"MKDIR [drive:]path"<<endl;
		cout<<"MD [drive:]path"<<endl<<endl;
	}
	else
	{
		//int result = _mkdir(m_param.c_str()); //result = 0 成功，=-1 失败
		//if (result != 0)
		//{
		//	cout<<"创建目录失败。"<<endl;
		//}

		string strMd;
		strMd += m_cmdName;
		strMd += " ";
		strMd += m_param;
		system(strMd.c_str());
	}
}