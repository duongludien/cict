#define MAX_VERTEXES 100
#define NO_EDGE 0

typedef struct {
	int n;
	int L[MAX_VERTEXES][MAX_VERTEXES];
} Graph;

void init_graph(Graph *G, int n) {
	int i, j;
	G->n = n;
	for(i=1; i<=G->n; i++) 
		for(j=1; j<=G->n; j++)
			G->L[i][j] = NO_EDGE;
}

void add_edge(Graph *G, int v1, int v2, int w) {
	G->L[v1][v2] = w;
}
