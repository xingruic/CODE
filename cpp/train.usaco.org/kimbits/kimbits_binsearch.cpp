/*
TASK:kimbits
ID:xingrui1
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n,l,I;
int T;
int main(){
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    T=clock();
    cin>>n>>l>>I;

    // needs work
    long long dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; i++) dp[0][i]=dp[i][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            // cout<<dp[i][j]<<'\t';
        }
        // cout<<endl;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<dp[i][j]<<'\t';
        }cout<<endl;
    }
    // long long cnt=0;
    // for(int i=0; i<=n; i++){
    //     for(int j=1; j<=l; j++){
    //         cnt+=dp[i][j];
    //         if(cnt)
    //     }
    // }

    string res="";
    // while(I>0){
        
    // }
}
/*
  1
 1 1
1 2 1
...
  |
  V
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
...
*/