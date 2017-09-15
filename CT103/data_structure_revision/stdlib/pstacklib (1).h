/*#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>*/
#include "plistlib.h"
//using namespace std;

typedef List Stack;

void MakeNull_Stack(Stack *S){
	MakeNull_List(S);
}
int Empty_Stack(Stack S){ 
	return Empty_List(S);
}

void Push(ElementType X, Stack *S){
		Insert_List (X, First (*S), S);
}

void Pop (Stack *S){	
	Delete_List (First (*S), S);
}
ElementType Top (Stack S){	
	Retrieve(First (S), S);
}
void Print_Stack(Stack S){
	while (!Empty_Stack(S)){
		cout << Top(S) << "  ";
		Pop(&S);
	}
	cout<< endl;	
}

