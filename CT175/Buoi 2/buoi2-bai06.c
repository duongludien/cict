/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include <stdio.h>
#include "lib/astacklib.h"
#include "lib/adjacent_matrix_lib_multiple_edges.h"

void depth_first_search(Graph G, int x, int mark[]) {
	Stack frontier;
	make_null_stack(&frontier);
	int i;
	
	/* Dua dinh can duyet vao ngan xep */
	push(&frontier, x);
	mark[x] = 1;
	
	while(!empty(frontier)) {
		/* Duyet v, danh dau la da duyet */	
		int v = top(frontier);
		pop(&frontier);	
		//printf("%d ", v);
		/* Lay cac dinh ke cua v */
		List L = neighbors(G, v);
		/* Dua cac dinh ke cua v vao stack */
		for(i=1; i<=L.size; i++) {
			if(mark[element_at(L, i)] == 0) {
				mark[element_at(L, i)] = 1;
				push(&frontier, element_at(L, i));
			}
		}
	}
}

int count_connected_components(Graph G) {
	int mark[G.n+1];
	int count = 0;
	
	/* Khoi tao ma tran danh dau, chua co dinh nao duoc duyet */
	int i;
	for(i=1; i<=G.n; i++)
		mark[i] = 0;
		
	for(i=1; i<=G.n; i++)
		if(mark[i] == 0) {
			count++;
			depth_first_search(G, i, mark);
		}
	
	return count;	
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
	
	printf("So thanh phan lien thong cua do thi la: %d", count_connected_components(G));
	
	return 0;
}
