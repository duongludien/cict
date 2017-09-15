/* File du lieu mau: dothi2.txt */

#include <stdio.h>
#include "directed_weighted_graph_lib.h"
#define INFINITY 9999999

int mark[MAX_VERTEXES];
int pi[MAX_VERTEXES];
int p[MAX_VERTEXES];

void Dijkstra(Graph G, int s) {
	int i, j, it;
	
	//Khoi tao gia tri
	for(i=1; i<=G.n; i++) {
		mark[i] = 0;
		pi[i] = INFINITY;
	}
	pi[s] = 0;
	p[s] -1;
	
	//Lap n-1 lan
	for(it=1; it<G.n; it++) {
		//Tim dinh chua xet va co pi[i] nho nhat
		int min_pi = INFINITY;
		for(j=1; j<=G.n; j++) {
			if(pi[j] < min_pi && mark[j] == 0) {
				min_pi = pi[j];
				i = j;
			}
		}
		
		//Danh dau i la da xet
		mark[i] = 1;
		
		//Xem xet viec cap nhat cac dinh ke cua i
		for(j=1; j<=G.n; j++) {
			if(G.L[i][j] != NO_EDGE && mark[j] == 0) {
				if(pi[j] > pi[i] + G.L[i][j]) {
					pi[j] = pi[i] + G.L[i][j];
					p[j] = i; 
				}
			}
		}
	}
}

void PrintResult(Graph G) {
	int i;
	for(i=1; i<=G.n; i++) {
		printf("pi[%d] = %3d\tp[%d] = %d\n", i, pi[i], i, p[i]);
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
	
	Dijkstra(G, 1);
	PrintResult(G);
	
	return 0;
}
