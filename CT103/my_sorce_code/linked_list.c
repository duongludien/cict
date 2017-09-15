#include <stdio.h>
#include <malloc.h>

/* ===== Declaration ===== */

typedef int ElementType;
struct Node {
    ElementType Element;
	struct Node *Next;
};
typedef struct Node* NodePtr;
typedef struct Node* Position;
typedef Position List;

/* ===== End of declaration ===== */

/* ===== Functions ===== */

void MakeNull_List(List *L) {
	*L = (struct Node*)malloc(sizeof(struct Node));
	(*L)->Next = '\0';
}

int Empty_List(List L) {
	return (L->Next == '\0');
}

void Insert_List(ElementType x, Position p, List *L) {
	Position tmp;
	tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->Element = x;
	tmp->Next = p->Next;
	p->Next = tmp;
}

Position Endlist(List L) {
	
}

/* ===== End of functions ===== */

int main(void) {
	List L;
	MakeNull_List(&L);
	Insert_List(5, L, &L);
	if(Empty_List(L)) {
		printf("Danh sach rong!");
	}
	
	return 0;
}
