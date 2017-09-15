#include "btree.h"

int main() {
	Tree T1, T2, T3, T4, T5, T6;	
	T1 = CreateTree(8, NULL, NULL);
	T2 = CreateTree(9, NULL, NULL);
	T3 = CreateTree(10, NULL, NULL);
	T4 = CreateTree(11, NULL, NULL);
	T5 = CreateTree(6, T1, T2);
	T6 = CreateTree(7, T3, T4);
	
	Tree T;	
	T = CreateTree(5, T5, T6);
	
	printf("%d %d %d", T->Data, T->Left->Data, T->Right->Data);
	cout << endl;
	TNode* n = Parent(T1);
	printf("%d", n->Data);
	
	if(isAncestor(T, T1))
		printf("\nYes");
	else
		printf("\nNo");
		
	//printf("\nThere are (is) %d node(s)", OneChildCounter(T));
	
	return 0;
}
