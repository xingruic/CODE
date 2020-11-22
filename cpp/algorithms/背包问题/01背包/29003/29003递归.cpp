#include<bits/stdc++.h>
using namespace std;
int T,n;
int t[105],v[105];
int a[1005][1005];
int ks0(int i=0,int j=T){
    if(i==n) return 0;
    if(a[i][j]!=-1) return a[i][j];
    if(j<t[i]) return (a[i][j]=ks0(i+1,j));
    else return (a[i][j]=max(ks0(i+1,j-t[i])+v[i],ks0(i+1,j)));
}
int ks(int i=n,int j=T){
    if(i==-1) return 0;
    if(a[i][j]!=-1) return a[i][j];
    if(j<t[i]) return a[i][j]=ks(i-1,j);
    return a[i][j]=max(ks(i-1,j),ks(i-1,j-t[i])+v[i]);
}
int ks0_1(){
    memset(a,0,sizeof(a));
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=T; j++){
            if(j<t[i]) a[i][j]=a[i+1][j];
            else a[i][j]=max(a[i+1][j-t[i]]+v[i],a[i+1][j]);
        }
    }
    return a[0][T];
}
/****************
 *   优化写法    *
 ***************/
int KS(){
    int b[1005]={0};
    for(int i=0; i<n; i++){
        for(int j=T; j>=0; j--){
            if(j<t[i]) continue;
            b[j]=max(b[j],b[j-t[i]]+v[i]);
        }
    }
    return b[T];
}
int main(){
    memset(a,-1,sizeof(a));
    cin>>T>>n;
    for(int i=0; i<n; i++) cin>>t[i]>>v[i];
    cout<<KS()<<endl;
}