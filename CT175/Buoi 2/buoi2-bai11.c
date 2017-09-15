/* Truyen vao doi so dong lenh file dothi2.txt hoac dothi4.txt de chay chuong trinh nay */

#include <stdio.h>
#include "lib/adjacent_matrix_lib_multiple_edges_trendy.h"

#define white 0
#define gray 1
#define black 2

int cycle;
int color[MAX_VERTEXES];

void dfs(Graph G, int x) {
	/* Truong hop x chua duoc duyet */
	if(color[x] == white) {
		/* Duyet x */
		color[x] = gray;	
		/* Duyet cac dinh ke voi no */
		List L;
		int i;
		make_null(&L);
		L = neighbors(G, x);
		for(i=1; i<=L.size; i++) 
			dfs(G, element_at(L, i));
	}
	/* Truong hop x dang duoc duyet => co chu trinh */
	else if(color[x] == gray) {
		cycle = 1;
		return;
	}
	color[x] = black;
}

int contains_cycle(Graph G) {
	cycle = 0;
	
	int i;
	for(i=1; i<=G.n; i++)
		color[i] = white;
	
	for(i=1; i<=G.n; i++)
		if(color[i] == white)
			dfs(G, i);
	
	return cycle;
}

int main(int argc, char *argv[]) {
	if(argc<2) {
		printf("Hay nhap: %s <ten-file>", argv[0]);
		return 1;
	}
	
	Graph G;
	int n, v1, v2;
	
	FILE *f = fopen(argv[1], "rt");
	fscanf(f, "%d", &n);
	init_graph(&G, n);
	
	while(fscanf(f, "%d%d", &v1, &v2) == 2) {
		add_edge(&G, v1, v2);
	}
	
	if(contains_cycle(G))
		printf("Yes");
	else
		printf("No");
	
	return 0;
}
