#include "stdlib/alistlib.h" 

//Cau 4: Chen phan tu vao danh sach dac co thu tu

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

//Co 2 thuat toan chen phan tu vao danh sach dac co thu tu

void InsertToOrderList(ElementType x, List *L) {
	if(x < L->Elements[0]) {
		Insert_List(x, First(*L), L);
		return;
	}
	if(x > L->Elements[L->Last-1]) {
		Insert_List(x, EndList(*L), L);
		return;
	}
	
	for(Position i=0; i<L->Last; i++) {
		if(x > Retrieve(i+1, *L) && x < Retrieve(i+2, *L)) {
			Insert_List(x, i+2, L);
			return;
		}
	}
}

void InsertToOrderList2(ElementType x, List *L) {
	if(x < Retrieve(First(*L), *L)) {
		Insert_List(x, First(*L), L);
		return;
	}
	if(x > Retrieve(EndList(*L) - 1, *L)) {
		Insert_List(x, EndList(*L), L);
		return;
	}
	
	Position p;
	p = First(*L);
	while(p!=EndList(*L)) {
		if(x >= Retrieve(p, *L) && x <= Retrieve(p+1, *L)) {
			Insert_List(x, p+1, L);
			return;
		}
		p = Next(p, *L);
	}
}

int main() {
	List L;
	MakeNull_List(&L);
	
	freopen("Bai04_Data.txt", "rt", stdin);
	
	ReadList(&L);
	cout << "\nBefore: ";
	Print_List(L);
	sorting(&L);
	InsertToOrderList2(5, &L);
	cout << "\nAfter: ";
	Print_List(L);
	
	return 0;
}
