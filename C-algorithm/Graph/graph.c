#include <stdlib.h>
#include <assert.h>

#include "graph.h"

struct Graph{
	int n;
	int m;
	struct successors{
		int d;		// list的元素个数， 指出边的数目
		int len;	// list的容量大小
		char is_sorted;
		int list[1];
	} *alist[1];
};

Graph graph_create(int n){
	Graph g;
	int i = 0;
	
	g = (Graph) malloc(sizeof(struct Graph) + sizeof(struct successors *) * (n - 1));
	assert(g);
	
	g->n = n;
	g->m = 0;
	
	for (i = 0; i < n; i++){
		g-alist[i] = malloc(sizeof(struct successors));
		assert(g->alist[i]);
		
		g->alist[i]->d = 0;
		g->alist[i]->len = 1;
		g->alist[i]->is_sorted = 1;
	}
	
	return g;
}

void graph_destroy(Graph g){
	int i = 0;
	for (i = 0; i < g->n; i++){
		free(g->alist[i]);
	}
	free(g);
}

void graph_add_edge(Graph g, int u, int v){
	assert(u >= 0 && u < g->n && v >= 0 && v < g->n);
	
	while (g->alist[u]->d == g->alist[u]->len){
		g->alist[u]->len *= 2;
		g->alist[u] = realloc(g->alist[u], sizeof(struct successors) + sizeof(int) * (g->alist[u]->len));
		assert(g->alist[u]);
	}
	
	g->alist[u]->list[(g->alist[u]->d)++] = v;
	g->alist[u]->is_sorted = 0;
	
	g->m++;
}

int graph_edge_count(Graph g){
	return g->m;
}

int graph_vertex_count(Graph g){
	return g->n;
}

int graph_out_degree(Graph g, int source){
	assert(g && source >= 0 && source < g->n);
	
	return g->alist[source]->d;
}

#define BSEARCH_THRESHOLD (10)

static int intcmp(const void *a, const void *b){
	return *((const int *) a) - *((const int *) b);
}

int graph_has_edge(Graph g, int source, int sink){
	int i = 0;
	
	assert(source >= 0 && source < g->n && sink >= 0 && sink < g->n);
	
	if (graph_out_degree(g, source) >= BSEARCH_THRESHOLD){
		if (! g->alist[source]->is_sorted){
			qsort(g->alist[source]->list, g->alist[source]->d, sizeof(int), intcmp);
			g->alist[source]->is_sorted = 1;
		}
		return bsearch(&sink, g->alist[source]->list, g->alist[source]->d, sizeof(int), intcmp) != 0;
	}
	else{
		for (i = 0; i < g->alist[source]->d; i++){
			if (g->alist[source]->list[i] == sink){
				return 1;
			}
		}
		return 0;
	}
}

void graph_foreach(Graph g, int source, void (*fn)(Graph g1, int u, int v, void *data1), void *data){
	int i = 0;
	
	assert(source >= 0 && source < g->n);
	
	for (i = 0; i < g->alist[source]->d; i++){
		fn(g, source, g->alist[source]->list[i], data);
	}
}