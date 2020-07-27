
#include<bits/stdc++.h>
using namespace std;
bool palindrome(int num){
	int len=0, temp=num;
	while(temp!=0){
		temp/=10;
		len++;
	}
	for(int i=0; i<=len/2; i++){
		if(num/(int)pow(10,i)%10!=num/(int)pow(10,len-i-1)%10){
			return false;
		}
	}
	return true;
}
int main(){
  int a,b;
  cin>>a>>b;
  bool prime;
  for(int i=a; i<=b&&i<10000000; i++){
  	prime=true;
    for(int j=2; j*j<=i; j++){
      if(i%j==0)prime=false;
    }
    if(prime&&palindrome(i)){
      cout<<i<<endl;
    }
  }
}
