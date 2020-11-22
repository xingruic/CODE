#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("longest_common_substring.txt","w",stdout);
    char a[]="A SIMPLE YES EXAMPLE",b[]="A SIMPLE NOT EXAMPLE";
    int n=sizeof(a);
    int dp[n+1][n+1];
    int ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}