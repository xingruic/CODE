#include<bits/stdc++.h>
using namespace std;
string a="ABCBDAB";
string b="BACBADB";
int main(){
    string res="";
    int x=a.size(),y=b.size();
    int dp[x+1][y+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                // cout<<"-----"<<i-1<<"-----"<<endl;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }
    for(int i=1; i<=x; i++){
        if(dp[i-1][i-1]+1==dp[i][i]) res=a[i-1]+res;
    }
    cout<<dp[x][y]<<endl;
    cout<<res<<endl;
}
// 19408573
// 91480573