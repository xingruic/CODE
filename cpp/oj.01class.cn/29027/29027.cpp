#include<bits/stdc++.h>
using namespace std;
string in,post,pre;
void inpopre(int st,int end,int sst,int endd){
  if(st==end){
      cout<<"in:"<<in[end]<<",at"<<end<<endl;
  }
  if(sst-1==endd){
      cout<<"post:"<<post[endd]<<",at"<<endd<<endl;
  }
  if(st==end||sst-1==endd) return;
  pre=pre+post[endd];
  cout<<endl<<pre<<endl;
  for(int i=st; i<end; i++){
    if(in[i]==post[endd]){
      inpopre(st,i,sst,sst+i-st-1);
      inpopre(i+1,end,sst+i-st,endd-1);
    }
  }
}
int main(){
  cin>>in>>post;
  inpopre(0,in.size()-1,0,post.size()-1);
  cout<<pre<<endl;
}
// BADC  BDCA
// CBDAEGF CDBGFEA
// SHAGBF SHGFBA