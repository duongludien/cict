//Duong Lu Dien
//B1401133

#include "alistlib.h"

#define MAX_VERTEXES 100

typedef struct {
	int n;
	int A[MAX_VERTEXES][MAX_VERTEXES];
} Graph;

void init_graph(Graph *G, int n) {
	int i, j;
	
	G->n = n;
	for(i=1; i<=n; i++) 
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *G, int x, int y) {
	G->A[x][y]++;
}

int degree_minus(Graph G, int x) {
	int deg = 0;
	int u;
	
	for(u=1; u<=G.n; u++)
		if(G.A[u][x] != 0)
			deg++;
	
	return deg;
}

int degree_plus(Graph G, int x) {
	int deg = 0;
	int u;
	
	for(u=1; u<=G.n; u++)
		if(G.A[x][u] != 0)
			deg++;
	
	return deg;
}

List neighbors(int u, Graph G) {
	List L;
	int v;
	
	make_null(&L);
	for(v=1; v<=G.n; v++)
		if(G.A[u][v] != 0)
			push_back(&L, v);
	
	return L;
}
