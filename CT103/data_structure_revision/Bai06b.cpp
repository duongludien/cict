#include "stdlib/plistlib.h" 

//Cau 6: Nhap cac phan tu va luu vao danh sach theo thu tu khong giam

void ReadOrderList(List *L) {
	MakeNull_List(L);
	int n;
	ElementType x;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d", &x);
		if(Empty_List(*L)) {
			Insert_List(x, First(*L), L);
			continue;
		}
		else {
			if(x < Retrieve(First(*L), *L)) {
				Insert_List(x, First(*L), L);
				continue;
			}
			if(x > Retrieve(Previous(EndList(*L), *L), *L)) {
				Insert_List(x, EndList(*L), L);
				continue;
			}
			Position p;
			p = First(*L);
			while(p->Next != NULL) {
				if(Retrieve(p, *L) <= x && x <= Retrieve(Next(p, *L), *L)) {
					Insert_List(x, Next(p, *L), L);
					continue;
				}
				p = Next(p, *L);
			}
		}
	}	
}

int main() {
	List L;
	
	freopen("Bai06_Data.txt", "rt", stdin);
	
	ReadOrderList(&L);
	cout << "\nYour list: ";
	Print_List(L);
	
	return 0;
}
