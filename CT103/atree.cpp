#include "stdlib/atreelib.h"
#include "stdlib/aqueuelib.h"

void ReadTree(Tree *T) {
	int n, i;
	
	MakeNull_Tree(T);
	
	cout << "\nEnter the number of Node: ";
	cin >> n;
	
	T->MaxNode = n;
	
	fflush(stdin);
	cout << "\nEnter the root's data: ";
	//scanf("%c", &(*T).Data[0]);
	T->Data[0] = getchar();
	T->Parent[0] = NIL;
	
	for(int i=1; i<n; i++) {
		fflush(stdin);
		cout << "\nEnter the data of Node " << i << ": ";
		//scanf("%c", &(*T).Data[i]);
		T->Data[i] = getchar();
		
		cout << "\nEnter the parent Node of Node " << i << ": ";
		scanf("%d", &(*T).Parent[i]);
	}
}

int leafCounter(TNode n, Tree T) {
	if(n == NIL)
		return 0;
	else {
		TNode i = LeftMostChild(n, T);
		if(i == NIL)
			return 1;
		else {
			int count = 0;
			while(i != NIL) {
				count += leafCounter(i, T);
				i = RightSibling(i, T);
			}
			return count;
		}
	}
}

void LevelOrder(TNode n, Tree T) {	
	if(n != NIL) {
		Queue Q;
		MakeNull_Queue(&Q);
		
		EnQueue(n, &Q);
		
		while(!Empty_Queue(Q)) {
			TNode i = Front(Q);
			printf("%c ", Label_Node(i, T));
			
			
		}
	}
}

int main() {
	int leaf_number;
	Tree T;
	
	ReadTree(&T);
	
	cout << "\nDuyet tien tu: ";
	PreOrder(0, T);
	
	cout << "\nDuyet trung tu: ";
	InOrder(0, T);
	
	cout << "\nDuyet hau tu: ";
	PostOrder(0, T);
	
	cout << "\nDuyet theo muc: ";
	LevelOrder(0, T);
	
	leaf_number = leafCounter(0, T);
	cout << "\nThe number of leaf is " << leaf_number;
	
	return 0;
}
