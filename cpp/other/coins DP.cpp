#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
int coins=5,values[5]={1,2,7,8,12},goal=15;
int dp[6][16]={{0}};
main(){
	for(int j=0;j<=coins;j++){
		for(int i=0;i<=goal;i++){
			dp[j][i]=INF;
		}
	}
	for(int i=1; i<=coins; i++){
		for(int j=1; j<=goal; j++){
			j=max(j,values[i]);
			dp[i][j]=min(dp[i-1][j],dp[i][j-values[i]]);
		}
	}
	cout<<dp[coins][goal]<<endl;
}
