#include<bits/stdc++.h>
using namespace std;
int main(){
  int v,n;
  cin>>v>>n;
  int w[n+1]={0};
  for(int i=1; i<=n; i++){
    cin>>w[i];
  }
  int dp[v+1];
  memset(dp,0,sizeof(dp));
  for(int i=1; i<=n; i++){
  	for(int j=v; j>=w[i]; j--){
		dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
		if(dp[j]==v){
			cout<<0<<endl;
			return 0;
		}
//		cout<<dp[i][j]<<' ';
	}//cout<<endl;
  }
  cout<<v-dp[v]<<endl;
  return 0;
}
