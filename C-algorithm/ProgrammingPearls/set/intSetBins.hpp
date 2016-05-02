/**
	桶实现IntSet
	
	结合链表和位向量的优点
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
	
	int test(int t){
		int hash = t * bins / maxval;
		for (node *p = bins[hash]; p != sentinel; p = p->next){
			if (p->val == t){
				return 1;
			}
		}
		return 0;
	}
	
public:
	IntSetBins(int maxelements, int pmaxval){
		bins = maxelements;
		maxval = pmaxval;
		bin = new node*[bins];
		sentinel = new node(maxval, 0);
		for (int i = 0; i < bins; i++){
			bin[i] = sentinel;
		}
		n = 0;
	}
	
	void rinsert(int t){
		int hash = t * bins / maxval;	// 溢出危险
		node *p = new node(t, bin[hash]);
		bin[hash] = p;	// 合并 bin[hash] = new node(t, bin[hash]);
		n++;
	}
	
	void insert(int t){
		if (test()){
			return ;
		}
		rinsert(t);
	}
	
	int size() const { return n; }
	
	void report(int *v){
		int j = 0;
		for (int i = 0; i < bins; i++){
			for (node *p = bin[i]; p != sentinel; p = p->next){
				v[j++] = p->val;
			}
		}
	}
};