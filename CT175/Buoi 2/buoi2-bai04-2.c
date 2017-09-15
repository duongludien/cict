/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include <stdio.h>
#include "lib/adjacent_matrix_lib_multiple_edges.h"
#include "lib/aqueuelib.h"

void traversal(Graph G, int x, int mark[]) {
	/* Neu x da duyet thi khong lam gi ca */
	if(mark[x] == 1)
		return;
	
	/* Truong hop x chua duyet */
	printf("%d ", x);
	mark[x] = 1;
	
	List L;
	make_null(&L);
	L = neighbors(G, x);
	
	int i;
	for(i=1; i<=L.size; i++)
		traversal(G, element_at(L, i), mark);
}

void depth_first_search(Graph G, int x, int mark[]) {
	int i;
	for(i=1; i<=G.n; i++)
		mark[i] = 0;
	traversal(G, 1, mark);
}

void depth_first_search_full(Graph G) {
	int mark[G.n+1];
	
	/* Khoi tao ma tran danh dau, chua co dinh nao duoc duyet */
	int i;
	for(i=1; i<=G.n; i++)
		mark[i] = 0;
	
	for(i=1; i<=G.n; i++)
		if(mark[i] == 0)
			depth_first_search(G, i, mark);
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
	
	depth_first_search_full(G);
	
	return 0;
}
