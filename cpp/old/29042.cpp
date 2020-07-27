#include<bits/stdc++.h>
using namespace std;
int main(){
  int f,s;
  cin>>s>>f;
  int w[s];
  for(int i=0; i<s; i++) cin>>w[i];
  if(f>s){
      int k=0;
      for(int i=0; i<s; i++) k=max(k,w[i]);
  }
  bool done=0;
  int ans=0;
  while(!done){
      cout<<f<<' '<<ans;
      for(int i=0; i<s; i++) cout<<' '<<w[i];
      cout<<'+'<<endl;
    for(int i=0; i<s; i++){
        if(w[i]==0){
            f++;
        }
      else if(f>0){
        w[i]--;
        f--;
      }else{
        break;
      }
    }
    ans++;
    if(w[s-1]==0) break;
  }
  cout<<ans<<endl;
}