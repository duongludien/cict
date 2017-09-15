#include <stdio.h>
#include "libraries/incident_matrix_lib.h"

int main() {
	Graph G;
	int n, m, e, u, v;
	FILE *f = fopen("dothi.txt", "rt");
	
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
