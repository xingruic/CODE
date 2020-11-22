#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n][m];
  memset(a,0,sizeof(a));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char temp;
      cin>>temp;
      if(temp=='*') a[i][j]=-1;
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(a[i][j]!=-1){
        if(i+1<n&&a[i+1][j]==-1) a[i][j]++;
        if(i>0&&a[i-1][j]==-1) a[i][j]++;
        if(j>0&&a[i][j-1]==-1) a[i][j]++;
        if(j+1<m&&a[i][j+1]==-1) a[i][j]++;
        if(i+1<n&&j+1<m&&a[i+1][j+1]==-1) a[i][j]++;
        if(i+1<n&&j>0&&a[i+1][j-1]==-1) a[i][j]++;
        if(i>0&&j+1<m&&a[i-1][j+1]==-1) a[i][j]++;
        if(i>0&&j>0&&a[i-1][j-1]==-1) a[i][j]++;
        cout<<a[i][j];
      }else cout<<'*';
    }cout<<endl;
  }
}