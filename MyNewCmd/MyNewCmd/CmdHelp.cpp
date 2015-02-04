#include "CmdHelp.h"
#include "CmdManager.h"

CmdHelp::~CmdHelp(){}

bool CmdHelp::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 4, "help") == 0)
	{
		m_cmdName = "help";
		m_param = strCmd.substr(4); 
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}

	return false;
}

void CmdHelp::run()
{
	if (!m_param.empty())
	{
		//����ִ��"help /?"��"help/?"��"help   /  ?"����ʱ����ʱ����Ϊ"/?"��"/  ?"
		m_param.erase(1, m_param.find_last_not_of(" ")-1); //ȥ��"/     ?"����������м�Ŀո񲿷�

		if (m_param.compare(0, 2, "/?") == 0)
		{
			cout<<"�ṩMyCmd����İ�����Ϣ��"<<endl<<endl;
			cout<<"HELP [command]"<<endl<<endl;
			cout<<"      command - ��ʾ������İ�����Ϣ��"<<endl<<endl;
		}
		else
		{
			cout<<"�������߲�֧�ִ�����볢��'������ /?'��"<<endl<<endl;
		}
	}
	else
	{
		CmdManager::display(); //ִ��"help"����ʱ
	}
}

