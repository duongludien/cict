#include "astacklib.h"

int toHop(int k, int n) {
	if(k == 0 || k == n)
		return 1;
	
	Stack S;
	MakeNull_Stack(&S);
	int th = 0, tmp1, tmp2;
	
	Push(k-1, &S);
	Push(n-1, &S);
	Push(k, &S);
	Push(n-1, &S);
	
	do {
		tmp1 = Top(S);
		Pop(&S);
		tmp2 = Top(S);
		Pop(&S);
		
		if(tmp2 == 0 || tmp2 == tmp1)
			th += 1;
		else {
			Push(tmp2 - 1, &S);
			Push(tmp1 - 1, &S);
			Push(tmp2, &S);
			Push(tmp1 - 1, &S);
		}
	} while(!Empty_Stack(S));
		
	return th;
}

int main() {
	cout << toHop(5, 10);
	
	return 0;
}
