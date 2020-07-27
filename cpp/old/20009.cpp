/*
ID: xingrui1
TASK: dualpal
LANG: C++
*/
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
bool palin(string num){
  string temp=num;
  for(int i=0; i<=(temp.size()-1)/2; i++){
    swap(temp[i],temp[temp.size()-i-1]);
  }
  return temp==num;
}
int main(){
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	cin>>n>>s;
	for(s++;n>0;s++){
		int count=0;
		for(int i=2; i<=10; i++){
			if(palin(convert(s,i))){
				count++;
				if(count==2){
					break;
				}
			}
		}
		if(count==2){
			n--;
			cout<<s<<endl;
		}
	}
}
