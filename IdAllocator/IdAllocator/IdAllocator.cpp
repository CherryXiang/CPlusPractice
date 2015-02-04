#include <iostream>
#include "IdAllocator.h"

using namespace std;

/*******************************************************************************
* 函数功能: 默认构造函数
* 参    数: [IN]
* 返 回 值: 
* 备    注：
*******************************************************************************/
CIdAllocator::CIdAllocator()
{
	m_sList = NULL;
	m_idMax = NLL;
	m_freeHead = NLL;
	m_usedHead = NLL;
}


/*******************************************************************************
* 函数功能: 析构函数，释放init时动态分配的数组内存
* 参    数: [IN] 
* 返 回 值: 
* 备    注：
*******************************************************************************/
CIdAllocator::~CIdAllocator()
{
	delete[] m_sList;
}


/*******************************************************************************
* 函数功能: id分配器的初始化
* 参    数: [IN] int n，id分配器可分配的id范围：0~n-1 
* 返 回 值: 返回ture，初始化成功；返回false，初始化失败
* 备    注：
*******************************************************************************/
bool CIdAllocator::Init(int n)
{
	if (n <= 0)
	{
		cout<<"初始化参数Error！"<<endl;
		return false;
	}

	m_idMax = n - 1;

	m_sList = new SNodeList[n];
	if (!m_sList)
	{
		cout<<"初始化失败！"<<endl;
		return false;
	}

	cout<<"Id allocator initializing......"<<endl;

	for (int i = 0; i <= m_idMax; ++i)
	{
		m_sList[i].flag = FREE;
		m_sList[i].pre = i - 1;
		m_sList[i].next = i + 1;
	}

	m_sList[0].pre = NLL; //头结点的前驱为空
	m_sList[m_idMax].next = NLL; //尾结点的后继为空

	m_freeHead = 0; //空闲链表头部初始化为指向存储区头部
	m_usedHead = NLL; //使用链表头部初始化为空，因尚未分配结点使用

	cout<<"Init finished!"<<endl<<endl;

	return true;
}


/*******************************************************************************
* 函数功能: 进行id分配
* 参    数: [IN] 无参数 
* 返 回 值: 分配成功则返回相应id；失败则返回-1
* 备    注：
*******************************************************************************/
int CIdAllocator::Alloc()
{
	int id = -1;

	if (m_freeHead != NLL)
	{
		id = m_freeHead; //每次分配空闲链表的头结点到使用链表
		m_sList[id].flag = USED;

		//分配后空闲链表的维护
		m_freeHead = m_sList[m_freeHead].next; //空闲链表的头部后移到next结点，产生新的头结点
		m_sList[m_freeHead].pre = NLL; //设置新头结点的前驱为空


		//分配后使用链表的维护，分配的结点插入到使用链表的头部成为使用链表的头结点
		m_sList[id].pre = NLL; //设置头结点的前驱为空
		m_sList[id].next = m_usedHead; //设置头结点的后继指向使用链表的头部
		if (m_usedHead != NLL)
		{
			m_sList[m_usedHead].pre = id; //使用链表原头结点的前驱指向分配结点
		}
		m_usedHead = id; //使用链表头部前移到已分配的结点，产生新的头结点
	}
	else
	{
		cout<<"sorry，没有空间可分配啦！"<<endl;
	}
	
	return id; //返回为-1时，表示没有空间可分配了，即空间分配失败
}


/*******************************************************************************
* 函数功能: 释放分配的id
* 参    数: [IN] int id，要释放的id 
* 返 回 值: 无
* 备    注：
*******************************************************************************/
void CIdAllocator::Free(int id)
{
	if (id < 0 || id > m_idMax)
	{
		cout<<"id的空间不存在！"<<endl;
	}
	else if (!IsAlloc(id))
	{
		cout<<"不能释放未使用的空间"<<endl;
	}
	else
	{
		m_sList[id].flag = FREE;

		//释放后使用链表的维护
		if (id == m_usedHead) //释放头结点情况，使用链表头部后移
		{
			m_usedHead = m_sList[id].next; //m_usedHead == NULL 时，说明释放结点既是头结点也是尾结点，释放后使用链表就空了，也即m_usedHead = NULL了
			if (m_usedHead != NLL)
			{
				m_sList[m_usedHead].pre = NLL; //新头结点前驱设为空
			}
		}
		else if (m_sList[id].next == NLL) //释放尾结点情况
		{
			m_sList[m_sList[id].pre].next = NLL; //释放结点其前驱的后继设为空NULL即可
		}
		else //释放中间结点的情况
		{
			m_sList[m_sList[id].next].pre = m_sList[id].pre;
			m_sList[m_sList[id].pre].next = m_sList[id].next;
		}


		//释放后空闲链表的维护，释放结点插入到空闲链表的头部
		m_sList[id].pre = NLL;
		m_sList[id].next = m_freeHead;
		if (m_freeHead != NLL)
		{
			m_sList[m_freeHead].pre = id;
		}
		m_freeHead = id;

		cout<<id<<"已被释放"<<endl;
	}
}


/*******************************************************************************
* 函数功能: 判断一个id是否已被分配
* 参    数: [IN] int id，要进行判断的id 
* 返 回 值: 返回ture，id已被分配；返回false，id未被分配或id超出范围不存在
* 备    注：
*******************************************************************************/
bool CIdAllocator::IsAlloc(int id)
{
	if (id < 0 || id > m_idMax)
	{
		cout<<"id不存在！"<<endl;
		return false;
	}

	if (m_sList[id].flag == USED)
	{
		cout<<"该id已分配"<<endl;
		return true;
	}
	else if (m_sList[id].flag == FREE)
	{
		cout<<"该id没有被分配"<<endl;
		return false;
	}

	return false;
}