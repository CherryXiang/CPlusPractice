#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "SubWay.h"

using namespace std;

class CSubWayManager
{
public:
	CSubWayManager();
	~CSubWayManager();

	bool Init();                   // ��ʼ��
	void DisplayLine();            // ��ʾ���е�����·
	void TakeSubWay();             // �˿ͳ�������

private:
	bool CheckStation(string station, int& stationPos, int& stationLine); // ��������յ�
	void EvaluateLine();                                                  // ������·
	void NoTransfer();                                                    // �޻���·�߼���
	void Transfer();                                                      // �л���·�߼���
	void ShowWay();                                                       // ��ʾ���ճ���·��

private:
	vector<CSubWay*>  m_subWayVec; // �洢���е���(���ǿ��ų�ȥ���������������Լ�����ע��)
	vector<string> m_lineVec;      // �洢���ճ���·��

	string m_sStart;               // �������
	int m_iStartPos;               // ���λ��
	int m_iStartLine;              // �������·��

	string m_sEnd;                 // �յ����� 
	int m_iEndPos;                 // �յ�λ��
	int m_iEndLine;                // �յ�����·��
};
