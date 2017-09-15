#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
	int weight;	
	int value;			
	float price;		
	char name[25];	
	int selected;		
} Thing;

typedef int Table[50][200];

Thing* read_from_file(int *n, int *W) {
	FILE *f = fopen("data.txt", "r");
	Thing *things;
	int i = 0;
	
	things = (Thing*)malloc(sizeof(Thing));
	if(!feof(f)) 
		fscanf(f, "%d", W);

	while(!feof(f)) {
		fscanf(f, "%d%d", &things[i].weight, &things[i].value);
		fgets(things[i].name, 25, f);
		things[i].name[strlen(things[i].name) - 1] = '\0';
		
		things[i].price = (float)things[i].value / things[i].weight;
		things[i].selected = 0;
		i++;
		things = realloc(things, (i+1) * sizeof(Thing));
	}

	*n = i;
	fclose(f);

	return things;
}

void create_table(Thing *things, int n, int W, Table X, Table F) {
	int v, i, j;
	int F_max, X_max;

	// The first row
	for(v=0; v<=W; v++) {
		X[0][v] = v / things[0].weight;
		F[0][v] = X[0][v] * things[0].value;
		//printf("X[0][%d] = %d; F[0][%d] = %d\n", v, X[0][v], v, F[0][v]);
	}

	// The next n-1 rows
	for(i=1; i<n; i++) {
		for(v=0; v<=W; v++) {
			F_max = INT_MIN;
			for(j=0; j <= v / things[i].weight; j++) {
				if(j * things[i].value + F[i-1][v - j * things[i].weight] > F_max) {
					F_max = j * things[i].value + F[i-1][v - j * things[i].weight];
					X_max = j;
				}
			}
			F[i][v] = F_max;
			X[i][v] = X_max;
			//printf("%d %d\t", F[i][v], X[i][v]);
		}
		//printf("\n");
	}
}

void find_result(Table X, Table F, Thing *things, int W, int n) {
	int i;
	for(i=n-1; i>=0; i--) {
		things[i].selected = X[i][W];
		//printf("Lay X[%d] = %d\n", i, X[i][W]);
		W -= things[i].selected * things[i].weight;
	}
}

int main(int argc, char const *argv[])
{
	int n, W;
	Thing *things;
	Table F, X;

	things = read_from_file(&n, &W);
	create_table(things, n, W, X, F);
	find_result(X, F, things, W, n);

	int i;
	for(i=0; i<n; i++) {
		printf("X[%d] = %d\n", i, things[i].selected);
	}

	free(things);
	return 0;
}