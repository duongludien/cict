#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ten[25];
	int TL, GT, PA;
} DoVat;

typedef int bang[10][100];

DoVat* ReadFromFile(int *n, int *W) {
	DoVat *dsdv;
	int i = 0;	
	FILE *f = fopen("DynamicProgramming_Knapsack1.txt", "r");
	fscanf(f, "%d", W);
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)) {
		fscanf(f, "%d%d", &dsdv[i].TL, &dsdv[i].GT);
		fgets(dsdv[i].ten, 25, f);
		dsdv[i].ten[strlen(dsdv[i].ten)-1] = '\0';
		dsdv[i].PA = 0;
		i++;
		dsdv = realloc(dsdv, (i+1) * sizeof(DoVat));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void TaoBang(DoVat *dsdv, int n, int W, bang F, bang X) {
	int i, j;
	
	//Dien dong dau tien cua bang
	for(i=0; i<=W; i++) {
		X[0][i] = i / dsdv[0].TL;
		F[0][i] = X[0][i] * dsdv[0].GT;
	}
	
	//Dien cac dong con lai
	for(i=1; i<n; i++) {
		for(j=0; j<=W; j++) {
			
		}
	}
}

int main() {
	int n, W, i;
	DoVat *dsdv;
	
	dsdv = ReadFromFile(&n, &W);
	
	printf("%d\n", W);
	printf("%3s%3s%3s%5s\n", "TL", "GT", "PA", "Ten");
	for(i=0; i<n; i++) {
		printf("%3d%3d%3d%5s\n", dsdv[i].TL, dsdv[i].GT, dsdv[i].PA, dsdv[i].ten);
	}
	
	free(dsdv);
	return 0;
}
