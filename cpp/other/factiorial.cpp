#include<iostream>
using namespace std;
long int fac(int num){
	if(num==0){
		return 1;
	}
	return fac(num-1)*num;
}
int main(){
	int num;
	cin>>num;
	cout<<fac(num)<<endl;
	return 0;
}
