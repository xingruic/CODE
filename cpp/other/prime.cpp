#include<bits/stdc++.h>
using namespace std;
bool prime(int num){
	for(int i=2; i<num; i++){
		if(num%i==0){
			cout<<i<<' '<<num/i<<endl;
			return false;
		}
	}
	return true;
}
int main(){
	int number;
	bool boolean = -5;
	cin>>number;
	cout<<"number is prime: "<<prime(number)<<endl;
}
