#include<bits/stdc++.h>
using namespace std;
int main(){
	int items,cap;
	cin>>items>>cap;
	int weight[items],value[items];
	for(int i=0; i<items; i++){
		cin>>value[i]>>weight[i];
	}
//	int items=4,cap=5;
//	int weight[items]={2,2,1,3};
//	int value[items]={4,5,2,8};
	int dp[items+1][cap+1]={{0}};
	for(int i=0; i<=items; i++){
		for(int j=0; j<=items; j++){
			dp[i][j]=0;
		}
	}
	for(int i=1; i<=items; i++){
		for(int j=0; j<=cap; j++){
			if(weight[i-1]>j){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=max(dp[i-1][j-weight[i-1]]+value[i-1],dp[i-1][j]);
//				cout<<"max("<<dp[i-1][j-weight[i-1]]+value[i-1]<<','<<dp[i-1][j]<<')'<<endl;
			}
//			cout<<"i:"<<i<<' '<<"j:"<<j<<' '<<"weight[i-1]:"<<weight[i-1]<<' '<<"value[i-1]"<<value[i-1]<<endl;
			//cout<<dp[i][j]<<' ';
		}//cout<<endl;
	}
	cout<<dp[items][cap]<<endl;
}

