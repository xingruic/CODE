#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int mod=1;
  for(int i=0; i<k; i++) mod*=10;
  vector<int> last;
  bool done=0;
  int cnt=0;
  for(;!done;cnt++){
    for(auto i=--last.end(); i!=--last.begin(); i--){
      if(*i==(n=n%mod)){
        done=1;
        break;
      }
    }
    last.push_back(n);
    n*=n;
  }
  cout<<cnt<<endl;
}