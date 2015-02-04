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

	bool Init();                   // 初始化
	void DisplayLine();            // 显示所有地铁线路
	void TakeSubWay();             // 乘客乘坐地铁

private:
	bool CheckStation(string station, int& stationPos, int& stationLine); // 检测起点和终点
	void EvaluateLine();                                                  // 评估线路
	void NoTransfer();                                                    // 无换乘路线计算
	void Transfer();                                                      // 有换乘路线计算
	void ShowWay();                                                       // 显示最终乘坐路线

private:
	vector<CSubWay*>  m_subWayVec; // 存储所有地铁(考虑开放出去，供各个地铁类自己操作注册)
	vector<string> m_lineVec;      // 存储最终乘坐路线

	string m_sStart;               // 起点名称
	int m_iStartPos;               // 起点位置
	int m_iStartLine;              // 起点所在路线

	string m_sEnd;                 // 终点名称 
	int m_iEndPos;                 // 终点位置
	int m_iEndLine;                // 终点所在路线
};
