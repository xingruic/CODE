#include<iostream>
using namespace std;
int main(){
  int k;
  cin>>k;
  int n;
  if(k==1){
  	cout<<2<<endl;
  	return 0;
  }
  double sum=0;
  for(n=1; sum<k; n++){
	sum+=1.0/n;
  }
  cout<<n-1<<endl;
}
