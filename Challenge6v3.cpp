#include"Stack.h"
#include"Queue.h"

bool Palindrome(){
    string Word;
    Queue QWord;
    Stack SWord;
    InitQueue(QWord);
    InitStack(SWord);
    cout<<"请输入一串字符(请以 @ 结尾)："<<endl; 
    cin>>Word;
    for(int i = 0; i < Word.length(); i++){
        if(Word[Word.length()-1] != '@') {
            cerr<<"请以 @ 结尾，再试一次"<<endl;
            exit(1);
        };
        if(QWord.front == (QWord.rear +1) % MaxSize){
            cerr<<"队已满！"<<endl;
            exit(1);
        }
        else
            EnQueue(QWord, Word[i]);
        if(SWord.top == MaxSize - 1){
            cerr<<"栈已满！"<<endl;
            exit(1);
        }
        else
            Push(SWord, Word[i]);
    }
    Pop(SWord);
    for(int i = 0; i < ((Word.length()-1)/2); i++){
        char QW = OutQueue(QWord);
        char SW = Pop(SWord);
        if(QW != SW){
            return false;
        }
    }
    return true;
};

int main(){
    while(1){
        if(Palindrome())
            cout<<"您输入的是回文"<<endl;
        else
            cout<<"您输入的不是回文"<<endl;
    }
}