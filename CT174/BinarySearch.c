/*************************************************
* Program:		Binary searching algorithm
* Description:	Search an item in an orderly array
* Language:		C
* Author:		Lu-Dien Duong
**************************************************/

#include <stdio.h>

//Recursive function using size of array
int binarySearch1(int x, int *a, int n) {
	if(n == 0)
		return 0;
	if(*(a+n/2) == x)
		return 1;
	else
		if(x < *(a+n/2))
			return binarySearch1(x, a, n/2);
		else 
			if(n % 2 == 0)
				return binarySearch1(x, a+n/2+1, n/2-1);
			else
				return binarySearch1(x, a+n/2+1, n/2);
}

//Recursive function using position left (L) and right(R) 
int binarySearch2(int x, int a[], int L, int R) {
	if(L>R)
		return 0;
	int M = (L+R) / 2;
	if(a[M] == x)
		return 1;
	if(x < a[M])
		return binarySearch2(x, a, L, M-1);
	return binarySearch2(x, a, M+1, R);
}

//Non-recursive function
int binarySearch3(int x, int a[], int n) {
	int L = 0, R = n-1, M;
	while(L<=R) {
		M = (L+R) / 2;
		if(a[M] == x)
			return 1;
		if(x < a[M])
			R = M-1;
		else
			L = M+1;
	}
	return 0;
}

int main() {
	int n = 7;
	int a[] = {1, 3, 4, 5, 10, 25, 40};

	int x;	
	printf("Nhap x: ");
	scanf("%d", &x);
		
	if(binarySearch3(x, a, n))
		printf("Tim thay!");
	else
		printf("Khong tim thay!");
		
	return 0;
}
