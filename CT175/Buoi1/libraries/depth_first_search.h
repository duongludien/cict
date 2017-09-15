#include "adjacent_matrix_lib_multiple_edges.h"
#include "astacklib.h"

/* Duyet do thi theo chieu sau */
void depth_first_search(Graph G) {
	Stack frontier;
	make_null_stack(&frontier);
	int mark[MAX_VERTEXES];
	
	/* Khoi tao mark, chua co dinh nao duoc xet */
	int i;
	for(i=1; i<=G.n; i++) {
		mark[i] = 0;
	}
	
	/* Dua 1 vao frontier va danh dau 1 la da xet*/
	push(&frontier, 1);
	mark[1] = 1;
	
	/* Vong lap chinh dung de duyet */
	while(!empty(frontier)) {
		/* Lay phan tu dau tien trong frontier ra */
		int x = top(frontier);
		pop(&frontier);
		printf("Duyet %d\n", x);
		/* Lay cac dinh ke cua no */
		List L;
		make_null(&L);
		L = neighbors(G, x);
		/* Xet tung dinh ke cua no */
		for(i=1; i<=L.size; i++) {
			int y = element_at(L, i);
			if(mark[y] == 0) {
				push(&frontier, y);
				mark[y] = 1;
			}
		}
	}
}
