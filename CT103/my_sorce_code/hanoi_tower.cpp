#include "astacklib.h"

void move(ElementType X) {
	ElementType tmp, tmp1;
	Stack S;
	MakeNull_Stack(&S);
	
	Push(X, &S);
	
	do {
		tmp = Top(S);
		Pop(&S);
		
		if(tmp.N == 1)
			printf("\nChuyen dia tu %c sang %c", tmp.A, tmp.B);
		else {
			//Move(n-1, C, B, A)
			tmp1.N = tmp.N - 1;
			tmp1.A = tmp.C;
			tmp1.B = tmp.B;
			tmp1.C = tmp.A;
			Push(tmp1, &S);
			
			//Move(1, A, B, C)
			tmp1.N = 1;
			tmp1.A = tmp.A;
			tmp1.B = tmp.B;
			tmp1.C = tmp.C;
			Push(tmp1, &S);
			
			//Move(n-1, A, C, B)
			tmp1.N = tmp.N - 1;
			tmp1.A = tmp.A;
			tmp1.B = tmp.C;
			tmp1.C = tmp.B;
			Push(tmp1, &S);
		}
	} while(!Empty_Stack(S));
}

int main() {
	ElementType x;
	
	x.N = 3;
	x.A = 'A';
	x.B = 'B';
	x.C = 'C';
	
	move(x);
	
	return 0;
}
