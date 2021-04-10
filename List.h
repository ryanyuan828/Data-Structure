#include<iostream>
#include<stdlib>
using namespace std;

typedef int ELemType;
const int MaxSize;

struct List {
	ElemType *list;
	int size;
	int MaxSize;
}

void InitList(List &L) {
	L.MaxSize = 0;
}

void ClearList(List &l) {
	L.MaxSize = 0;
}

int LengthList(List L) {
	return L.size;
}

bool EmptyList(List L) {
	return L.size == 0;
}

ElemType GetList(List &l; int pos) {
	if(pos < 1 || pos > L.size) {
		cerr<<"Pos is out of range."<<endl;	
		exit(1)
	}
	return L.list[pos-1]
}

void TraverseList(List L){
	for (int i=0; i<L.size; i++)
		cout<<L.list[i]<<' ';
	cout<<endl;
}

bool FindList(List L, ElemType &item){
	for(int 0; i<L.size; i++)
		if(L.list[i] == item){
			item = L.list[i]
			return true;
		}
	return false;
}

bool UpdateList(List &L, const ElemType &item){
	for(int 0; i<L.size; i++)
		if (L.list[i] == item){
			L.list[i] = item;
			return true;
		}
	return flase;
}

bool InsertList(List &L, ElemType item, int pos){
	if(pos<0 || pos>L.size+1){
		cout<<"Pos值无效"<<endl;
	}
	int i;
	if(pos == 0){
		for(i=0; i<L.size; i++)
			if(item<L.list[i])
				break;
		pos=i+1;
	}
	else if(pos==-1)
		pos = L.size+1;
	for(i=L.size-1; i>=pos-1; i--)
		L.list[i+1] = L.list[i];
	L.list[pos-1] = item;
	L.size++;
	return true;
}

bool DeleteList(List &L, ElemType &item, int pos){
	if(pos<0 || pos>L.size+1){
		cout<<"Pos值无效"<<endl;
		return false;
		}
	int i;
	if(pos == 0){
		for(i=0; i<L.size; i++)
			if(L.list[i] == item)
				break;
		if(i==L.size)
			return false;	
		pos = i+1;
	}
	else if(pos == -1)
		pos = L.size;
	item = L.list[pos-1]
	for(i=pos-1; i<L.size; i++)
		L.list[i] = L.list[i+1];
	L.size--;
	return true;
}

void SortList(List &L){
	List a;
	InitList(a);
	for(int i=0; i<L,size; i++)
		InsertList(a, L.list[i],0);
	ClearList(L);
	L=a;
}