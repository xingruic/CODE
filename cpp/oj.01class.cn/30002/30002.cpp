#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int v[n],w[n];
    for(int i=0; i<n; i++) cin>>v[n]>>w[n];
    // max(dp[i][j-weight],dp[i-1][j-weight])+value
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j-w[i-1]>=0){
                dp[i][j]=max(dp[i][j-w[i-1]]+v[i-1],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][m]<<endl;
}