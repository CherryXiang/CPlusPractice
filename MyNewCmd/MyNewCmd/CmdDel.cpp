#include "CmdDel.h"

CmdDel::~CmdDel(){}

bool CmdDel::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 3, "del") == 0)
	{
		m_cmdName = "del";
		m_param = strCmd.substr(3);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdDel::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"删除一个或数个文件。"<<endl<<endl;
		cout<<"DEL [/P] [/F] [/S] [/Q] [/A[[:]attributes]] names"<<endl<<endl;
		cout<<"  names         指定一个或多个文件或者目录列表。"<<endl;
		cout<<"                通配符可用来删除多个文件。"<<endl;
		cout<<"                如果指定了一个目录，该目录中的所"<<endl;
		cout<<"                有文件都会被删除。"<<endl<<endl;
	}
	else
	{
		string strDel;
		strDel += m_cmdName;
		strDel += " ";
		strDel += m_param;
		system(strDel.c_str());
	}
}