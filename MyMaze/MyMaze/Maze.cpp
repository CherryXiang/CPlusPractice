#include <iostream>
#include <ctime>
#include <windows.h>

#include "Maze.h"

using namespace std;

/*******************************************************************************
* 函数功能: 默认构造函数
* 参    数: [IN]
* 返 回 值: 
* 备    注：
*******************************************************************************/
CMaze::CMaze()
{
	m_maze = NULL;
	m_col = 0;
	m_col = 0;
	m_startPoint.x = 0;
	m_startPoint.y = 0;
	m_endPoint.x = 0;
	m_endPoint.y = 0;
	m_steppedPoint.clear();
}

/*******************************************************************************
* 函数功能: 析构函数，释放init时动态分配的数组内存
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
CMaze::~CMaze()
{
	for (int i = 0; i < m_row; ++i) //释放时，一行一行的释放，如果改为i < m_col，则在m_row < m_col时，会越界导致程序崩溃
	{
		delete []m_maze[i];
		m_maze[i] = NULL;
	}
	
	delete []m_maze;
	m_maze = NULL;
}

/*******************************************************************************
* 函数功能: 对迷宫进行初始操作
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
bool CMaze::Init(int len, int wid)
{
	cout<<endl<<"迷宫初始化中......"<<endl;

	m_steppedPoint.clear();
	if (m_maze != NULL)
	{
		for (int i = 0; i < m_row; ++i)
		{
			delete[] m_maze[i];
		}

		delete[] m_maze;
	}

	//迷宫周围添加栅栏后的横列数
	m_col = len + 2;
	m_row = wid + 2;

	//动态分配存储迷宫图的二维数组空间
	m_maze = new char*[m_row];
	if (m_maze == NULL)
	{
		cout<<"初始化失败！"<<endl;
		return false;
	}

	for (int i = 0; i < m_row; ++i)
	{
		m_maze[i] = new char[m_col];
		if (m_maze[i] == NULL)
		{
			cout<<"初始化失败！"<<endl;
			return false;
		}
	}

	cout<<"初始化完毕！"<<endl<<endl;

	return true;
}

/*******************************************************************************
* 函数功能: 启动迷宫程序
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
void CMaze::Start()
{
	MakeMaze();

	cout<<"注：*表示迷宫周围栅栏，O表示迷宫通道，M表示迷宫墙"<<endl;
	cout<<"    q表示起点，z表示终点，x表示通路"<<endl<<endl;
	cout<<endl<<"当前迷宫图："<<endl<<endl;
	DrawMaze();

	cout<<endl<<"OK，让我们来一起找出一条通路吧！"<<endl;
	if (FindPath())
	{
		cout<<endl<<"看看找到通路的迷宫图："<<endl<<endl;
		DrawMaze();
	}
}

/*******************************************************************************
* 函数功能: 退出迷宫程序
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
void CMaze::Exit()
{
	cout<<endl<<"谢谢，欢迎下次再来玩哦~"<<endl<<endl;
	cout<<"游戏将退出......"<<endl<<endl;

	Sleep(2000);
	//exit(0); //exit后不会执行析构
}

/*******************************************************************************
* 函数功能: 创建生成迷宫图案
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
void CMaze::MakeMaze()
{
	//设置迷宫周围栅栏
	for (int i = 0; i < m_col; ++i)
	{
		m_maze[0][i] = '*';
		m_maze[m_row - 1][i] = '*';
	}
	for (int i = 1; i < m_row - 1; ++i)
	{
		m_maze[i][0] = '*';
		m_maze[i][m_col - 1] = '*';
	}

	//设置迷宫图，随机产生0或1,0表示迷宫通道(O符号)，1表示迷宫墙(M符号)
	srand((unsigned)time(NULL)); 
	for (int i = 1; i < m_row - 1; ++i)
	{
		for (int j = 1; j < m_col - 1; ++j)
		{
			int randNum = rand() % 2;

			if (randNum == 0)
			{
				m_maze[i][j] = 'O'; //通路
			}
			else
			{
				m_maze[i][j] = 'M'; //墙壁
			}
		}
	}

	//设置一些迷宫通道，以避免随机产生的迷宫总是无通路
	int m = 1;
	int n = 1;
	m_maze[m][n] = 'O';
	for (; m < m_row - 2; m++)
	{
		if (n < m_col - 2)
		{
			m_maze[m][n + 1] = 'O';
			m_maze[m + 1][n + 1] = 'O';
			n++;
		}
		else
		{
			m_maze[m][n - 1] = 'O';
		}
	}
	if (n < m_col - 2)
	{
		for (; n < m_col - 2; n++)
		{
			m_maze[m][n + 1] = 'O';
		}
	}

	//设置迷宫的起点和终点
	m_startPoint.x = 1;
	m_startPoint.y = 1;
	m_maze[1][1] = 'q';

	m_endPoint.x = m_row - 2;
	m_endPoint.y = m_col - 2;
	m_maze[m_row - 2][m_col - 2] = 'z';

}

/*******************************************************************************
* 函数功能: 绘制迷宫图案
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
void CMaze::DrawMaze()
{
	for (int i = 0; i < m_row; ++i)
	{
		for (int j = 0; j < m_col; ++j)
		{
			cout<<" "<<m_maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*******************************************************************************
* 函数功能: 判断某一坐标点是否被踩过
* 参    数: [IN] Point point，要check的坐标点
* 返 回 值: true，踩过；false，未踩过
* 备    注：
*******************************************************************************/
bool CMaze::IsStepped(Point point)
{
	if (!m_steppedPoint.empty())
	{
		for (vector<Point>::iterator it = m_steppedPoint.begin(); it != m_steppedPoint.end(); ++it)
		{
			if (it->x == point.x && it->y == point.y)
			{
				return true;
			}
		}
	}

	return false;
}

/*******************************************************************************
* 函数功能: check迷宫中某个O点在某个方向上是否走的通
* 参    数: [IN] Point point，要check的坐标点；int direction，要check的方向：上下左右
* 返 回 值: true，走的通；false，走不通
* 备    注：
*******************************************************************************/
bool CMaze::CheckPath(Point point, int direction)
{
	Point nextP;

	switch (direction)
	{
	case RIGHT: 
	    nextP.x = point.x;
		nextP.y = point.y + 1;
		if ((m_maze[nextP.x][nextP.y] == 'O' || m_maze[nextP.x][nextP.y] == 'z') 
			&& !IsStepped(nextP)) //向右走，y坐标+1
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case DOWN: 
		nextP.x = point.x + 1;
		nextP.y = point.y;
		if ((m_maze[nextP.x][nextP.y] == 'O' || m_maze[nextP.x][nextP.y] == 'z') 
			&& !IsStepped(nextP)) //向下走，x坐标+1
 	    {
		   return true;
	    }
	    else
		{
		   return false;
		}
		break;

	case LEFT:
		nextP.x = point.x;
		nextP.y = point.y - 1;
		if ((m_maze[nextP.x][nextP.y] == 'O' || m_maze[nextP.x][nextP.y] == 'z') 
			&& !IsStepped(nextP)) //向左走，y坐标-1
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case UP:
		nextP.x = point.x - 1;
		nextP.y = point.y;
		if ((m_maze[nextP.x][nextP.y] == 'O' || m_maze[nextP.x][nextP.y] == 'z') 
			&& !IsStepped(nextP)) //向上走，x坐标-1
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default: return false;
		break;
	}

	return false;
}

/*******************************************************************************
* 函数功能: 判断某一坐标点是否到达终点
* 参    数: [IN] Point point,要判断的坐标点
* 返 回 值: true，到达终点；false，未达终点
* 备    注：
*******************************************************************************/
bool CMaze::IsEndPoint(Point point)
{
	if (point.x == m_endPoint.x && point.y == m_endPoint.y)
	{
		return true;
	}

	return false;
}

/*******************************************************************************
* 函数功能: 在绘制的迷宫中从起点到终点找出路
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
bool CMaze::FindPath()
{
	Step firstStep;
	firstStep.point = m_startPoint;
	firstStep.backDirect = NO;
	m_path.push(firstStep);

	while (!m_path.empty())
	{
		//拿出当前的Step探索其在哪个方向可以走通，按照从右开始的顺时针方向探索
		Step currentStep = (Step)m_path.top();
		Point steppedPoint = currentStep.point;
		m_path.pop();

		Step nextStep;

		if (currentStep.backDirect != RIGHT && CheckPath(currentStep.point, RIGHT)) //先向右探索
		{
			currentStep.goDirect = RIGHT;
            nextStep.backDirect = LEFT;
			nextStep.point.x = currentStep.point.x;
			nextStep.point.y = currentStep.point.y + 1;
		}
		else if (currentStep.backDirect != DOWN && CheckPath(currentStep.point, DOWN)) //再向下探索
		{
			currentStep.goDirect = DOWN;
			nextStep.backDirect = UP;
			nextStep.point.x = currentStep.point.x + 1;
			nextStep.point.y = currentStep.point.y;
		}
		else if (currentStep.backDirect != LEFT && CheckPath(currentStep.point, LEFT)) //再向左探索
		{
			currentStep.goDirect = LEFT;
			nextStep.backDirect = RIGHT;
			nextStep.point.x = currentStep.point.x;
			nextStep.point.y = currentStep.point.y - 1;
		}
		else if (currentStep.backDirect != UP && CheckPath(currentStep.point, UP)) //再向上探索
		{
			currentStep.goDirect = UP;
			nextStep.backDirect = DOWN;
			nextStep.point.x = currentStep.point.x - 1;
			nextStep.point.y = currentStep.point.y;
		}
		else //4个方向都探索完后仍通，则后退一步重新探索
		{
			m_steppedPoint.push_back(steppedPoint);
			if (IsEndPoint(currentStep.point))
			{
				break;
			}
			continue;
		}

		m_path.push(currentStep);
		m_path.push(nextStep);

		m_steppedPoint.push_back(steppedPoint);

		if (IsEndPoint(nextStep.point))
		{
			break;
		}
	}



	if (m_path.empty())
	{
		cout<<endl<<"Sorry，没有通路可走也！"<<endl;
		return false;
	}
	else
	{
		cout<<endl<<"哦也，找到一条通路！"<<endl;
		int size = m_path.size();

		//设置迷宫中通路经过的坐标点的值为'x'
		while (!m_path.empty())
		{
			Step s = m_path.top();
			m_maze[s.point.x][s.point.y] = 'x';
			m_path.pop();
		}
		m_maze[1][1] = 'q';
		m_maze[m_row - 2][m_col - 2] = 'z';

		return true;
	}

	return false;
}