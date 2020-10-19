#include<bits/stdc++.h>
using namespace std;
int main(){
    int time,num;
    cin>>time>>num;
    int dp[num+1][time+1];
    memset(dp,0,sizeof(dp));
    int v[num],t[num];
    for(int i=0; i<num; i++){
        cin>>t[i]>>v[i];
    }
    for(int i=1; i<=num; i++){
        for(int j=1; j<=time; j++){
            dp[i][j]=max((j-t[i-1]>=0?dp[i-1][j-t[i-1]]+v[i-1]:0),dp[i-1][j]);
        }
    }
    cout<<dp[num][time]<<endl;
}