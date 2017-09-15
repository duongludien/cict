#include <stdio.h>

void swap(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void MySort(int arr[], int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(arr[i] > arr[j]) 
				swap(&arr[i], &arr[j]);	
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
	MySort(arr, n);
	printf("\nResult: ");
	PrintList(arr, n);
	
	return 0;
}
