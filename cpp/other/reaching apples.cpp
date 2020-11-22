#include<iostream>
using namespace std;
int main(){
  int h[10],height,apples=0;
  for(int i=0; i<10; i++){
    cin>>h[i];
  }
  cin>>height;
  for(int i=0; i<10; i++){
    if(h[i]-height-30<=0){
      apples++;
    }
  }
  cout<<apples<<endl;
}
