/****************************************************************************************
Copyright (C), 2014��Haowan123 Tech. Co., Ltd.
�� �� ��: IdAllocator.h
��    ��: ���� 
��    ��: V1.0
�������: 2014-1-21
��������: ����һ����0~n-1��id��ʹ�ã���һ��id������
�������: 
�޸ļ�¼: 
  1.�޸����ڣ�2014-1-22
  2.�� �� �ߣ�����
  3.�޸ļ������������ӿ�Prind()���޸�Init()�ӿڣ������ļ�ͷ��ע��
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

	//�����ӿ�
	bool Init(int n); //�洢���ĳ�ʼ��
	int Alloc(); //���ռ����
	void Free(int id); //���ռ��ͷ�
	bool IsAlloc(int id); //���ռ��Ƿ��ѷ���

private:
	typedef struct Node
	{
		int flag; //��������������־
		int pre; //���ǰ��
		int next; //�����
	}SNodeList;

	//SNodeList m_sList[SLISTMAXLEN]; //�ɷ�������洢��
	SNodeList *m_sList; //��ʼ���ٶ�̬����һ���������
	int m_idMax; //�û�ָ����id����
	int m_freeHead; //��������ͷ��
	int m_usedHead; //ʹ������ͷ��
};