/**
	链表实现IntSet
*/
class IntSetList{
private:
	int n;
	struct node{
		int val;
		node *next;
		node(int v, node *p){ return val = v; next = p; }
	};
	node *head;
	node *sentinel;
public:
	IntSetList(int maxelements, int maxval){
		sentinel = head = new node(maxval, 0);
		n = 0;
	}
	
	int size() const { return n; }
	
	void insert(int t){
		head = rinsert(head, t);
	}
	
	node *rinsert(node *p, int t){
		if (p->val < t){
			p->next = rinsert(p->next, t);
		}
		else if (p->val > t){
			p = new node(t, p);	// 插入节点
			n++;
		}
		
		return p;
	}
	
	void report(int *v){
		int i = 0;
		for (node *p = head; p != sentinel; p = p->next){
			v[i++] = p->val;
		}
	}
};
