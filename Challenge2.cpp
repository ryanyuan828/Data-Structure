#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;

//typedef int ElemType;

struct student {
    int ID;
    string name;
    float score;
};

struct List {
    student* list;
    int size;
    int MaxSize;
};

bool operator == (List l, int ID) {
    if (l.list->ID == ID)
        return true;
    else
        return false;
};

bool operator == (List l, string name) {
    if (l.list->name == name)
        return true;
    else
        return false;
};

bool operator < (List l, float score) {
    if (l.list->score < score)
        return true;
    else
        return false;
};

bool Edit (List& l){
    int ID;
    string scoress;
    stringstream ss;
    float scoref;
    int i = 0;
    cout<<"Please enter the ID: ";
    cin>>ID;
    for (i = 0; i < l.size; i++)
        if  (l.list[i].ID == ID){
            cout<<"ID: "<<l.list[i].ID<<endl;
            cout<<"Name: "<<l.list[i].name<<endl;
            cout<<"Original score: "<<l.list[i].score<<endl;
            cout<<"Please enter the new score(q to quit): ";
            cin>>scoress;
            ss<<scoress;
            ss>>scoref;
            if (scoress == "q"){
                cout<<"Present score is: "<<l.list[i].score<<" (not change)"<<endl;
                cout<<">>QUIT<<"<<endl;
                return false;
            }
            l.list[i].score = scoref;
            cout<<"Present score: "<<l.list[i].score<<endl;
            cout<<">>One record edited<<"<<endl;
            return true;
        }
    cout<<">>YOU ENTERED A WRONG ID, EDITION FAILED<<"<<endl;
    return false;
};

bool Add (List& l){
    int ID;
    string name;
    float score;
    cout<<"Please enter ID: ";
    cin>>ID;
    for (int i = 0; i < l.size; i++)
        if  (l.list[i].ID == ID){
            cout<<">>SAME ID IN THE LIST, ADDITION FAILED<<"<<endl;
            return false;
        }
    if (l.size == l.MaxSize){
        int k = sizeof(student);
        l.list = (student*)malloc(200*sizeof(student));
        cout<<"Reallocateed"<<endl;
        if (l.list == NULL){
            cout<<"DYNAMIC SPACE IS EMPTY, INITION FAILED"<<endl;
            return false;
        }
        l.MaxSize = 2*l.MaxSize;
    }
    l.list[l.size].ID = ID;
    cout<<"Please enter name: ";
    cin>>name;
    l.list[l.size].name = name;
    cout<<"Please enter score: ";
    cin>>score;
    l.list[l.size].score = score;
    cout<<">>One record added: "<<l.list[l.size].ID<<", "<<l.list[l.size].name<<", "<<l.list[l.size].score<<"<<"<<endl;
    l.size++;
    return true;
};

bool ViewAll (List& l){
    for (int i = 0; i < l.size; i++){
        cout<<l.list[i].ID<<", "<<l.list[i].name<<", "<<l.list[i].score<<endl;
    }
    cout<<">>All ("<<l.size<<") records printed<<"<<endl;
    return true;
};

bool Search (List& l){
    float score;
    cout<<"Enter the score: ";
    cin>>score;
    for (int i = 0; i < l.size; i++){
        if (l.list[i].score < score){
            cout<<l.list[i].ID<<", "<<l.list[i].name<<", "<<l.list[i].score<<endl;
        }
    }
    return true;
}

char menu(){
    cout<<"Please enter your choice:"<<endl;
    cout<<"(P)rint all records"<<endl;
    cout<<"(A)dd one record"<<endl;
    cout<<"(E)dit one score"<<endl;
    cout<<"(S)earch the score below"<<endl;
    cout<<"(Q)uit"<<endl;
    char choice;
    cin>>choice;
    return choice;
};

bool InitList (List& l){
        l.MaxSize = 100;
        l.list = new student[l.MaxSize]{{2019070101, "Li Hua", 98.5}, {2019070102, "Wang Yanxia", 86}, {2019070103, "Sun Tao", 56}, {2019070104, "Shan Xiaohong", 96}, {2019070105, "Zhang Hua", 83}, {2019070106, "Li Xiaomin", 72}, {2019070107, "Chen Xiaoting", 98}};
        if (l.list == NULL){
            cout<<"DYNAMIC SPACE IS EMPTY, INITION FAILED"<<endl;
            return false;
        }
        l.size = 7;
        return true;
};

int main(){
    List l;
    InitList(l);
    while(1){
        switch (menu()) {
            case 'P' : 
            case 'p' : ViewAll(l);cout<<endl;break;
            case 'A' : 
            case 'a' : Add(l);cout<<endl;break;
            case 'E' : 
            case 'e' : Edit(l);cout<<endl;break;
            case 'S' :
            case 's' : Search(l);cout<<endl;break;
            case 'Q' : 
            case 'q' : cout<<endl;return 0;break;
            default :
                cout<<">>YOU ENTERED A WRONG CHOICE, PLEASE ENTER AGAIN<<"<<endl<<endl;break;
        }
    }
}