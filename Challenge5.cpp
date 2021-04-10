#include"Queue.h"
#include<cstring>
#include<sstream>

static Queue q;
static int number = 1;

char menu(){
    cout<<">>>>>医院排队系统<<<<"<<endl;
    cout<<"A.病人取号"<<endl;
    cout<<"N.下一位病人就诊"<<endl;
    cout<<"Q.停止派号"<<endl;
    cout<<"输入您的选择： ";
    char choice;
    cin>>choice;
    return choice;
};

void Arrive(){
    string name0;
    string name1;
    string dot = ".";
    cout<<"请输入病人姓名：";
    cin>>name0;
    stringstream ss;
    ss<<number;
    string numberss = ss.str();
    name1 = numberss + dot + name0;
    EnQueue(q,name1);
    cout<<name0<<"，您排第"<<number<<"位"<<endl;
    number++;
}

void Next(){
    string name = OutQueue(q);
    cout<<"下一位："<<name<<endl;
};

void Quit(){
    cout<<">>>现停止派号<<<"<<endl;
    while(!EmptyQueue(q)){
        string name = OutQueue(q);
        cout<<name<<endl;
    }
    cout<<">>>请以上病人按顺序就诊<<<"<<endl;
}

int main(){
    InitQueue(q);
    while(1){
        switch (menu()) {
            case 'A' : 
            case 'a' : Arrive();cout<<endl;break;
            case 'N' :
            case 'n' : Next();cout<<endl;break;
            case 'Q' : 
            case 'q' : Quit();cout<<endl;return 0;break;
            default :
                cout<<"输入错误，请重新输入"<<endl<<endl;break;
        }
    }
}