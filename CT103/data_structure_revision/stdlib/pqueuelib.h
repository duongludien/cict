#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef int ElementType; 
typedef struct Node{
	ElementType Element;
	Node* Next;    
}Node;
typedef Node* Position;
typedef struct{
	Position Front, Rear;  
} Queue; 

// initialization of queue
void MakeNullQueue(Queue *Q){
   Position Header;
   Header=(Node*)malloc(sizeof(Node)); //C?p ph?t Header
   Header->Next=NULL;
   Q->Front=Header;
   Q->Rear=Header;
} 

// Check queue ? empty or not
int Empty_Queue(Queue Q){
		return (Q.Front==Q.Rear);
} 

// check queue is full or not
int Full_Queue(Queue Q){
	 return 1;
} 

// return the first element of queue
ElementType Front(Queue Q){
 	if (Empty_Queue (Q))       
	 	printf ("Hang rong");
    else  
       return (Q.Front)->Next->Element;
} 

// delete the first element of queue
void DeQueue(Queue *Q){
	if (!Empty_Queue(*Q)){
		Position Tempt;
		Tempt=Q->Front;
		Q->Front=Q->Front->Next;
		free(Tempt);
	}else 
		printf("Loi?: Hang rong");
 } 


// add value x to queue
void EnQueue(ElementType X, Queue *Q){ 
	 Q->Rear->Next=(Node*)malloc(sizeof(Node)); // th?m 1 Phan tu v?o sau Rear
	 Q->Rear=Q->Rear->Next;  // Tra Rear den phan tu moi
	 Q->Rear->Element=X; //Dat gia tri them vao cho Rear
	 Q->Rear->Next=NULL; // Gan Next cua Rear (o moi) toi Null
} 

