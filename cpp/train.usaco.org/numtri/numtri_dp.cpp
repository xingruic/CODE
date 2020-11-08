/*
ID: xingrui1
LANG: C++
TASK: numtri
*/
#include<bits/stdc++.h>
using namespace std;
int r;
int a[1005][1005];
int m[1005][1005];
int find(int i=0,int j=0){
    if(i==r-1){
        return a[i][j];
    }
    if(m[i][j]!=-1) return m[i][j];
    return m[i][j]=(a[i][j]+max(find(i+1,j+1),find(i+1,j)));
}
int main(){
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    cin>>r;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=i; j++){
            cin>>a[i][j];
        }
    }
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<r; j++) cout<<a[i][j]<<' ';
    //     cout<<endl;
    // }
    for(int i=1; i<=r; i++){
        for(int j=1; j<=i; j++){
            m[i][j]=a[i][j]+max(m[i-1][j-1],m[i-1][j]);
            // cout<<m[i][j]<<' ';
        }// cout<<endl;
    }
    int t=0;
    for(int i=1; i<=r; i++){
        t=max(t,m[r][i]);
    }
    cout<<t<<endl;
}