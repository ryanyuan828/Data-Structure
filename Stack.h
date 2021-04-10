#include<iostream>
using namespace std;
typedef int ElemType;

const int MaxSize = 10;

struct Stack{
    ElemType stack[MaxSize];
    int top;
};

void InitStack(Stack& S){
    S.top = -1;
}

void Push(Stack& S, ElemType item){
    S.top++;
    S.stack[S.top] = item;
}

ElemType Pop(Stack& S){
    if(S.top == -1){
        cerr<<"Stack is empty!"<<endl;
        exit(1);
    }
    S.top--;
    return S.stack[S.top+1];
}

ElemType Peek(Stack& S){
    if(S.top == -1){
        cerr<<"Stack is empty!"<<endl;
        exit(1);
    }
    return S.stack[S.top];
}

bool EmptyStack(Stack& S){
    return S.top == -1;
}

void ClearStack(Stack& S){
    S.top = -1;
    //S.MaxSize = 0;
}