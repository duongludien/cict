#include <stdio.h>
#include "libraries/adjacent_matrix_lib_multiple_edges.h"

int main() {
	Graph G;
	int n = 4, v;
	
	init_graph(&G, n);
	
	add_edge(&G, 1, 2);
	add_edge(&G, 1, 3);
	add_edge(&G, 1, 3);
	add_edge(&G, 3, 4);
	add_edge(&G, 1, 4);
	
	for(v=1; v<=n; v++)
		printf("deg(%d) = %d\n", v, degree(G, v));
	
	return 0;
}
