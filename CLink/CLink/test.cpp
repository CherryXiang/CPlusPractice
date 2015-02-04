/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: test.cpp
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-23
功能描述: 对静态链表类进行测试
其它相关: 
修改记录: 
****************************************************************************************/

#include <iostream>
#include <string>
//#include "CLink.h" //只包含H头文件(未包含其CPP文件)，编译会出现"无法解析的外部符号"error。或在H文件末尾include其CPP后，再在此直接include其H文件即可
//#include "CLink.cpp" //直接包含CPP实现文件是可以，但不太符合include一般习惯
#include "StaticList.h" //该H文件中include模板类的H文件和CPP文件，用到的地方直接include该H文件即可

using namespace std;

int main()
{
	//模板类型为int的测试
	int data1 = 2;
	int data2 = 5;
	int data3 = 9;
	int data4 = 1;
	int data5 = 3;

	int size = 0;
	cout<<"请输入您的CLink的size：";
	cin>>size;

	CCLink<int> cIntLink;
	if (cIntLink.Init(size))
	{
		int id1 = cIntLink.Alloc();
		if (id1 != NLL)
		{
			cIntLink[id1] = data1;
			cout<<"存储的数据："<<cIntLink[id1]<<endl;
		}

		int id2 = cIntLink.Alloc();
		if (id2 != NLL)
		{
			cIntLink[id2] = data2;
			cout<<"存储的数据："<<cIntLink[id2]<<endl;
		}

		cIntLink.IsAlloc(id1);
		cIntLink.Free(id1);
		cIntLink.IsAlloc(id1);
	}


	//模板类型为string的测试
	string str1 = "str1";
	string str2 = "str2";
	string str3 = "str3";
	string str4 = "str4";

	cout<<endl<<endl;
	cout<<"请输入您的CLink的size：";
	cin>>size;

	CCLink<string> cStrLink;
	if (cStrLink.Init(size))
	{
		int id1 = cStrLink.Alloc();
		if (id1 != NLL)
		{
			cStrLink[id1] = str1;
			cout<<"存储的数据："<<cStrLink[id1]<<endl;
		}

		int id2 = cStrLink.Alloc();
		if (id2 != NLL)
		{
			cStrLink[id2] = str2;
			cout<<"存储的数据："<<cStrLink[id2]<<endl;
		}

		cStrLink.IsAlloc(id1);
		cStrLink.Free(id1);
		cStrLink.IsAlloc(id1);
	}



	return 0;
}