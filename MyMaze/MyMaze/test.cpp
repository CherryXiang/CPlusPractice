/****************************************************************************************
Copyright (C), 2014��Haowan123 Tech. Co., Ltd.
�� �� ��: test.cpp
��    ��: ���� 
��    ��: V1.0
�������: 2014-1-24
��������: ��ʵ�ֵ��Թ����в���
�������: 
�޸ļ�¼: 
****************************************************************************************/

#include <iostream>
#include "Maze.h"

using namespace std;

int main()
{
	char goOn;
	
	do 
	{
		cout<<endl<<"************************СС�Թ���************************"<<endl;
	
		int length = 0;
		int width = 0;
	
		cout<<endl<<"�������Թ�����(����1��������)��";
		cin>>length;
		while (length < 2)
		{
			cout<<"Error�����������볤��:";
			cin>>length;
		}
	
		cout<<endl<<"�������Թ����(����1��������)��";
		cin>>width;
		while (width < 2)
		{
			cout<<"Error��������������:";
			cin>>width;
		}
	
		CMaze maze;
		if (maze.Init(length, width))
		{
			maze.Start();
		}
		else
		{
			cout<<"Sorry,��ǰ��ϷС״���У���ӭ�´�����~"<<endl;
			return 0;
		}
	
		cout<<endl<<"��������һ���Թ�����(Y/N):";
		cin>>goOn;
		while (goOn != 'N' && goOn != 'n' && goOn != 'Y' && goOn != 'y')
		{
			cout<<endl<<"Sorry~"<<endl;
			cout<<"��������һ���Թ�����(Y/N):";
			cin>>goOn;
		}
	
		if (goOn == 'N' || goOn == 'n') //�˳���Ϸ
		{
			maze.Exit();
			break;
		}
	
	}while (goOn == 'Y' || goOn == 'y'); //������Ϸ

	return 0;
}