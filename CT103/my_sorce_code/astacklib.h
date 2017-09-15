#include <iostream>
#include <conio.h>
using namespace std;

#ifndef MaxLength
	#define MaxLength 500
#endif

#ifndef ElementType
	typedef int ElementType;  // define type of elements
#endif

typedef struct {
	ElementType Elements[MaxLength];  //store elements of list
	int  Top_idx; //store the top of stack
} Stack;

void MakeNull_Stack(Stack *S){
	  		S->Top_idx=MaxLength;
} 

int Empty_Stack(Stack S){ 
			return S.Top_idx==MaxLength; 
}

int Full_Stack(Stack S){	
		return S.Top_idx==0;
}

// Return the value of the top element = Retrieve(First(S),S)
ElementType Top(Stack S){
	if (!Empty_Stack(S))
		return S.Elements[S.Top_idx];
	else printf("Loi! Ngan xep rong");
} 

// Delete the top element   = Delete_List(First(S),S)
void Pop(Stack *S)
{
	if (!Empty_Stack(*S))
		S->Top_idx=S->Top_idx+1;
	else printf("Loi! Ngan xep rong!");
}

// Add value x to the top = Insert_List(x,First(S),S)
void Push(ElementType X, Stack *S){
	if (Full_Stack(*S))
		printf("Loi! Ngan xep day!");
	else{
		S->Top_idx=S->Top_idx-1;
		S->Elements[S->Top_idx]=X;
	}
}

void Print_Stack(Stack S){
	while (!Empty_Stack(S)){
		cout << Top(S) << "  ";
		Pop(&S);
	}
	cout<< endl;	
}
