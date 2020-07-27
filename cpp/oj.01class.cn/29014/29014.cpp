#include<bits/stdc++.h>
using namespace std;
void print(int a[],int len){
    for(int i=0; i<len; i++)cout<<a[i]<<' ';
    cout<<endl;
    return;
}
int main(){
  //1
  int r,c,h,v,t;
  cin>>r>>c>>h>>v>>t;
  int tr[r-1]={0},tc[c-1]={0};
  for(int i=0; i<t; i++){
      int x,y,p,q;
      cin>>x>>y>>p>>q;
      if(y!=q){
          tc[y-2]++;
      }else if(x!=p){
          tr[x-2]++;
      }
  }
  print(tr,r-1);
  print(tc,c-1);
  /*
  1. talkers in every row/col into arrays
  2. sort arrays
  3. greedy
  */
}