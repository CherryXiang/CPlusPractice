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
		m_param = strCmd.substr(2); //����Ϊ����cd������ַ���������"cd.."�����������
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}

	return false;
}

void CmdCd::run()
{
	if (!m_param.empty())
	{
		if (m_param.compare(0, 2, "/?") == 0) //"cd  /   ?"��������ľͲ�������
		{
			cout<<"��ʾ��ǰĿ¼����ı䵱ǰĿ¼��"<<endl<<endl;
			cout<<"CD [/D] [drive:][path]"<<endl;
			cout<<"CD [..]"<<endl<<endl;
			cout<<"  ..   ָ��Ҫ�ĳɸ�Ŀ¼��"<<endl<<endl;
			cout<<"���� CD drive����ʾָ���������еĵ�ǰĿ¼��"<<endl;
			cout<<"��������ֻ���� CD������ʾ��ǰ��������Ŀ¼��"<<endl<<endl;
		}
		else
		{
			int result = _chdir(m_param.c_str());
			if (result != 0)
			{
				cout<<"ϵͳ�Ҳ���ָ����·����"<<endl<<endl;
			} 
			else
			{
				//ֻҪm_param����_chdir()����ִ�гɹ������ȡ�ɹ���ľ���·��������ǰ·�����ɣ������ٷ���������жϴ���
				char absolPath[256]; 
				_getcwd(absolPath, sizeof(absolPath));
				CmdManager::m_currentDir = absolPath;
			}
		}
	}
	else
	{
		cout<<CmdManager::m_currentDir<<endl<<endl; //�˴�Ҫ���string���ͱ������������#include <string>ͷ�ļ�
	}
}











//����"cd.."��"cd..\"��"cd../"��"cd..\\\\\"��"cd\"��"cd/"�⼸��״��ʱm_currentDir�����ã������򵥵�=m_param�� "cd d:"��"cd ../test"��"cd ..\\\test"�����
//��Ϊ4�д�������ǣ�".."��ͷ�ġ�"."��ͷ��"\"��"\"��ͷ������

//if ((m_param.compare(0, 2, "..") == 0)) //"cd.."��"cd .."���
//{
//	string s = CmdManager::m_currentDir;
//	if (s.find_last_of('\\') == s.find_first_of('\\'))
//	{
//		CmdManager::m_currentDir = s.substr(0, s.find_first_of('\\')+1);
//	}
//	else
//	{
//		CmdManager::m_currentDir = s.substr(0, s.find_last_of('\\'));  //���õ�ǰĿ¼�ĸ�Ŀ¼Ϊ��ǰĿ¼
//	}			
//}

//else if (m_param.compare(".") == 0)  //"cd ./"��"cd .\"��"cd .////"��"cd ./test"��"cd .\test"��
//{
//	//CmdManager::m_currentDir = m_param; //�����κδ�������ǰĿ¼����
//}

//else if ((m_param.compare("/") == 0) || (m_param.compare("\\") == 0)) //"cd\"��"cd/"���
//{
//	string s = CmdManager::m_currentDir;
//	CmdManager::m_currentDir = s.substr(0, s.find_first_of('\\')+1);
//}

//else
//{
//	//m_param�����Ǿ���·���������·������getcwdȡ������·������m_currentDir
//	char absolPath[256]; 
//	_getcwd(absolPath, sizeof(absolPath));
//	CmdManager::m_currentDir = absolPath;
//}