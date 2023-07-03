#include<bits/stdc++.h>
using namespace std;
int n;
char a[21][21];
int b[21][21];
void flood(int i=1,int j=1){
    if(i>1){
        if(b[i-1][j]==-1){
            if(a[i-1][j]==a[i][j]){
                b[i-1][j]=b[i][j];
                flood(i-1,j);
            }
        }
    }
    if(j>1){
        if(b[i][j-1]==-1){
            if(a[i][j-1]==a[i][j]){
                b[i-1][j]=b[i][j];
                flood(i,j-1);
            }
        }
    }
    if(i<n){
        if(b[i+1][j]==-1){
            if(a[i+1][j]==a[i][j]){
                b[i+1][j]=b[i][j];
                flood(i+1,j);
            }
        }
    }
    if(j<n){
        if(b[i][j+1]==-1){
            if(a[i][j+1]==a[i][j]){
                b[i+1][j]=b[i][j];
                flood(i,j+1);
            }
        }
    }
}
int main(){
    memset(b,-1,sizeof(b));
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            b[i][j]=cnt++;
            flood(i,j);
        }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)cout<<b[i][j]<<' ';
        cout<<endl;
    }    
}