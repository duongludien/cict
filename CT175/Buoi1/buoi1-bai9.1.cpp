/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include <stdio.h>
#include <vector>

#define MAX_VERTEXES 100
using namespace std;

typedef struct {
	int n;
	vector<int> adj[MAX_VERTEXES];	
} Graph;

/* Khoi tao do thi n dinh */
void init_graph(Graph *G, int n) {
	G->n = n;
}

/* Them cung e = (x,y) vao do thi G */
void add_edge(Graph *G, int x, int y) {
	G->adj[x].push_back(y);
	G->adj[y].push_back(x);
}

/* Kiem tra dinh y co ke voi x hay khong */
int adjacent(Graph G, int x, int y) {
	int i;
	for(i=0; i<G.adj[x].size(); i++)
		if(G.adj[x][i] == y)
			return 1;
	return 0;
}

/* Tinh bac cua dinh x */
int degree(Graph G, int x) {
	return G.adj[x].size();
}

int main(int argc, char *argv[]) {
	if(argc<2) {
		printf("Hay nhap: %s <ten-file>", argv[0]);
		return 1;
	}
	
	Graph G;
	int n, v1, v2;
	
	FILE *f = fopen(argv[1], "rt");
	fscanf(f, "%d", &n);
	init_graph(&G, n);
	
	while(fscanf(f, "%d%d", &v1, &v2) == 2) {
		add_edge(&G, v1, v2);
	}
	
	for(v1=1; v1<=n; v1++) 
		printf("deg(%d) = %d\n", v1, degree(G, v1));
	
	return 0;
}
