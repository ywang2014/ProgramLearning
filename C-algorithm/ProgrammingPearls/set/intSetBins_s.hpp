/**
	查找类的实现完整代码
*/
class IntSetBins{
private:
	int n;
	int bins;
	int maxval;
	struct node{
		int val;
		node *next;
		node(int v, node *p){
			val = v;
			next = p;
		}
	};
	node **bin;
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
	IntSetBins(int maxelems, int pmaxval){
		bins = maxelems;
		maxval = pmaxval;
		bin = new node*[bins];
		sentinel = new node(maxval, 0);
		for (int i = 0; i < bins; i++){
			bin[i] = sentinel;
		}
		n = 0;
	}
	
	int size(){ return n; }
	
	void insert(int t){
		int i = t / (1 + maxval / bins);
		bin[i] = rinsert(bin[i], t);
	}
	
	void report(int *v){
		int index = 0;
		for (int i = 0; i < bins; i++){
			for (node *p = bin[i]; p != sentinel; p = p->next){
				v[index++] = p->val;
			}
		}
	}
};