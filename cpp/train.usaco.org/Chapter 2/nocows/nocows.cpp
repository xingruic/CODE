/*
ID:xingrui1
LANG:C++
TASK:nocows
*/
#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[200][200];
int nocows(int i,int j){
    if(j<1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i<2) return dp[i][j]=i;
    int cnt=0;
    for(int l=1; l<i; l++){
        cnt+=(nocows(l,j-1)*nocows(i-1-l,j-1))%9901;
        cnt%=9901;
    } 
    return dp[i][j]=cnt;
}
int main(){
    memset(dp,-1,sizeof(dp));
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    cin>>n>>k;
    // cout<<(nocows(n,k)-(dp[n][k-1]==-1?0:dp[n][k-1])+9901)%9901<<endl;
    cout<<(nocows(n,k)-nocows(n,k-1)+9901)%9901<<endl;
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=k; j++) cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
}