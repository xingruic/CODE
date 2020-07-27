#include<bits/stdc++.h>
using namespace std;
int euclid(int a, int b){
	if(a%b==0){
		return b;
	}
	return euclid(b,a%b);
}
int main(){
	int a,b;
	cin>>a>>b;
	int temp=euclid(a,b);
	cout<<a*b/temp<<endl;
}
