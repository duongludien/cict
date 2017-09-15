#include "alistlib.h"

#define MAX_VERTEXES 100

typedef struct {
	int n;									//So dinh
	int A[MAX_VERTEXES][MAX_VERTEXES];		//Ma tran dinh - dinh
} Graph;

/* Khoi tao do thi G co n dinh */
void init_graph(Graph *G, int n) {
	int i, j;
	
	G->n = n;
	for(i=1; i<=n; i++) 
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

/* Them cung e = (x,y) vao do thi G */
void add_edge(Graph *G, int x, int y) {
	G->A[x][y] += 1;		//y ke voi x
	G->A[y][x] += 1;		//x ke voi y
}

/* Kiem tra y co ke voi x khong */
int adjacent(Graph G, int x, int y) {
	return G.A[x][y] != 0;
}

/* Tinh bac cua dinh x: deg(x), truong hop da cung */
int degree(Graph G, int x) {
	int deg = 0, y;
	
	for(y=0; y<=G.n; y++) 
		deg += G.A[x][y];
	
	return deg;
}

/* Tim cac dinh ke cua dinh x */
List neighbors(Graph G, int x) {
	List L;
	make_null(&L);
	int y;
	for(y=1; y<=G.n; y++) 
		if(adjacent(G, x, y))
			push_back(&L, y);
	return L;
}
