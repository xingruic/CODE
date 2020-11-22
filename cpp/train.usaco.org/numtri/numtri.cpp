/*
ID: xingrui1
LANG: C++
TASK: numtri
*/
#include<bits/stdc++.h>
using namespace std;
int r;
int a[1000][1000];
int m[1000][1000];
int times[1000][1000];
int find(int i=0,int j=0){
    if(i==r-1){
        return a[i][j];
    }
    times[i][j]++;
    if(m[i][j]!=-1) return m[i][j];
    return m[i][j]=(a[i][j]+max(find(i+1,j+1),find(i+1,j)));
}
int main(){
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    cin>>r;
    for(int i=0; i<r; i++){
        for(int j=0; j<=i; j++){
            cin>>a[i][j];
        }
    }
    memset(m,-1,sizeof(m));
    cout<<find()<<endl;
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<r; j++) cout<<times[i][j]<<' ';
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<r; j++) cout<<m[i][j]<<' ';
    //     cout<<endl;
    // }
}