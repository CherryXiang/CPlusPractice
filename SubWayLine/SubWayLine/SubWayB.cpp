#include "SubWayB.h"

//string subwayB[17] = {"B1","B2","B3","B4","B5","T1","B6","B7","B8","B9","B10","T2","B11","B12","B13","B14","B15"};

CSubWayB::CSubWayB()
{
	m_iSubWay = SUBWAY_B;
	m_iType = OPENED;	
	//m_pSubWayB = subwayB;
	m_pSubWayB[0] = "B1";
	m_pSubWayB[1] = "B2";
	m_pSubWayB[2] = "B3";
	m_pSubWayB[3] = "B4";
	m_pSubWayB[4] = "B5";
	m_pSubWayB[5] = "T1";
	m_pSubWayB[6] = "B6";
	m_pSubWayB[7] = "B7";
	m_pSubWayB[8] = "B8";
	m_pSubWayB[9] = "B9";
	m_pSubWayB[10] = "B10";
	m_pSubWayB[11] = "T2";
	m_pSubWayB[12] = "B11";
	m_pSubWayB[13] = "B12";
	m_pSubWayB[14] = "B13";
	m_pSubWayB[15] = "B14";
	m_pSubWayB[16] = "B15";

	m_mTransferStation.insert(map<int, string> :: value_type(5, "T1"));
	m_mTransferStation.insert(map<int, string> :: value_type(11, "T2"));
}

CSubWayB::~CSubWayB()
{
	m_mTransferStation.clear();
}

void CSubWayB::Display()
{
	if (NULL == m_pSubWayB)
	{
		return;
	}

	cout<<"地铁B号线(直线)："<<endl;
	for (int i = 0; i < 17; ++i)
	{
		cout<<m_pSubWayB[i];
		if (i != 16)
		{
			cout<<"-";
		}
	}
	cout<<endl<<endl;
}

int CSubWayB::GetSubWay()
{
	return m_iSubWay;
}

int CSubWayB::GetType()
{
	return m_iType;
}

int CSubWayB::GetLength()
{
	return 17;
}

string CSubWayB::GetStation(int position)
{
	return m_pSubWayB[position];
}

int CSubWayB::GetPosition(string station, int& subway)
{
	int index = NOTEXIST;
	subway = SUBWAY_B;

	for (int i = 0; i < 17; ++i)
	{
		if (station == m_pSubWayB[i])
		{
			index = i;
			break;
		}
	}

	return index;
}

map<int, string> CSubWayB::GetTransferStation()
{
	return m_mTransferStation;
}