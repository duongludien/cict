/****************************
*	BubbleSort Algorithm
*	Code by Lu-Dien Duong
*****************************/

#include <stdio.h>

void swap(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int arr[], int n) {
	int i, j;
	
	for(i=0; i<n-1; i++) {
		for(j=n-1; j>=i+1; j--) {
			if(arr[j] < arr[j-1])
				swap(&arr[j], &arr[j-1]);
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
	int arr[] = {3, 9, 4, 7, 10, 2, 5, 1, 6, 8};
	
	printf("Before: ");
	PrintList(arr, n);
	BubbleSort(arr, n);
	printf("\nResult: ");
	PrintList(arr, n);
	
	return 0;
}
