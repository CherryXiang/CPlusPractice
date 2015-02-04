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
	int m_iSubWay;                       // 地铁名称
	int m_iType;                         // 地铁类型
	string m_pSubWayB[17];               // 地铁B号线路记录
	map<int, string> m_mTransferStation; // B号线上的换乘站记录
};