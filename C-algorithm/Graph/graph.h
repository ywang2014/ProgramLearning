/**
	图的实现算法 -- Yale大牛的
*/
#ifndef __GRAPH_H
#define __GRAPH_H

typedef struct Graph *Graph;

Graph graph_create(int n);
void graph_destroy(Graph g);
void graph_add_edge(Graph g, int source, int sink);
int graph_vertex_count(Graph g);
int graph_edge_count(Graph g);
int graph_out_degree(Graph g, int source);
int graph_has_edge(Graph g, int source, int sink);
void graph_foreach(Graph g, int source, int void (*fn)(Graph g1, int source1, int sink, void *data1), void *data);

#endif
