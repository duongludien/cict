/****************************
*	SelectionSort Algorithm
*	Code by Lu-Dien Duong
*****************************/

#include <stdio.h>

void swap(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectionSort(int arr[], int n) {
	int i, j;
	int min, minindex;
	
	for(i=0; i<n-1; i++) {
		min = arr[i];
		minindex = i;
		for(j=i+1; j<n; j++) {
			if(arr[j] < min) {
				min = arr[j];
				minindex = j;
			}
		}
		swap(&arr[i], &arr[minindex]);
	}
}

void PrintList(int arr[], int n) {
	int i;
	
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}

int main() {
	int n = 10;
	int arr[] = {3, 9, 4, 7, 10, 2, 5, 1, 6, 8};
	
	printf("Before: ");
	PrintList(arr, n);
	SelectionSort(arr, n);
	printf("\nResult: ");
	PrintList(arr, n);
	
	return 0;
}
