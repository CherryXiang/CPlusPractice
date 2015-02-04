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
	cout<<"��ӭ�����������"<<endl;

	do 
	{
		cout<<endl<<"��������������������㣺";
		cin>>m_sStart;
		if (true == CheckStation(m_sStart, m_iStartPos, m_iStartLine))
		{
			break;
		}
	} while (true);

	do
	{
		cout<<endl<<"�������������������յ㣺";
		cin>>m_sEnd;
		if (true == CheckStation(m_sEnd, m_iEndPos, m_iEndLine))
		{
			break;;
		}
	} while (true);

	EvaluateLine();

	cout<<endl<<"�������·�����£�"<<endl;
	ShowWay();
	cout<<endl<<"ף����;���~"<<endl<<endl;
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
		cout<<"����վ�����ƴ������������룡"<<endl;
		return false;
	}

	//�ų��յ�����Ϊͬһվ�����

	return true;
}

void CSubWayManager::EvaluateLine()
{
	if (m_iStartLine == m_iEndLine) //�����յ���ͬһ�������ϣ����޻���
	{
		NoTransfer();
	}
	else //�����յ㲻��ͬһ�������ϣ����л���
	{
		Transfer();
	}
}

void CSubWayManager::NoTransfer()
{
	for (vector<CSubWay*>::iterator it = m_subWayVec.begin(); it != m_subWayVec.end(); ++it)
	{
		if (m_iStartLine == (*it)->GetSubWay()) //�ж�����һ����������
		{
			string station;
			if (OPENED == (*it)->GetType()) //ֱ���͵������
			{
				if (m_iStartPos < m_iEndPos) //������
				{
					for (int i = m_iStartPos; i <= m_iEndPos; ++i)
					{
						station = (*it)->GetStation(i);
						m_lineVec.push_back(station);
					}
				}
				else //������
				{
					for (int i = m_iStartPos; i >= m_iEndPos; --i)
					{
						station = (*it)->GetStation(i);
						m_lineVec.push_back(station);
					}
				}
			}
			else if (CLOSED == (*it)->GetType()) //�����͵������
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
	cout<<endl<<"��"<<stationCount<<"վ"<<endl;
}