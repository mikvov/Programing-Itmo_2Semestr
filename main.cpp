#include<string.h>
#include<iostream>
#include"Stroka.h"
using namespace std;


int main(){
    Stroka obj("INMO");
    Stroka obj2=obj;
    cout<<obj2.GetStr()<<endl;
    return 0;
}