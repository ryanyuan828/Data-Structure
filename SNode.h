#include <iostream>
using namespace std;
typedef int ElemType;

struct SNode{
	ElemType data;
	SNode* next;
};

void InitStack(SNode& *S){
	HS = NULL;
	for 
}

void ClearStack(SNode& *S){
	SNode* cp, *np;
	cp = HS;
	while(cp != NULL){
		np = cp->next;
		delete cp;
		cp = np;
	}
	HS = NULL;
}

ElemType Peek(SNode& S){
	if(HS == NULL){
		cerr<<"Linked stack is empty!"<<endl;
		exit(1);
	}
	return HS->data;
}

void Push(SNode& S, ELemType tiem){
	SNode* newptr = new SNode;
	newptr->data = item;
	newptr->next = HS;
	HS = newptr;
}

ElemType Pop(SNode& S){
	if(HS == NULL){
		cerr<<"Linked stack is empty!"<<endl;
		exit(1);
	}
	SNode* p = HS;
	HS = HS->next;
	ElemType temp = p->data;
	delete p;
	return temp;
}