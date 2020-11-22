#include<bits/stdc++.h>
using namespace std;
int a[5]={1,9,4,2,4};
int l=5;
int goal=10;
int cnt=0;
bool any(int i=0,int sum=goal){
	cnt++;
	if(i==l){
		return sum==0;
	}
	if(sum==0){
		return 1;
	}
	if(any(i+1,sum)){
		return 1;
	}
	if(any(i+1,sum-a[i])){
		cout<<a[i]<<endl;
		return 1;
	}
	return 0;
}
int main(){
	cout<<any()<<endl<<cnt<<endl;
}
