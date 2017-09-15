/* File du lieu mau: robot.txt */

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

int HopLe(int i, int j, int m, int n) {
	return (i >= 0 && i < m && j >= 0 && j < n);
}

int TinhDinh(int i, int j, int m, int n) {
	return (i * n + j) + 1;
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
	int n, m, i, j;
	FILE *f = fopen(argv[1], "rt");
	
	fscanf(f, "%d%d", &m, &n);
	init_graph(&G, n * m);
	int maze[m][n];
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			fscanf(f, "%d", &maze[i][j]);
		}
	}
	fclose(f);
	
	//Them cac o xung quanh o (i, j) vao do thi
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			/*
			//(i-1, j)
			if(HopLe(i-1, j, m, n)) 
				add_edge(&G, TinhDinh(i, j, m, n), TinhDinh(i-1, j, m, n), maze[i-1][j]);
			*/
			
			//(i+1, j);
			if(HopLe(i+1, j, m, n)) 
				add_edge(&G, TinhDinh(i, j, m, n), TinhDinh(i+1, j, m, n), maze[i+1][j]);
			
			/*//(i, j-1)
			if(HopLe(i, j-1, m, n)) 
				add_edge(&G, TinhDinh(i, j, m, n), TinhDinh(i, j-1, m, n), maze[i][j-1]);
			*/
			
			//(i, j+1)
			if(HopLe(i, j+1, m, n)) 
				add_edge(&G, TinhDinh(i, j, m, n), TinhDinh(i, j+1, m, n), maze[i][j+1]);
		}
	}
	
	Dijkstra(G, 1);
	printf("%d\n", pi[20]);
	PrintResult(G);
	
	return 0;
}
