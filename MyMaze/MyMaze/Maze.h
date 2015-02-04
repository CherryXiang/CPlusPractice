/****************************************************************************************
Copyright (C), 2014��Haowan123 Tech. Co., Ltd.
�� �� ��: CMaze.h
��    ��: ���� 
��    ��: V1.0
�������: 2014-1-24
��������: ʵ��һ���Թ������������յ㣬Ȼ�����������ɵ����յ��·��
�������: 
�޸ļ�¼: 
  1.�޸����ڣ�2014-1-26
  2.�� �� �ߣ�����
  3.�޸ļ�������Init()�ӿ��з����������Ա����MakeMaze()���޸�~CMaze()��֮ǰ������Խ��
              �Ľ�FindPath()��֮ǰ�Ļ�żȻ��ѭ��
****************************************************************************************/

#pragma once
#include <stack>
#include <vector>

using namespace std;

//�Թ��п��ߵķ�����
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

	bool Init(int len, int wid);                //�����û�������Թ�����ȣ���ʼ��һ���Թ�����
	void Start();                               //�����Թ�����ȡ�����յ��ʼ�ҳ�·
	void Exit();                                //�˳��Թ�����

protected:
	typedef struct                              //�Թ��е������
	{
		int x;                                  //x����
		int y;                                  //y����
	}Point; 

	typedef struct                              //���Թ�ʱ�Ĳ���
	{
		Point point;                            //�������ȵ������
		int goDirect;                           //����ǰ������
		int backDirect;                         //���Ӻ��˷���
	}Step;

	void MakeMaze();                            //���������Թ�ͼ��
	void DrawMaze();                            //�����Թ�
	bool FindPath();                            //���Թ�����㵽�յ��ҳ�·
	bool IsStepped(Point point);                //�ж�ĳһ������Ƿ񱻲ȹ�
	bool CheckPath(Point point, int direction); //�жϵ�ǰ���Ӳȵ��������ĳ���������Ƿ��ߵ�ͨ
	bool IsEndPoint(Point point);               //�Ƿ񵽴��յ�����

private:
	char **m_maze;                              //��ά���鱣����Թ�ͼ����һȦդ��
	int m_col;                                  //�Թ�ͼ����
	int m_row;                                  //�Թ�ͼ����

	Point m_startPoint;                         //�Թ��������
	Point m_endPoint;                           //�Թ��յ�����

	stack<Step> m_path;                         //�洢��ͨ�Ĳ��ӣ�����㵽�յ���ͨ�Ĳ����������ͳ�һ���Թ���·
	vector<Point> m_steppedPoint;               //�洢���߹���(Ҳ�����߲�ͨ��)�����
};