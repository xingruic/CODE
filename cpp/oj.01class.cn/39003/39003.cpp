#include<bits/stdc++.h>
using namespace std;
string convert(int num,int base){
  if(num==0) return "0";
  string ans="";
  while(num){
    int remainder=num%base;
    num/=base;
    if(remainder<0){
      remainder+=-1*base;
      num++;
    }
    if(remainder<=9)
      ans=(char)(remainder+'0')+ans;
    else
      ans=(char)(remainder+'A'-10)+ans;
    // cout<<remainder<<endl;
  }
  return ans;
}
int main(){
  int x,y;
  cin>>x>>y;
  cout<<x<<'='<<convert(x,y)<<"(base"<<y<<')'<<endl;
}