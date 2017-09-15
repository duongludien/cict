#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// #define MaxLength 255
typedef int ElementType;  		// define type of elements in list 
typedef struct Node {
	ElementType Element;  		//store the value of element
	Node* Next; 				//point to the next element of list
} Node;
typedef Node* Position; 		// Position type
typedef Position List;

// List initialization
void MakeNull_List(List *Header){
	(*Header)=(Node*) malloc(sizeof(Node));
	(*Header)->Next= NULL;
}

//Check list is empty or not
int Empty_List(List L){
	return (L->Next==NULL);
}
// return the first position of list
Position First(List L){
	return L;
}

// return the lastest position of list
Position EndList(List L){
	Position P;
	P=First(L);
	while (P->Next!=NULL) P=P->Next;
	return P;
} 


// return the next position of position P
Position Next(Position P, List L){
	return P->Next;
}

// Return the value of elements[P] of list
ElementType Retrieve(Position P, List L){
	if (P->Next!=NULL)
		return P->Next->Element;
}

void Insert_List(ElementType X, Position P, List *L){
	Position T;
	T=(Node*)malloc(sizeof(Node));
	T->Element=X;
	T->Next=P->Next;
	P->Next=T;
}

void Delete_List(Position P, List *L){ 
	Position Temp;
	if (P->Next!=NULL){  
		Temp=P->Next; 
		P->Next=Temp->Next; 
		free(Temp);
	  }
} 


Position Locate(ElementType X, List L){	
	Position P;
	int Found = 0;
	P = First(L);
	while ((Next(P,L) != NULL) && (Found == 0))
		if (Retrieve(P,L) == X) Found = 1;
		else P = Next(P,L);
	return P;
} 

void Print_List(List L){
	Position P;
	P = First(L);
	while (P != EndList(L))
	{
		cout << Retrieve(P,L) <<" ";
		P = Next(P, L);
	}
	cout << "\n";
}

Position Previous(Position P, List L){
	Position Q;
	
	if (P==First(L)) return NULL;
	
	Q= First(L);
	while (Next(Q,L)!= NULL)
		if (Next(Q,L) == P) 
		   return Q;
		else 
		   Q = Next(Q,L); 	  
	return NULL;
}


