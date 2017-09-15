#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node {
	DataType data;
	struct Node *Next;
} Node;
typedef Node* Position;
typedef Position List;

void MakeNull_List(List *L) {
	*L = (Node*)malloc(sizeof(Node));
	(*L)->Next = '\0';
}

int Empty_List(List L) {
	return (L->Next == '\0');
}

void Insert_List(DataType x, Position p, List *L) {
	Position tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->data = x;
	tmp->Next = p->Next;
	p->Next = tmp;
}

int main() {
	List L;
	
	MakeNull_List(&L);
	Insert_List(5, L->Next, &L);
	if(Empty_List(L)) {
		printf("Empty!");
	}
	
	return 0;
}
