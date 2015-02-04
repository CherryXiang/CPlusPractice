/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: CMaze.h
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-24
功能描述: 实现一个迷宫，给出起点和终点，然后计算出从起点可到达终点的路径
其它相关: 
修改记录: 
  1.修改日期：2014-1-26
  2.修 改 者：兰香
  3.修改简述：从Init()接口中分离出保护成员函数MakeMaze()，修改~CMaze()，之前析构的越界
              改进FindPath()，之前的会偶然死循环
****************************************************************************************/

#pragma once
#include <stack>
#include <vector>

using namespace std;

//迷宫中可走的方向定义
#define NO 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

class CMaze
{
public:
	CMaze();
	~CMaze();

	bool Init(int len, int wid);                //根据用户输入的迷宫长宽度，初始化一个迷宫出来
	void Start();                               //启动迷宫，获取起点和终点后开始找出路
	void Exit();                                //退出迷宫程序

protected:
	typedef struct                              //迷宫中的坐标点
	{
		int x;                                  //x坐标
		int y;                                  //y坐标
	}Point; 

	typedef struct                              //走迷宫时的步子
	{
		Point point;                            //步子所踩的坐标点
		int goDirect;                           //步子前进方向
		int backDirect;                         //步子后退方向
	}Step;

	void MakeMaze();                            //创建生成迷宫图案
	void DrawMaze();                            //绘制迷宫
	bool FindPath();                            //从迷宫的起点到终点找出路
	bool IsStepped(Point point);                //判断某一坐标点是否被踩过
	bool CheckPath(Point point, int direction); //判断当前步子踩的坐标点在某个方向上是否走的通
	bool IsEndPoint(Point point);               //是否到达终点坐标

private:
	char **m_maze;                              //二维数组保存的迷宫图，含一圈栅栏
	int m_col;                                  //迷宫图列数
	int m_row;                                  //迷宫图行数

	Point m_startPoint;                         //迷宫起点坐标
	Point m_endPoint;                           //迷宫终点坐标

	stack<Step> m_path;                         //存储走通的步子，从起点到终点走通的步子连起来就成一条迷宫出路
	vector<Point> m_steppedPoint;               //存储已走过的(也包含走不通的)坐标点
};