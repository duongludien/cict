/***********************************************************************\
* Problem:		The Numbers Triangle 2									*
* Algorithm:	Greedy from bottom										*
* Input file:	Greedy_NumbersTriangle.txt								*
* Code by:		Lu-Dien DUONG											*
* Website:		www.duongludien.com										*
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

int findMax(int *arr, int n, int *pre_j) {
	int i;
	int max_index = 0;
	int max = arr[0];
	for(i=1; i<n; i++) 
		if(arr[i] > max) {
			max = arr[i];
			max_index = i;
		}
	*pre_j = max_index;		
	return max;
}

int* Greedy(int **T, int n) {
	int i;
	int pre_i = n-1, pre_j;
	
	int *path = (int*)malloc(n * sizeof(int));
	
	path[n-1] = findMax(T[n-1], n, &pre_j);
	for(i=n-2; i>=0; i--) {
		if(j == 0) {
			path[i] = maximum(i-1, )
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
