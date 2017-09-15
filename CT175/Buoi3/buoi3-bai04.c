/* File du lieu mau: dothi4.txt */

#include <stdio.h>
#include "edges_list_lib.h"
#define INFINITY 9999999
#define MAX_VERTEXES 500

int pi[MAX_VERTEXES];
int p[MAX_VERTEXES];

void Bellman_Ford(Graph G, int s) {
	int i, j, it;
	
	//Khoi tao gia tri
	for(i=1; i<=G.n; i++) 
		pi[i] = INFINITY;
	pi[s] = 0;
	p[s] = -1;
	
	//Lap n-1 lan
	for(it=1; it<G.n; it++) {
		//Duyet qua tat ca cac cung
		for(j=0; j<G.m; j++) {
			int u = G.edges[j].u;
			int v = G.edges[j].v;
			int w = G.edges[j].w;
			if(pi[u] + w < pi[v]) {
				pi[v] = pi[u] + w;
				p[v] = u;
			}
		}
	}
}

void PrintResult(Graph G, int s, int t) {
	int i, j;
	for(i=1; i<=G.n; i++) {
		printf("pi[%d] = %3d\tp[%d] = %d\n", i, pi[i], i, p[i]);
	}
	
	int path[MAX_VERTEXES];
	int k = 0;
	int current = t;
	
	while(current != -1) {
		path[k] = current;
		k++;
		current = p[current];
	}
	printf("Duong di ngan nhat tu %d den %d la: ", s, t);
	for(j=k-1; j>=0; j--) {
		printf("%d ", path[j]);
	}
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Hay nhap: %s <ten-file-du-lieu>", argv[0]);
		return 1;
	}
	
	Graph G;
	int n, m, i, v1, v2, w;
	FILE *f = fopen(argv[1], "rt");
	
	fscanf(f, "%d%d", &n, &m);
	init_graph(&G, n, m);
	for(i=1; i<=m; i++) {
		fscanf(f, "%d%d%d", &v1, &v2, &w);
		add_edge(&G, v1, v2, w);
	}
	fclose(f);
	
	Bellman_Ford(G, 1);
	PrintResult(G, 1, 8);
	
	return 0;
}
