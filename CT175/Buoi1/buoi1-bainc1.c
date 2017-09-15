/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include <stdio.h>
#include "libraries/incident_matrix_lib.h"

int main(int argc, char **argv) {
	Graph G;
	int n, m, e, u, v;
	
	if(argc < 2) {
		printf("Hay nhap: %s <ten-file>", argv[0]);
		return 1;
	}
	
	FILE *f = fopen(argv[1], "rt");
	
	fscanf(f, "%d%d", &n, &m);
	init_graph(&G, n, m);
	
	for(e=1; e<=m; e++) {
		fscanf(f, "%d%d", &u, &v);
		add_edge(&G, e, u, v);
	}
	
	for(v=1; v<=G.n; v++) {
		printf("deg(%d) = %d\n", v, degree(G, v));
	}
	
	return 0;
}
