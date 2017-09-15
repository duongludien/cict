#include "astacklib_fibonacci.h"

int fibonacci(ElementType x) {
	ElementType tmp;
	Stack S;
	MakeNull_Stack(&S);
	
	Push(x, &S);
	
	do {
		tmp = Top(S);
		Pop(&S);
		
		if(tmp.n == 0)
			return 0;
		else if(tmp.n == 1)
			return 1;
		else {
			//Chèn vào Stack
		}
	} while(!Empty_Stack(S));
}

int main() {
	ElementType x;
	
	x.n = 4;
	x.fn = fibonacci(x);
	
	return 0;
}
