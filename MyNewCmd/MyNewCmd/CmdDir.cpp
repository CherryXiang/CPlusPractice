#include <direct.h>
#include "CmdDir.h"

CmdDir::~CmdDir(){}

bool CmdDir::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 3, "dir") == 0)
	{
		m_cmdName = "dir";
		m_param = strCmd.substr(3);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdDir::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"显示目录中的文件和子目录列表。"<<endl<<endl;
		cout<<"DIR [drive:][path][filename] [/A[[:]attributes]] [/B] [/C] [/D] [/L] [/N]"<<endl;
		cout<<"  [/O[[:]sortorder]] [/P] [/Q] [/R] [/S] [/T[[:]timefield]] [/W] [/X] [/4]"<<endl<<endl;
		cout<<"  [drive:][path][filename]"<<endl;
		cout<<"              指定要列出的驱动器、目录和/或文件。"<<endl<<endl;
	}
	else
	{
		string strDir;
		strDir += m_cmdName;
		strDir += " ";
		strDir += m_param;
		system(strDir.c_str());
	}
}