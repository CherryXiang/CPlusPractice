/****************************************************************************************
Copyright (C), 2014��Haowan123 Tech. Co., Ltd.
�� �� ��: test.cpp
��    ��: ���� 
��    ��: V1.0
�������: 2014-1-23
��������: �Ծ�̬��������в���
�������: 
�޸ļ�¼: 
****************************************************************************************/

#include <iostream>
#include <string>
//#include "CLink.h" //ֻ����Hͷ�ļ�(δ������CPP�ļ�)����������"�޷��������ⲿ����"error������H�ļ�ĩβinclude��CPP�����ڴ�ֱ��include��H�ļ�����
//#include "CLink.cpp" //ֱ�Ӱ���CPPʵ���ļ��ǿ��ԣ�����̫����includeһ��ϰ��
#include "StaticList.h" //��H�ļ���includeģ�����H�ļ���CPP�ļ����õ��ĵط�ֱ��include��H�ļ�����

using namespace std;

int main()
{
	//ģ������Ϊint�Ĳ���
	int data1 = 2;
	int data2 = 5;
	int data3 = 9;
	int data4 = 1;
	int data5 = 3;

	int size = 0;
	cout<<"����������CLink��size��";
	cin>>size;

	CCLink<int> cIntLink;
	if (cIntLink.Init(size))
	{
		int id1 = cIntLink.Alloc();
		if (id1 != NLL)
		{
			cIntLink[id1] = data1;
			cout<<"�洢�����ݣ�"<<cIntLink[id1]<<endl;
		}

		int id2 = cIntLink.Alloc();
		if (id2 != NLL)
		{
			cIntLink[id2] = data2;
			cout<<"�洢�����ݣ�"<<cIntLink[id2]<<endl;
		}

		cIntLink.IsAlloc(id1);
		cIntLink.Free(id1);
		cIntLink.IsAlloc(id1);
	}


	//ģ������Ϊstring�Ĳ���
	string str1 = "str1";
	string str2 = "str2";
	string str3 = "str3";
	string str4 = "str4";

	cout<<endl<<endl;
	cout<<"����������CLink��size��";
	cin>>size;

	CCLink<string> cStrLink;
	if (cStrLink.Init(size))
	{
		int id1 = cStrLink.Alloc();
		if (id1 != NLL)
		{
			cStrLink[id1] = str1;
			cout<<"�洢�����ݣ�"<<cStrLink[id1]<<endl;
		}

		int id2 = cStrLink.Alloc();
		if (id2 != NLL)
		{
			cStrLink[id2] = str2;
			cout<<"�洢�����ݣ�"<<cStrLink[id2]<<endl;
		}

		cStrLink.IsAlloc(id1);
		cStrLink.Free(id1);
		cStrLink.IsAlloc(id1);
	}



	return 0;
}