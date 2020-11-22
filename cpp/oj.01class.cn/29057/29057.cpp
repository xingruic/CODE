#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int num[n], nums=0, count[n]={0};
  for(int i=0; i<n; i++){
    cin>>num[i];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
    	if(j!=i){
	        for(int k=j+1; k<n; k++){
	        	if(k!=i){
		          if(num[i]==num[j]+num[k]){
		          	count[i]=1;
		          }
	      		}
	        }
	    }
    }
  }
  for(int i=0; i<n; i++){
  	if(1==count[i]) nums++;
  }
  cout<<nums<<endl;
}
