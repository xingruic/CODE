#include<iostream>
using namespace std;
int main(){
  int l,r,num2=0;
  cin>>l>>r; 
  for(int i=l; i<=r; i++){
    int j=i;
	while(j!=0){
      if(j%10==2)num2++;
      j/=10;
    }
  }
  cout<<num2<<endl;
  return 0;
}
