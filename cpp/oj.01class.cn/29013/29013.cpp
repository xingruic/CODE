#include<iostream>
#include<string>
using namespace std;
int main(){
  string isbn;
  int last;
  cin>>isbn; 
  last+=isbn[0]-48;
  for(int i=2; i<5; i++){
    last+=(isbn[i]-48)*i;
  }
  for(int i=6; i<11; i++){
    last+=(isbn[i]-48)*(i-1);
  }
  last%=11;
  if(last==isbn[12]-48||(isbn[12]=='X'&&last==10)){
    cout<<"Right"<<endl;
  }else if(last==10){
    isbn[12]='X';
  	cout<<isbn<<endl;
  }else{
    isbn[12]=last+48;
    cout<<isbn<<endl;
  }
  return 0;
}
