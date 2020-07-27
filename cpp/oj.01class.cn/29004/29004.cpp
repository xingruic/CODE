#include<bits/stdc++.h>
using namespace std;
int len(int num){
  int i;
  for(i=0; num>0; i++) num/=10;
  return i;
}
int main(){
  int n,k;
  cin>>n>>k;
  float t=pow(10,k);
  for(;len(n)<len(k);n*=n){}
  int a=n%t;
  int cnt=0;
  do{
  	n=(n%t)*(n%t);
  	cnt++;
  }while(n%t!=a);
  cout<<cnt;
}
