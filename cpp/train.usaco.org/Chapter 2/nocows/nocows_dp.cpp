/*
ID:xingrui1
LANG:C++
TASK:nocows
*/
#include<bits/stdc++.h>
using namespace std;
int n,k;
int dp[200][100];
int main(){
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
    memset(dp,0,sizeof(dp));
    cin>>n>>k;
    for(int j=1; j<=k; j++){
        dp[1][j]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            for(int l=1; l<i; l++){
                dp[i][j]+=(dp[l][j-1]*dp[i-1-l][j-1])%9901;
                dp[i][j]%=9901;
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++) cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout<<(dp[n][k]-dp[n][k-1]+9901)%9901<<endl;
}