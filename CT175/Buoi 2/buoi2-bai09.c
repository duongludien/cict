/* Truyen vao doi so dong lenh file dothi2.txt hoac dothi3.txt de chay chuong trinh nay */

#include <stdio.h>
#include "lib/adjacent_matrix_lib_multiple_edges.h"

int color[MAX_VERTEXES];
int fail;

void colorize(Graph G, int x, int c) {
	/* Truong hop x chua duoc to mau */
	if(color[x] == -1) {
		color[x] = c;	//To mau c cho dinh x
		/* To mau !c cho cac dinh ke voi x */		
		List L;
		make_null(&L);
		L = neighbors(G, x);
		int i;
		for(i=1; i<=L.size; i++) 
			colorize(G, element_at(L, i), !c);
	}
	else {	//Truong hop x da duoc to mau
		if(color[x] != c) {
			fail = 1;
			return;
		}
	}
}

int bicolor(Graph G) {
	int i;
	
	fail = 0;
	for(i=1; i<=G.n; i++)
		color[i] = -1;
	colorize(G, 1, 0);
	return !fail;	
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
	
	if(bicolor(G))
		printf("Yes");
	else 
		printf("No");
	
	return 0;
}
