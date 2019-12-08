#include<iostream>
using namespace std;

int max_comp(int* a, int n)
{
    int max = 0, i;
    max = a[0];
    for (i = 0; i < n; i++){
        if (*a > max){
            max = *a;
        }
        a++;
    }
    return max;
}

int main()
{
    int n, i, max;
    cout<<"Please enter the number 'n': ";
    cin>>n;
    const int n1 = n;
    int a[n1];
    cout<<"Please enter all the numbers: ";
    for(i = 0; i < n; i++){
        cin>>a[i];
    }
    max = max_comp(a,n);
    cout<<"The biggest number is "<<max<<endl;
    return 0;
}