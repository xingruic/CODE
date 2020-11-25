#include<iostream>
using namespace std;
int main(){
	int a,b=0;
	cin>>a;
	while(a!=0){
		b=b*10+a%10;
		a/=10;
	}
	cout<<b<<endl;
}
