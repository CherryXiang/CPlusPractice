#include <iostream>
#include "MyBiTree.h"

using namespace std;

CMyBiTree::CMyBiTree()
    :m_biTree(NULL)
{

}

CMyBiTree::~CMyBiTree()
{
	DestroyBiTree(m_biTree);
}

void CMyBiTree::GenerateBiTree()
{
	CreateBiTree(m_biTree);
}

void CMyBiTree::CreateBiTree(BiNode* &biTree)
{
	int data;
	cin>>data;
	if (0 == data)
	{
		biTree = NULL;
		return;
	}

	biTree  = new BiNode;
	if (NULL != biTree)
	{
		biTree->data = data;
		CreateBiTree(biTree->pLeftTree);
		CreateBiTree(biTree->pRightTree);
	}
}

void CMyBiTree::Display()
{
	PreOrder(m_biTree);
}

void CMyBiTree::PreOrder(BiNode* biTree)
{
	if (NULL != biTree)
	{
		cout<<biTree->data<<" ";
		PreOrder(biTree->pLeftTree);
		PreOrder(biTree->pRightTree);
	}
}

void CMyBiTree::DestroyBiTree(BiNode* biTree)
{
	if (NULL != biTree)
	{
		DestroyBiTree(biTree->pLeftTree);
		DestroyBiTree(biTree->pRightTree);
	}
	delete biTree;
	biTree = NULL;
}