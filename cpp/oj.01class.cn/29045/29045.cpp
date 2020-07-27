#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  bool nsm=n<0;
  n=abs(n);
  int ans=0;
  while(n>0){
  	ans*=10;
    ans+=n%10;
    n/=10;
  }
  if(nsm) cout<<ans*-1;
  else cout<<ans;
}
