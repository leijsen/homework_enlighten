#include<iostream>
#include<malloc.h>
using namespace std;
int main(){
    int num,N;
    cin>>num>>N;
    int a[10000];
    char c[37]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    register int i=0;
    while(num){
        a[i]= num%N;
        num = num/N;
        i++;
    }
    i -= 1;
    for(;i>=0;i--){
        cout<<c[a[i]];
    }
}