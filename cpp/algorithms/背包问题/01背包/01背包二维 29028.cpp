#include<bits/stdc++.h>
using namespace std;
//oj.01class.cn/problem/29028
int main(){
  int v,n;
  cin>>v>>n;
  int w[10000]={0};
  for(int i=1; i<=n; i++){
    cin>>w[i];
  }
  int dp[n+1][v+1];
  memset(dp,0,sizeof(dp));
  for(int i=1; i<=n; i++){
  	for(int j=1; j<=v; j++){
  		if(w[i]>j){
  			dp[i][j]=dp[i-1][j];
		}else{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
		}
		if(dp[i][j]==v){
			cout<<0<<endl;
			return 0;
		}
//		cout<<dp[i][j]<<' ';
	}//cout<<endl;
  }
  cout<<v-dp[n][v]<<endl;
  return 0;
}
