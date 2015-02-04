#include <iostream>
#include <ctime>
#include <windows.h>

#include "Maze.h"

using namespace std;

/*******************************************************************************
* ��������: Ĭ�Ϲ��캯��
* ��    ��: [IN]
* �� �� ֵ: 
* ��    ע��
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
* ��������: �����������ͷ�initʱ��̬����������ڴ�
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
CMaze::~CMaze()
{
	for (int i = 0; i < m_row; ++i) //�ͷ�ʱ��һ��һ�е��ͷţ������Ϊi < m_col������m_row < m_colʱ����Խ�絼�³������
	{
		delete []m_maze[i];
		m_maze[i] = NULL;
	}
	
	delete []m_maze;
	m_maze = NULL;
}

/*******************************************************************************
* ��������: ���Թ����г�ʼ����
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
bool CMaze::Init(int len, int wid)
{
	cout<<endl<<"�Թ���ʼ����......"<<endl;

	m_steppedPoint.clear();
	if (m_maze != NULL)
	{
		for (int i = 0; i < m_row; ++i)
		{
			delete[] m_maze[i];
		}

		delete[] m_maze;
	}

	//�Թ���Χ���դ����ĺ�����
	m_col = len + 2;
	m_row = wid + 2;

	//��̬����洢�Թ�ͼ�Ķ�ά����ռ�
	m_maze = new char*[m_row];
	if (m_maze == NULL)
	{
		cout<<"��ʼ��ʧ�ܣ�"<<endl;
		return false;
	}

	for (int i = 0; i < m_row; ++i)
	{
		m_maze[i] = new char[m_col];
		if (m_maze[i] == NULL)
		{
			cout<<"��ʼ��ʧ�ܣ�"<<endl;
			return false;
		}
	}

	cout<<"��ʼ����ϣ�"<<endl<<endl;

	return true;
}

/*******************************************************************************
* ��������: �����Թ�����
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
void CMaze::Start()
{
	MakeMaze();

	cout<<"ע��*��ʾ�Թ���Χդ����O��ʾ�Թ�ͨ����M��ʾ�Թ�ǽ"<<endl;
	cout<<"    q��ʾ��㣬z��ʾ�յ㣬x��ʾͨ·"<<endl<<endl;
	cout<<endl<<"��ǰ�Թ�ͼ��"<<endl<<endl;
	DrawMaze();

	cout<<endl<<"OK����������һ���ҳ�һ��ͨ·�ɣ�"<<endl;
	if (FindPath())
	{
		cout<<endl<<"�����ҵ�ͨ·���Թ�ͼ��"<<endl<<endl;
		DrawMaze();
	}
}

/*******************************************************************************
* ��������: �˳��Թ�����
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
void CMaze::Exit()
{
	cout<<endl<<"лл����ӭ�´�������Ŷ~"<<endl<<endl;
	cout<<"��Ϸ���˳�......"<<endl<<endl;

	Sleep(2000);
	//exit(0); //exit�󲻻�ִ������
}

/*******************************************************************************
* ��������: ���������Թ�ͼ��
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
void CMaze::MakeMaze()
{
	//�����Թ���Χդ��
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

	//�����Թ�ͼ���������0��1,0��ʾ�Թ�ͨ��(O����)��1��ʾ�Թ�ǽ(M����)
	srand((unsigned)time(NULL)); 
	for (int i = 1; i < m_row - 1; ++i)
	{
		for (int j = 1; j < m_col - 1; ++j)
		{
			int randNum = rand() % 2;

			if (randNum == 0)
			{
				m_maze[i][j] = 'O'; //ͨ·
			}
			else
			{
				m_maze[i][j] = 'M'; //ǽ��
			}
		}
	}

	//����һЩ�Թ�ͨ�����Ա�������������Թ�������ͨ·
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

	//�����Թ��������յ�
	m_startPoint.x = 1;
	m_startPoint.y = 1;
	m_maze[1][1] = 'q';

	m_endPoint.x = m_row - 2;
	m_endPoint.y = m_col - 2;
	m_maze[m_row - 2][m_col - 2] = 'z';

}

/*******************************************************************************
* ��������: �����Թ�ͼ��
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
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
* ��������: �ж�ĳһ������Ƿ񱻲ȹ�
* ��    ��: [IN] Point point��Ҫcheck�������
* �� �� ֵ: true���ȹ���false��δ�ȹ�
* ��    ע��
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
* ��������: check�Թ���ĳ��O����ĳ���������Ƿ��ߵ�ͨ
* ��    ��: [IN] Point point��Ҫcheck������㣻int direction��Ҫcheck�ķ�����������
* �� �� ֵ: true���ߵ�ͨ��false���߲�ͨ
* ��    ע��
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
			&& !IsStepped(nextP)) //�����ߣ�y����+1
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
			&& !IsStepped(nextP)) //�����ߣ�x����+1
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
			&& !IsStepped(nextP)) //�����ߣ�y����-1
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
			&& !IsStepped(nextP)) //�����ߣ�x����-1
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
* ��������: �ж�ĳһ������Ƿ񵽴��յ�
* ��    ��: [IN] Point point,Ҫ�жϵ������
* �� �� ֵ: true�������յ㣻false��δ���յ�
* ��    ע��
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
* ��������: �ڻ��Ƶ��Թ��д���㵽�յ��ҳ�·
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
bool CMaze::FindPath()
{
	Step firstStep;
	firstStep.point = m_startPoint;
	firstStep.backDirect = NO;
	m_path.push(firstStep);

	while (!m_path.empty())
	{
		//�ó���ǰ��Step̽�������ĸ����������ͨ�����մ��ҿ�ʼ��˳ʱ�뷽��̽��
		Step currentStep = (Step)m_path.top();
		Point steppedPoint = currentStep.point;
		m_path.pop();

		Step nextStep;

		if (currentStep.backDirect != RIGHT && CheckPath(currentStep.point, RIGHT)) //������̽��
		{
			currentStep.goDirect = RIGHT;
            nextStep.backDirect = LEFT;
			nextStep.point.x = currentStep.point.x;
			nextStep.point.y = currentStep.point.y + 1;
		}
		else if (currentStep.backDirect != DOWN && CheckPath(currentStep.point, DOWN)) //������̽��
		{
			currentStep.goDirect = DOWN;
			nextStep.backDirect = UP;
			nextStep.point.x = currentStep.point.x + 1;
			nextStep.point.y = currentStep.point.y;
		}
		else if (currentStep.backDirect != LEFT && CheckPath(currentStep.point, LEFT)) //������̽��
		{
			currentStep.goDirect = LEFT;
			nextStep.backDirect = RIGHT;
			nextStep.point.x = currentStep.point.x;
			nextStep.point.y = currentStep.point.y - 1;
		}
		else if (currentStep.backDirect != UP && CheckPath(currentStep.point, UP)) //������̽��
		{
			currentStep.goDirect = UP;
			nextStep.backDirect = DOWN;
			nextStep.point.x = currentStep.point.x - 1;
			nextStep.point.y = currentStep.point.y;
		}
		else //4������̽�������ͨ�������һ������̽��
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
		cout<<endl<<"Sorry��û��ͨ·����Ҳ��"<<endl;
		return false;
	}
	else
	{
		cout<<endl<<"ŶҲ���ҵ�һ��ͨ·��"<<endl;
		int size = m_path.size();

		//�����Թ���ͨ·������������ֵΪ'x'
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