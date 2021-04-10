#include<iostream>
using namespace std;
typedef string ElemType;

const int MaxSize = 100;

struct Queue{
	ElemType queue[MaxSize];
	int front, rear, len;
};

void InitQueue(Queue& Q){
	Q.front = Q.rear = 0;
};

void EnQueue(Queue& Q, ElemType item){
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.queue[Q.rear] = item;
};

ElemType OutQueue(Queue& Q){
	if (Q.rear == Q.front){
		cerr<<"Queue is empty, can not read"<<endl;
		exit(1);
	}
	Q.front = (Q.front + 1) % MaxSize;
	return Q.queue[Q.front];
};

ElemType PeekQueue(Queue Q){
	if (Q.rear == Q.front){
		cerr<<"Queue is empty, can not read"<<endl;
		exit(1);
	}
	return Q.queue[(Q.front + 1) % MaxSize];
};

bool EmptyQueue(Queue Q){
	return Q.front == Q.rear;
};

void ClearQueue (Queue& Q){
	Q.front = Q.rear = 0;
	//Q.queue = NULL;
};