/****************************
*	InsertionSort Algorithm
*	Code by Lu-Dien Duong
*****************************/

#include <stdio.h>

void swap(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertionSort(int arr[], int n) {
	int i, j;
	
	for(i=1; i<n; i++) {
		j = i;
		while(j>0 && arr[j] < arr[j-1]) {
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}

void PrintList(int arr[], int n) {
	int i;
	
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}

int main() {
	int n = 10;
	int arr[] = {5, 8, 2, 10, 5, 12, 8, 1, 15, 4};
	
	printf("Before: ");
	PrintList(arr, n);
	InsertionSort(arr, n);
	printf("\nResult: ");
	PrintList(arr, n);
	
	return 0;
}
