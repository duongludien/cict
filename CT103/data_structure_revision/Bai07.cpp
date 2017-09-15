#include "stdlib/plistlib.h"

void ReadList1(List *L) {
	int n, tmp;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	
	Position p = First(*L);
	
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d", &tmp);
		Insert_List(tmp, p, L);
		p = Next(p, *L);
	}
}

void DeleteDuplicate(List *L) {
	Position p, q;
	
	p = First(*L);
	
	while(p->Next != NULL) {
		q = Next(p, *L);
		while(q->Next != NULL) {
			if(Retrieve(q, *L) == Retrieve(p, *L))
				Delete_List(q->Next, L);
			q = Next(q, *L);
		}
		p = Next(p, *L);
	}
}

int main() {
	List L;
	MakeNull_List(&L);
	
	freopen("Bai07_Data.txt", "rt", stdin);
	
	ReadList1(&L);
	
	cout << "\nBefore: ";
	Print_List(L);
	
	DeleteDuplicate(&L);
	
	cout << "\nAfter: ";
	Print_List(L);
}
