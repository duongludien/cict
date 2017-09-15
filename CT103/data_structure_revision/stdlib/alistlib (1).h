#include <iostream>
#include <conio.h>
using namespace std;

#define MaxLength 255
typedef int ElementType;  // define type of elements in list
typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];  //store elements of list
	Position Last; //store the current length of list
} List;

// List initialization
void MakeNull_List(List *L) { 
	L->Last=0; 
}

//Check list is empty or not
int Empty_List(List L){
	return L.Last==0;
}

// Check l? is full or not?
int Full_List(List L)
	{
			return L.Last==MaxLength;
	} 

// return the first position of list
Position First(List L){
	return 1;
}

// return the lastest position of list
Position EndList(List L){
	return L.Last+1;
}


// return the next position of position P
Position Next(Position P, List L){
	if (P<1 || P>L.Last){
		cout << "The position " << P << " is out of list";
		return -1;
	}
	return P+1;
}

// Return the value of elements[P] of list
ElementType Retrieve(Position P,List L){
	if (P<1 || P>L.Last){
		cout << "The position " << P << " is out of list";
		return -1;
	}
	return L.Elements[P-1];
}

void Insert_List(ElementType X, Position P, List *L){
	if (L->Last==MaxLength)
		cout << "List is full";
	else if ((P<1) || (P>L->Last+1))
		cout << "The position " << P << " is illegal";
	else{
		Position Q;	
		for(Q=(L->Last-1)+1;Q>P-1;Q--)
			L->Elements[Q]=L->Elements[Q-1];	
		
		L->Elements[P-1]=X;
		L->Last++;
	}
}

void Delete_List(Position P,List *L){
	if ((P<1) || (P>L->Last))
		cout << "The position " << P << " is illegal";
	else if (Empty_List(*L))
		cout << "List is empty";
	else{
		Position Q;
		for(Q=P-1;Q<L->Last-1;Q++)
		L->Elements[Q]=L->Elements[Q+1];
		
		L->Last--;
	}
}

Position Locate(ElementType X, List L){
  Position P;
	int Found = 0;
	P = First(L); 
	while ((P != EndList(L)) && (Found == 0))
		if (Retrieve(P,L) == X) Found = 1;
		else P = Next(P, L);
	return P;
} 

void Print_List(List L){
	Position P= First(L);
	while (P != EndList(L)){
		cout << Retrieve(P,L) << " ";
		//cout <<"vi tri p:"<<P<<" co gia tri:" << Retrieve(P,L) << endl;
		P=Next(P,L);
	}
	cout<< "\n";
	
}
