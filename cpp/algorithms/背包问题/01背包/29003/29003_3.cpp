#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,m;
	cin>>t>>m;
	int time[m+1],val[m+1];
	for(int i=1; i<=m; i++){
		cin>>time[i]>>val[i];
	}
	int dp[t+1];
	memset(dp,0,sizeof(dp));
	for(int i=1; i<=m; i++){
		for(int j=t; j>=time[i]; j--){
			dp[j]=max(dp[j-time[i]]+val[i],dp[j]);
		}
	}
	for(int i=0; i<=t; i++) cout<<dp[i]<<'\t';
	cout<<endl;
	cout<<dp[t]<<endl;
}
