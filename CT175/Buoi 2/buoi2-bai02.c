/* Truyen vao doi so dong lenh file dothi.txt de chay chuong trinh nay */

#include <stdio.h>
#include "lib/aqueuelib.h"
#include "lib/adjacent_matrix_lib_multiple_edges.h"

void breath_first_search(Graph G, int x) {
	Queue frontier;
	make_null_queue(&frontier);
	int mark[G.n+1];
	
	/* Khoi tao mark, chua co dinh nao duoc xet */
	int i;
	for(i=1; i<=G.n; i++) {
		mark[i] = 0;
	}
	
	/* Dua 1 vao frontier, danh dau la da xet */
	push(&frontier, x);
	mark[x] = 1;
	
	/* Vong lap chinh de duyet */
	while(!empty(frontier)) {
		int x = top(frontier);
		pop(&frontier);
		printf("%d ", x);
		List L;
		make_null(&L);
		L = neighbors(G, x);
		for(i=1; i<=L.size; i++) {
			int y = element_at(L, i);
			if(mark[y] == 0) {
				push(&frontier, y);
				mark[y] = 1;
			}
		}
	}
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
	
	breath_first_search(G, 1);
	
	return 0;
}
