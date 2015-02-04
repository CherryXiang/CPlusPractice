/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: CLink.h
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-23
功能描述: 采用CIdAllocator辅助类实现静态链表
其它相关: 
修改记录: 
****************************************************************************************/

#pragma once

#include "IdAllocator.h"

template <typename T>
class CCLink
{
public:
	CCLink();
	~CCLink();

	//下标操作符重载
	T& operator[](const int index);
	const T& operator[](const int index) const;

	//公共接口
	bool Init(const int n);
	int Alloc(); 
	void Free(const int n);
	bool IsAlloc(const int n);

private:
	CIdAllocator idAllocator;
	T *m_dataArray;
};

//#include "CLink.cpp" //在此直接将模板类实现包含进来(实质上还是模板类的定义和实现在一起)，在使用时仅包含该H文件即可