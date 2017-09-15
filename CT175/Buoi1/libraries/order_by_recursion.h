#include "adjacent_matrix_lib_multiple_edges.h"

/* Duyet de quy dinh x */
void traversal(Graph G, int x, int mark[]) {
	if(mark[x] == 1)
		return;
	printf("Duyet %d\n", x);
	mark[x] = 1;
	List L;
	make_null(&L);
	L = neighbors(G, x);
	int i;
	for(i=1; i<=L.size; i++) {
		traversal(G, element_at(L, i), mark);
	}
}

/* Duyet de quy do thi */
void depth_first_search(Graph G) {
	int i;
	int mark[MAX_VERTEXES];
	for(i=1; i<=G.n; i++) {
		mark[i] = 0;
	}
	traversal(G, 1, mark);
}
