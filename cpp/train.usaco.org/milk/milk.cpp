/*
ID: xingrui1
TASK: milk
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("milk.in","r",stdin);
    // freopen("milk.out","w",stdout);
    int n,m,P=0;
    cin>>n>>m;
    // price and amount each farmer grants
    int p[m],a[m];
    for(int i=0; i<m; i++){
        cin>>p[i]>>a[i];
    }
    for(int i=0; i<m; i++){
        for(int j=1; j<m; j++){
            if(p[j-1]>p[j]){
                swap(p[j-1],p[j]);
                swap(a[j-1],a[j]);
            }
        }
    }
    for(int i=0; i<m; i++){
        if(n>a[i]){
            n-=a[i];
            P+=p[i]*a[i];
            a[i]=0;
        }else{
            P+=p[i]*n;
            break;
        }
    }
    cout<<P<<endl;
}