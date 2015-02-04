/****************************************************************************************
Copyright (C), 2014，Haowan123 Tech. Co., Ltd.
文 件 名: IdAllocator.h
作    者: 兰香 
版    本: V1.0
完成日期: 2014-1-21
功能描述: 分配一个从0~n-1的id来使用，即一个id分配器
其它相关: 
修改记录: 
  1.修改日期：2014-1-22
  2.修 改 者：兰香
  3.修改简述：清除多余接口Prind()，修改Init()接口，增加文件头部注释
****************************************************************************************/

#pragma once

//#define SLISTMAXLEN 10
#define USED 1
#define FREE 0
#define NLL -1

class CIdAllocator
{
public:
	CIdAllocator();
	~CIdAllocator();

	//公共接口
	bool Init(int n); //存储区的初始化
	int Alloc(); //结点空间分配
	void Free(int id); //结点空间释放
	bool IsAlloc(int id); //结点空间是否已分配

private:
	typedef struct Node
	{
		int flag; //结点区域空闲与否标志
		int pre; //结点前驱
		int next; //结点后继
	}SNodeList;

	//SNodeList m_sList[SLISTMAXLEN]; //可分配的最大存储区
	SNodeList *m_sList; //初始化再动态分配一个数组出来
	int m_idMax; //用户指定的id上限
	int m_freeHead; //空闲链表头部
	int m_usedHead; //使用链表头部
};