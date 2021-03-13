#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("29085.in","r",stdin);
    freopen("29085.out","w",stdout);
    int t,n,m; // number of days, number of items, starting balance
    cin>>t>>n>>m;
    int a[t+1][n+1]; // price of each item each day
    memset(a,0,sizeof(a));
    for(int i=1; i<=t; i++) for(int j=1; j<=n; j++) cin>>a[i][j];
    if(t==1){
        cout<<m<<endl;
        return 0;
    }
    if(n==1){
        int cnt=0;
        for(int i=1; i<t-1; i++){
            m+=cnt*a[i][1];
            cnt=0;
            if(a[i][1]<a[i+1][1]){
                cnt=m/a[i][1];
                m-=cnt*a[i][1];
                cout<<m<<' '<<cnt<<endl;
            }
        }
        cout<<m+cnt*a[t][1]<<endl;
        return 0;
    }
    for(int o=1; o<t; o++){
        int dp[m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++){
            for(int j=a[o][i]; j<=m; j++){
                dp[j]=max(dp[j],dp[j-a[o][i]]+a[o+1][i]-a[o][i]);
            }
        }
        m+=dp[m];
    }
    cout<<m<<endl;
}