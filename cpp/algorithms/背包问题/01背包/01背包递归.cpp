#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[1005],w[1005];
int a[1005][1005];
int ks(int i=0,int j=m){
    if(i==n) return 0;
    if(a[i][j]!=-1) return a[i][j];
    if(j<w[i]) return (a[i][j]=ks(i+1,j));
    else return (a[i][j]=max(ks(i+1,j-w[i])+v[i],ks(i+1,j)));
}
int main(){
    memset(a,-1,sizeof(a));
    cin>>m>>n;
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    cout<<ks()<<endl;
}