/*
ID:xingrui1
LANG:C++
TASK:inflate
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int points[n],minutes[n];
    for(int i=0; i<n; i++){
        cin>>points[i]>>minutes[i];
    }
    int dp[m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(minutes[i-1]<=j){
                dp[j]=max(dp[j-minutes[i-1]]+points[i-1],dp[j]);
            }
            // cout<<dp[i][j]<<'\t';
        }
        // cout<<endl;
    }
    cout<<dp[m]<<endl;
}