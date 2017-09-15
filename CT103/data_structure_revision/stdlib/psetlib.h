#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#ifndef ElementType
	typedef int ElementType;  // define type of elements
#endif

typedef struct Node {
	ElementType Element;  		//store the value of element
	Node* Next; 				//point to the next element of list
}Node;
typedef Node* Position; 		// Position type
typedef Position Set;



// set initialization
void MakeNullSet(Set *Header){
	(*Header)=(Node*) malloc(sizeof(Node));
	(*Header)->Next= NULL;
}

//Check list is empty or not
int EmptySet(Set L){
	return (L->Next==NULL);
}
// return the first position of list
Position First(Set L){
	return L;
}

// return the lastest position of list
Position EndSet(Set L){
	Position P;
	P=First(L);
	while (P->Next!=NULL) P=P->Next;
	return P;
} 
// return the next position of position P
Position Next(Position P, Set L){
	return P->Next;
}

// Return the value of elements[P] of list
ElementType Retrieve(Position P, Set L){
	if (P->Next!=NULL)
		return P->Next->Element;
}

void InsertSet(ElementType X, Set *L){  
		Position T,P;
	   	int  finish=0;
		P=First(*L);
		while ((P->Next!=NULL)&&(finish==0))
		 	if (P->Next->Element<=X)
		    		P=P->Next;
		  	else  finish=1;
	        // P dang luu tru vi tri de xen phan tu X vao
		T=(Node*)malloc(sizeof(Node));
		T->Element=X;
		T->Next=P->Next;
		P->Next=T;
} 


void DeleteSet(ElementType X, Set *L){
		Position T,P=*L;
	       int  finish=0;
		while ((P->Next!=NULL)&& (finish==0))
			if  (P->Next->Element<X) P=P->Next;
			else finish=1;
		if ((finish==1) && (P->Next->Element==X)){  // t?m th?y x
			T=P->Next;
			P->Next=T->Next;
			 free(T);
		}
	} 

int Member(ElementType X, Set L){
	Position P;
	int Found = 0;
	P = First(L);
	while ((P != EndSet(L)) && (Found == 0))
		if (Retrieve(P,L) >= X) Found = 1;
		else P = Next(P, L);
	if (Found==1 && Retrieve(P,L)==X ) //tim th?y X
  			return 1;
  	else return 0;		
}

void Print_Set(Set L){
	Position P;
	P = First(L);
	while (P != EndSet(L))
	{
		cout << Retrieve(P,L) <<" ";
		P = Next(P, L);
	}
	cout << "\n";
}

Position Previous(Position P, Set L){
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

void UnionSet(Set A, Set B, Set *C){ 	
	Position p;
  	MakeNullSet(C);
  	p=First(A);
  	while (p!=EndSet(A)){ 
		InsertSet(Retrieve(p,A),C);
      	 p=Next(p,A);
    	 }
  	p=First(B);
 	 while (p!=EndSet (B)){ 
		if (Member(Retrieve(p,B),*C)==0) // p khong thuoc C
         	   	InsertSet (Retrieve(p,B), C);
	 	 p=Next(p,B);
	 }
} 

void IntersectionSet(Set A, Set B, Set *C){
	  	Position p;
	  	MakeNullSet(C);
	  	p=First(A);
	  	while (p!=EndSet(A)){
			if (Member(Retrieve(p,A),B)==1)  
	       			InsertSet (Retrieve(p,A),C);
	      		p=Next(p,A);
	 	 }
}

void DefferentSet(Set A, Set B, Set *C){
	  	Position p;
	  	MakeNullSet(C);
	  	p=First(A);
	  	while (p!=EndSet(A)){
			if (Member(Retrieve(p,A),B)!=1)  
	       			InsertSet(Retrieve(p,A),C);
	      		p=Next(p,A);
	 	 }
}

