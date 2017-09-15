//Duong Lu Dien
//B1401133

#include <stdio.h>
#include "graph.h"
#include "aqueuelib.h"

#define INF 9999

List topo_sort(Graph G) {
	int d[MAX_VERTEXES];	//d[u]: Bac vao cua dinh u
	List L;
	Queue Q;
	make_null(&L);
	make_null_queue(&Q);
	int u, v, i, j;
	
	//Tinh bac vao cua cac dinh cua do thi
	for(u=1; u<=G.n; u++)
		d[u] = degree_minus(G, u);
	
	//Them cac dinh u co d[u] == 0 vao Queue
	for(u=1; u<=G.n; u++) {
		if(d[u] == 0) {
			push(&Q, u);
		}			
	}
	
	//Lap cho den khi Q rong
	while(!empty_queue(Q)) {
		//Lay dinh dau tien trong Q ra
		u = top(Q);
		pop(&Q);
		//Dua u vao danh sach L
		push_back(&L, u);
		//Lay cac dinh ke cua u
		List L2;
		make_null(&L2);
		L2 = neighbors(u, G);
		//for(cac dinh ke cua u)
		for(i=1; i<=L2.size; i++) {
			v = element_at(L2, i);
			d[v]--;
			if(d[v] == 0)
				push(&Q, v);
		}
	}
	
	return L;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	freopen("data.txt", "r", stdin);
	
	//Doc do thi tu file stdin
	Graph G;
	int n, i, x;
	int d[MAX_VERTEXES];
	
	scanf("%d", &n);
	init_graph(&G, n);
	for(i=1; i<=n; i++) {
		scanf("%d", &d[i]);
		do {
			scanf("%d", &x);
			if(x != 0)
				add_edge(&G, x, i);
		} while(x != 0);
	}
	
	//Them cung noi alpha (dinh n+1) voi cac dinh co bac vao bang 0, co bac ra bang 0 voi beta (dinh n+2)
	for(i=1; i<=G.n; i++) {
		if(degree_minus(G, i) == 0) {
			add_edge(&G, n+1, i);
		}
			
		if(degree_plus(G, i) == 0) {
			add_edge(&G, n+2, i);
		}	
	}
	
	//Sap xep thu tu topo va luu vao danh sach L
	List L = topo_sort(G);
	for(i=1; i<=L.size; i++)
		printf("%d ", element_at(L, i));
	
	//Tinh thoi gian som nhat de hoan thanh cong viec u: t[u]
	int t[MAX_VERTEXES];
	t[n+1] = 0;		//t[alpha] = 0
	for(i=1; i<=L.size; i++) {
		int u = element_at(L, i);
		t[u] = 0;
		//Duyet qua cac dinh tao anh cua u
		for(x=1; x<=G.n; x++) {
			if(G.A[x][u] != 0)
				t[u] = max(t[u], t[x] + d[x]);
		}
		printf("t[%d] = %d\n", u, t[u]);
	}
	
	//Tinh thoi gian tre nhat de bat dau cong viec u: T[u]
	int T[MAX_VERTEXES];
	T[n+2] = t[n] + d[n];
	for(i=L.size-1; i>=1; i--) {
		int u = element_at(L, i);
		T[u] = INF;
		//Duyet qua tat ca cac anh cua u
		for(x=1; x<=G.n; x++) {
			if(G.A[u][x] != 0) {
				T[u] = min(T[u], t[x] - d[u]);
			}	
		}
		printf("T[%d] = %d\n", u, T[u]);
	}
	
	//In ket qua
	for(i=1; i<=G.n; i++) {
		printf("Thoi gian som nhat de hoan thanh cong viec %d: %d\n", i, t[i]);
		printf("Thoi gian muon nhat de bat dau cong viec %d: %d\n", i, T[i]);
	}
	
	return 0;
}
