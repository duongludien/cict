/****************************
*	QuickSort Algorithm
*	Code by Lu-Dien Duong
*****************************/

#include <stdio.h>

void swap(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int FindPivot(int arr[], int i, int j) {
	int firstkey = arr[i];
	int k = i+1;
	while(k<=j && arr[k] == firstkey) {
		k++;
	}
	if(k>j)
		return -1;
	if(arr[k]<firstkey)
		return i;
	return k;
}

int Partition(int arr[], int i, int j, int pivot) {
	int L, R;
	L = i;
	R = j;
	
	while(L<R) {
		while(arr[L] < pivot) L++;
		while(arr[R] >= pivot) R--;
		if(L<R)
			swap(&arr[L], &arr[R]);
	}
	
	return L;
}

void QuickSort(int arr[], int i, int j) {
	int pivot, L;
	pivot = FindPivot(arr, i, j);
	if(pivot != -1) {
		L = Partition(arr, i, j, arr[pivot]);
		QuickSort(arr, i, L-1);
		QuickSort(arr, L, j);
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
	QuickSort(arr, 0, n-1);
	printf("\nResult: ");
	PrintList(arr, n);
	return 0;
}
