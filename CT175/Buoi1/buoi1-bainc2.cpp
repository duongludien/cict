/* Truyen vao doi so dong lenh file dothi2.txt de chay chuong trinh nay */

#include <stdio.h>
#include <vector>
using namespace std;

#define MAX_VERTEXES 100

typedef struct {
	int n;									//So dinh
	int A[MAX_VERTEXES][MAX_VERTEXES];		//Ma tran dinh - dinh
} Graph;

/* Khoi tao do thi G co n dinh */
void init_graph(Graph *G, int n) {
	int i, j;
	
	G->n = n;
	for(i=1; i<=n; i++) 
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

/* Them cung e = (x,y) vao do thi G */
void add_edge(Graph *G, int x, int y) {
	G->A[x][y] += 1;		//y ke voi x
	G->A[y][x] += 1;		//x ke voi y
}

/* Kiem tra y co ke voi x khong */
int adjacent(Graph G, int x, int y) {
	return G.A[x][y] != 0;
}

/* Tinh bac cua dinh x: deg(x), truong hop da cung */
int degree(Graph G, int x) {
	int deg = 0, y;
	
	for(y=0; y<=G.n; y++) 
		deg += G.A[x][y];
	
	return deg;
}

/* Tim cac dinh ke cua dinh x */
vector<int> neighbors(Graph G, int x) {
	vector<int> L;
	//make_null()
	int y;
	for(y=1; y<=G.n; y++) 
		if(adjacent(G, x, y))
			L.push_back(y);
	return L;
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
	
	for(v1=1; v1<=G.n; v1++) {
		vector<int> L;
		L = neighbors(G, v1);
		printf("Cac dinh ke cua %d la: ", v1);
		for(int i=0; i<L.size(); i++) {
			printf("%d ", L[i]);
		}
		printf("\n");
	}
	
	return 0;
}
