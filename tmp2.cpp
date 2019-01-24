#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int a = 2;
    int *b = &a;
    int *c = &a;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<&a;
    return 0;
}
