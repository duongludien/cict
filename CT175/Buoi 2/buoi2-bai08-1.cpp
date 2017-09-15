/* Truyen vao doi so dong lenh file dothi.txt de chay chuong trinh nay */

#include <iostream>
#include <stack>
#include "lib/adjacent_matrix_lib_multiple_edges.h"
using namespace std;

void depth_first_search(Graph G, int x) {
	stack<int> frontier;
	int mark[G.n+1];
	
	/* Khoi tao ma tran danh dau, chua co dinh nao duoc duyet */
	int i;
	for(i=1; i<=G.n; i++)
		mark[i] = 0;
	
	/* Dua dinh can duyet vao ngan xep */
	frontier.push(x);
	mark[x] = 1;
	
	while(!frontier.empty()) {
		/* Duyet v, danh dau la da duyet */	
		int v = frontier.top();
		frontier.pop();
		cout << v << " ";
		/* Lay cac dinh ke cua v */
		List L = neighbors(G, v);
		/* Dua cac dinh ke cua v vao stack */
		for(i=1; i<=L.size; i++) {
			if(mark[element_at(L, i)] == 0) {
				mark[element_at(L, i)] = 1;
				frontier.push(element_at(L, i));
			}
		}
	}
}

int main(int argc, char *argv[]) {
	if(argc<2) {
		cout << "Hay nhap: %s <ten-file>" << argv[0];
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
	
	depth_first_search(G, 1);
	
	return 0;
}
