#pragma once

#include <iostream>
#include <vector>

#include "CmdBase.h"

using namespace std;

class CmdManager
{
public:
	CmdManager();
	~CmdManager();

	void init(); //��ʼ���������õ�ǰĬ��Ŀ¼�ͽ���֧�ֵ�������һ��vector
	void start(); //���������������д���

	static void display(); //��ʾ��֧������İ�����Ϣ(���ڳ�ʼ��ʱ����vector�е�����)�����help����

	static string m_currentDir; //��ǰĿ¼·��

private:
	void setCurrentDir(); //����m_currentDirֵ������ʾ��ǰĿ¼
	string getCmd(); //�ӿ���̨��ȡ�û����������
	void manageCmd(string strCmd); //ת���������Ӧ�������ദ��ִ�� 


	vector<CmdBase*>  m_cmdClassVec; //�洢����������ָ��  //��ʼ����
	static vector<string> m_cmdVector; //�洢������Ϣ  //Ĭ���ѳ�ʼ��
	string m_inputCmd; //�û���������
};