#include "stdlib/alistlib.h"

void ReadList(List *L) {
	int n;
	ElementType tmp;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d", &tmp);
		Insert_List(tmp, EndList(*L), L);
	}
}

//Cau a: Sap xep cac phan tu (kieu int) trong danh sach dac, co 2 thuat toan

void sorting(List *L) {
	ElementType tmp;
	for(Position i=0; i<L->Last; i++) {
		for(Position j=i; j<L->Last; j++) {
			if(L->Elements[i] > L->Elements[j]) {
				tmp = L->Elements[i];
				L->Elements[i] = L->Elements[j];
				L->Elements[j] = tmp;
			}
		}
	}
}

void sorting2(List *L) {
	ElementType tmp;
	Position p, q;
	
	p = First(*L);
	while(p!=EndList(*L)) {
		q = Next(p, *L);
		while(q!=EndList(*L)) {
			if(Retrieve(p, *L) > Retrieve(q, *L)) {
				tmp = Retrieve(p, *L);
				L->Elements[p-1] = Retrieve(q, *L);
				L->Elements[q-1] = tmp;
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
	
	ReadList(&L);
	cout << "\nBefore: ";
	Print_List(L);
	//sorting(&L);
	sorting2(&L);
	cout << "\nAfter: ";
	Print_List(L);
	
	return 0;
}
