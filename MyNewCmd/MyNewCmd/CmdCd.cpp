#include <direct.h>
#include <string>
#include "CmdCd.h"
#include "CmdManager.h"

CmdCd::~CmdCd(){}

bool CmdCd::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 2, "cd") == 0)
	{
		m_cmdName = "cd";
		m_param = strCmd.substr(2); //参数为紧接cd后面的字符串，考虑"cd.."这种情况在内
		m_param.erase(0, m_param.find_first_not_of(" ")); //去除参数前面的空格部分
		return true;
	}

	return false;
}

void CmdCd::run()
{
	if (!m_param.empty())
	{
		if (m_param.compare(0, 2, "/?") == 0) //"cd  /   ?"这种情况的就不考虑了
		{
			cout<<"显示当前目录名或改变当前目录。"<<endl<<endl;
			cout<<"CD [/D] [drive:][path]"<<endl;
			cout<<"CD [..]"<<endl<<endl;
			cout<<"  ..   指定要改成父目录。"<<endl<<endl;
			cout<<"键入 CD drive：显示指定驱动器中的当前目录。"<<endl;
			cout<<"不带参数只键入 CD，则显示当前驱动器和目录。"<<endl<<endl;
		}
		else
		{
			int result = _chdir(m_param.c_str());
			if (result != 0)
			{
				cout<<"系统找不到指定的路径。"<<endl<<endl;
			} 
			else
			{
				//只要m_param传给_chdir()函数执行成功，则获取成功后的绝对路径赋给当前路径即可，不必再分情况解析判断处理
				char absolPath[256]; 
				_getcwd(absolPath, sizeof(absolPath));
				CmdManager::m_currentDir = absolPath;
			}
		}
	}
	else
	{
		cout<<CmdManager::m_currentDir<<endl<<endl; //此处要输出string类型变量，故需添加#include <string>头文件
	}
}











//考虑"cd.."、"cd..\"、"cd../"、"cd..\\\\\"、"cd\"、"cd/"这几种状况时m_currentDir的设置，将不简单的=m_param， "cd d:"、"cd ../test"、"cd ..\\\test"等情况
//分为4中大情况考虑：".."开头的、"."开头、"\"或"\"开头、其他

//if ((m_param.compare(0, 2, "..") == 0)) //"cd.."、"cd .."情况
//{
//	string s = CmdManager::m_currentDir;
//	if (s.find_last_of('\\') == s.find_first_of('\\'))
//	{
//		CmdManager::m_currentDir = s.substr(0, s.find_first_of('\\')+1);
//	}
//	else
//	{
//		CmdManager::m_currentDir = s.substr(0, s.find_last_of('\\'));  //设置当前目录的父目录为当前目录
//	}			
//}

//else if (m_param.compare(".") == 0)  //"cd ./"、"cd .\"、"cd .////"、"cd ./test"、"cd .\test"等
//{
//	//CmdManager::m_currentDir = m_param; //不做任何处理，即当前目录不变
//}

//else if ((m_param.compare("/") == 0) || (m_param.compare("\\") == 0)) //"cd\"、"cd/"情况
//{
//	string s = CmdManager::m_currentDir;
//	CmdManager::m_currentDir = s.substr(0, s.find_first_of('\\')+1);
//}

//else
//{
//	//m_param不管是绝对路径还是相对路径，都getcwd取到绝对路径赋给m_currentDir
//	char absolPath[256]; 
//	_getcwd(absolPath, sizeof(absolPath));
//	CmdManager::m_currentDir = absolPath;
//}