#include <string.h>
#include "plistlib.h"

List nhapSoNguyen() {
	char n[50];
	List L;
	MakeNull_List(&L);
	
	printf("Nhap vao so nguyen: ");
	gets(n);
	for(int i=0; i<strlen(n); i++) 
		Insert_List(n[i]-48, First(L), &L);
	
	return L;
}

List congSoNguyen(List L1, List L2) {
	List L;
	MakeNull_List(&L);
	
	Position p1 = First(L1);
	Position p2 = First(L2);
	
	int tmp = 0;
	int n;
	
	while(p1->Next!=NULL || p2->Next!=NULL) {
		if(p1->Next!=NULL && p2->Next!=NULL)
			n = Retrieve(p1, L1) + Retrieve(p2, L2) + tmp;
		else if(p1->Next!=NULL && p2->Next==NULL) 
			n = Retrieve(p1, L1) + tmp;
		else if(p1->Next==NULL && p2->Next!=NULL)
			n = Retrieve(p2, L2) + tmp;
		
		if(n>9) {
			if(Next(Next(p1, L1), L1) == NULL && Next(Next(p2, L2), L2) == NULL) {
				Insert_List(n, First(L), &L);
				break;
			}
			else {
				Insert_List(n%10, First(L), &L);
				tmp = n/10;
			}
		}
		else {
			Insert_List(n, First(L), &L);
			tmp = 0;
		}
		
		p1 = Next(p1, L1);
		p2 = Next(p2, L2);
	}
	
	return L;
}

int main() {	
	List L1, L2, L;
	MakeNull_List(&L1);
	MakeNull_List(&L2);
	MakeNull_List(&L);
	
	L1 = nhapSoNguyen();
	L2 = nhapSoNguyen();
	
	L = congSoNguyen(L1, L2);
	
	printf("Tong la: ");
	Print_List(L);
	
	return 0;
}
