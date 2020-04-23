#include<string.h>
#include<iostream>
#include"DesStr.h"
using namespace std;


int main(){
    DecStr a("100");
    DecStr b("10");
    DecStr c=a+b;
    cout<<c.GetStr()<<endl;
    return 0;
}