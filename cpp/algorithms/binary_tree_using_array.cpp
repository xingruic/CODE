#include<bits/stdc++.h>
using namespace std;
void prntarr(int a[],int l){
    for(int i=0; i<l; i++){
        cout<<a[i]<<' ';
    }cout<<endl;
    return;
}
void preorder(int v[],int idxl[],int idxr[],int i=0){
  cout<<v[i]<<endl;
  if(idxl[i]!=-2) preorder(v,idxl,idxr,idxl[i]);
  //'idxl[i]!=-2',because in line 25,'idxl[i]=lf-1',so '-1' will turn into '-2'
  if(idxr[i]!=-2) preorder(v,idxl,idxr,idxr[i]);
  //'idxr[i]!=-2',because in line 26,'idxr[i]=rf-1',so '-1' will turn into '-2'
  return;
}
int main(){
  int n;
  cin>>n;
  int v[n];
  for(int i=0; i<n; i++) cin>>v[i];
  int idxl[n];
  int idxr[n];
  for(int i=0; i<n; i++){
    int lf,rt;
    cin>>lf>>rt;
    idxl[i]=lf-1;
    idxr[i]=rt-1;
  }
  for(int i=0; i<n; i++){
    cout<<idxl[i]<<' '<<idxr[i]<<endl;
  }
  preorder(v,idxl,idxr);
}