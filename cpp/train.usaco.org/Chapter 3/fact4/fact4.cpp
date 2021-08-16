/*
ID:xingrui1
LANG:C++
TASK:fact4
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    int num;
    cin>>num;
    bool remove2=0;
    int res=1;
    for(int i=num; i>=2; i--){
        res*=i;
        // cout<<res<<endl;
        while(res%10000==0) res/=10000;
        res%=10000;
    }
    while(res%10==0) res/=10;
    cout<<res%10<<endl;
}