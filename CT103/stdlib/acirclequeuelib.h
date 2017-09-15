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
	ElementType Elements[MaxLength];  //store elements of queue
	int Front, Rear;  //index of front and rear of queue 
} Queue;

// initialization of queue
void MakeNull_Queue(Queue *Q)
	{
		Q->Front=-1;
		Q->Rear=-1;
 	 } 
// Check queue ? empty or not
int Empty_Queue(Queue Q)
{	
		return (Q.Front ==-1);
}	

// check queue is full or not
int Full_Queue(Queue Q){
	 return (Q.Rear-Q.Front+1) % MaxLength==0;
} 

// return the first element of queue
ElementType Front(Queue Q){
 	if (Empty_Queue (Q))       
	 	printf ("Hang rong");
    else  
       return Q.Elements[Q.Front];
} 

// delete the first element of queue
void DeQueue(Queue *Q){
   if (!Empty_Queue(*Q)){
		if (Q->Front==Q->Rear) 
			MakeNull_Queue(Q);
		else 
			Q->Front=(Q->Front+1) % MaxLength;
  	}else 
	  	printf("Loi: Hang rong!");
 } 

// add value x to queue
void EnQueue(ElementType X,Queue *Q){
	if (!Full_Queue(*Q)){
		if (Empty_Queue(*Q)) 
			Q->Front=0;
		    Q->Rear=(Q->Rear+1) % MaxLength;
		    Q->Elements[Q->Rear]=X;
	 }else printf("Loi: Hang day!");
} 


