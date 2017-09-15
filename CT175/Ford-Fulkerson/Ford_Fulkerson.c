//Du lieu cho trong file data.txt, data2.txt, data3.txt, data4.txt

#include <stdio.h>
#include "aqueuelib.h"

#define MAXN 100
#define NO_EDGE 0
#define INF 9999999

typedef struct {
	int n;				//So dinh
	int C[MAXN][MAXN];	//Kha nang
	int F[MAXN][MAXN];	//Luong
} Graph;

typedef struct {
	int dir;		//0: Chua co nhan, -1: -, +1: +
	int pre;		//Dinh phia truoc
	int sigma;		//Luong tang luong
} Label;

//Khoi tao tat ca luong bang 0
void init_flow(Graph *G) {
	int u, v;
	for(u=1; u<G->n; u++) 
		for(v=1; v<G->n; v++) 
			G->F[u][v] = 0;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void init_graph(Graph *G, int n)  {
	int i, j;
	G->n = n;
	for(i=1; i<=n; i++) 
		for(j=1; j<=n; j++)
			G->C[i][j] = 0;
}

void add_edge(Graph *G, int u, int v, int c) {
	G->C[u][v] = c;
}

//Tim luong cuc dai
int Ford_Fulkerson(Graph *G, int s, int t) {
	//Du lieu
	int i;
	int found;
	Label labels[MAXN];
	int sum_flow = 0;
	
	//Khoi tao luong bang 0
	init_flow(G);
	Queue Q;
	
	//Lap 1: den khi khong tim duoc duong tang luong
	do {
		//Xoa nhan cac dinh
		for(i=1; i<=G->n; i++)
			labels[i].dir = 0;
			
		//Gan nhan cho s
		labels[s].dir = +1;
		labels[s].pre = s;
		labels[s].sigma = INF;
		
		//Khoi tao Q rong, dua s vao Q
		make_null_queue(&Q);
		enqueue(&Q, s);
		
		found = 0;
		
		//Lap 2: gan nhan cho cac dinh	
		while(!empty(Q)) {
			//Lay dinh x trong Q ra
			int x = top(Q);
			dequeue(&Q);
			
			//Gan nhan cho cac dinh ke voi x
			for(i=1; i<=G->n; i++) {
				//Cung thuan
				if(labels[i].dir == 0 && G->C[x][i] != NO_EDGE && G->F[x][i] < G->C[x][i]) {
					labels[i].dir = +1;
					labels[i].pre = x;
					labels[i].sigma = min(G->C[x][i] - G->F[x][i], labels[x].sigma);
					enqueue(&Q, i);
				}
				
				//Cung nghich
				if(labels[i].dir == 0 && G->C[x][i] != NO_EDGE && G->F[x][i] < 0) {
					labels[i].dir = -1;
					labels[i].pre = x;
					labels[i].sigma = min(labels[x].sigma, G->F[x][i]);
					enqueue(&Q, i);
				}
			}
			
			//Neu t duoc gan nhan => tim duoc luong tang luong, thoat vong lap 2
			if(labels[t].dir != 0) {
				found = 1;
				break;
			}
		}
		
		if(found == 1) {
			int x = t;
			int sigma = labels[t].sigma;
			sum_flow += sigma;
			
			while(x != s) {
				if(labels[x].dir > 0) {		//Tang luong
					printf("Tang luong: %d\n", sigma);
					G->F[labels[x].pre][x] += sigma;
				}
				//Giam luong
				else { 						//Giam luong
					printf("Giam luong: %d\n", sigma);
					G->F[labels[x].pre][x] -= sigma;
				}
				x = labels[x].pre;
			}
		} else
			break;
	} while(1);
	
	return sum_flow;
}

int main() {
	freopen("data.txt", "r", stdin);
	
	int n, m, u, v, c, i;
	Graph G;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(i=0; i<m; i++) {
		scanf("%d%d%d", &u, &v, &c);
		add_edge(&G, u, v, c);
	}
	
	printf("Tong luong: %d", Ford_Fulkerson(&G, 1, n));
	
	return 0;
}
