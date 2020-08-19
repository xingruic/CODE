#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int cnt[n]={0};
  for(int i=0; i<n; i++){
    int j=i;
    while(j>0&&a[j-1]==a[j]){
        j--;
    }
    cnt[j]++;
  }
  for(int i=0; i<n; i++){
  	if(cnt[i]) cout<<a[i]<<' '<<cnt[i]<<endl;
  }
}