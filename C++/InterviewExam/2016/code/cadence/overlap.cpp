/**
	使用红黑树实现的算法
	
	时间复杂度：O(nlogn)
*/

#include <iostream>  
#include <conio.h>  
#include "MERGE_SORT.h"  

using namespace std;

#define BLACK 0  
#define RED 1  
#define Nil -1  
#define LEN sizeof(struct Tree)  
#define n 4//矩形的个数  

struct Tree *root = NULL;
struct Tree *nil = NULL;

struct interval
{
	int low, high;
};

struct Rectangular
{
	int flag;
	struct interval x, y;
};

struct Tree
{
	struct Tree *right, *left;
	struct Tree *parent;
	struct interval Int;
	int Max;
	int key;
	int color;
};

int MAX(int a, int b, int c)
{
	int temp = a > b ? a : b;
	return temp > c ? temp : c;
}

void LEFT_ROTATE(struct Tree*x)
{//左旋转：分三个步骤①②③来叙述旋转代码的。  
	struct Tree*y = x->right;//设置y结点。  
	x->right = y->left;//本行代码以及下面的if结构表达的是“y的左孩子成为x的右孩子”。①  
	if (y->left != nil)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;//本行代码以及下面的if-else结构表达的过程是“y成为该子树新的根”。②  
	if (x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else x->parent->right = y;
	y->left = x;//本行代码以及下面一行都表达了“x成为y的左孩子”。③  
	x->parent = y;
	y->Max = x->Max;
	x->Max = MAX(x->Int.high, x->left->Max, x->right->Max);
}

void RIGHT_ROTATE(struct Tree*x)
{//右旋转：分三个步骤①②③来叙述旋转代码的。  
	struct Tree*y = x->left;//设置y结点。  
	x->left = y->right;//本行代码以及下面的if结构表达的是“y的左孩子成为x的右孩子”。①  
	if (y->right != nil)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;//本行代码以及下面的if-else结构表达的过程是“y成为该子树新的根”。②  
	if (x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right = y;
	}
	else x->parent->left = y;
	y->right = x;//本行代码以及下面一行都表达了“x成为y的左孩子”。③  
	x->parent = y;
	y->Max = x->Max;
	x->Max = MAX(x->Int.high, x->left->Max, x->right->Max);
}

void RB_INSERT_FIXUP(struct Tree*z)
{
	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			struct Tree*y = z->parent->parent->right;//叔结点  
			if (y->color == RED)//情况一：叔结点为红色  
			{//给p1,y,p2着色以保持性质5。并且解决了z的父结点和z都是红色结点问题  
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;//把z的祖父结点当成新结点z进入下一次循环  
			}
			else
			{
				if (z == z->parent->right)//情况二：检查z是否是一个右孩子且叔结点为黑色，前提是p1结点不是叶子结点  
				{//使用一个左旋让情况2转变为情况3  
					z = z->parent;
					LEFT_ROTATE(z);//由于进入if语句后可知旋转结点不可能是叶子结点，这样就不用判断z是否是叶子结点了。  
				}
				z->parent->color = BLACK;//情况三：是z是一个左孩子且叔结点为黑色，改变z的父和祖父结点颜色并做一次右旋，以保持性质5  
				z->parent->parent->color = RED;
				RIGHT_ROTATE(z->parent->parent);//由于p2可能是叶子结点，所以最好还是用一个if判断  
			}
		}
		else//下面else分支类似于上面,注意到else分支的情况2和情况3所做旋转正好是if分支情况的逆。  
		{
			struct Tree*y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					RIGHT_ROTATE(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				LEFT_ROTATE(z->parent->parent);
			}
		}
	}
	root->color = BLACK;//最后给根结点着为黑色。  
}

void RB_INSERT(struct Tree* z)
{
	z->key = z->Int.low;
	struct Tree*y = nil;
	struct Tree*x = root;
	while (x != nil)
	{
		y = x;
		x->Max = MAX(x->Int.high, x->Max, z->Int.high);
		if (z->key<x->key)
		{
			x = x->left;
		}
		else x = x->right;
	}
	z->parent = y;
	if (y == nil)
	{
		root = z;
	}
	else if (z->key<y->key)
	{
		y->left = z;
	}
	else y->right = z;
	z->left = nil;//给插入结点左右孩子赋值为空。  
	z->right = nil;
	z->color = RED;//给插入结点着为红色。  
	z->Max = z->Int.high;//+  
	RB_INSERT_FIXUP(z);
}

void RB_TRANSPLANT(struct Tree*u, struct Tree*v)
{
	if (u->parent == nil)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else u->parent->right = v;
	v->parent = u->parent;
}

//非递归版本的查找二叉查找树的最小值  
struct Tree*ITERATIVE_TREE_MINIMUM(struct Tree*x)
{
	while (x->left != nil)
	{
		x = x->left;
	}
	return x;
}

//非递归版本的二叉查找树查找函数  
struct Tree*ITERATIVE_TREE_SEARCH(struct Tree*x, int k)
{
	while (x != nil&&k != x->key)
	{
		if (k<x->key)
		{
			x = x->left;
		}
		else x = x->right;
	}
	return x;
}

void RB_DELETE_FIXUP(struct Tree*x)
{
	struct Tree*w = NULL;//w是x的兄弟结点  
	while (x != root&&x->color == BLACK)//如果x是黑色并且不是根结点，才进行循环。  
	{//x是一个具有双重颜色的结点，调整的目的是把x的黑色属性向上移动。  
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == RED)//情况一：x的兄弟结点w是红色的。  
			{//改变w和x.p的颜色+一次旋转使其变为情况二，三，四。  
				w->color = BLACK;
				x->parent->color = RED;
				LEFT_ROTATE(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK&&w->right->color == BLACK)//情况二：x的兄弟结点w是黑色的，而且w的两个子节点都是黑色。  
			{
				w->color = RED;//从x和w上去掉一重黑色。x还是黑色，而w变为红色。  
				x = x->parent;//x结点向上移动成为新的待调整结点。  
			}
			else
			{
				if (w->right->color == BLACK)//情况三：x的兄弟结点w是黑色的，w的左孩子是红色的，w的右孩子是黑色的。  
				{//交换w和w.left的颜色+旋转使其转变为情况四。  
					w->left->color = BLACK;
					w->color = RED;
					RIGHT_ROTATE(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;//以下是情况四：x的兄弟结点w是黑色的，且w的右孩子是红色的。  
				x->parent->color = BLACK;//置x.p和w.right为黑色+旋转使其去掉x的额外黑色。  
				w->right->color = BLACK;
				LEFT_ROTATE(x->parent);
				x = root;//x成为根结点，结束循环。  
			}
		}
		else//以下和上面的if分支类似，不做累述。  
		{
			w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RIGHT_ROTATE(x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK&&w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					LEFT_ROTATE(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				RIGHT_ROTATE(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

void RB_DELETE(struct Tree*z)
{
	struct Tree*y = z, *x;//y为待删除或待移动结点  
	int y_original_color = y->color;//保存y的原始颜色，为做最后的调整做准备。  
	if (z->left == nil)
	{
		x = z->right;//x指向y的唯一子结点或者是叶子结点，保存x的踪迹使其移动到y的原始位置上  
		RB_TRANSPLANT(z, z->right);//把以z.right为根的子树替换以z为根的子树。  
	}
	else if (z->right == nil)
	{
		x = z->left;//x指向y的唯一子结点或者是叶子结点，保存x的踪迹使其移动到y的原始位置上  
		RB_TRANSPLANT(z, z->left);//把以z.left为根的子树替换以z为根的子树。  
	}
	else
	{
		y = ITERATIVE_TREE_MINIMUM(z->right);//找到z.right的后继。  
		y_original_color = y->color;//y的新的原始结点被重置。  
		x = y->right;//x指向y的唯一子结点或者是叶子结点，保存x的踪迹使其移动到y的原始位置上  
		if (y->parent == z)
		{
			x->parent = y;//由于z的父结点是要删除的结点，所以不能指向它，于是指向y  
		}
		else
		{
			RB_TRANSPLANT(y, y->right);//把以y.right为根的子树替换以y为根的子树。  
			y->right = z->right;
			y->right->parent = y;
		}
		RB_TRANSPLANT(z, y);//把以y为根的子树替换以z为根的子树。  
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;//把已经删除的结点颜色赋值给y，保证了y以上的树结构红黑性质不变。  
	}
	struct Tree*k = x->parent;
	while (k != nil)
	{
		k->Max = MAX(k->left->Max, k->right->Max, k->Int.high);
		k = k->parent;
	}
	if (y_original_color == BLACK) //y的原始颜色为黑色，说明需要调整红黑颜色。  
		RB_DELETE_FIXUP(x);
}

bool overlap(struct interval x, struct interval i)
{
	if (x.high<i.low || i.high<x.low)
	{
		return  true;//没有重叠  
	}
	else
	{
		return false;
	}
}

struct Tree *INTERVAL_SEARCH(struct Tree *T, struct interval i)
{
	struct Tree *x = T;
	while (x != nil&&overlap(x->Int, i))
	{
		if (x->left != nil&&x->left->Max >= i.low)
		{
			x = x->left;
		}
		else x = x->right;
	}
	return x;
}

bool Rectangle_overlap(struct Rectangular A[], struct Array B[])
{//判断n个矩阵是否重叠，运行时间为O(nlgn)  
	int i = 1;
	while (i != 2 * n)
	{
		if (A[B[i].index].flag == 0)//0代表矩形Ri的纵坐标的还未进入扫描线。  
		{
			struct Tree*z = new struct Tree[LEN];
			z->key = A[B[i].index].y.low;
			z->Int.low = A[B[i].index].y.low;
			z->Int.high = A[B[i].index].y.high;
			A[B[i].index].flag = 1;
			if (root != z&&INTERVAL_SEARCH(root, z->Int) != nil)
			{//如果矩形重叠存在，那么直接返回。  
				return true;
			}
			RB_INSERT(z);//将这个矩形插入进区间树  
		}
		else//否则，矩形Ri的纵坐标进入过扫描线了，那么遇到的横坐标(B[i].key代表横坐标)必然是Ri的高端点。  
		{
			if (i == 2 * n - 1 || A[B[i + 1].index].y.low != A[B[i].index].y.high)
			{
				struct Tree*z = ITERATIVE_TREE_SEARCH(root, A[B[i].index].y.low);//先找到区间树中的这个结点。  
				RB_DELETE(z);//从区间树中删除这个矩形。  
			}
		}
		i++;
	}
	return false;
}

void init(struct Rectangular A[], struct Array B[])
{//区间树初始化。  
	nil = new struct Tree[LEN];//设置叶子结点  
	nil->key = Nil; nil->color = BLACK;
	root = nil;
	int i = 0;
	struct Tree*z = new struct Tree[LEN];//设置根结点。  
	z->key = A[B[i].index].y.low;
	z->Int.low = A[B[i].index].y.low;
	z->Int.high = A[B[i].index].y.high;
	RB_INSERT(z);
	root = z;
	A[B[i].index].flag = 1;
}

int char_int()
{
	//char ch = '\0';
	//int i = 0, s = 0, t = 1;
	//char ch1[n] = { 0 };

	//while (ch != ' ')
	//{
	//	if (ch == '#')
	//	{
	//		while (i)
	//		{
	//			cout << "\b";
	//			ch1[i] = ' ';
	//			i--;
	//		}
	//	}
	//	ch = getchar();
	//	cout << ch;
	//	ch1[i++] = ch;
	//}
	//cout << "\b";//\b退格符号  
	//while (i>1)
	//{
	//	s += (ch1[i-- - 2] - '0')*t;
	//	t *= 10;
	//	cout << "\b";
	//}
	//return s;
	int num = 0;
	cin >> num;
	return num;
}

int main()
{
	struct Rectangular A[n] = { 0 };
	struct Array B[2 * n] = { 0 };
	for (int i = 0, j = 0; i<n, j<2 * n; i++, j += 2)
	{
		cout << "请输入第" << i << "个矩阵的数据：(按#号键重新输入，按空格键结束输入)" << endl;
		cout << "左上角的(x,y): " << (A[i].x.low = char_int()) << (A[i].y.high = char_int()) << endl;
		cout << "右下角的(x,y): " << (A[i].x.high = char_int()) << (A[i].y.low = char_int()) << endl;
		B[j].key = A[i].x.low;
		B[j].index = i;
		B[j + 1].key = A[i].x.high;
		B[j + 1].index = i;
	}
	MERGE_SORT(B, 0, 2 * n - 1);//归并排序，时间为O(nlgn)  
	init(A, B);
	if (Rectangle_overlap(A, B))
	{
		cout << "重叠矩阵存在！" << endl;
	}
	else cout << "重叠矩阵不存在" << endl;

	getchar();
	return 0; 
}