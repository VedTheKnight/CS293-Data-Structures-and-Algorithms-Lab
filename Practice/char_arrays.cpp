#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char a[] = "hello world";
    char b[] = "hello world";
    int flag = strcmp(a,b); //returns 0 if strings are equal!
    cout<<flag;
    return 0;
}