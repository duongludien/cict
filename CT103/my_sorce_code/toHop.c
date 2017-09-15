#include <stdio.h>

int th(int k, int n) {
	if(k == 0 || k == n)
		return 1;
	return th(k-1, n-1) + th(k, n-1);
}

int main() {
	printf("%d", th(5, 10));
	
	return 0;
}
