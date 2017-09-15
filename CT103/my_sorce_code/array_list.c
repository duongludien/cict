#include <stdio.h>

#define MAX 10
typedef int ElementType;
typedef int PositionType;

typedef struct {
	ElementType Elements[MAX];
	PositionType Last;
} List;

PositionType ENDLIST(List);
void INSERT_LIST(ElementType, PositionType, List*);
PositionType LOCATE(ElementType, List);
ElementType RETRIEVE(PositionType, List);
void DELETE_LIST(PositionType, List*);
PositionType NEXT(PositionType, List);
PositionType PREVIOUS(PositionType, List);
PositionType FIRST(List);
int EMPTY_LIST(List);
void MAKENULL_LIST(List*);
void sort(List*);
void INSERT_AFTER_SORTING(ElementType, List*);

int main(void) {
	List L;
	L.Last = 3;
	L.Elements[0] = 1;
	L.Elements[1] = 3;
	L.Elements[2] = 4;
	
	//sort(&L);
	INSERT_AFTER_SORTING(4, &L);
	
	printf("%d %d %d %d", L.Elements[0], L.Elements[1], L.Elements[2], L.Elements[3]);
	//printf("%d %d %d", L.Elements[0], L.Elements[1], L.Elements[2]);
		
	return 0;
}

PositionType ENDLIST(List L) {
	return L.Last + 1;
}

void INSERT_LIST(ElementType x, PositionType p, List *L) {
	int i;
	
	if(ENDLIST(*L) >= MAX) {
		printf("\nThe list was full. Can not insert!");
		return;
	}
	if(p < FIRST(*L) || p >= ENDLIST(*L)) {
		printf("\nThe position is not suitable. Can not insert!");
		return;
	}
	else {
		L->Last++;
		for(i=L->Last-1; i>p; i--) {
			L->Elements[i] = L->Elements[i-1];
		}
		L->Elements[p] = x;
	}
}

PositionType LOCATE(ElementType x, List L) {
	int i;
	for(i=0; i<L.Last; i++) {
		if(L.Elements[i] == x)
			return i;
	}
	return ENDLIST(L);
}

ElementType RETRIEVE(PositionType p, List L) {
	if(p < FIRST(L) || p >= ENDLIST(L)) {
		printf("\nThis position doesn't exist in list!");
		return '\0';
	}
	else {
		return L.Elements[p];
	}
}

void DELETE_LIST(PositionType p, List *L) {
	int i;
	
	if(p < FIRST(*L) || p >= ENDLIST(*L)) {
		//printf("\nThis position doesn't exist in list!");
		return;
	}
	else {
		L->Last--;
		for(i=p; i<L->Last; i++) {
			L->Elements[i] = L->Elements[i+1];
		}
	}
}

PositionType NEXT(PositionType p, List L) {
	if(p == L.Last-1) {
		return ENDLIST(L);
	} 
	else if(p < FIRST(L) || p >= ENDLIST(L)) {
		return '\0';
	}
	else {
		return p+1;
	}
}

PositionType PREVIOUS(PositionType p, List L) {
	if(p <= FIRST(L) || p >= ENDLIST(L)) {
		return '\0';
	} 
	else {
		return p-1;
	}
}

PositionType FIRST(List L) {
	if(L.Last == 0)
		return ENDLIST(L);
	return 0;
}

int EMPTY_LIST(List L) {
	if(L.Last == 0)
		return 1;
	return 0;	
}

void MAKENULL_LIST(List *L) {
	L->Last = 0;
}
/*
void sort(List *L) {
	PositionType i, j;
	for(i=0; i<L->Last; i++) {
		for(j=i+1; j<L->Last; j++) {
			if(L->Elements[i] > L.Elements[j]) {
				swap(L.Elements[i], L.Elements[j]);
			}
		}
	}
}
*/
void INSERT_AFTER_SORTING(ElementType x, List *L) {
	if(x < L->Elements[0]) {
		INSERT_LIST(x, 0, L);
	}
	else if(x > L->Elements[L->Last-1])
	{
		INSERT_LIST(x, L->Last, L);
	}
	else {
		PositionType i;
		for(i=0; i<L->Last; i++) {
			if(x >= L->Elements[i] && x <= L->Elements[i+1]) {
				INSERT_LIST(x, i+1, L);
				break;
			}
		}
	}
	
}
