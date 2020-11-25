#include<bits/stdc++.h>
using namespace std;
string convert(int num,int base){
  string ans="";
  while(num!=0){
    char temp;
    if(num%base>9){
    	temp=num%base+55;
	}else{
		temp=num%base+48;
	}
    ans=temp+ans;
    num/=base;
  }
  return ans;
}
int main(){
	string num="0";
	int b,l;
	cin>>b>>l;
	int i=0;
	do{
		cout<<num<<endl;
		i++;
		num=convert(i,b);
	}while(num.size()<=l);
}
