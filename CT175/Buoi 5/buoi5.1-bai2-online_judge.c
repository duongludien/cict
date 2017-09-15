#include <stdio.h>

#define MAX_VERTEXES 100
#define NO_EDGE 0
#define MAX_ELEMENTS 500
#define INF 9999999

typedef int ElementType;

typedef struct {
	int size;
	ElementType elements[MAX_ELEMENTS];
} List;

void make_null(List *L) {
	L->size = 0;
}

void push_back(List *L, ElementType x) {
	L->elements[L->size] = x;
	L->size++;
}

ElementType element_at(List L, int i) {
	return L.elements[i-1];
}

void copy(List *L1, List L2) {
	int i;
	
	make_null(L1);
	for(i=1; i<=L2.size; i++) 
		push_back(L1, element_at(L2, i));
}

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
	G->L[v2][v1] = w;
}

//Tim dinh v trong L gan voi u nhat
int distanceFrom(Graph G, List L, int u) {
	int min_dist = INF;
	int min_v = -1;
	int i;
	
	for(i=1; i<=L.size; i++) {
		int v = element_at(L, i);
		if(G.L[u][v] != NO_EDGE && G.L[u][v] < min_dist) {
			min_dist = G.L[u][v];
			min_v = v;
		}
	}
	
	return min_v;
}

int Prim(Graph G, Graph *T) {
	//Cac bien ho tro
	int i, u;
	List L;
	make_null(&L);
	int mark[G.n+1];
	int sum_w = 0;
	
	//Khoi tao do thi ket qua
	init_graph(T, G.n);
	
	//Ban dau, chua co dinh nao trong L
	for(i=1; i<=G.n; i++)
		mark[i] = 0;
	
	//1. Dua mot dinh bat ki vao danh sach L
	push_back(&L, 1);
	mark[1] = 1;
	
	//2. Lap n-1 lan
	for(i=1; i<G.n; i++) {
		//2.1. Tim dinh u gan voi L nhat
		int min_u, min_v;
		int min_dist = INF;
		for(u=1; u<=G.n; u++) {
			if(mark[u] == 0) {		//mark[u] == 0: u khong chua trong L
				int v = distanceFrom(G, L, u);
				if(v != -1 && G.L[u][v] < min_dist) {
					min_dist = G.L[u][v];
					min_u = u;
					min_v = v;
				}
			}
		}
		
		//2.2. Dua dinh u vao L
		push_back(&L, min_u);
		mark[min_u] = 1;
		
		//2.3. Dua cung u, v, min_dits vao T
		add_edge(T, min_u, min_v, min_dist);
		sum_w += min_dist;
	}
	
	return sum_w;	
}

int main() {
	Graph G;
	int m, n;
	int u, v, w;
	
	/*
	FILE *f = fopen("buoi5-bai1.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	init_graph(&G, n);
	while(fscanf(f, "%d%d%d", &u, &v, &w) == 3) {
		add_edge(&G, u, v, w);
	}
	*/
	
	//freopen("data2.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	while(scanf("%d%d%d", &u, &v, &w) == 3) {
		add_edge(&G, u, v, w);
	}
	
	Graph T;
	int sum_w;
	sum_w = Prim(G, &T);
	
	printf("%d\n", sum_w);	
	int i, j;
	for(i=1; i<=T.n; i++) {
		for(j=1; j<=T.n; j++)
			if(T.L[i][j] != NO_EDGE && i < j) {
				printf("%d %d %d\n", i, j, T.L[i][j]);
			}
	}
	
	return 0;
}
