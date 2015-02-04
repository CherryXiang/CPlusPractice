#include <direct.h>
#include <string>
#include <cctype>
#include <algorithm>

#include "CmdManager.h"

#include "CmdBase.h"
#include "CmdCd.h"
#include "CmdDir.h"
#include "CmdHelp.h"
#include "CmdExit.h"
#include "CmdCopy.h"
#include "CmdDel.h"
#include "CmdMkdir.h"
#include "CmdRmdir.h"

string CmdManager::m_currentDir = "C:\\Users\\Administrator";
vector<string> CmdManager::m_cmdVector;

CmdManager::CmdManager()
{
	m_inputCmd = "";
}

CmdManager::~CmdManager()
{
	for (vector<CmdBase*>::iterator it = m_cmdClassVec.begin(); it != m_cmdClassVec.end(); ++it)
	{
		delete (*it);
	}
}

void CmdManager::init()
{
	cout<<"Microsoft Windows [版本 6.1.7601]"<<endl;
	cout<<"版权所有 (c) 2009 Microsoft Corporation。保留所有权利。"<<endl<<endl;

	setCurrentDir();

	//在初始化的时候就new出已有的各个子类放入一个vector中，在后续遍历vector中子类的parse再设置其成员变量
	m_cmdClassVec.push_back(new CmdCd()); 
	m_cmdClassVec.push_back(new CmdDir());
	m_cmdClassVec.push_back(new CmdHelp());
	m_cmdClassVec.push_back(new CmdExit());
	m_cmdClassVec.push_back(new CmdCopy());
	m_cmdClassVec.push_back(new CmdMkdir());
	m_cmdClassVec.push_back(new CmdRmdir());
	m_cmdClassVec.push_back(new CmdDel());

	//存储可提供命令的帮助信息
	string strCdName = "CD";
	string strCdDesc = "显示当前目录的名称或将其更改";
	m_cmdVector.push_back(strCdName);
	m_cmdVector.push_back(strCdDesc);

	string strDirName = "DIR";
	string strDirDesc = "显示一个目录中的文件和子目录";
	m_cmdVector.push_back(strDirName);
	m_cmdVector.push_back(strDirDesc);

	string strHelpName = "HELP";
	string strHelpDesc = "提供MyCmd命令的帮助信息";
	m_cmdVector.push_back(strHelpName);
	m_cmdVector.push_back(strHelpDesc);

	string strExitName = "EXIT";
	string strExitDesc = "退出 MYCMD.EXE 程序";
	m_cmdVector.push_back(strExitName);
	m_cmdVector.push_back(strExitDesc);

	string strCopyName = "COPY";
	string strCopyDesc = "将至少一个文件复制到另一个位置";
	m_cmdVector.push_back(strCopyName);
	m_cmdVector.push_back(strCopyDesc);

	string strMdName = "MD";
	string strMdDesc = "创建一个目录";
	m_cmdVector.push_back(strMdName);
	m_cmdVector.push_back(strMdDesc);

	string strRdName = "RD";
	string strRdDesc = "删除目录";
	m_cmdVector.push_back(strRdName);
	m_cmdVector.push_back(strRdDesc);

	string strDelName = "DEL";
	string strDelDesc = "删除至少一个文件";
	m_cmdVector.push_back(strDelName);
	m_cmdVector.push_back(strDelDesc);
}

void CmdManager::start()
{
	while (1)
	{
		string strCmd = getCmd();

		if (!strCmd.empty()) //如果输入的命令为空，则不进行处理重新设置当前目录即可；若不为空，则进行处理后再设置当前目录
		{
			manageCmd(strCmd);
		}

		setCurrentDir();
	}
}

void CmdManager::setCurrentDir()
{
	int result = _chdir(m_currentDir.c_str());

	if (result != 0)
	{
		cout<<"设置目录失败！"<<endl;
		exit(0);
	}
	else
	{
		cout<<m_currentDir<<">";
	}
}

void CmdManager::display()
{
	cout<<"有关某个命令的详细信息，请键入Help 命令名"<<endl;

	for (vector<string>::iterator it = m_cmdVector.begin(); it != m_cmdVector.end(); it = it +2)
	{
		cout<<*it<<"\t"<<*(it+1)<<endl;
	}
}

string CmdManager::getCmd()
{
	getline(cin, m_inputCmd);

	if (!m_inputCmd.empty())
	{
		m_inputCmd.erase(0, m_inputCmd.find_first_not_of(" ")); //去除前面空格部分
		m_inputCmd.erase(m_inputCmd.find_last_not_of(" ")+1); //去除后面空格部分
	}

	transform(m_inputCmd.begin(), m_inputCmd.end(), m_inputCmd.begin(), tolower); //将获取的命令全部转为小写字母

	return m_inputCmd;
}

void CmdManager::manageCmd(string strCmd)
{
	for (vector<CmdBase*>::iterator it = m_cmdClassVec.begin(); it != m_cmdClassVec.end(); ++it)
	{
		if ((*it)->parseCmd(strCmd)) //解析到strCmd命令为该类执行则run，否则不处理
		{
			(*it)->run();
			break;
		}
	}
}