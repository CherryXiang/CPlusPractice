#include "CmdExit.h"

CmdExit::~CmdExit(){}

bool CmdExit::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 4, "exit") == 0)
	{
		m_cmdName = "exit";
		m_param = strCmd.substr(4);
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}

	return false;
}

void CmdExit::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"�˳� MYCMD.EXE ����"<<endl<<endl;
		cout<<"EXIT"<<endl<<endl;
	}
	else
	{
		exit(0);
	}
}