#include<bits/stdc++.h>
using namespace std;
// http://oj.01class.cn/problem/53408
int n,m,s,t;
int a[10000][10000];
int dijkstra(int start,int end){
    int dist[10000];
    memset(dist,0x3c,sizeof(dist));
    for(int j=1; j<=n; j++){
        dist[j]=a[start][j];
    }
    bool e;
    while(1){
        e=1;
        for(int i=1; i<=n; i++){
            if(dist[i]<0x33333333){
                for(int j=1; j<=n; j++){
                    if(i==j||a[i][j]>0x33333333) continue;
                    if(dist[j]>dist[i]+a[i][j]){
                        // cout<<i<<' '<<j<<' '<<dist[j]<<' '<<dist[i]<<' '<<a[i][j]<<endl;
                        e=0,dist[j]=dist[i]+a[i][j];
                    }
                }
            }
        }
        if(e) break;
    }
    return dist[end];
}
int main(){
    cin>>n>>m>>s>>t;
    memset(a,0x3c,sizeof(a));
    for(int i=1; i<=n; i++) a[i][i]=0;
    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(z>a[x][y]) continue;
        a[x][y]=z;
        a[y][x]=z;
    }
    cout<<dijkstra(s,t)<<endl;
}
/*
7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1
*/
