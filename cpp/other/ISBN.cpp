#include<iostream>
#include<string>
using namespace std;
int main(){
  string isbn;
  int last=0;
  cin>>isbn;
  last+=isbn[0]-48;
  for(int i=0; i<3; i++){
    last+=(isbn[i+2]-48)*(i+2);
  }
  for(int i=0; i<5; i++){
    last+=(isbn[i+6]-48)*(i+5);
  }
  cout<<last<<endl;
  last%=11;
  cout<<isbn[12]<<endl;
  if(isbn[12]==last)cout<<"Right"<<endl;
  else{
    isbn[12]==last;
    cout<<isbn<<endl;
  }
  return 0;
}
