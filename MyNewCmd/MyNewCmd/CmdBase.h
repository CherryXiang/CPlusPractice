#pragma once

#include <iostream>
using namespace std;

class CmdBase
{
public:
	virtual ~CmdBase();

    //����������������������Ϊ��������������������������ĸ������ദ��
	//����ֵ��Ϊbool���ͣ������ڽ���ʱΪ����ִ�оͷ���true,���򷵻�false
	virtual bool parseCmd(string strCmd) = 0; 
	
	//���������ʵ���Լ������ִ�к���
	virtual void run() = 0; 

protected:
	string m_cmdName; //������
	string m_param; //�������
};
