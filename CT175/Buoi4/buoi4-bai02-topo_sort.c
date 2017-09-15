//Duong Lu Dien
//B1401133

#include <stdio.h>
#include "graph.h"
#include "aqueuelib.h"

void ReadFromFile(Graph *G, char *path) {
	int n, m, i;
	int u, v;
	FILE *f = fopen(path, "rt");	
	
	if(!feof(f)) {
		fscanf(f, "%d%d", &n, &m);
		init_graph(G, n);
		for(i=0; i<m; i++) {
			fscanf(f, "%d%d", &u, &v);
			add_edge(G, u, v);
		}
	}
	
	fclose(f);
}

List topo_sort(Graph G) {
	int d[MAX_VERTEXES];		//d[u]: Bac vao cua dinh u
	List L;
	Queue Q;
	make_null(&L);
	make_null_queue(&Q);
	
	//Tinh bac vao cua cac dinh cua do thi
	int u, v, i, j;
	
	for(u=1; u<=G.n; u++)
		d[u] = degree_minus(G, u);
	
	//Them cac dinh u co d[u] == 0 vao Queue
	for(u=1; u<=G.n; u++) {
		if(d[u] == 0) {
			push(&Q, u);
			//printf("push(%d, &Q)\n", u);
		}			
	}
	
	//Lap cho den khi Q rong
	while(!empty_queue(Q)) {
		//Lay dinh dau tien trong Q ra
		u = top(Q);
		pop(&Q);
		//Dua u vao danh sach L
		push_back(&L, u);
		//printf("push_back(%d, L)\n", u);
		//Lay cac dinh ke cua u
		List L2;
		make_null(&L2);
		L2 = neighbors(u, G);
		//for(cac dinh ke cua u)
		for(i=1; i<=L2.size; i++) {
			v = element_at(L2, i);
			//printf("%d\n", v);
			d[v]--;
			if(d[v] == 0)
				push(&Q, v);
		}
	}
	
	return L;
}

int main() {
	Graph G;
	
	ReadFromFile(&G, "buoi4-bai01-data.txt");
	
	List L;
	make_null(&L);
	int i;
	
	L = topo_sort(G);
	for(i=1; i<=L.size; i++)
		printf("%d ", element_at(L, i));

	return 0;
}
