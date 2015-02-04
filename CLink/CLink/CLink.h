/****************************************************************************************
Copyright (C), 2014��Haowan123 Tech. Co., Ltd.
�� �� ��: CLink.h
��    ��: ���� 
��    ��: V1.0
�������: 2014-1-23
��������: ����CIdAllocator������ʵ�־�̬����
�������: 
�޸ļ�¼: 
****************************************************************************************/

#pragma once

#include "IdAllocator.h"

template <typename T>
class CCLink
{
public:
	CCLink();
	~CCLink();

	//�±����������
	T& operator[](const int index);
	const T& operator[](const int index) const;

	//�����ӿ�
	bool Init(const int n);
	int Alloc(); 
	void Free(const int n);
	bool IsAlloc(const int n);

private:
	CIdAllocator idAllocator;
	T *m_dataArray;
};

//#include "CLink.cpp" //�ڴ�ֱ�ӽ�ģ����ʵ�ְ�������(ʵ���ϻ���ģ����Ķ����ʵ����һ��)����ʹ��ʱ��������H�ļ�����