/*
ID: xingrui1
LANG: C++
TASK: pprime
*/
#include<iostream>
using namespace std;
bool palindrome(int num){
	int flip=0, temp=num;
	while(temp!=0){
		flip=flip*10+temp%10;
		temp/=10;
	}
	if(flip==num)
	return true;
	else
	return false;
}
bool prime(int num){
	for(int i=2; i*i<=num; i++){
		if(num%i==0)
		return false;
	}
	return true;
}
int main(){
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(b>10000000) b=10000000;
	for(int i=a; i<=b; i++){
		if(palindrome(i)&&prime(i))cout<<i<<endl;
	}
	return 0;
}