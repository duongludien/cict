#include <stdio.h>

#define MAX_ELEMENTS 100

typedef int ElementType;

typedef struct {
	int size;
	ElementType data[MAX_ELEMENTS];
} List;

/* Tao danh sach rong */
void make_null(List *L) {
	L->size = 0;
}

/* Kiem tra danh sach rong */
int empty_list(List L) {
	return L.size == 0;
}

/* Them mot phan tu vao cuoi danh sach */
void push_back(List *L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}

/* Lay phan tu tai vi tri i */
ElementType element_at(List L, int i) {
	return L.data[i-1];
}

/* Tra ve so phan tu cua danh sach */
int count_list(List L) {
	return L.size;
}

/* In cac phan tu cua danh sach */
void print_list(List L) {
	int i;
	
	if(empty_list(L)) {
		printf("Khong co!");
		return;
	}	
	for(i=0; i<L.size; i++) 
		printf("%d ", L.data[i]);
}
