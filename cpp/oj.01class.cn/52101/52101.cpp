#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int c[n];
  for(int i=0; i<n; i++) cin>>c[i];
  int bes=0;
  for(int i=0; i<=n/2; i++){
    if(!i%2){
      bes+=max(c[i],c[n-1-i]);
    }
  }
  cout<<bes<<endl;
}
