#define MAX_VERTEXES 100
#define MAX_EDGES 500

typedef struct {
	int n;								//So dinh
	int m;								//So cung
	int A[MAX_VERTEXES][MAX_EDGES];		//Ma tran dinh - cung
} Graph;

/* Khoi tao do thi G co n dinh va m cung */
void init_graph(Graph *G, int n, int m) {
	int i, j;
	
	G->n = n;
	G->m = m;
	for(i=1; i<=G->n; i++) 
		for(j=1; j<=G->m; j++)
			G->A[i][j] = 0;
}

/* Them cung e = (x,y) vao do thi G */
void add_edge(Graph *G, int e, int x, int y) {
	G->A[x][e] = 1;		//x lien thuoc voi e
	G->A[y][e] = 1;		//y lien thuoc voi e
}

/* Kiem tra y co ke voi x hay khong */
int adjacent(Graph G, int x, int y) {
	int e;
	
	for(e=1; e<=G.m; e++)
		if(G.A[x][e] == 1 && G.A[y][e] == 1)
			return 1;
	return 0;
}

/* Tinh bac cua dinh x: deg(x) */
int degree(Graph G, int x) {
	int deg = 0;
	int e;
	
	for(e=1; e<=G.m; e++)
		if(G.A[x][e] == 1)
			deg++;
	return deg;
}
