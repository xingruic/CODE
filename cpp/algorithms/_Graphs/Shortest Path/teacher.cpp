#include<bits/stdc++.h>
using namespace std;
int a[2510][2510];
int d[2510];
bool f[2510];
int t,c,ts,te;
void dijkstra(int st){
    for (int i=1;i<=t;i++)  d[i]=a[st][i];
    memset(f,false,sizeof(f));
    f[st]=true;d[st]=0;
    for (int i=1;i<=t;i++)
    {
        int min=1000000000,k=0;
        for (int j=1;j<=t;j++)
        if ((!f[j])&&(d[j]<min)) {
        min=d[j];k=j;}
        if (k==0)  return; 
        f[k]=true; 
        for (int j=1;j<=t;j++)  
           { if ((!f[j])&&(d[k]+a[k][j]<d[j]))   
             d[j]=d[k]+a[k][j];     }
    }
}
int main(){
    cin>>t>>c>>ts>>te;
    int x,y,z;
    memset(a,10,sizeof(a));
    for (int i=1;i<=c;i++){
        cin>>x>>y>>z;
        if (a[x][y]&&a[x][y]>z) {a[x][y]=z;a[y][x]=z;}//判断重复的情况 
        if (!a[x][y]) {a[x][y]=z;a[y][x]=z;}
    }
dijkstra(ts);//起点 
cout<<d[te];//终点 
    return 0;
}