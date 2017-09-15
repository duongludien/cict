/*******************************************************************\
* Problem:		The Knapsack 3 (Every item has a limited number)	*
* Algorithm:	Greedy												*
* Input file:	Greedy_Knapsack3.txt								*
* Code by:		Lu-Dien DUONG										*
* Website:		www.duongludien.com									*
\*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int TL;			//Weight
	int GT;			//Value
	float DG;		//Unit price
	int SL;			//Number
	char ten[25];	//Name
	int PA;			//Selected Number
} DoVat;

DoVat* ReadFromFile(int *n, int *W) {
	FILE *f = fopen("Greedy_Knapsack3.txt", "r");
	DoVat *dsdv;
	char *tmp;
	int i = 0;
	
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	if(!feof(f)) 
		fscanf(f, "%d", W);
	while(!feof(f)) {
		fscanf(f, "%d%d%d", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].SL);
		fgets(dsdv[i].ten, 25, f);
		
		//Split char "\n" of name string
		tmp = strtok(dsdv[i].ten, "\n");
		strcpy(dsdv[i].ten, tmp);
		
		dsdv[i].DG = (float)dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = realloc(dsdv, (i+1) * sizeof(DoVat));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x, DoVat *y) {
	DoVat tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void Sorting(DoVat *dsdv, int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(dsdv[i].DG < dsdv[j].DG)
				swap(dsdv+i, dsdv+j);
		}
	}
}

void Greedy(DoVat *dsdv, int n, int W, int *TV, int *TW) {
	int i = 0;
	
	*TV = 0;		//Total value
	*TW = 0;		//Total weight
	Sorting(dsdv, n);
	while(i<n && W > 0) {
		int tmp = W / dsdv[i].TL;
		dsdv[i].PA = (tmp >= dsdv[i].SL ? dsdv[i].SL : tmp);
		W -= dsdv[i].TL * dsdv[i].PA;
		*TV += dsdv[i].GT * dsdv[i].PA;
		*TW += dsdv[i].TL * dsdv[i].PA;
		i++;
	}
}

void inDanhSach(DoVat *dsdv, int n) {
	int i, stt = 1;
	
	printf("\n|-----|---------------------------|----------|----------|------------|------------|-------------|------------|\n");
	printf("| %3s | %25s | %8s | %8s | %10s | %10s | %11s | %10s |\n", "STT", "Loai do vat", "So luong", "Da chon", "Gia tri", "Tong GT", "Trong luong", "Tong TL");
	printf("|-----|---------------------------|----------|----------|------------|------------|-------------|------------|\n");
	for(i=0; i<n; i++) 
		if(dsdv[i].PA >= 0) {
			printf("| %3d | %25s | %8d | %8d | %10d | %10d | %11d | %10d |\n", stt, dsdv[i].ten, dsdv[i].SL, dsdv[i].PA, dsdv[i].GT, dsdv[i].PA * dsdv[i].GT,  dsdv[i].TL, dsdv[i].PA * dsdv[i].TL);
			printf("|-----|---------------------------|----------|----------|------------|------------|-------------|------------|\n");
			stt++;
		}
}

int main() {
	int n, W, TV, TW;
	DoVat *dsdv;
		
	dsdv = ReadFromFile(&n, &W);
	printf("So do vat: %d\nTrong tai ba lo ban dau: %d kg\n", n, W);
	Greedy(dsdv, n, W, &TV, &TW);
	Sorting(dsdv, n);
	inDanhSach(dsdv, n);
	printf("\nBa lo da dung: %d kg\nTong gia tri: %d", TW, TV);
	
	free(dsdv);
	return 0;
}
