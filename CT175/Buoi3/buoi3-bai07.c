/* File du lieu mau: dothi1.txt */

#include <stdio.h>
#include "directed_weighted_graph_lib.h"
#define INFINITY 9999999

int pi[MAX_VERTEXES][MAX_VERTEXES];
int next[MAX_VERTEXES][MAX_VERTEXES];

void Floyd_Warshall(Graph G) {
	int u, v, k;
	
	//Khoi tao du lieu
	for(u=1; u<=G.n; u++) {
		for(v=1; v<=G.n; v++) {
			pi[u][v] = INFINITY;
			next[u][v] = -1;
		}
	}
	
	for(u=1; u<=G.n; u++) {
		pi[u][u] = 0;
	}
	
	//Truong hop u va v ke nhau
	for(u=1; u<=G.n; u++) {
		for(v=1; v<=G.n; v++) {
			if(G.L[u][v] != NO_EDGE) {
				pi[u][v] = G.L[u][v];
				next[u][v] = v;
			}
		}
	}
	
	//Lap n lan
	for(k=1; k<=G.n; k++) {
		for(u=1; u<=G.n; u++) {
			for(v=1; v<=G.n; v++) {
				if(pi[u][v] > pi[u][k] + pi[k][v]) {
					pi[u][v] = pi[u][k] + pi[k][v];
					next[u][v] = next[u][k];
				}
			}
		}
	}
}

void PrintResult(Graph G) {
	int u, v;
	for(u=1; u<=G.n; u++) {
		for(v=u+1; v<=G.n; v++) {
			printf("%d -> %d: %d\n", u, v, pi[u][v]);
		}
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
	init_graph(&G, n);
	for(i=1; i<=m; i++) {
		fscanf(f, "%d%d%d", &v1, &v2, &w);
		add_edge(&G, v1, v2, w);
	}
	fclose(f);
	
	Floyd_Warshall(G);
	PrintResult(G);
	
	return 0;
}
