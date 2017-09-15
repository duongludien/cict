/***********************************************************************\
* Problem:		The Numbers Triangle 1									*
* Algorithm:	Greedy from above										*
* Input file:	Greedy_NumbersTriangle.txt								*
* Code by:		Lu-Dien DUONG											*
* http://www.duongludien.com											*
\***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int** ReadFromFile(int *n) {
	int i = 0, j;
	int **T;
	FILE *f;
	
	f = fopen("Greedy_NumbersTriangle.txt", "r");
	T = (int**)malloc(sizeof(int*));
	while(!feof(f)) {
		T[i] = (int*)malloc((i+1) * sizeof(int));
		
		for(j=0; j<i+1; j++) {
			fscanf(f, "%d", &T[i][j]);
		}
		
		i++;
		T = realloc(T, (i+1) * sizeof(int*));
	}
	
	*n = i;
	fclose(f);
	return T;
}

int maximum(int a, int b) {
	return a >= b ? a : b;
}

int* Greedy(int **T, int n) {
	int i;
	int pre_i = 0, pre_j = 0;
	
	int *path = (int*)malloc(n * sizeof(int));
	
	path[0] = T[0][0];
	for(i=1; i<n; i++) {
		if(pre_j == 0) {
			path[i] = maximum(T[pre_i+1][0], T[pre_i+1][1]);
			if(path[i] == T[pre_i+1][0])
				pre_j = 0;
			else 
				pre_j = 1;
			pre_i = pre_i+1;
		}
		else {
			path[i] = maximum(T[pre_i+1][pre_j-1], maximum(T[pre_i+1][pre_j], T[pre_i+1][pre_j+1]));
			if(path[i] == T[pre_i+1][pre_j-1])
				pre_j = pre_j-1;
			else if(path[i] == T[pre_i+1][pre_j])
				pre_j = pre_j;
			else 
				pre_j = pre_j+1;
			pre_i = pre_i+1;
		}
	}
	
	return path;
}

void PrintResult(int *arr, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
}

int sum(int *arr, int n) {
	int sum = 0, i;
	for(i=0; i<n; i++)
		sum += arr[i];
	return sum;
}

void PrintTriangle(int **T, int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=0; j<i+1; j++) {
			printf("%3d ", T[i][j]);
		}	
		printf("\n");
	}
}

int main() {
	int n;
	int **T;
	int *path;
	
	T = ReadFromFile(&n);
	PrintTriangle(T, n);
	path = Greedy(T, n);
	printf("\nResult: ");
	PrintResult(path, n);
	printf("\nPath length: %d", sum(path, n));
	free(T);
	return 0;
}
