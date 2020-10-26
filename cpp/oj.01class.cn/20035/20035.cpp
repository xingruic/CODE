#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("20035.in","r",stdin);
    // freopen("20035.out","w",stdout);
    int v,n;
    cin>>v>>n;
    int a[v];
    for(int i=0; i<v; i++) cin>>a[i];
    long long dp[v+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=v; i++){
        for(int j=0; j<=n; j++){
            if(j==0) dp[i][j]=1;
            // cout<<dp[i][j]<<endl;
        }
    }
    for(int i=1; i<=v; i++){
        for(int j=1; j<=n; j++){
            if(j>=a[i-1]) dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
            else dp[i][j]=dp[i-1][j];
            // cout<<dp[i][j]<<' ';
        }// cout<<endl;
    }
    cout<<dp[v][n]<<endl;
}