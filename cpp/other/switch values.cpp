#include<iostream>
using namespace std;
int Switch(int a,int b){
	a+=b;
	b=a-b;
	a-=b;
	return 0;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<a<<endl<<b<<endl;
	swap(a,b);
	cout<<a<<endl<<b<<endl;
	return 0;
}

