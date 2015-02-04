#include "CmdHelp.h"
#include "CmdManager.h"

CmdHelp::~CmdHelp(){}

bool CmdHelp::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 4, "help") == 0)
	{
		m_cmdName = "help";
		m_param = strCmd.substr(4); 
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdHelp::run()
{
	if (!m_param.empty())
	{
		//考虑执行"help /?"、"help/?"、"help   /  ?"命令时，此时参数为"/?"或"/  ?"
		m_param.erase(1, m_param.find_last_not_of(" ")-1); //去除"/     ?"这种情况下中间的空格部分

		if (m_param.compare(0, 2, "/?") == 0)
		{
			cout<<"提供MyCmd命令的帮助信息。"<<endl<<endl;
			cout<<"HELP [command]"<<endl<<endl;
			cout<<"      command - 显示该命令的帮助信息。"<<endl<<endl;
		}
		else
		{
			cout<<"帮助工具不支持此命令。请尝试'命令名 /?'。"<<endl<<endl;
		}
	}
	else
	{
		CmdManager::display(); //执行"help"命令时
	}
}

