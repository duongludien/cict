#include <stdio.h>
#include "undirected_weighted_graph_lib.h"
#include "alistlib.h"

#define INF 9999999

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
	
	FILE *f = fopen("buoi5.1-bai1.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	init_graph(&G, n);
	while(fscanf(f, "%d%d%d", &u, &v, &w) == 3) {
		add_edge(&G, u, v, w);
	}
	
	Graph T;
	int sum_w;
	sum_w = Prim(G, &T);
	
	/*	
	int i, j;
	for(i=1; i<=T.n; i++) 
		for(j=1; j<=T.n; j++)
			if(T.L[i][j] != NO_EDGE) 
				printf("(%d; %d) %d\n", i, j, T.L[i][j]);
	*/
	
	printf("%d", sum_w);
		
	return 0;
}
