/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: test.cpp
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-21
功能描述: 对id分配器接口类进行测试
其它相关: 
修改记录: 
  1.修改日期：2014-1-22
  2.修 改 者：兰香
  3.修改简述：增加文件头部注释
****************************************************************************************/

#include <iostream>
#include "IdAllocator.h"

using namespace std;

int main()
{
	cout<<"该id分配器可分配的一个id号来使用"<<endl;

	int n = 0;
	cout<<"请输入您的id上限值：";
	cin>>n;

	CIdAllocator idAllocator;

	if (idAllocator.Init(n))
	{
		int n1 = idAllocator.Alloc();
		if (n1 != -1)
		{
			cout<<"已分配id:"<<n1<<endl;
		}

		int n2 = idAllocator.Alloc();
		if (n2 != -1)
		{
			cout<<"已分配id:"<<n2<<endl;
		}

		int id1 = 3;
		idAllocator.IsAlloc(id1);

		int id2 = 6;
		idAllocator.IsAlloc(id2);

		idAllocator.Free(1);
		idAllocator.Free(0);
		idAllocator.Free(2);
		idAllocator.Free(8);
	}

	return 0;
}
