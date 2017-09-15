#include "astacklib_fibonacci.h"

int fibonacci(int n) {
	Stack S;
	int tmp;
	int f = 0;
	
	MakeNull_Stack(&S);
	
	Push(n, &S);
	
	cout << "Push: " << n;
	
	do {
		tmp = Top(S);
		cout << "\nPop: " << tmp;
		Pop(&S);
		
		if(tmp < 2)
			f += tmp;
		else {
			Push(tmp-1, &S);
			Push(tmp-2, &S);
			cout << "\nPush: " << tmp-1 << " " << tmp-2;
		} 
	} while(!Empty_Stack(S));
	
	return f;
}

int main() {
	int fbnc = fibonacci(12);
	cout << "\nFibonacci(12) is " << fbnc;
}
