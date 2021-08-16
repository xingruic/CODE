/*
ID:xingrui1
LANG:C++
TASK:subset
*/
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[40][820];
// long long cnt2=0;
long long subset(int i=0,int j=0){
    if(a[i][j]) return a[i][j];
    // cnt2++;
    if(i==n){
        if(2*j==n*(n+1)/2){
            return a[i][j]=1;
        }
        return a[i][j]=0;
    }
    return a[i][j]=subset(i+1,j+i+1)+subset(i+1,j);
}
int main(){
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    memset(a,0,sizeof(a));
    // int t=clock();
    cin>>n;
    if(n*(n+1)/2%2!=0){
        cout<<0<<endl;
        return 0;
    }
    cout<<subset()/2<<endl;
    // cout<<cnt2<<endl;
    // cout<<clock()-t<<endl;
}