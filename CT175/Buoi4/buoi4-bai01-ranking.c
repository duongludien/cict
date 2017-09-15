//Duong Lu Dien
//B1401133

#include <stdio.h>
#include "graph.h"

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

int rank[MAX_VERTEXES];			//rank[u]: Hang cua dinh u
void ranking(Graph G) {
	int d[MAX_VERTEXES];		//d[u]: Bac vao cua dinh u
	
	//Tinh bac vao cua cac dinh cua do thi
	int u, v, i, j;
	
	for(u=1; u<=G.n; u++)
		d[u] = degree_minus(G, u);

	//Dua cac dinh i co d[i] == 0 vao S1;
	List S1, S2;
	make_null(&S1);
	for(u=1; u<=G.n; u++) {
		if(d[u] == 0) {
			push_back(&S1, u);
			//printf("push_back(%d)\n", u);
		}	
	}
	
	//Khoi tao k = 0
	int k = 0;
	
	//Lap cho den khi S1 rong
	while(!empty(S1)) {
		make_null(&S2);
		//for(Cac dinh trong S1)
		for(i=1; i<=S1.size; i++) {
			u = element_at(S1, i);
			rank[u] = k;
			
			//Lay cac dinh ke cua u
			List L;
			make_null(&L);
			L = neighbors(u, G);
			//for(Cac dinh ke cua u)
			for(j=1; j<=L.size; j++) {
				v = element_at(L, j);
				d[v]--;
				if(d[v] == 0) {
					push_back(&S2, v);
					//printf("push_back(&S2, %d)\n", v);
				}	
			}
			
			//Another way to find u's neighbors
			/*
			for(v=1; v<=G.n; v++) {
				if(G.A[u][v] != 0) {
					d[v]--;
					if(d[v] == 0) {
						push_back(&S2, v);
					}
						
				}
			}
			*/
		}
		//Tang k len 1 don vi
		k++;
		//Copy S2 vao S1
		copy(&S1, S2);
	}
}

int main() {
	Graph G;
	int i;
	
	ReadFromFile(&G, "buoi4-bai01-data.txt");
	
	ranking(G);
	for(i=1; i<=G.n; i++)
		printf("rank[%d] = %d\n", i, rank[i]);
	
	return 0;
}
