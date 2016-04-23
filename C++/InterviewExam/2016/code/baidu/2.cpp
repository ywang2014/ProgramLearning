/**
	百度实习生笔试题2：
	
	给定两个棵树，计算树A，是否包含树B，包含的意思是，树B是树A的一个子结构。
	
	输入，两颗树的根节点。
*/

// static int res = -1;	// 尽量不要使用全局变量

struct tnode{
	int value;
	tnode* left;
	tnode* right;
}

void  maybeSubTree(tnode* root1, tnode* root2, int &res){
    
    if (root1->value == root2->value){
        if (root2->left == NULL && root2->right == NULL){
            res = 1;
            return ;
        }
        
        if (root2->left != NULL){
            maybeSubTree(root1->left, root2->left);
        }
        
        if (root2->right != NULL){
            maybeSubTree(root1->right, root2->right);
        }
    }
}

void subTree(tnode* root1, tnode* root2, int &res){
    if (root1 == NULL)
    {
        return ;
    }
    
    if (root1->value == root2->value){
       maybeSubTree(root1, root2, res);
    }
   
   if (root1->left != NULL){
       subTree(root1->left, root2);
   }
   
   if (root1->right != NULL){
       subTree(root1->right, root2);
   }
}



int isSubTree(tnode* root1, tnode* root2)
{
   // WRITE YOUR CODE HERE
   if (root1 == NULL || root2 == NULL){
       return -1;
   }
   int res = -1;
   
   subTree(root1, root2, res);
   
   return res;
}