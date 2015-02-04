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
	cout<<"Microsoft Windows [�汾 6.1.7601]"<<endl;
	cout<<"��Ȩ���� (c) 2009 Microsoft Corporation����������Ȩ����"<<endl<<endl;

	setCurrentDir();

	//�ڳ�ʼ����ʱ���new�����еĸ����������һ��vector�У��ں�������vector�������parse���������Ա����
	m_cmdClassVec.push_back(new CmdCd()); 
	m_cmdClassVec.push_back(new CmdDir());
	m_cmdClassVec.push_back(new CmdHelp());
	m_cmdClassVec.push_back(new CmdExit());
	m_cmdClassVec.push_back(new CmdCopy());
	m_cmdClassVec.push_back(new CmdMkdir());
	m_cmdClassVec.push_back(new CmdRmdir());
	m_cmdClassVec.push_back(new CmdDel());

	//�洢���ṩ����İ�����Ϣ
	string strCdName = "CD";
	string strCdDesc = "��ʾ��ǰĿ¼�����ƻ������";
	m_cmdVector.push_back(strCdName);
	m_cmdVector.push_back(strCdDesc);

	string strDirName = "DIR";
	string strDirDesc = "��ʾһ��Ŀ¼�е��ļ�����Ŀ¼";
	m_cmdVector.push_back(strDirName);
	m_cmdVector.push_back(strDirDesc);

	string strHelpName = "HELP";
	string strHelpDesc = "�ṩMyCmd����İ�����Ϣ";
	m_cmdVector.push_back(strHelpName);
	m_cmdVector.push_back(strHelpDesc);

	string strExitName = "EXIT";
	string strExitDesc = "�˳� MYCMD.EXE ����";
	m_cmdVector.push_back(strExitName);
	m_cmdVector.push_back(strExitDesc);

	string strCopyName = "COPY";
	string strCopyDesc = "������һ���ļ����Ƶ���һ��λ��";
	m_cmdVector.push_back(strCopyName);
	m_cmdVector.push_back(strCopyDesc);

	string strMdName = "MD";
	string strMdDesc = "����һ��Ŀ¼";
	m_cmdVector.push_back(strMdName);
	m_cmdVector.push_back(strMdDesc);

	string strRdName = "RD";
	string strRdDesc = "ɾ��Ŀ¼";
	m_cmdVector.push_back(strRdName);
	m_cmdVector.push_back(strRdDesc);

	string strDelName = "DEL";
	string strDelDesc = "ɾ������һ���ļ�";
	m_cmdVector.push_back(strDelName);
	m_cmdVector.push_back(strDelDesc);
}

void CmdManager::start()
{
	while (1)
	{
		string strCmd = getCmd();

		if (!strCmd.empty()) //������������Ϊ�գ��򲻽��д����������õ�ǰĿ¼���ɣ�����Ϊ�գ�����д���������õ�ǰĿ¼
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
		cout<<"����Ŀ¼ʧ�ܣ�"<<endl;
		exit(0);
	}
	else
	{
		cout<<m_currentDir<<">";
	}
}

void CmdManager::display()
{
	cout<<"�й�ĳ���������ϸ��Ϣ�������Help ������"<<endl;

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
		m_inputCmd.erase(0, m_inputCmd.find_first_not_of(" ")); //ȥ��ǰ��ո񲿷�
		m_inputCmd.erase(m_inputCmd.find_last_not_of(" ")+1); //ȥ������ո񲿷�
	}

	transform(m_inputCmd.begin(), m_inputCmd.end(), m_inputCmd.begin(), tolower); //����ȡ������ȫ��תΪСд��ĸ

	return m_inputCmd;
}

void CmdManager::manageCmd(string strCmd)
{
	for (vector<CmdBase*>::iterator it = m_cmdClassVec.begin(); it != m_cmdClassVec.end(); ++it)
	{
		if ((*it)->parseCmd(strCmd)) //������strCmd����Ϊ����ִ����run�����򲻴���
		{
			(*it)->run();
			break;
		}
	}
}