#include<iostream>
using namespace std;
int main(){
  int a,b,c,d,e,f;
  cin>>a;
  b=a%10*10000;
  b+=a/10%10*1000;
  b+=a/100%10*100;
  b+=a/1000%10*10;
  b+=a/10000%10;
  cout<<b<<endl;
}
