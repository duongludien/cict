#include "stdlib/alistlib.h" 

//Cau 5: Tim kiem va xoa mot phan tu trong danh sach

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

void DeleteAnElement(ElementType x, List *L) {
	Position p;
	
	p = First(*L);
	
	while(p != EndList(*L)) {
		if(Retrieve(p, *L) == x) {
			Delete_List(p, L);
			break;
		}
		p = Next(p, *L);
	}
}

int main() {
	List L;
	MakeNull_List(&L);
	ElementType x;
	
	freopen("Bai05_Data.txt", "rt", stdin);
	
	ReadList(&L);
	cout << "\nEnter the element that you want to delete: ";
	cin >> x;
	cout << "\nBefore: ";
	Print_List(L);
	DeleteAnElement(x, &L);
	cout << "\nAfter: ";
	Print_List(L);
	
	return 0;
}
