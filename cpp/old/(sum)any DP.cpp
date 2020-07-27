#include<bits/stdc++.h>
using namespace std;
int m=331;
int l=10;
int List[10]={1,5,7,10,21,98,71,23,69,32};
int DP[331][10]={{0}};//1==true,2==false
bool any(int s=m,int i=0){
	if(DP[s][i]==1){
		return 1;
	}
	if(s==0){
		DP[s][i]=1;
	}
	if(i==l){
		DP[s][i]=0;
	}
	if(any(s,i+1)){
		DP[s][i]=1;
	}
	if(any(s-List[i],i+1)){
		cout<<List[i]<<endl;
		DP[s][i]=1;
	}
	return DP[s][i];
}
int main(){
	cout<<any(m)<<endl;
}
