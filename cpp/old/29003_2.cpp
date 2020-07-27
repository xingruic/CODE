#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,m;
	cin>>t>>m;
	int time[m+1],val[m+1];
	for(int i=1; i<=m; i++){
		cin>>time[i]>>val[i];
	}
	int dp[m+1][t+1];
	memset(dp,0,sizeof(dp));
	//for(int i=0; i<=t; i++){
	//	for(int j=0; j<=m; j++)cout<<a[i][j]<<' ';
	//	cout<<endl;
	//}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=t; j++){
			if(time[i]>j){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=max(dp[i-1][j-time[i]]+val[i],dp[i-1][j]);
			}
		}
	}
	cout<<dp[m][t]<<endl;
}
