/************************************************************************\
* Problem:		ATM Payment												*
* Algorithm:	Greedy 													*
* Input file:	Greedy_ATM.txt											*
* Code by:		Lu-Dien DUONG											*
* Website:		www.duongludien.com										*
\************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	long MG;
	char tenTien[25];
	int PA;
} Tien;

Tien* ReadFromFile(int *n) {
	FILE *f = fopen("Greedy_ATM.txt", "r");
	Tien *dslt;
	char *tmp;
	int i = 0;
	int len;
	
	dslt = (Tien*)malloc(sizeof(Tien));
	while(!feof(f)) {
		fscanf(f, "%d", &dslt[i].MG);
		fgets(dslt[i].tenTien, 25, f);
		tmp = strtok(dslt[i].tenTien, "\n");
		strcpy(dslt[i].tenTien, tmp);
		dslt[i].PA = 0;
		i++;
		dslt = realloc(dslt, (i+1) * sizeof(Tien));
	}
	*n = i;
	fclose(f);
	return dslt;
}

void swap(Tien *x, Tien *y) {
	Tien tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void Sorting(Tien *dslt, int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(dslt[i].MG < dslt[j].MG)
				swap(dslt+i, dslt+j);
		}
	}
}

void Greedy(Tien *dslt, int n, long t) {
	int i = 0;
	
	Sorting(dslt, n);
	while(i<n && t > 0) {
		dslt[i].PA = t / dslt[i].MG;
		t -= dslt[i].MG * dslt[i].PA;
		i++;
	}
}

void inDanhSach(Tien* dslt, int n) {
	int i, stt = 1;
	
	printf("\n|-----|---------------------------|----------|----------------------|\n");
	printf("| %3s | %25s | %8s | %20s |\n", "STT", "Loai tien", "So luong", "Thanh tien");
	printf("|-----|---------------------------|----------|----------------------|\n");
	for(i=0; i<n; i++)
		if(dslt[i].PA > 0) {
			printf("| %3d | %25s | %8d | %20d |\n", stt, dslt[i].tenTien, dslt[i].PA, dslt[i].PA * dslt[i].MG);
			printf("|-----|---------------------------|----------|----------------------|\n");
			stt++;
		}
}

int main() 
{
	Tien *dslt;
	int n;
	long t;
	
	dslt = ReadFromFile(&n);
	
	printf("Nhap vao so tien can rut: ");
	scanf("%d", &t);
	Greedy(dslt, n, t);
	inDanhSach(dslt, n);
	
	free(dslt);
	return 0;
}
