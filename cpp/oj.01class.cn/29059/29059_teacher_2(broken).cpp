#include<bits/stdc++.h> 
using namespace std;
 int a[1000][1000];
 int main(){
 int n,cnt=1,x=1,y=1;
 cin>>n;
 cnt=1;
 a[1][1]=1;

 while (cnt<n*n){

 while (a[x][y+1]==0&&y+1<=n) {
cnt++;
a[x][++y]=cnt;
}//向右
 while (a[x+1][y]==0&&x+1<=n) {
cnt++;
a[++x][y]=cnt;
}//向下
 while (a[x][y-1]==0&&y-1>=1) {
cnt++;
a[x][--y]=cnt;
}//向左
 while (a[x-1][y]==0&&x-1>=1) {
cnt++;
a[--x][y]=cnt;

 }//向上
 } for(int i=1;
i<=n;
i++){
 for(int j=1;
j<=n;
j++) cout<<a[i][j]<<'\t';
 cout<<endl;

 } return 0;

 } 