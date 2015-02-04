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
	int m_iSubWay;                       // 地铁名称
	int m_iType;                         // 地铁类型
	string m_pSubWayA[20];               // 地铁A号线路记录
	map<int, string> m_mTransferStation; // A号线上的换乘站记录
};
