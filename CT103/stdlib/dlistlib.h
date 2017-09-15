#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef int ElementType;  		// define type of elements in list
typedef struct Node{
	ElementType Element;  		//store the value of element
	Node *Previous; 			//point to the previous element of list	
	Node *Next; 				//point to the next element of list
}Node;
typedef Node* Position; 		// Position type
typedef Position DoubleList;

// List initialization
void MakeNull_List (DoubleList *DL){  
		(*DL)= NULL; 
} 


//Check list is empty or not
int Empty (DoubleList DL){ 
		return (DL==NULL); 
} 

// return the first position of list
Position First(DoubleList DL){
	return DL;
}

// return the lastest position of list
Position EndList(DoubleList DL){
	return NULL;
} 


// return the next position of position P
Position Next(Position P, DoubleList DL){
	return P->Next;
}

// return the next position of position P
Position Previous(Position P, DoubleList DL){
	return P->Previous;
}
// Return the value of elements[P] of list
ElementType Retrieve(Position p, DoubleList DL){
	return p->Element;
}


void Insert_List (ElementType X,Position p, DoubleList *DL){	
	
     if (*DL == NULL){	
	 		(*DL)=(Node*)malloc(sizeof(Node));
			(*DL)->Element = X;
			(*DL)->Previous =NULL;
     		(*DL)->Next =NULL;
  	} else{
          	if (p==EndList(*DL)){ // insert at the end of list
 				Position temp,R;
  				temp=(Node*)malloc(sizeof(Node));
  				temp->Element=X;
				temp->Next=NULL;
				R = *DL;
				// get previous of endlist
				while (R->Next!=EndList(*DL)){
					R = Next(R,*DL);
				}
				temp->Previous=R;
				R->Next = temp;
         		
			}else {
				Position temp;
  				temp=(Node*)malloc(sizeof(Node));
  				temp->Element=X;
				temp->Next=p;
				temp->Previous=p->Previous;
				if (p->Previous!=NULL) // check p is not header of list
					p->Previous->Next=temp;
				else
				   (*DL) = temp;
				p->Previous=temp;
			}
 	}
 } 
 
void Delete_List (Position p, DoubleList *DL) { 
   if (*DL == NULL) 
     printf("Danh sach rong");
   else{
     if (p==*DL) 
        //delete the first element then change content of DL
		 (*DL)=(*DL)->Next;
     else p->Previous->Next=p->Next;
     if (p->Next!=NULL) // check p is the last position of list
         p->Next->Previous=p->Previous;
     free(p);
	}
}

Position Locate(ElementType X, DoubleList DL){	
	Position P;
	int Found = 0;
	P = First(DL);
	while ((P != EndList(DL)) && (Found == 0))
		if (P->Element == X) Found = 1;
		else P = Next(P, DL);
	return P;
} 

void PrintList(DoubleList DL){
	Position P;
	P = First(DL);
	while (P != EndList(DL))
	{
		cout << Retrieve(P,DL) <<" ";
		P = Next(P, DL);
	}
	cout << "\n";
}

