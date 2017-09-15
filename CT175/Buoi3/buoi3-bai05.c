/* File du lieu mau: dothi4.txt va dothi5.txt */

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

int negative_cycles(Graph G, int s) {
	int negative = 0;
	int j;
	
	Bellman_Ford(G, s);
	
	for(j=0; j<G.m; j++) {
		int u = G.edges[j].u;
		int v = G.edges[j].v;
		int w = G.edges[j].w;
		if(pi[u] + w < pi[v]) {
			negative = 1;
			break;
		}
	}
	
	return negative;
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
	
	if(negative_cycles(G, 1)) 
		printf("YES");
	else
		printf("NO");
	
	return 0;
}
