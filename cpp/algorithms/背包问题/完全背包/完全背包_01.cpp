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
                int t=0;
                for(int k=0; k*w[i]<=j; k++){
                    t=max(dp[i-1][j-k*w[i]]+k*v[i],t);
                }
                dp[i][j]=t;
            }
            // cout<<dp[i][j]<<' ';
        }// cout<<endl;
    }
    cout<<dp[n][m]<<endl;
}