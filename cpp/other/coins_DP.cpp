#include<bits/stdc++.h>
#define INF 0x7fffffff-1
using namespace std;
main(){
	int coins;
	cin>>coins;
	int values[coins];
	for(int i=0;i<coins;i++){
		cin>>values[i];
	}
	int goal;
	cin>>goal;
	int dp[coins+1][goal+1]={{0}};
	for(int j=0;j<=coins;j++){
		for(int i=0;i<=goal;i++){
			dp[j][i]=INF;
		}
	}
	for(int i=1; i<=coins; i++){
		for(int j=1; j<=goal; j++){
			if(values[i-1]>j){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=min(dp[i-1][j],dp[i][j-values[i-1]]+1);
			}
			if(j%values[i-1]==0&&j/values[i-1]==1){
				dp[i][j]=1;
			}
			//cout<<dp[i][j]<<' ';
		}//cout<<endl;
	}
	cout<<dp[coins][goal]<<endl;
}
