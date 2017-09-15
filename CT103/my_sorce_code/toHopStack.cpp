#include "astacklib.h"

int th(int k, int n) {
	Stack S;
	MakeNull_Stack(&S);
	
	if(k == 0 || k == n)
		return 1;
	
	int tmp1, tmp2;
	int tohop = 0;
	
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
			tohop += 1;
		else {
			Push(tmp2, &S);
			Push(tmp1, &S);
		}
	} while(!Empty_Stack(S));
	
	return tohop;
}

int main() {
	cout << th(2, 3);
	
	return 0;
}
