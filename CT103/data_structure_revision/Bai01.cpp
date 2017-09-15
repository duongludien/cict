#include "stdlib/alistlib.h"

//Cau a: Nhap phan tu vao danh sach theo thu tu da nhap

void ReadList1(List *L) {
	int n, tmp;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d", &tmp);
		Insert_List(tmp, EndList(*L), L);
	}
}

//Cau b: Nhap phan tu vao danh sach theo thu tu dao nguoc

void ReadList2(List *L) {
	int n, tmp;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d", &tmp);
		Insert_List(tmp, First(*L), L);
	}
}

//Cau c: Ham Print_List trong thu vien alistlib.h (./stdlib/alistlib.h)

int main() {
	freopen("Bai01_Data.txt", "rt", stdin);
	
	List L1, L2;
	MakeNull_List(&L1);
	MakeNull_List(&L2);
	
	ReadList1(&L1);
	cout << endl;
	Print_List(L1);
	
	ReadList2(&L2);
	cout << endl;
	Print_List(L2);
	
	return 0;
}
