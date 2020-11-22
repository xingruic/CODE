#include<iostream>
using namespace std;
int main(){
  int n,m;
  cin>>m>>n;
  for(int i=n; m>0&&i>1; i--){
    n*=i-1;
    m--;
  }
  cout<<n%100003<<endl;
}
