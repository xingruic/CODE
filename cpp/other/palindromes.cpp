#include<bits/stdc++.h>
using namespace std;
bool palindrome(int num){
	int len=0, temp=num;
	while(temp!=0){
		temp/=10;
		len++;
	}
	for(int i=0; i<=len/2; i++){
		cout<<num/(int)pow(10,i)%10<<' '<<num/(int)pow(10,len-i-1)%10<<endl;
		if(num/(int)pow(10,i)%10!=num/(int)pow(10,len-i-1)%10){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	cout<<palindrome(n)<<endl;
} 
