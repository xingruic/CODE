#include<iostream>
using namespace std;
long long pow2(int e=1){
	if(e==0){
		return 1;
	}
	return 2*pow2(e-1);
}
int main(){
	int e;
	cin>>e;
	cout<<pow2(e)<<endl;
	return 0;
}
