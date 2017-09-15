/* Truyen vao doi so dong lenh file doibong1.txt, doibong2.txt va doibong3.txt de chay chuong trinh nay */

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
	int n, c, v1, v2;
	
	FILE *f = fopen(argv[1], "rt");
	fscanf(f, "%d%d", &n, &c);
	init_graph(&G, n);
	
	int j;
	for(j=0; j<c; j++) {
		fscanf(f, "%d%d", &v1, &v2);
		add_edge(&G, v1, v2);
	}
	
	if(bicolor(G)) {
		int i;
		printf("Doi 1: ");
		for(i=1; i<=n; i++)
			if(color[i] == 0)
				printf("%d ", i);
		printf("\nDoi 2: ");
		for(i=1; i<=n; i++)
			if(color[i] != 0)
				printf("%d ", i);
	}
	else 
		printf("Impossible");
	
	return 0;
}
