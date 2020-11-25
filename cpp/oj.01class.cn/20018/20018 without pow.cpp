#include<iostream>
using namespace std;
int main(){
  int farmers;
  cin>>farmers;
  int time[1000001]={0}, start, end, END=0, L1, L0;
  for(int i=0; i<farmers; i++){
    cin>>start>>end;
    if(end>END)END=end;
    for(int j=start; j<=end; j++){
      time[j]=1;
    }
  }
  int l1=0,l0=0;
  for(int i=0; i<END; i++){
    if(time[i]==0){
      l0++;
      L1=max(L1,l1);
      l1=0;
    }else{
      l1++;
      L0=max(L0,l0);
      l0=0;
    }
  }
  L1=max(L1,l1);
  L0=max(L0,l0);
  cout<<L1<<' '<<L0;
}
