#include<bits/stdc++.h>
using namespace std;
string a="ABCBDAB";
int main(){
    string b=a;
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<b.size()-1; j++){
            if(b[j]>b[j+1]) swap(b[j],b[j+1]);
        }
    }
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
        if(dp[i-1][i-1]+1==dp[i][i]) res+=b[i-1];
    }
    cout<<dp[x][y]<<endl;
    cout<<res<<endl;
}
// 19408573