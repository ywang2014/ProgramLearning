/**
	二分查找树实现IntSet
*/
class IntSetBST{
private:
	int n;
	int *v;
	int vn;
	
	struct node{
		int val;
		node *left;
		node *right;
		node(int i){
			val = i;
			left = right = NULL;
		};
	};
	
	node *root;
public:
	IntSetBST(int maxelements, int maxval){
		root = 0;
		n = 0;
	}
	int size() const { return n; }
	void insert(int t){ root = rinsert(root, t}; }
	void report(int *x){
		v = x;
		vn = 0;
		traverse(root);
	}
	
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
		
		return p;
	}
	
	void traverse(p){
		if (p == 0){
			return ;
		}
		traverse(p->left);
		v[vn++] = p->val;
		traverse(p->right);
	}

};