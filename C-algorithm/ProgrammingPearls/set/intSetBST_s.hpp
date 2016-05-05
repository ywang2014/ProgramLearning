/**
	查找类的实现完整代码
*/
class IntSetBST{
private:
	int n;
	int *arr;
	int vn;
	struct node{
		int val;
		node *left;
		node *right;
		node(int v){
			val = v;
			left = right = 0;
		}
	};
	node *root;
	
	node *rinsert(node *p, int t){
		if (p == 0){
			p = new node(t);
			n++;
		}
		else if (t < p->val){
			p->left = rinsert(p->left, t);
		}
		else if (t > p->val){
			p->right = rinsert(p->right, t);
		}
		// if p->val == t do nothing
		return p;
	}
	
	void traverse(node *p){
		if (p == 0){
			return ;
		}
		traverse(p->left);
		arr[vn++] = p->val;
		traverse(p->right);
		
	}
	
public:
	IntSetBST(int maxelems, int maxval){
		root = 0;
		n = 0;
	}
	
	int size(){ return n; }
	
	void insert(int t){
		root = rinsert(root, t);
	}
	
	void report(int *v){
		arr = v;
		vn = 0;
		traverse(root);
	}
};