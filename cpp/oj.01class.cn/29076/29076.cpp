#include<bits/stdc++.h>
using namespace std;
int v[0xfffff]={0}, l[0xfffff]={0}, r[0xfffff]={0};
bool sym(int idl,int idr){
  if(idl==-1&&idr==-1) return 1;
  if(idl==-1||idr==-1||v[idl]!=v[idr]) return 0;
  return sym(r[idl],l[idr])&&sym(r[idr],l[idl]);
}
int sum(int i,int s=0){
  if(i==-1) return s;
  s++;
  if(l[i]!=-1) s=sum(l[i],s);
  if(r[i]!=-1) s=sum(r[i],s);
  return s;
}
int main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>v[i];
  for(int i=1; i<=n; i++){
      cin>>l[i]>>r[i];
  }
  int m=0;
  for(int i=1; i<=n; i++){
    if(sym(l[i],r[i])) m=max(m,sum(i));
  }
  cout<<m<<endl;
}