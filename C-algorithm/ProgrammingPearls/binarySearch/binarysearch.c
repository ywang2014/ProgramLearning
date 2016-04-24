/**
	书中实现的代码(第5章)
	
*/

typedef int DataType;

int n;
DataType x[MAXN];

/* return any position if t in sorted x[0..n-1] or -1 if t is not present */
int binarysearch(DataType t){
	int l;
	int u;
	int m;
	
	l = 0;
	u = n - 1;
	while (l <= u){
		m = (l + u) / 2;
		if (x[m] < t){
			l = m + 1;
		}
		else if (x[m] == t){
			return m;
		}
		else{	// x[m] > t 
			u = m -1;
		}
	}
	
	return -1;
}