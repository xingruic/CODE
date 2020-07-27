#include<bits/stdc++.h>
using namespace std;
long long b[20000]={0,1,1};
long long fib(int a){
	if(a==1||a==2) return 1;
	if(!b[a]&&a) b[a]=fib(a-1)+fib(a-2);
	return b[a];
}
long long DPfib(int a){
	for(int i=3; i<=a; i++){
		b[i]=b[i-1]+b[i-2];
	}
	return b[a];
}
int main(){
	cout<<fib(0)<<endl<<DPfib(50)<<endl;
}
