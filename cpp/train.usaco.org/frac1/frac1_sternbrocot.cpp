/*
ID: xingrui1
LANG: C++
TASK: frac1
*/
#include<bits/stdc++.h>
using namespace std;
int n;
void s(int a=0,int b=1,int c=1,int d=0){
    if(a+c>b+d||b+d>n){
        return;
    }
    s(a,b,a+c,b+d);
    cout<<a+c<<'/'<<b+d<<endl;
    s(a+c,b+d,c,d);
}
int main(){
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin>>n;
    cout<<0<<'/'<<1<<endl;
    s();
}