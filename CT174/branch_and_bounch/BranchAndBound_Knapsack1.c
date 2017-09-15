/*******************************************************************\
* Problem:		The Knapsack 1 (Every item has an unlimited number)	*
* Algorithm:	Branch and Bound									*
* Input file:	BranchAndBound_Knapsack1.txt						*
* Code by:		Lu-Dien DUONG										*
* Website:		www.duongludien.com									*
\*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
	char ten[25];
	float TL, GT;
	int PA;
} DoVat;

DoVat *dsdv;	//Danh sach do vat
float W;		//Trong luong balo
int n;			//So do vat
int x[MAX];		//Phuong an tot nhat tam thoi
float CT;		//Can tren
float TGT;		//Tong gia tri
float GTLNTT;	//Gia tri lon nhat tam thoi
float TLCL;		//Trong luong con lai cua balo

void ReadFromFile() {
	int i = 0;
	char *tmp;
	FILE *f = fopen("BranchAndBound_Knapsack1.txt", "r");
	fscanf(f, "%f", &W);
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)) {
		fscanf(f, "%f%f", &dsdv[i].TL, &dsdv[i].GT);
		fgets(dsdv[i].ten, 25, f);
		tmp = strtok(dsdv[i].ten, "\n");
		strcpy(dsdv[i].ten, tmp);
		dsdv[i].PA = 0;
		i++;
		dsdv = realloc(dsdv, (i+1) * sizeof(DoVat));
	}
	n = i;
}

void inDSDV() {
	int i, stt = 1;
	
	printf("\n|-----|---------------------------|----------|------------|\n");
	printf("| %3s | %25s | %8s | %10s |\n", "STT", "Loai do vat", "So luong", "Tong GT");
	printf("|-----|---------------------------|----------|------------|\n");
	float ttl = 0.0;
	for(i=0; i<n; i++) 
		if(dsdv[i].PA > 0) {
			printf("| %3d | %25s | %8d | %10.1f |\n", stt, dsdv[i].ten, dsdv[i].PA, dsdv[i].PA * dsdv[i].GT);
			printf("|-----|---------------------------|----------|------------|\n");
			stt++;
			ttl += dsdv[i].PA * dsdv[i].TL;
		}
	
	printf("\nTrong luong ba lo ban dau: %.1f\n", W);
	printf("Trong luong balo con lai: %.1f\n", W-ttl);
	printf("Tong trong luong va Tong gia tri sau khi da chon: %.1f va %.1f", ttl, GTLNTT);
}

void swap(DoVat *x, DoVat *y) {
	DoVat tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sorting() {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(dsdv[i].GT / dsdv[i].TL < dsdv[j].GT / dsdv[j].TL)
				swap(&dsdv[i], &dsdv[j]);
		}
	}
}

//Khoi tao gia tri cho nut goc
void init() {
	TLCL = W;
	TGT = 0;
	CT = W * (dsdv[0].GT / dsdv[0].TL);
	GTLNTT = 0;
}

//Ghi nhan gia tri nho nhat tam thoi va phuong an khi balo day hoac het do vat
void GhiNhanKyLuc() {
	if(GTLNTT < TGT) {
		GTLNTT = TGT;
		int i;
		for(i=0; i<n; i++)
			dsdv[i].PA = x[i];
	}
}

//Nhanh can
void BranchAndBound(int i) {
	int j;
	for(j=TLCL/dsdv[i].TL; j>=0; j--) {
		TGT += dsdv[i].GT * j;
		TLCL -= dsdv[i].TL * j;
		if(i < n-1)
			CT = TGT + TLCL * (dsdv[i+1].GT / dsdv[i+1].TL);
		
		if(CT > GTLNTT) {
			x[i] = j;
			if(TLCL == 0 || i == n-1)		//Balo het cho OR Da xet het do vat
				GhiNhanKyLuc();
			else 
				BranchAndBound(i+1);
		}
		//Quay lui
		x[i] = 0;
		TGT -= dsdv[i].GT * j;
		TLCL += dsdv[i].TL * j;
	}
}

int main() {
	ReadFromFile();
	sorting();
	init();
	BranchAndBound(0);
	inDSDV();
	free(dsdv);
	return 0;
}
