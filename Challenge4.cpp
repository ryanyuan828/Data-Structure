#include"Stack.h"
#include<cstring>
#include<sstream>

void Transfrom(long num){
	Stack a;
	InitStack(a);
	while(num!=0){
		int k = num % 16;
		Push(a,k);
		num /= 16;
	}
	while(!EmptyStack(a)){
		int x = Pop(a);
		if(x < 10)
			cout<<x;
		else {
			switch (x){
				case 10: cout<<'A'; break;
				case 11: cout<<'B'; break;
				case 12: cout<<'C'; break;
				case 13: cout<<'D'; break;
				case 14: cout<<'E'; break;
				case 15: cout<<'F';
			}
		}
	}
	cout<<endl;
};

int main(){
	while(1){
		string numss;
    	stringstream ss;
		long numl;
		cout<<"Please enter a DEC number(q to quit): ";
		cin>>numss;
        ss<<numss;
        ss>>numl;
		if (numss == "q"){
            cout<<">>QUIT<<"<<endl;
            return false;
            }
		Transfrom(numl);
	}
}