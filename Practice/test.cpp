#include <iostream>
using namespace std;
int main(){
    int *p = new int{33};
    int *q = p;

    cout<<p<<" "<<*p<<endl;
    cout<<q<<" "<<*q<<endl;

    delete p;
    p = nullptr;

    cout<<p<<" "<<*p<<endl;
    cout<<p<<" "<<*p<<endl;

    return 0;
}