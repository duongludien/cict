#include "alistlib.h"
#define MAX_VERTEXES 100

typedef struct {
	int n;						//So dinh
	List adj[MAX_VERTEXES];		//Danh sach cac dinh ke
} Graph;

/* Khoi tao do thi G co n dinh */
void init_graph(Graph *G, int n) {
	int i;
	G->n = n;
	for(i=1; i<=n; i++)
		make_null(&G->adj[i]);
}

/* Them cung e = (x,y) vao do thi G */
void add_edge(Graph *G, int x, int y) {
	push_back(&G->adj[x], y);	//y ke voi x
	push_back(&G->adj[y], x);	//x ke voi y
}

/* Kiem tra dinh y co ke voi x hay khong */
int adjacent(Graph G, int x, int y) {
	int i;
	for(i=1; i<=G.adj[x].size; i++)
		if(element_at(G.adj[x], i) == y)
			return 1;
	return 0;
}

/* Tinh bac cua dinh x */
int degree(Graph G, int x) {
	return G.adj[x].size;
}
