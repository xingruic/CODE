#include<iostream>
using namespace std;
int main(){
  int x,g6=0,g5=0,g4=0;
  cin>>x;
  if(x%4==0){
    g4=x/4;
  }else if(x%4==1){
    g4=x/4-1;
    g5=1;
  }else if(x%4==2){
    g4=x/4-1;
    g6=1;
  }else{
    g4=x/4-2;
    g5=1;
    g6=1;
  }
  cout<<g6<<' '<<g5<<' '<<g4;
}
