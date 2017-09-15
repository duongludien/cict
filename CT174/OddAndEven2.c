#include <stdio.h>

int isOdd(int);
int isEven(int);

int isOdd(int n) {
	if(n == 0) return 0;
	return isEven(n-1);
}

int isEven(int n) {
	if(n == 0) return 1;
	return isOdd(n-1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("Odd: %d", isOdd(n));
	printf("\nEven: %d", isEven(n));
	return 0;
}
