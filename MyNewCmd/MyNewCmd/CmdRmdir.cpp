#include <direct.h>
#include "CmdRmdir.h"

CmdRmdir::~CmdRmdir(){}

bool CmdRmdir::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 2, "rd") == 0)
	{
		m_cmdName = "rd";
		m_param = strCmd.substr(2);
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}
	else if (strCmd.compare(0, 5, "rmdir") == 0)
	{
		m_cmdName = "rmdir";
		m_param = strCmd.substr(5);
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}

	return false;
}

void CmdRmdir::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"ɾ��һ��Ŀ¼��"<<endl<<endl;
		cout<<"RMDIR [/S] [/Q] [drive:]path"<<endl;
		cout<<"RD [/S] [/Q] [drive:]path"<<endl<<endl;
		cout<<"    /S      ��Ŀ¼�����⣬����ɾ��ָ��Ŀ¼�µ�������Ŀ¼��"<<endl;
		cout<<"            �ļ�������ɾ��Ŀ¼����"<<endl<<endl;
		cout<<"    /Q      ����ģʽ���� /S ɾ��Ŀ¼��ʱ��Ҫ��ȷ��"<<endl<<endl;
	}
	else
	{
		//int result = _rmdir(m_param.c_str()); //ʹ��_rmdir����ʱ��Ŀ¼����Ϊ�գ��������ʧ�ܣ���������-1.�ɹ�ʱ����������0
		//if (result != 0)
		//{
		//	if (_access(m_param.c_str()) == 0) //Ҫɾ�����ļ��д���
		//	{
		//		cout<<"Ŀ¼���ǿյġ�"<<endl;
		//	}
		//	else
		//	{
		//		cout<<"ϵͳ�Ҳ���ָ�����ļ���"
		//	}
		//}

		string strRd;
		strRd += m_cmdName;
		strRd += " ";
		strRd += m_param;
		system(strRd.c_str());
	}
}