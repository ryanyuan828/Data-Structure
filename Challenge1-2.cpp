#include<iostream>
using namespace std;

struct worker{
    char name;
    int number;
    int salary;
};

void input(int num, worker* workers){
    for(int i = 0; i < num; i++){
        cout<<"请输入第"<<(i+1)<<"位职工的名字:"<<endl;
        cin>>workers[i].name;
        cout<<"请输入第"<<(i+1)<<"位职工的职工号:"<<endl;
        cin>>workers[i].number;
        cout<<"请输入第"<<(i+1)<<"位职工的工资:"<<endl;
        cin>>workers[i].salary;
        cout<<endl;
    }
}

int average(int num, worker* workers,int& ave){
    int sum = 0;
    for(int i = 0; i < num; i++)
        sum += workers[i].salary;
    ave = sum / num;
    return ave;
}

void output(int num, worker* workers, int ave){
    for(int i = 0; i < num; i++){
        cout<<"第"<<(i+1)<<"位职工的名字:"<<workers[i].name<<endl;
        cout<<"第"<<(i+1)<<"位职工的职工号:"<<workers[i].number<<endl;
        cout<<"第"<<(i+1)<<"位职工的工资:"<<workers[i].salary<<endl;
        cout<<num<<"位职工的平均工资:"<<ave<<endl;
    }
}

int main(){
    int num = 0, ave = 0;
    cout<<"请输入职工人数"<<endl;
    cin>>num;
    const int number = num;
    worker workers[number];
    input(num, workers);
    ave = average(num, workers, ave);
    output(num, workers, ave);
    return 0;
}