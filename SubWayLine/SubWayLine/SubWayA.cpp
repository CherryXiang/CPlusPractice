#include "SubWayA.h"

//string subwayA[20] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","T1","A10","A11","A12","A13","T2","A14","A15","A16","A17","A18"};

CSubWayA::CSubWayA()
{
	m_iSubWay = SUBWAY_A;
	m_iType = CLOSED;
	//m_pSubWayA = subwayA;
	m_pSubWayA[0] = "A1";
	m_pSubWayA[1] = "A2";
	m_pSubWayA[2] = "A3";
	m_pSubWayA[3] = "A4";
	m_pSubWayA[4] = "A5";
	m_pSubWayA[5] = "A6";
	m_pSubWayA[6] = "A7";
	m_pSubWayA[7] = "A8";
	m_pSubWayA[8] = "A9";
	m_pSubWayA[9] = "T1";
	m_pSubWayA[10] = "A10";
	m_pSubWayA[11] = "A11";
	m_pSubWayA[12] = "A12";
	m_pSubWayA[13] = "A13";
	m_pSubWayA[14] = "T2";
	m_pSubWayA[15] = "A14";
	m_pSubWayA[16] = "A15";
	m_pSubWayA[17] = "A16";
	m_pSubWayA[18] = "A17";
	m_pSubWayA[19] = "A18";

	m_mTransferStation.insert(map<int, string> :: value_type(9, "T1"));
	m_mTransferStation.insert(map<int, string> :: value_type(14, "T2"));
}

CSubWayA::~CSubWayA()
{
	m_mTransferStation.clear();
}

void CSubWayA::Display()
{
	if (NULL == m_pSubWayA)
	{
		return;
	}

	cout<<"地铁A号线(环形)："<<endl;
	for (int i = 0; i < 20; ++i)
	{
		cout<<m_pSubWayA[i];
		if (i != 19)
		{
			cout<<"-";
		}
	}
	cout<<endl<<endl;
}

int CSubWayA::GetSubWay()
{
	return m_iSubWay;
}

int CSubWayA::GetType()
{
	return m_iType;
}

int CSubWayA::GetLength()
{
	return 20;
}

string CSubWayA::GetStation(int position)
{
	return m_pSubWayA[position];
}

int CSubWayA::GetPosition(string station, int& subway)
{
	int position = NOTEXIST;
	subway = SUBWAY_A;

	for (int i = 0; i < 20; ++i)
	{
		if (station == m_pSubWayA[i])
		{
			position = i;
			break;
		}
	}

	return position;
}

map<int, string> CSubWayA::GetTransferStation()
{
	return m_mTransferStation;
}
