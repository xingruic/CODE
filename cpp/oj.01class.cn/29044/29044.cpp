#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int b[n][n],a[n][n];
  int han[n/2],pc[n/2];
  int h=0,p=0;
  memset(b,0,sizeof(b));
  memset(a,0,sizeof(a));
  memset(han,-1,sizeof(han));
  memset(pc,-1,sizeof(pc));
  for(int i=1; i<n; i++){
    for(int j=i; j<n; j++){
      cin>>b[i][j];
      a[i][j]=b[i][j];
    }
  }
  for(int i=0; i<n/2; i++){
    int m=0,u,v;
    for(int i=1; i<n; i++){
      for(int j=i; j<n; j++){
        if(m<=a[i][j]){
          m=a[i][j];
          u=i;
          v=j;
        }
      }
    }
    han[h++]=u;
    a[u][v]=0;
    for(int i=0; i<n/2; i++){
      m=0;
      for(int j=0; j<n; j++){
        if(m<=a[han[i]][j]){
          m=a[han[i]][j];
          v=j;
        }
      }
      for(int i=0; i<n; i++){
        a[i][v]=0;
        a[v][i]=0;
      }
      pc[p++]=v;
    }
  }
  bool hanwin=1;
  int m=0;
  for(int i=0; i<n/2; i++){
    for(int j=i+1; j<n/2; j++){
      m=max(b[han[i]][han[j]],m);
    }
  }
  for(int i=0; i<n/2; i++){
    for(int j=i+1; j<n/2; j++){
      if(b[pc[i]][pc[j]]>m) hanwin=0;
    }
  }
  if(hanwin) cout<<1<<endl<<m;
  else cout<<0;
}