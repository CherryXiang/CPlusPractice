#include "CmdCopy.h"

CmdCopy::~CmdCopy(){}

bool CmdCopy::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 4, "copy") == 0)
	{
		m_cmdName = "copy";
		m_param = strCmd.substr(4);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdCopy::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"将一份或多份文件复制到另一个位置。"<<endl<<endl;
		cout<<"COPY [/D] [/V] [/N] [/Y | /-Y] [/Z] [/L] [/A | /B ] source [/A | /B]"<<endl;
		cout<<"     [+ source [/A | /B] [+ ...]] [destination [/A | /B]]"<<endl<<endl;
		cout<<"  source       指定要复制的文件"<<endl;
		cout<<"  destination  为新文件指定目录和/或文件名"<<endl<<endl;
	}
	else
	{
		/////system("xcopy 源路径 目标路径[文件夹可以不存在] /e /i")  system("rd c:\\123\\);好象在Vista下不能删除C盘下的文件
		string strCopy;
		strCopy += m_cmdName;
		strCopy += " ";
		strCopy += m_param;
		system(strCopy.c_str());
	}
}