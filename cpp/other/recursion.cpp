#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
long long f[5000]={0};
long long fib(int n){
  if(n==2 || n==1){
	return 1;
  }
  else{
  	if(f[n]==0){
  		f[n]=fib(n-1)+fib(n-2);
	}
	return f[n];
  }
}
int main(){
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}
//1 1 2 3 5 8 13 21 34 55 89
