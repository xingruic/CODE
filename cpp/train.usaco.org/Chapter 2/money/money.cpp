/*
TASK:money
ID:xingrui1
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int v,n;
    cin>>v>>n;
    int a[v];
    for(int i=0; i<v; i++) cin>>a[i];
    long long dp[n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=v; i++){
        for(int j=0; j<=n; j++){
            if(j==0) dp[j]=1;
            // cout<<dp[i][j]<<endl;
        }
    }
    for(int i=1; i<=v; i++){
        for(int j=1; j<=n; j++){
            if(j>=a[i-1]) dp[j]=dp[j]+dp[j-a[i-1]];
            else dp[j]=dp[j];
            // cout<<dp[i][j]<<' ';
        }// cout<<endl;
    }
    cout<<dp[n]<<endl;
}