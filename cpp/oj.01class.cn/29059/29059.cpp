#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,I,J;
  cin>>N>>I>>J;
  int t=N;
  int i=0,j=0;
  int cnt=1;
  while(i+N-1>I-1&&i<I-1&&j+N-1>J-1&&j<J-1){
      cnt+=4*N-4;
      i++;
      j++;
      N-=2;
  }
  if(i+N-1>I-1&&i<I-1){
      if(j>=J-1){
          if(i!=I-1){
              cnt+=4*N-4-(I-2-i);
          }
      }else{
          cnt+=N-1+I-1-i;
      }
  }else{
      if(i>=I-1){
          cnt+=J-1-j;
      }else{//i+N-1<=I-1
            cnt+=N*4-4-N+1-(J-1-j);
      }
  }
    cout<<cnt<<endl;
}