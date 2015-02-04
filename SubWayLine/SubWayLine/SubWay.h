#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

#define SUBWAY_A 1
#define SUBWAY_B 2
#define NOTEXIST -1

// 地铁类型枚举
enum ESUBWAYTYPE
{
	UNKNOWN = -1,
	CLOSED = 0,  // 环形封闭式
	OPENED = 1   // 直线开放式
};

// 地铁基类
class CSubWay
{
public:
	virtual ~CSubWay();

	// 公共接口定义
	virtual void Display() = 0;                               // 地铁线路显示
	virtual int GetSubWay() = 0;                              // 获取地铁名称
	virtual int GetType() = 0;                                // 获取地铁类型
	virtual int GetLength() = 0;                              // 获取地铁总站数
	virtual string GetStation(int position) = 0;              // 根据站点位置获取站名
	virtual int GetPosition(string station, int& subway) = 0; // 根据站名获取站位置和所在地铁线
	virtual map<int, string> GetTransferStation() = 0;        // 获取换乘站信息
};