#include <stdio.h>
#include "edge_list_lib.h"

void swap(Edge *e1, Edge *e2) {
	Edge tmp;
	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void sorting_edges(Graph *G) {
	int i, j;
	for(i=1; i<=G->m; i++)
		for(j=i; j<=G->m; j++)
			if(G->edge[i].w > G->edge[j].w)
				swap(&G->edge[i], &G->edge[j]);
}

int findRoot(int parent[], int n, int u) {
	if(parent[u] == u)
		return u;
	return findRoot(parent, n, parent[u]);
}

int Kruskal(Graph *G, Graph *T) {
	int sum_w = 0;
	int parent[G->n];
	int i;
	int u, v, w, root_u, root_v;
	
	//Sap xep cac cung theo thu tu tang dan cua trong so
	sorting_edges(G);
	
	//Khoi tao do thi ket qua
	init_graph(T, G->n);
	for(i=1; i<=G->n; i++)
		parent[i] = i;			//Moi dinh la mot bo phan lien thong
		
	//Tien hanh duyet va them cac cung vao do thi ket qua
	for(i=1; i<=G->m; i++) {
		u = G->edge[i].u;
		v = G->edge[i].v;
		w = G->edge[i].w;
		root_u = findRoot(parent, G->n, u);
		root_v = findRoot(parent, G->n, v);
		if(root_u != root_v) {
			add_edge(T, u, v, w);
			//Gop cac bo phan lien thong lai
			parent[root_u] = root_v;
			sum_w += w;
		}
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
	sum_w = Kruskal(&G, &T);
	
	/*	
	int i;
	for(i=1; i<=T.m; i++) 
		printf("(%d; %d) %d\n", T.edge[i].u, T.edge[i].v, T.edge[i].w);
	*/
		
	printf("%d", sum_w);
		
	return 0;
}
