#include<iostream>
using namespace std;
int main(){
  int farmers;
  cin>>farmers;
  bool books[1000001];
  int start=0, end=0, START=1000001, END=0, L1=0, L0=0;
  for(int i=0; i<farmers; i++){
    cin>>start>>end;
    START=min(START,start);
    if(end>END)END=end;
    for(int j=start; j<end; j++){
      books[j]=1;
    }
  }
  int l1=0,l0=0;
  for(int i=START; i<END; i++){
    if(books[i]==0){
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
