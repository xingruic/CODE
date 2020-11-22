#include<bits/stdc++.h>
using namespace std;
//oj.01class.cn/problem/29003 ²ÉÒ© 
int main(){
	int items,time;
	cin>>time>>items;
	int weight[items+1],value[items+1];
	for(int i=1; i<=items; i++){
		cin>>weight[i]>>value[i];
	}
	int dp[items+1][time+1]={{0}};
	for(int i=0; i<=items; i++){
		for(int j=0; j<=time; j++){
			dp[i][j]=0;
//			cout<<dp[i][j]<<' ';
		}//cout<<endl;
	}//cout<<endl;
	for(int i=1; i<=items; i++){
		for(int j=1; j<=time; j++){
			if(weight[i]>j){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=max(dp[i-1][j-weight[i]]+value[i],dp[i-1][j]);
			}
//			cout<<dp[i][j]<<' ';
		}//cout<<endl;
	}
//	for(int i=0; i<=items; i++){
//		for(int j=0; j<=time; j++){
//			cout<<dp[i][j]<<' ';
//		}cout<<endl;cout<<endl;
//	}
	cout<<dp[items][time]<<endl;
}
