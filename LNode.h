#include<iostream>
using namespace std;
typedef int ElemType;

struct LNode{
	ElemType data;
	LNode* next;
};

void InitList (LNode* &HL){
	HL = NULL;
};

void ClearList (LNode* &HL){
	LNode* cp;
	LNode* np;
	cp = HL;
	while (cp != NULL){
		np = cp->next;
		delete cp;
		cp = np;
	}
	HL = NULL;
};

int LengthList (LNode* HL){
	int i = 0;
	while (HL != NULL){
		i++;
		HL = HL->next;
	}
	return i;
};

bool EmptyList(LNode* HL){
	return HL == NULL;
};

ElemType GetList (LNode* HL, int pos){
	if (pos < 1){
		cerr<<"Pos is out of range."<<endl;
		exit(1);
	}
	int i = 0;
	while (HL != NULL){
		i++;
		if(i == pos) break;
		HL = HL->next;
	}
	if (HL != NULL)
		return HL->data;
	else{
		cerr<<"Pos is out of range."<<endl;
		exit(1);
	}
};

void TraverseList (LNode* HL){
	while(HL != NULL){
		cout<<HL->data<<" ";
		HL = HL->next;
	}
	cout<<endl;
};

bool FindList (LNode* HL, ElemType& item){
	LNode* cp;
	for (cp = HL; cp != NULL; cp = cp->next){
		if (HL->data == item){
			item = HL->data;
			return true;
		}
		else 
			HL = HL->next;
	}
	return false;
};

bool UpdateList(LNode* HL, const ElemType &item){
	LNode* cp;
	for (cp = HL; cp != NULL; cp = cp->next){
		if (HL->data == item){
			HL->data = item;
			return true;
		}
		else HL = HL->next;
	}
	return false;
};

bool InsertList(LNode* &HL, ElemType item, int pos){
	if (pos < -1){
		cout<<"Pos is invalid."<<endl;
	}
	LNode* newptr = new LNode;
	newptr->data = item;
	LNode* cp = HL;
	LNode* ap = NULL;
	if (pos == 0){
		while(cp != NULL){
			if (item < cp->data)
				break;
			else{
				ap = cp;
				cp = cp->next;
			}
		}	
	}
	else if (pos == -1)
		while(cp != NULL){
			ap = cp;
			cp = cp->next;
		}
	else{
		int i = 0;
		while(cp != NULL){
			i++;
			if (i == pos) break;
			else{
				ap = cp;
				cp = cp->next;
			}
		}
		if (cp == NULL && i + 1 < pos){
			cout<<"Pos is longer than length+1"<<endl;
			return false;
		}
	}
	if(ap == NULL){
		newptr->next = HL;
		HL = newptr;
	}
	else
	{
		newptr->next = cp;
		ap->next = newptr;
	}
	return true;
};

bool DeleteList (LNode* &HL, ElemType& item, int pos){
	if (HL == NULL){
		cerr<<"ListNode is blank, operation is invalid."<<endl;
		return false;
	}
	if(pos < -1){
		cout<<"Pos is invalid."<<endl;
		return false;
	}
	LNode* cp = HL;
	LNode* ap = NULL;
	if (pos == 0){
		for(cp = HL; cp != NULL; ap = cp, cp = cp->next)
			if (item == cp->data) break;
		if(cp == NULL){
		cout<<"No node can be deleted."<<endl;
		return false;
		}
	}
	else if (pos == -1)
		for(cp = HL; cp != NULL; ap = cp, cp = cp->next)
			;
	else {
		int i = 0;
		for(cp = HL; cp != NULL; ap = cp, cp = cp->next){
			i++;
			if (i == pos) break;
		}
		if (cp == NULL){
			cout<<"Pos is invalid"<<endl;
		}
	}
	if (ap == NULL)
		HL = HL->next;
	else
		ap->next = cp->next;
	delete cp;
	return true;
};

void SortList (LNode* &HL){
	LNode* SL;
	InitList (SL);
	LNode* r = HL;
	while(r != NULL){
		LNode* t = r->next;
		LNode* cp = SL;
		LNode* ap = NULL;
		while(cp != NULL){
			if(r->data < cp->data)
				break;
			else{
				ap = cp;
				cp = cp->next;
			}
		}
		if(ap == NULL){
			r->next = SL;
			SL = r;
		}
		else{
			r->next = cp;
			ap->next = r;
		}
		r = t;
	}
	HL = SL;
};