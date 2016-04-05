/**
	红黑树接口 RBTree.h 
	
	interface for the class of red black tree
	
*/

#ifndef RBTREE_INCLUDED
#define RBTREE_INCLUDED

#if _MSC_VER > 1000
#pragma once
#endif	// _MSC_VER > 1000

#define BLACK 0
#define RED 1
#define NULL 0
typedef int BOOL;

typedef struct RBTreeNode{
	int key;
	int color;
	struct RBTreeNode *parent;
	struct RBTreeNode *left;
	struct RBTreeNode *right;
	
	RBTreeNode(){}
	RBTreeNode(int k) : key(k){
		color = RED;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
}RBTree, RBTreeNode;


class CRBTree{
	public:
		CRBTree();
		virtual ~CRBTree();
		
		void RB_InitLeafNode();
		BOOL RB_Insert(int keyVal);
		BOOL RB_Delete(int keyVal);
		RBTreeNode *RB_Find(int keyVal);
		void RB_Print();
		int RB_GetSize() const {
			return m_Size;
		}
		
	private:
		void RB_Insert_FixedUp(RBTreeNode *&pNode);
		void RB_Del_FixedUp(RBTreeNode *&pNode);
		void RB_Left_Rotate(RBTreeNode *&pNode);
		void RB_Right_Rotate(RBTreeNode *&pNode);
		void RB_Print(RBTreeNode *&pNode);
		void RB_SwapTwoNodes(RBTreeNode *&pNode1, RBTreeNode *&pNode2);
		void RB_EmptyTree(RBTreeNode *&pNode);
		
		RBTree *m_root;		// 根节点
		RBTreeNode *m_NIL;	// 空结点
		int m_Size;
};


#endif 	// RBTREE_INCLUDED