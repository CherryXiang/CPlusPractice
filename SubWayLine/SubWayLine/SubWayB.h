#pragma once

#include "SubWay.h"

class CSubWayB : public CSubWay
{
public:
	CSubWayB();
	virtual ~CSubWayB();

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
	string m_pSubWayB[17];               // ����B����·��¼
	map<int, string> m_mTransferStation; // B�����ϵĻ���վ��¼
};