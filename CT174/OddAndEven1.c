#include <stdio.h>

int isOdd(int);
int isEven(int);

int isOdd(int n) {
	if(n == 0) return 0;
	return isEven(n-1);
}

int isEven(int n) {
	return !isOdd(n);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("Odd: %d", isOdd(n));
	printf("\nEven: %d", isEven(n));
	return 0;
}
