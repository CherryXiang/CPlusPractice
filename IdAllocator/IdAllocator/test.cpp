/****************************************************************************************
Copyright (C), 2014��Haowan123 Tech. Co., Ltd.
�� �� ��: test.cpp
��    ��: ���� 
��    ��: V1.0
�������: 2014-1-21
��������: ��id�������ӿ�����в���
�������: 
�޸ļ�¼: 
  1.�޸����ڣ�2014-1-22
  2.�� �� �ߣ�����
  3.�޸ļ����������ļ�ͷ��ע��
****************************************************************************************/

#include <iostream>
#include "IdAllocator.h"

using namespace std;

int main()
{
	cout<<"��id�������ɷ����һ��id����ʹ��"<<endl;

	int n = 0;
	cout<<"����������id����ֵ��";
	cin>>n;

	CIdAllocator idAllocator;

	if (idAllocator.Init(n))
	{
		int n1 = idAllocator.Alloc();
		if (n1 != -1)
		{
			cout<<"�ѷ���id:"<<n1<<endl;
		}

		int n2 = idAllocator.Alloc();
		if (n2 != -1)
		{
			cout<<"�ѷ���id:"<<n2<<endl;
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
