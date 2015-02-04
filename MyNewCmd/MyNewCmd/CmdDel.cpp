#include "CmdDel.h"

CmdDel::~CmdDel(){}

bool CmdDel::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 3, "del") == 0)
	{
		m_cmdName = "del";
		m_param = strCmd.substr(3);
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}

	return false;
}

void CmdDel::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"ɾ��һ���������ļ���"<<endl<<endl;
		cout<<"DEL [/P] [/F] [/S] [/Q] [/A[[:]attributes]] names"<<endl<<endl;
		cout<<"  names         ָ��һ�������ļ�����Ŀ¼�б�"<<endl;
		cout<<"                ͨ���������ɾ������ļ���"<<endl;
		cout<<"                ���ָ����һ��Ŀ¼����Ŀ¼�е���"<<endl;
		cout<<"                ���ļ����ᱻɾ����"<<endl<<endl;
	}
	else
	{
		string strDel;
		strDel += m_cmdName;
		strDel += " ";
		strDel += m_param;
		system(strDel.c_str());
	}
}