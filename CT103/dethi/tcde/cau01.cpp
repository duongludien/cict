#include "stdlib/plistlib.h"

void ReadList1(List *L) {
	ElementType e;
	int n;
	
	printf("\nEnter the number of elements: ");
	scanf("%d", &n);
	
	Position p = First(*L);
	
	for(int i=0; i<n; i++) {
		printf("\nEnter the element number %d: ", i+1);
		scanf("%d%d", &e.x, &e.y);
		Insert_List(e, p, L);
		p = Next(p, *L);
	}
}

int ElementCounter(List L) {
	int count = 0;
	Position p = First(L);
	
	while(p->Next != NULL) {
		count++;
		p = Next(p, L);
	}
	
	return count;
}

void InsertToEndList(ElementType x, List *L) {
	Insert_List(x, EndList(*L), L);
}

Position nthLocate(int n, List L) {
	if(n > ElementCounter(L))
		return NULL;
	
	Position p;
	int count = 0;
	p = First(L);
	
	while(p->Next != NULL && count < n) {
		count++;
		if(count == n) {
			return p;
		}
		p = Next(p, L);
	}
}

int Yequal2X(ElementType x) {
	return 2 * x.x == x.y;
}

void DeleteYequal2X(List *L) {
	Position p = First(*L);
	
	while(p->Next != NULL) {
		//cout << "<" << p->Element.x << ";" << p->Element.y << ">";
		
		if(Yequal2X(Retrieve(p, *L)))
			Delete_List(p, L);
		
		p = Next(p, *L);
	}
}

int main() {
	List L;
	MakeNull_List(&L);
	
	freopen("cau01_Data.txt", "rt", stdin);
	
	ReadList1(&L);
	cout << "\nYour list: ";
	Print_List(L);
	
	int count;
	
	count = ElementCounter(L);
	
	cout << "\nThere are " << count << " element(s) in this node";
	
	ElementType e;
	cout << "\nEnter the element that you want to insert: ";
	
	cin >> e.x;
	cin >> e.y;
	
	InsertToEndList(e, &L);
	
	cout << "\nYour list: ";
	Print_List(L);
	
	count = ElementCounter(L);
	/*
	//cout << "\nThere are " << count << " element(s) in this node";
	
	int n;
	cout << "\nEnter the number n: ";
	cin >> n;
	Position q = nthLocate(n, L);
	cout << "\nThe " << n << " element is " << "(" << q->Element.x << ";" << q->Element.y << ")";
	
	cout << "\nYour list before delete y = 2x: ";
	Print_List(L);
	DeleteYequal2X(&L);
	cout << "\nYour list after delete y = 2x: ";
	Print_List(L);
	*/
	return 0;
}
