#include<bits/stdc++.h>
using namespace std;
int n,m;
int w[1000],v[1000];
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>v[i]>>w[i];
    }
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j<w[i]) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-w[i]]+v[i],dp[i][j-w[i]]+v[i]));
            }
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++) cout<<dp[i][j]<<'\t';
    //     cout<<endl;
    // }
    cout<<dp[n][m]<<endl;
}