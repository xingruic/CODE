#include<bits/stdc++.h>
using namespace std;
int a[5000]={0};
int fibb(int n){
	if(n==0||n==1){
		return 1;
	}
	if(a[n]==0){
		a[n]=fibb(n-1)+fibb(n-2);
	}
	return a[n];
}
int main(){
	int n;
	cin>>n;
	cout<<fibb(n-1);
}

