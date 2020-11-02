#include<bits/stdc++.h>
using namespace std;
int t,n,m; // # of days,# of artifacts,initial money
int p[105][105];
int main(){
    freopen("29085.in","r",stdin);
    freopen("29085.out","w",stdout);
    memset(p,0,sizeof(p));
    cin>>t>>n>>m;
    for(int i=0; i<t; i++) for(int j=0; j<n; j++) cin>>p[i][j];
    if(t==1){
        cout<<m<<endl;
        return 0;
    }else if(n==1){
        for(int i=0; i<t-1; i++){
            if(p[i][0]<p[i+1][0]) m=m/p[i][0]*p[i+1][0]+m%p[i][0];
            // cout<<i+1<<": "<<m<<endl;
        }
        cout<<m<<endl;
        return 0;
    }
    // cout<<p[0][2]<<endl<<endl;
    for(int o=0; o<t-1; o++){
        int w[n],v[n];
        for(int i=0; i<n; i++){
            w[i]=p[o][i];
            v[i]=p[o+1][i]-p[o][i];
        }
        int dp[m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=w[i]; j<=m; j++){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        m+=dp[m];
    }
    cout<<m<<endl;
    return 0;
}