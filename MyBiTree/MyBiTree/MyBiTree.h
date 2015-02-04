#pragma once

typedef struct BiNode
{
	int data;
	BiNode* pLeftTree;
	BiNode* pRightTree;

	BiNode()
	{
		data = 0;
		pLeftTree = NULL;
		pRightTree = NULL;
	}
}BiNode;

class CMyBiTree
{
public:
	CMyBiTree();
	~CMyBiTree();

	void GenerateBiTree();
	void Display();

private:
	void PreOrder(BiNode* biTree);
	void CreateBiTree(BiNode* &biTree);
	void DestroyBiTree(BiNode* biTree);

private:
	BiNode* m_biTree;
};