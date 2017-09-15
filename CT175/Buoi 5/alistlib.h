#define MAX_ELEMENTS 500

typedef int ElementType;

typedef struct {
	int size;
	ElementType elements[MAX_ELEMENTS];
} List;

void make_null(List *L) {
	L->size = 0;
}

void push_back(List *L, ElementType x) {
	L->elements[L->size] = x;
	L->size++;
}

ElementType element_at(List L, int i) {
	return L.elements[i-1];
}

void copy(List *L1, List L2) {
	int i;
	
	make_null(L1);
	for(i=1; i<=L2.size; i++) 
		push_back(L1, element_at(L2, i));
}
