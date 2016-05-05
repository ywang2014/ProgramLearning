/**
	查找类的实现完整代码
*/
class IntSetList{
private:
	int n;
	struct node{
		int val;
		node *next;
		node(int v, node *p){
			val = v;
			next = p;
		}
	};
	node *head;
	node *sentinel;
	
	node *rinsert(node *p, int t){
		if (p->val < t){
			p->next = rinsert(p->next, t);
		}
		else if (p->val > t){
			p = new node(t, p);
			n++;
		}
		return p;
	}
	
public:
	IntSetList(int maxelems, int maxval){
		sentinel = head = new node(maxval, 0);
		n = 0;
	}
	
	int size(){ return n; }
	
	void insert(int t){
		head = rinsert(head, t);
	}
	
	void report(int *v){
		int index = 0;
		for (node *p = head; p != sentinel; p = p->next){
			v[index++] = p->val;
		}
	}
};