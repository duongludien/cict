/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include <stdio.h>
#include "libraries/adjacent_list_lib.h" 

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
	
	for(v1=1; v1<=n; v1++) {
		printf("Cac dinh ke cua dinh %d: ", v1);
		int i;
		for(i=0; i<G.adj[v1].size; i++)
			printf("%d ", G.adj[v1].data[i]);
		printf("\n");
	}
	
	return 0;
}
