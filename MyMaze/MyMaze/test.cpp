/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: test.cpp
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-24
功能描述: 对实现的迷宫进行测试
其它相关: 
修改记录: 
****************************************************************************************/

#include <iostream>
#include "Maze.h"

using namespace std;

int main()
{
	char goOn;
	
	do 
	{
		cout<<endl<<"************************小小迷宫阵************************"<<endl;
	
		int length = 0;
		int width = 0;
	
		cout<<endl<<"请输入迷宫长度(大于1的正整数)：";
		cin>>length;
		while (length < 2)
		{
			cout<<"Error！请重新输入长度:";
			cin>>length;
		}
	
		cout<<endl<<"请输入迷宫宽度(大于1的正整数)：";
		cin>>width;
		while (width < 2)
		{
			cout<<"Error！请重新输入宽度:";
			cin>>width;
		}
	
		CMaze maze;
		if (maze.Init(length, width))
		{
			maze.Start();
		}
		else
		{
			cout<<"Sorry,当前游戏小状况中，欢迎下次来玩~"<<endl;
			return 0;
		}
	
		cout<<endl<<"还想再玩一次迷宫阵吗？(Y/N):";
		cin>>goOn;
		while (goOn != 'N' && goOn != 'n' && goOn != 'Y' && goOn != 'y')
		{
			cout<<endl<<"Sorry~"<<endl;
			cout<<"还想再玩一次迷宫阵吗？(Y/N):";
			cin>>goOn;
		}
	
		if (goOn == 'N' || goOn == 'n') //退出游戏
		{
			maze.Exit();
			break;
		}
	
	}while (goOn == 'Y' || goOn == 'y'); //继续游戏

	return 0;
}