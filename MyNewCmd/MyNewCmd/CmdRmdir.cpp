#include <direct.h>
#include "CmdRmdir.h"

CmdRmdir::~CmdRmdir(){}

bool CmdRmdir::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 2, "rd") == 0)
	{
		m_cmdName = "rd";
		m_param = strCmd.substr(2);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}
	else if (strCmd.compare(0, 5, "rmdir") == 0)
	{
		m_cmdName = "rmdir";
		m_param = strCmd.substr(5);
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdRmdir::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"删除一个目录。"<<endl<<endl;
		cout<<"RMDIR [/S] [/Q] [drive:]path"<<endl;
		cout<<"RD [/S] [/Q] [drive:]path"<<endl<<endl;
		cout<<"    /S      除目录本身外，还将删除指定目录下的所有子目录和"<<endl;
		cout<<"            文件。用于删除目录树。"<<endl<<endl;
		cout<<"    /Q      安静模式，带 /S 删除目录树时不要求确认"<<endl<<endl;
	}
	else
	{
		//int result = _rmdir(m_param.c_str()); //使用_rmdir函数时，目录必须为空，否则调用失败，函数返回-1.成功时，函数返回0
		//if (result != 0)
		//{
		//	if (_access(m_param.c_str()) == 0) //要删除的文件夹存在
		//	{
		//		cout<<"目录不是空的。"<<endl;
		//	}
		//	else
		//	{
		//		cout<<"系统找不到指定的文件。"
		//	}
		//}

		string strRd;
		strRd += m_cmdName;
		strRd += " ";
		strRd += m_param;
		system(strRd.c_str());
	}
}