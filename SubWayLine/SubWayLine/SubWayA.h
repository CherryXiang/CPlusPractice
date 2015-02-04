#pragma once

#include "SubWay.h"

class CSubWayA : public CSubWay
{
public:
	CSubWayA();
	virtual ~CSubWayA();

	virtual void Display();
	virtual int GetSubWay();
	virtual int GetType();
	virtual int GetLength();
	virtual string GetStation(int position);
	virtual int GetPosition(string station, int& subway); 
	virtual map<int, string> GetTransferStation();

private:
	int m_iSubWay;                       // ��������
	int m_iType;                         // ��������
	string m_pSubWayA[20];               // ����A����·��¼
	map<int, string> m_mTransferStation; // A�����ϵĻ���վ��¼
};
