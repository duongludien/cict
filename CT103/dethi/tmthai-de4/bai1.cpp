#include "alistlib.h"

void ReadList(List *L) {
	int n, i;
	ElementType tmp;
	
	printf("\nNhap vao so phan tu cua danh sach: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		printf("\nNhap vao phan tu thu %d: ", i+1);
		scanf("%d", &tmp);
		Insert_List(tmp, EndList(*L), L);
	}
}

void SortList(List *L) {
	Position p = First(*L);
	while(p != EndList(*L)) {
		Position q = Next(p, *L);
		while(q != EndList(*L)) {
			if(Retrieve(p, *L) < Retrieve(q, *L)) {
				ElementType tmp;
				tmp = Retrieve(p, *L);
				L->Elements[p-1] = L->Elements[q-1];
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
	
	ReadList(&L);
	printf("\nBefore: ");
	Print_List(L);
	SortList(&L);
	printf("\nAfter: ");
	Print_List(L);
	
	return 0;
}
