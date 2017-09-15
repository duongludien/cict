#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define MAXLENGTH 500
#define NIL -1

typedef char DataType;
typedef int Node;
typedef struct {
   DataType Data[MAXLENGTH];  
   Node Parent[MAXLENGTH];
   int MaxNode; 
} Tree; 

void MakeNull_Tree (Tree *T) {
	(*T).MaxNode=0; 
}

int EmptyTree(Tree T) {
    return T.MaxNode == 0;
}

Node Parent(Node n, Tree T) {
	if(EmptyTree(T)||(n>T.MaxNode-1))
     		return NIL;
	else return T.Parent[n];
} 


DataType Label_Node(Node n,Tree T) { 
	 if(!EmptyTree(T)&&(n<=T.MaxNode-1))
         return T.Data[n];
}

Node Root(Tree T) {
  if (!EmptyTree(T)) return 0;
  else return NIL;
}

Node LeftMostChild(Node n, Tree T) {
   Node i; int found;
   if (n<0) return NIL;
   i=n+1; found=0;
   while ((i<=T.MaxNode-1) && !found) 
          if (T.Parent[i]==n) found=1; 
          else i=i+1;
   if (found) return i;
   else return NIL;
}  
	   
Node RightSibling(Node n,Tree T) {
      Node i,parent;  int found;
	  if (n<0) return NIL;
	  parent=T.Parent[n];
	  i=n+1; found=0;
      while ((i<=T.MaxNode-1) && !found)
           if (T.Parent[i]==parent) found=1;
           else i=i+1;
      if (found) return i; 
      else return NIL;
}

void PreOrder(Node n,Tree T) {
  if (n != NIL) {
    Node i;
    printf("%c ", Label_Node(n,T));
    i=LeftMostChild(n,T);
    while (i!=NIL) {
       PreOrder(i,T);
       i=RightSibling(i,T);
    }
  }
} 

void InOrder(Node n, Tree T) {
   if (n!= NIL) {
      Node i;
      i=LeftMostChild(n, T);
      if (i!=NIL) InOrder(i,T);
      printf("%c ",Label_Node(n,T));
      i=RightSibling(i,T);
      while (i!=NIL) {
         InOrder(i,T);
         i=RightSibling(i,T);
      }
   }
}  


void PostOrder(Node n,Tree T) {
  if (n!=NIL) {
    Node i;
    i=LeftMostChild(n,T);
    while (i!=NIL) {
      PostOrder(i,T);
      i=RightSibling(i,T);
    }
    printf("%c ",Label_Node(n,T));
  }
}
