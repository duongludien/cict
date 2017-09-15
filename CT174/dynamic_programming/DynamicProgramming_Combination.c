#include <stdio.h>

int Combination(int n, int k) {
	int p1, p2, i, j;
	int v[10];
	
	v[0] = v[1] = 1;
	for(i=2; i<=n; i++) {
		p1 = v[0];
		v[0] = 1;
		for(j=1; j<=i-1; j++) {
			p2 = v[j];
			v[j] = p1+p2;
			p1 = p2;
		}
		v[i] = 1;
	}
	
	return v[k];
}

int main() {
	printf("Combination(4, 3) = %d", Combination(4, 3));
	return 0;
}
