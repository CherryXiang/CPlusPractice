#include "CmdCopy.h"

CmdCopy::~CmdCopy(){}

bool CmdCopy::parseCmd(string strCmd)
{
	if (strCmd.compare(0, 4, "copy") == 0)
	{
		m_cmdName = "copy";
		m_param = strCmd.substr(4);
		m_param.erase(0, m_param.find_first_not_of(" ")); //ȥ������ǰ��Ŀո񲿷�
		return true;
	}

	return false;
}

void CmdCopy::run()
{
	if (m_param.compare(0, 2, "/?") == 0)
	{
		cout<<"��һ�ݻ����ļ����Ƶ���һ��λ�á�"<<endl<<endl;
		cout<<"COPY [/D] [/V] [/N] [/Y | /-Y] [/Z] [/L] [/A | /B ] source [/A | /B]"<<endl;
		cout<<"     [+ source [/A | /B] [+ ...]] [destination [/A | /B]]"<<endl<<endl;
		cout<<"  source       ָ��Ҫ���Ƶ��ļ�"<<endl;
		cout<<"  destination  Ϊ���ļ�ָ��Ŀ¼��/���ļ���"<<endl<<endl;
	}
	else
	{
		/////system("xcopy Դ·�� Ŀ��·��[�ļ��п��Բ�����] /e /i")  system("rd c:\\123\\);������Vista�²���ɾ��C���µ��ļ�
		string strCopy;
		strCopy += m_cmdName;
		strCopy += " ";
		strCopy += m_param;
		system(strCopy.c_str());
	}
}