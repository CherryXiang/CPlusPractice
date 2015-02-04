#include <iostream>
#include "IdAllocator.h"

using namespace std;

/*******************************************************************************
* ��������: Ĭ�Ϲ��캯��
* ��    ��: [IN]
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
CIdAllocator::CIdAllocator()
{
	m_sList = NULL;
	m_idMax = NLL;
	m_freeHead = NLL;
	m_usedHead = NLL;
}


/*******************************************************************************
* ��������: �����������ͷ�initʱ��̬����������ڴ�
* ��    ��: [IN] 
* �� �� ֵ: 
* ��    ע��
*******************************************************************************/
CIdAllocator::~CIdAllocator()
{
	delete[] m_sList;
}


/*******************************************************************************
* ��������: id�������ĳ�ʼ��
* ��    ��: [IN] int n��id�������ɷ����id��Χ��0~n-1 
* �� �� ֵ: ����ture����ʼ���ɹ�������false����ʼ��ʧ��
* ��    ע��
*******************************************************************************/
bool CIdAllocator::Init(int n)
{
	if (n <= 0)
	{
		cout<<"��ʼ������Error��"<<endl;
		return false;
	}

	m_idMax = n - 1;

	m_sList = new SNodeList[n];
	if (!m_sList)
	{
		cout<<"��ʼ��ʧ�ܣ�"<<endl;
		return false;
	}

	cout<<"Id allocator initializing......"<<endl;

	for (int i = 0; i <= m_idMax; ++i)
	{
		m_sList[i].flag = FREE;
		m_sList[i].pre = i - 1;
		m_sList[i].next = i + 1;
	}

	m_sList[0].pre = NLL; //ͷ����ǰ��Ϊ��
	m_sList[m_idMax].next = NLL; //β���ĺ��Ϊ��

	m_freeHead = 0; //��������ͷ����ʼ��Ϊָ��洢��ͷ��
	m_usedHead = NLL; //ʹ������ͷ����ʼ��Ϊ�գ�����δ������ʹ��

	cout<<"Init finished!"<<endl<<endl;

	return true;
}


/*******************************************************************************
* ��������: ����id����
* ��    ��: [IN] �޲��� 
* �� �� ֵ: ����ɹ��򷵻���Ӧid��ʧ���򷵻�-1
* ��    ע��
*******************************************************************************/
int CIdAllocator::Alloc()
{
	int id = -1;

	if (m_freeHead != NLL)
	{
		id = m_freeHead; //ÿ�η�����������ͷ��㵽ʹ������
		m_sList[id].flag = USED;

		//�������������ά��
		m_freeHead = m_sList[m_freeHead].next; //���������ͷ�����Ƶ�next��㣬�����µ�ͷ���
		m_sList[m_freeHead].pre = NLL; //������ͷ����ǰ��Ϊ��


		//�����ʹ�������ά��������Ľ����뵽ʹ�������ͷ����Ϊʹ�������ͷ���
		m_sList[id].pre = NLL; //����ͷ����ǰ��Ϊ��
		m_sList[id].next = m_usedHead; //����ͷ���ĺ��ָ��ʹ�������ͷ��
		if (m_usedHead != NLL)
		{
			m_sList[m_usedHead].pre = id; //ʹ������ԭͷ����ǰ��ָ�������
		}
		m_usedHead = id; //ʹ������ͷ��ǰ�Ƶ��ѷ���Ľ�㣬�����µ�ͷ���
	}
	else
	{
		cout<<"sorry��û�пռ�ɷ�������"<<endl;
	}
	
	return id; //����Ϊ-1ʱ����ʾû�пռ�ɷ����ˣ����ռ����ʧ��
}


/*******************************************************************************
* ��������: �ͷŷ����id
* ��    ��: [IN] int id��Ҫ�ͷŵ�id 
* �� �� ֵ: ��
* ��    ע��
*******************************************************************************/
void CIdAllocator::Free(int id)
{
	if (id < 0 || id > m_idMax)
	{
		cout<<"id�Ŀռ䲻���ڣ�"<<endl;
	}
	else if (!IsAlloc(id))
	{
		cout<<"�����ͷ�δʹ�õĿռ�"<<endl;
	}
	else
	{
		m_sList[id].flag = FREE;

		//�ͷź�ʹ�������ά��
		if (id == m_usedHead) //�ͷ�ͷ��������ʹ������ͷ������
		{
			m_usedHead = m_sList[id].next; //m_usedHead == NULL ʱ��˵���ͷŽ�����ͷ���Ҳ��β��㣬�ͷź�ʹ������Ϳ��ˣ�Ҳ��m_usedHead = NULL��
			if (m_usedHead != NLL)
			{
				m_sList[m_usedHead].pre = NLL; //��ͷ���ǰ����Ϊ��
			}
		}
		else if (m_sList[id].next == NLL) //�ͷ�β������
		{
			m_sList[m_sList[id].pre].next = NLL; //�ͷŽ����ǰ���ĺ����Ϊ��NULL����
		}
		else //�ͷ��м�������
		{
			m_sList[m_sList[id].next].pre = m_sList[id].pre;
			m_sList[m_sList[id].pre].next = m_sList[id].next;
		}


		//�ͷź���������ά�����ͷŽ����뵽���������ͷ��
		m_sList[id].pre = NLL;
		m_sList[id].next = m_freeHead;
		if (m_freeHead != NLL)
		{
			m_sList[m_freeHead].pre = id;
		}
		m_freeHead = id;

		cout<<id<<"�ѱ��ͷ�"<<endl;
	}
}


/*******************************************************************************
* ��������: �ж�һ��id�Ƿ��ѱ�����
* ��    ��: [IN] int id��Ҫ�����жϵ�id 
* �� �� ֵ: ����ture��id�ѱ����䣻����false��idδ�������id������Χ������
* ��    ע��
*******************************************************************************/
bool CIdAllocator::IsAlloc(int id)
{
	if (id < 0 || id > m_idMax)
	{
		cout<<"id�����ڣ�"<<endl;
		return false;
	}

	if (m_sList[id].flag == USED)
	{
		cout<<"��id�ѷ���"<<endl;
		return true;
	}
	else if (m_sList[id].flag == FREE)
	{
		cout<<"��idû�б�����"<<endl;
		return false;
	}

	return false;
}