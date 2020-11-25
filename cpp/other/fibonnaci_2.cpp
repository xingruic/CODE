#include<iostream>
using namespace std;
long long fib(int n){
	long long an_2=0,an_1=1,an=1;
	for(int i=1; i<n; i++){
		an=an_2+an_1;
		an_2=an_1;
		an_1=an;
	}
	return an;
}
int main(){
	int n;
	cin>>n;
	cout<<fib(n);
}
