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
int Full_Queue(Queue Q)
{	 
	return ((Q.Rear-Q.Front+1)==MaxLength);
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
		Q->Front=Q->Front+1;
	   	if (Q->Front>Q->Rear)              				
		   MakeNull_Queue(Q); //Dat lai hang rong
	}else printf("Loi: Hang rong!");
} 

// add value x to queue
void EnQueue(ElementType X,Queue *Q)
{	if (!Full_Queue(*Q)){ 
		if (Empty_Queue(*Q)) Q->Front=0;
	  	if (Q->Rear==MaxLength-1){
		  	//Di chuyen tinh tien ra truoc Front -1 vi tri
		  	for(int i=Q->Front;i<=Q->Rear;i++)
			 	Q->Elements[i-Q->Front]=Q->Elements[i];
			 //Xac dinh vi tri Rear moi
		 	Q->Rear=MaxLength - Q->Front-1;
		  	Q->Front=0;
		 }
		//Tang Rear de luu noi dung moi
		Q->Rear=Q->Rear+1;
		Q->Elements[Q->Rear]=X;
	}
	else printf("Loi: Hang day!");
} 

void Print_Queue(Queue Q){
	while (!Empty_Queue(Q)){
		cout << Front(Q) << "  ";
		DeQueue(&Q);
	}
	cout<< endl;
}

