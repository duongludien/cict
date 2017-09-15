#include <stdio.h>
#include "aqueuelib.h"

#define MAXN 100
#define NO_EDGE 0
#define INF 9999999

//Do thi duoc bieu dien bang phuong phap ma tran trong so
typedef struct {
	int C[MAXN][MAXN];		//Kha nang cua cung
	int F[MAXN][MAXN];		//Luong tren cung
	int n;
} Graph;

//Nhan cua mot dinh
typedef struct {
	int dir;	//1: Co nhan, da xet; -1: Co nhan, chua xet; 0: khong co nhan
	int pre;	//Dinh phia truoc
	int sigma;	//Luong tang luong
} Label;

//Khoi tao do thi G co n dinh
void init_graph(Graph *G, int n) {
	int i, j;
	G->n = n;
	for(i=1; i<=G->n; i++) 
		for(j=1; j<=G->n; j++)
			G->C[i][j] = NO_EDGE;
}

//Khoi tao tat ca cac luong bang 0
void init_flow(Graph *G) {
	int i, j;
	for(i=1; i<= G->n; i++)
		for(j=1; j<= G->n; j++)
			G->F[i][j] = 0;
}

//Giai thuat Ford - Fulkerson tim luong cuc dai trong mang
int Ford_Fulkerson(Graph *G, int s, int t) {
	Label labels[G->n];
	
	//1. Khoi tao tat ca luong bang 0
	init_flow(&G);
	
	//2. Lap
	Queue Q;
	do {
		int u;
		//2.1. Xoa nhan cac dinh va gan nhan cho dinh s
		//2.1.1. Xoa tat ca cac nhan
		for(u=1; u<=G->n; u++) 
			labels[u].dir = 0;
			
		//2.1.2. Gan nhan cho dinh s (+1, s, INF)
		labels[s].dir = +1;
		labels[s].pre = s;
		labels[s].sigma = INF;
		
		//2.1.3. Khoi tao Q rong, dua s vao Q
		make_null_queue(&Q);
		enqueue(&Q, s);
		
		//2.2. Lap gan nhan cho cac dinh
		int found = 0;
		while(!empty(Q)) {
			//2.2.1. Lay mot dinh trong Q ra => x
			int x = top(Q);
			dequeue(&Q);
			int v;
			
			//2.2.2. Gan nhan cho cac dinh ke voi x
			for(v=1; v<=G->n; v++) {
				//Truong hop cung thuan
				if(labels[v].dir == 0 && G->C[x][v] != NO_EDGE && )
			}
			
			//2.2.3. Neu t duoc gan nhan thi tim duoc duong tang luong, break
		}
		
		if(/*tim duoc duong tang luong*/) {
			//2.3. Tang luong
		}
		else 
			break;
	}
	while(1);
}
