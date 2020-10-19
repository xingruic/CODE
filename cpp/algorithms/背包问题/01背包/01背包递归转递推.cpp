#include<bits/stdc++.h>
using namespace std;
int n=5,m=10;
int v[1005]={6,3,5,4,6},w[1005]={2,2,6,5,4};
int a[1005][1005];
int ks(int i=0,int j=m){
    if(i==n) return 0;
    if(j<w[i]) return (ks(i+1,j));
    else return (max(ks(i+1,j-w[i])+v[i],ks(i+1,j)));
}
int ks1(int i=0,int j=m){
    if(i==n) return 0;
    if(a[i][j]!=-1) return a[i][j];
    if(j<w[i]) return (a[i][j]=ks1(i+1,j));
    else return (a[i][j]=max(ks1(i+1,j-w[i])+v[i],ks1(i+1,j)));
}
int ks2(){
    // ./ks2.xlsx
    memset(a,0,sizeof(a));
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=m; j++){
            if(j<w[i]) a[i][j]=a[i+1][j];
            else a[i][j]=max(a[i+1][j-w[i]]+v[i],a[i+1][j]);
            cout<<a[i][j]<<'\t';
        }cout<<endl;
    }
    return a[0][m];
}
int ks3(int i=n,int j=m){
    if(i==0){
        a[i][j]=0;
        // cout<<a[i][j]<<endl;
        return a[i][j];
    }
    if(a[i][j]!=-1){
        // cout<<a[i][j]<<endl;
        return a[i][j];
    }
    if(j<w[i]){
        a[i][j]=ks3(i-1,j);
        // cout<<a[i][j]<<endl;
        return a[i][j];
    }else{
        a[i][j]=max(ks3(i-1,j-w[i])+v[i],ks3(i-1,j));
        // cout<<a[i][j]<<endl;
        return a[i][j];
    }
}
int main(){
    memset(a,-1,sizeof(a));
    // cin>>m>>n;
    // for(int i=0; i<n; i++) cin>>w[i]>>v[i];
    cout<<ks3()<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cout<<a[i][j]<<'\t';
        }cout<<endl;
    }
}