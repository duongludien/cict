/****************************
*	HeapSort Algorithm
*	Code by Lu-Dien Duong
*****************************/

#include <stdio.h>

void swap(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void PushDown(int arr[], int first, int last) {
	int r = first;
	while(r <= (last-1)/2)
		//Truong hop a[r] chi co mot con trai
		if(last == 2*r+1) {
			if(arr[r] > arr[last])
				swap(&arr[r], &arr[last]);
			r = last;
		}
		//Truong hop a[r] > con trai && con trai < con phai
		else if(arr[r] > arr[2*r+1] && arr[2*r+1] < arr[2*r+2])	{
			swap(&arr[r], &arr[2*r+1]);
			r = 2*r+1;
		}
		//Truong hop a[r] > con phai && con phai < con trai
		else if(arr[r] > arr[2*r+2] && arr[2*r+2] < arr[2*r+1]) {
			swap(&arr[r], &arr[2*r+2]);
			r = 2*r+2;
		}
		else
			r = last;
}

void HeapSort(int arr[], int n) {
	int i;
	for(i=(n-2)/2; i>=0; i--)
		PushDown(arr, i, n-1);
	for(i=n-1; i>=2; i--) {
		swap(&arr[0], &arr[i]);
		PushDown(arr, 0, i-1);
	}
	swap(&arr[0], &arr[1]);
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
	HeapSort(arr, n);
	printf("\nResult: ");
	PrintList(arr, n);
	return 0;
}
