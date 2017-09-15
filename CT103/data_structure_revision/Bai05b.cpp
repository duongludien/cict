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

void DeleteAnElement(ElementType x, List *L) {
	Position p;
	p = First(*L);
	while(p->Next != NULL) {
		if(Retrieve(p, *L) == x)
			Delete_List(p, L);
		p = Next(p, *L);
	}
}

int main() {
	List L;
	ElementType x;
	MakeNull_List(&L);
	
	freopen("Bai05_Data.txt", "rt", stdin);
	
	ReadList1(&L);
	
	cout << "\nBefore: ";
	Print_List(L);
	
	cout << "\nEnter the element that you want to delete: ";
	cin >> x;
	DeleteAnElement(x, &L);
	
	cout << "\nAfter: ";
	Print_List(L);
}
