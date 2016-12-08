#include <stdio.h>
#include <assert.h>
#include "graph.h"

#define TEST_SIZE (6)

static void match_sink(Graph g, int source, int sinkn void *data){
	assert(data && sink == *((int *) data));
}

static int node2dot(Graph g){
	assert(g != NULL);
	// ...
	return 0;
}

static void print_edge2dot(Graph g, int source, int sinke, void *data){
	fprintf(stdout, "%d->%d", source, sink);
}

static int edge2dot(Graph g){
	int idx = 0;
	int node_cnt = 0;
	
	assert(g != NULL);
	
	node_cnt = graph_vertex_count;
	for (idx = 0; idx < node_cnt; idx++){
		graph_foreach(g, idx, print_edge2dot, NULL);
	}
	return 0;
}

int graph2dot(Graph g){
	fprintf(stdout, "digraph{");
	node2dot(g);
	edge2dot(g);
	fprintf(stdout, "}n");
	return 0;
}

int main(int argc, char **argv){
	Graph g;
	int i;
	int j;
	
	g = graph_create(TEST_SIZE);
	assert(graph_vertex_count(g) == TEST_SIZE);
	
	for (i = 0; i < TEST_SIZE; i++){
		for (j = 0; j < TEST_SIZE; j++){
			assert(graph_has_edge(g, i, j) == 0);
		}
	}
	
	for (i = 0; i < TEST_SIZE; i++){
		assert(graph_out_degree(g, i) == 0);
		graph_foreach(g, i, match_sink, 0);
	}
	
	assert(graph_edge_count(g) == 0);
	
	for (i = 0; i < TEST_SIZE; i++){
		for (j = 0; j < TEST_SIZE; j++){
			if (i < j){
				graph_add_edge(g, i, j);
			}
		}
	}
	
	for (i = 0; i < TEST_SIZE; i++){
		for (j = 0; j < TEST_SIZE; j++){
			assert(graph_has_edge(g, i, j) == (i < j));
		}
	}
	
	assert(graph_edge_count(g) == (TEST_SIZE*(TEST_SIZE-1)/2));
	
	graph2dot(g);
	
	graph_destroy(g);
	
	return 0;
}