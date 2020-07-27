#include<iostream>
using namespace std;
int main(){
  int n,a,s=0,l=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a>l){
      l=a;
    }if(a<s){
      s=a;
    }
  }
  cout<<l<<s<<endl;
}
