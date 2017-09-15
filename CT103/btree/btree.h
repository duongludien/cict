#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef int DataType;
typedef struct TNode {
	DataType Data;
	TNode* Left;
	TNode* Right;
	TNode* Parent;
} TNode;

typedef TNode* Tree;

void MakeNull_Tree(Tree *T) {
	(*T) = NULL;
}

int Empty_Tree(Tree T) {
	return T == NULL;
}

TNode* LeftChild(Tree T) {
	if(T!=NULL) 
		return T->Left;
	return NULL;
}

TNode* RightChild(Tree T) {
	if(T!=NULL) 
		return T->Right;
	return NULL;
}

Tree CreateTree(DataType v, Tree T1, Tree T2) {
	TNode* T;
	T = (TNode*)malloc(sizeof(TNode));
	T->Data = v;
	T->Left = T1;
	T->Right = T2;
	T->Parent = NULL;
	if(T1!=NULL) 
		T1->Parent = T;
	if(T2!=NULL)
		T2->Parent = T;
	return T;
}

TNode* Parent(TNode* n) {
	return n->Parent;
}

bool isAncestor(TNode *n, TNode *m) {
	TNode* i;
	//bool found = false;
	i = m;
	while(i != NULL /*&& !found*/) {
		if(Parent(i) == n)
			//found = true;
			return true;
		i = Parent(i);
	}
	//return found;
	return false;
}
/*
int OneChildCounter(Tree T) {
	if((LeftChild(T) != NULL && RightChild(T) != NULL) || Empty_Tree(T))
		return 0;
	if(LeftChild(T) != NULL)
		return 1 + OneChildCounter(LeftChild(T));
	if(RightChild(T))
		return 1 + OneChildCounter(RightChild(T));
}
*/
