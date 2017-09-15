#define MAX_EDGES 500

typedef struct {
	int u, v;
	int w;
} Edge;

typedef struct {
	int n, m;
	Edge edges[MAX_EDGES];
} Graph;

void init_graph(Graph *G, int n, int m) {
	G->n = n;
	G->m = m;
}

void add_edge(Graph *G, int u, int v, int w) {
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}
