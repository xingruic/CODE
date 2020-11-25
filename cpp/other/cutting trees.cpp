#include<iostream>
using namespace std;
int main(){
  int ll,m,start,end,trees=0;
  cin>>ll>>m;
  int l[ll+1]={0};
  for(int i=0; i<m; i++){
    cin>>start>>end;
    for(int j=start; j<=end; j++){
      l[j]=1;
    }
  }
  for(int i=0; i<=ll; i++){
    if(l[i]==0){
      trees++;
    }
  }
  cout<<trees<<endl;
}
