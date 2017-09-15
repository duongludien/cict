#include "stdlib/alistlib.h"

void ReadOrderList(List *L) {
	MakeNull_List(L);
	int n;
	ElementType x;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d", &x);
		if(Empty_List(*L))
			Insert_List(x, 1, L);
		else {
			if(x < Retrieve(1, *L)) {
				Insert_List(x, 1, L);
				continue;
			}
			if(x > Retrieve(EndList(*L), *L)) {
				Insert_List(x, EndList(*L), L);
				continue;
			}
			for(int j=0; j<L->Last; j++) {
				if(Retrieve(j, *L) <= x && x <= Retrieve(j+1, *L)) {
					Insert_List(x, j+1, L);
					continue;
				}
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
