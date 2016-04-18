/**
	并行排序
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "assert.h"
#include "fmt.h"
#include "thread.h"
#include "mem.h"

// sort types
struct args{
	int *a;
	int lb;
	int ub;
};


// sort data
int cutoff = 10000;

// sort functions
int partition(int a[], int i, int j){
	int v;
	int k;
	int t;
	
	j++;
	k = i;
	v = a[k];
	while (i < j){
		i++; while (i < j && a[i] < v) i++;	// 相等的呢？
		j--; while (a[j] > v) j--;
		if (i < j){ t = a[i]; a[i] = a[j]; a[j] = t; }
	}
	t = a[k]; a[k] = a[j]; a[j] = t;
	
	return j;
}

int quick(void *c1){
	struct args *p = c1;
	int lb = p->lb;
	ub = p->ub;
	
	if (lb < ub){
		int k = partition(p->a, lb, ub);
		// quick
		p->lb = lb;
		p->ub = k - 1;
		if (k - lb > cutoff){
			Thread_T t;
			t = Thread_new(quick, p, sizeof(*p), NULL);
			Fmt_print("thread %p sorted %d..%d\n", t, lb, k - 1);
		}
		else{
			quick(p);
		}
		
		p->lb = k + 1;
		p->ub = ub;
		if (ub - k > cutoff){
			Thread_T t;
			t = Thread_new(quick, p, sizeof(*p), NULL);
			Fmt_print("thread %p sorted %d..%d\n", t, k+1, ub);
		}
		else{
			quick(p);
		}
	}
	return EXIT_SUCCESS;
}

void sort(int *x, int n, int argc, char *argv[]){
	struct args args;
	
	if (argc >= 3){
		cutoff = atoi(argv[2]);
	}
	args.a = x;
	args.lb = 0;
	args.ub = n - 1;
	quick(&args);
	Thread_join(NULL);	// 等待所有线程结束
}



int main(int argc, char *argv[]){
	int i;
	int n = 100000;
	int *x;
	int preempt;
	
	preempt = Thread_init(1, NULL);
	assert(preempt == 1);
	if (argc >= 2){
		n = atoi(argv[1]);
	}
	x = CALLOC(n, sizeof(int));
	srand(time(NULL));
	for (i = 0; i < n; i++){
		x[i] = rand();
	}
	sort(x, n, argc, argv);
	for (i = 1; i < n; i++){
		if (x[i] < x[i-1]){
			break;
		}
	}
	assert(i == n);
	Thread_exit(EXIT_SUCCESS);
	
	return EXIT_SUCCESS;
}