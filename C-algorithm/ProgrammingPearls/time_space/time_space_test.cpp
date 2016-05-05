/**
	时间空间测试
*/
#define MEASURE(T, text){	\
	cout << text << "\t";	\
	cout << sizeof(T) << "\t";	\
	int lastp = 0;	\
	for (int i = 0; i < 11; i++){	\
		T *p = new T;	\
		int thisp = (int)p;	\
		if (lastp != 0){	\
			cout << " " << thisp - lastp;	\
		}	\
		lastp = thisp;	\
	}	\
	cout << "\n";	\
}

#define M(op)	\
	print op as a string	\
	int timesum = 0;	\
	for (int trial = 0; trial < trials; trial++){	\
		int start = clock();	\
		for (int i = 1; i <= n; i++){	\
			op;	\
		}	\
		int t = clock() - start;	\
		print t;	\
		timesum += t;	\
	}	\
	print 1e9 * timesum / (n * n * trials * CLOCKS_PER_SEC)	
	
