#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1][n+1]={{0}};// »Ã·½
    a[1][(n+1)/2]=1;
    int i,j;
    for(int k=2; k<=n*n; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(a[i][j]==k-1){
                    // cout<<k<<' ';
                    if(i==1&&j<n){
                        a[n][j+1]=k;
                        // cout<<1<<endl;
                        break;
                    }
                    if(i>1&&j==n){
                        a[i-1][1]=k;
                        // cout<<2<<endl;
                        break;
                    }
                    if(i==1&&j==n){
                        a[i+1][j]=k;
                        // cout<<3<<endl;
                        break;
                    }
                    if(i>1&&j<n){
                        if(a[i-1][j+1]==0) a[i-1][j+1]=k;
                        else a[i+1][j]=k;
                        // cout<<4<<endl;
                        break;
                    }
                }
            }
            if(j<n) break;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j<n) cout<<a[i][j]<<' ';
            else cout<<a[i][j]<<endl;
        }
    }
}