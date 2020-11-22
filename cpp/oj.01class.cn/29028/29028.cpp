#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[40];
int ks(int i=n,int j=m){
    if(i==-1){
        return j;
    }
    if(j<a[i]) return ks(i-1,j);
    // cout<<a[i]<<endl;
    return min(ks(i-1,j),ks(i-1,j-a[i]));
}
int main(){
    cin>>m>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<ks()<<endl;
}