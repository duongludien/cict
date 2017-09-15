#define MAX_EDGES 200

typedef struct {
	int u, v;
	int w;
} Edge;

typedef struct {
	int m, n;				//Do thi n dinh, m cung
	Edge edge[MAX_EDGES];	//Danh sach cac cung
} Graph;

void init_graph(Graph *G, int number_of_vertexes) {
	G->m = 0;
	G->n = number_of_vertexes;
}

void add_edge(Graph *G, int x, int y, int weight) {
	G->m++;
	G->edge[G->m].u = x;
	G->edge[G->m].v = y;
	G->edge[G->m].w = weight;
}
