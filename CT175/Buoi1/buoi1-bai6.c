/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include "libraries/adjacent_matrix_lib_multiple_edges.h"

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
	
	for(v1=1; v1<=G.n; v1++) {
		List L;
		make_null(&L);
		L = neighbors(G, v1);
		printf("Cac dinh ke cua %d la: ", v1);
		print_list(L);
		printf("\n");
	}
	
	return 0;
}
