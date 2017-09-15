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

//Cau b: Sap xep cac phan tu (kieu int) trong danh sach lien ket

void sorting(List *L) {	
	Position p, q;
	ElementType tmp;
	
	p = First(*L);
	
	while(p->Next != NULL) {
		q = Next(p, *L);
		
		while(q->Next != NULL) {
			if(Retrieve(p, *L) > Retrieve(q, *L)) {
				tmp = Retrieve(p, *L);
				p->Next->Element = q->Next->Element;
				q->Next->Element = tmp;
			}
			q = Next(q, *L);
		}
		
		p = Next(p, *L);
	}
}

int main() {
	List L;
	MakeNull_List(&L);
	
	freopen("Bai03_Data.txt", "rt", stdin);
	
	ReadList1(&L);
	
	cout << "\nBefore: ";
	Print_List(L);
	
	sorting(&L);
	
	cout << "\nAfter: ";
	Print_List(L);
}
