#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,sum[209][209]={0};
    cin>>n>>k;
    for(int i=1;i<=k;i++) sum[i][1]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            for(int m=1;m<j;m++)
                sum[i][j]=(sum[i][j]+sum[i-1][j-m-1]*sum[i-1][m])%9901;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            cout<<sum[i][j]<<' ';
        }cout<<endl;
    }
    if(sum[k][n]-sum[k-1][n]<0)
        cout<<sum[k][n]-sum[k-1][n]+9901<<endl;
    else
        cout<<sum[k][n]-sum[k-1][n]<<endl;
    return 0;
}