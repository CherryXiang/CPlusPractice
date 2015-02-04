#include "CmdExit.h"

CmdExit::~CmdExit(){}

bool CmdExit::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 4, "exit") == 0)
	{
		m_cmdName = "exit";
		m_param = strCmd.substr(4);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdExit::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"退出 MYCMD.EXE 程序。"<<endl<<endl;
		cout<<"EXIT"<<endl<<endl;
	}
	else
	{
		exit(0);
	}
}