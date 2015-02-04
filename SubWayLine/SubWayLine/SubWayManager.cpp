#include "SubWayManager.h"

#include "SubWayA.h"
#include "SubWayB.h"

CSubWayManager::CSubWayManager()
{
	m_subWayVec.clear();
	m_lineVec.clear();
	m_sStart = "";
	m_iStartLine = NOTEXIST;
	m_iStartPos = NOTEXIST;
	m_sEnd = "";
	m_iEndLine = NOTEXIST;
	m_iEndPos = NOTEXIST;
}

CSubWayManager::~CSubWayManager()
{
	for (vector<CSubWay*>::iterator it = m_subWayVec.begin(); it != m_subWayVec.end(); ++it)
	{
		delete (*it);
	}

	m_lineVec.clear();
}

bool CSubWayManager::Init()
{
	m_subWayVec.clear();
	m_subWayVec.push_back(new CSubWayA());
	m_subWayVec.push_back(new CSubWayB());
	return true;
}

void CSubWayManager::DisplayLine()
{
	for (vector<CSubWay*>::iterator it = m_subWayVec.begin(); it != m_subWayVec.end(); ++it)
	{
		(*it)->Display();
	}
}

void CSubWayManager::TakeSubWay()
{
	cout<<"欢迎乘坐好玩地铁"<<endl;

	do 
	{
		cout<<endl<<"请输入您乘坐地铁的起点：";
		cin>>m_sStart;
		if (true == CheckStation(m_sStart, m_iStartPos, m_iStartLine))
		{
			break;
		}
	} while (true);

	do
	{
		cout<<endl<<"请输入您乘坐地铁的终点：";
		cin>>m_sEnd;
		if (true == CheckStation(m_sEnd, m_iEndPos, m_iEndLine))
		{
			break;;
		}
	} while (true);

	EvaluateLine();

	cout<<endl<<"乘坐最短路线如下："<<endl;
	ShowWay();
	cout<<endl<<"祝您旅途愉快~"<<endl<<endl;
}

bool CSubWayManager::CheckStation(string station, int& stationPos, int& stationLine)
{
	for (vector<CSubWay*>::iterator it = m_subWayVec.begin(); it != m_subWayVec.end(); ++it)
	{
		stationPos = (*it)->GetPosition(station, stationLine);
		if (NOTEXIST != stationPos)
		{
			break;
		}
	}

	if (NOTEXIST == stationPos)
	{
		cout<<"输入站点名称错误，请重新输入！"<<endl;
		return false;
	}

	//排除终点和起点为同一站的情况

	return true;
}

void CSubWayManager::EvaluateLine()
{
	if (m_iStartLine == m_iEndLine) //起点和终点在同一地铁线上，即无换乘
	{
		NoTransfer();
	}
	else //起点和终点不在同一地铁线上，即有换乘
	{
		Transfer();
	}
}

void CSubWayManager::NoTransfer()
{
	for (vector<CSubWay*>::iterator it = m_subWayVec.begin(); it != m_subWayVec.end(); ++it)
	{
		if (m_iStartLine == (*it)->GetSubWay()) //判断在哪一条地铁线上
		{
			string station;
			if (OPENED == (*it)->GetType()) //直线型地铁情况
			{
				if (m_iStartPos < m_iEndPos) //正向走
				{
					for (int i = m_iStartPos; i <= m_iEndPos; ++i)
					{
						station = (*it)->GetStation(i);
						m_lineVec.push_back(station);
					}
				}
				else //反向走
				{
					for (int i = m_iStartPos; i >= m_iEndPos; --i)
					{
						station = (*it)->GetStation(i);
						m_lineVec.push_back(station);
					}
				}
			}
			else if (CLOSED == (*it)->GetType()) //环形型地铁情况
			{
				int distance = 0;
				int length = (*it)->GetLength();

				if (m_iStartPos < m_iEndPos)
				{
					distance = m_iEndPos - m_iStartPos;
					if (distance > length - distance)
					{
						for (int i = m_iStartPos; i >= 0; --i)
						{
							station = (*it)->GetStation(i);
							m_lineVec.push_back(station);
						}
						for (int i = length - 1; i >= m_iEndPos; --i)
						{
							station = (*it)->GetStation(i);
							m_lineVec.push_back(station);
						}
					}
					else
					{
						for (int i = m_iStartPos; i <= m_iEndPos; ++i)
						{
							station = (*it)->GetStation(i);
							m_lineVec.push_back(station);
						}
					}
				}
				else
				{
					distance = m_iStartPos - m_iEndPos;
					if (distance > length - distance)
					{
						for (int i = m_iStartPos; i <= length - 1; ++i)
						{
							station = (*it)->GetStation(i);
							m_lineVec.push_back(station);
						}
						for (int i = 0; i <= m_iEndPos; ++i)
						{
							station = (*it)->GetStation(i);
							m_lineVec.push_back(station);
						}
					}
					else
					{
						for (int i = m_iStartPos; i >= m_iEndPos; --i)
						{
							station = (*it)->GetStation(i);
							m_lineVec.push_back(station);
						}
					}
				}
			}

			break;
		}
	}
}

void CSubWayManager::Transfer()
{

}

void CSubWayManager::ShowWay()
{
	for (vector<string>::iterator it = m_lineVec.begin(); it != m_lineVec.end(); ++it)
	{
		cout<<(*it);
		if (it != m_lineVec.end() - 1)
		{
			cout<<"->";
		}
	}

	int stationCount = m_lineVec.size();
	cout<<endl<<"共"<<stationCount<<"站"<<endl;
}