#include <stdio.h>

#define MaxLength 9

typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int TopIndex;
} Stack;

void MAKENULL_STACK(Stack *S) {
	S->TopIndex = MaxLength;
}

int EMPTY_STACK(Stack S) {
	return S.TopIndex == MaxLength;
}

int FULL_STACK(Stack S) {
	return S.TopIndex == 0;
}

int TOP(Stack S, ElementType *x) {
	if(!EMPTY_STACK) {
		*x = S.Elements[S.TopIndex];
		return 0;						//No error
	}
	printf("This stack is empty!");
	return 1;							//Error: Empty stack
}

void POP(Stack *S) {
	if(!EMPTY_STACK(*S)) {
		S->TopIndex = S->TopIndex + 1;
	}
	else {
		printf("This stack is empty!");
	}
}

void PUSH(ElementType x, Stack *S) {
	if(!FULL_STACK(*S)) {
		S->TopIndex = S->TopIndex - 1;
		S->Elements[S->TopIndex] = x;
	}
	else {
		printf("This stack is full!");
	}
}

int main(void) {
	Stack S;
	int i;
	
	MAKENULL_STACK(&S);
	
	PUSH(5, &S);
	
	if(!TOP(S, &i)) {
		printf("\n%d", i);
	}
	
	return 0;
}
