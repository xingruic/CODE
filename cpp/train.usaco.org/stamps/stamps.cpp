/*
TASK:stamps
ID:xingrui1
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
int k,n; // # of stamps allowed, # of different stamp values
int a[50]={0};
int main(){
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    cin>>k>>n;
    int maxa=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    int dp[k*maxa+1];
    memset(dp,0x7f,sizeof(dp));
    dp[0]=0;
    int i;
    for(i=1; i<=k*maxa; i++){
        for(int j=0; j<n; j++){
            if(i>=a[j]){
                dp[i]=min(dp[i],dp[i-a[j]]+1);
                // cout<<dp[i]<<' '<<a[j]<<", ";
            }
        }
        // cout<<"--- "<<i<<' '<<dp[i]<<endl;
        if(dp[i]>k) break;
    }
    cout<<i-1<<endl;
}