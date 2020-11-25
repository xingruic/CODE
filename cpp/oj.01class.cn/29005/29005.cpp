#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int rnum[n], nlist[n]={0};
  for(int i=0; i<n; i++){
    cin>>rnum[i];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n-1; j++){
      if(rnum[j]>rnum[j+1])
      	swap(rnum[j],rnum[j+1]);
    }
  }
  nlist[0]=rnum[0];
  int j=1;
  for(int i=1; i<n; i++){
    if(rnum[i]!=rnum[i-1]){
      nlist[j]=rnum[i];
      j++;
    }
  }
  cout<<j<<endl;
  for(int i=0; i<j; i++){
    cout<<nlist[i]<<' ';
  }
}
