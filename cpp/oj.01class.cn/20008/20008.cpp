/*
ID: xingrui1
TASK: palsquare
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
  }//1000100001
  return temp==num;
}
int main(){
  freopen("palsquare.in","r",stdin);
  freopen("palsquare.out","w",stdout);
  int base;
  cin>>base;
  for(int i=1; i<=300; i++){
    if(palin(convert(i*i,base))){
      cout<<convert(i,base)<<' '<<convert(i*i,base)<<endl;
    }
  }
//	string pal;
//	cin>>pal;
//	cout<<palin(pal)<<endl;
}
