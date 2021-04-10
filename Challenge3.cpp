#include"LNode.h"

static LNode* l;

char menu(){
    cout<<"1.新建数字顺序表"<<endl;
    cout<<"2.查找某数是否在表中"<<endl;
    cout<<"3.插入一个数字到表中"<<endl;
    cout<<"4.删除表中数字"<<endl;
    cout<<"5.给数字顺序表排序"<<endl;
    cout<<"6.屏幕输出整个表"<<endl;
    cout<<"7.不想玩了，拜拜！"<<endl;
    cout<<"输入您的选择： ";
    char choice;
    cin>>choice;
    return choice;
};

void Traverse(){
    cout<<"所有数字：";
    TraverseList(l);
};

void Find(){
    ElemType item;
    cout<<"请输入要查找的数字：";
    cin>>item;
    if(FindList(l, item))
        cout<<item<<"在表中"<<endl;
    else
        cout<<item<<"不在表中"<<endl;
};

void Delete(){
    ElemType item = 0;
    int pos = 0;
    cout<<"请输入要删除的数字：";
    cin>>item;
    //cout<<"请输入要删除的数字的位置：";
    //cin>>pos;
    if (DeleteList (l, item, pos))
        cout<<item<<"删除成功"<<endl;
    else
        cout<<item<<"删除失败"<<endl;
    Traverse();    
};

void Insert(){
    ElemType item = 0;
    int pos = -1;
    cout<<"请输入要插入的数字：";
    cin>>item;
    //cout<<"请输入要插入的数字的位置：";
    //cin>>pos;
    if (InsertList (l, item, pos))
        cout<<item<<"插入成功"<<endl;
    else
        cout<<item<<"插入失败"<<endl;
    Traverse();
};

void Initial(){
    InitList(l);
    Traverse();
};

void Sort(){
    cout<<"排序前";
    Traverse();
    SortList(l);
    cout<<"排序后";
    Traverse();
};

int main(){
    cout<<"欢迎您进入数字顺序表游戏！"<<endl;
    cout<<"请选择："<<endl;
    while(1){
        switch (menu()) {
            case '1' : Initial();cout<<endl;break;
            case '2' : Find();cout<<endl;break;
            case '3' : Insert();cout<<endl;break;
            case '4' : Delete();cout<<endl;break;
            case '5' : Sort();cout<<endl;break;
            case '6' : Traverse();cout<<endl;break;
            case '7' : return 1;
            default :
                cout<<"请重新选择(1～7)：";break;
        }
    }
}