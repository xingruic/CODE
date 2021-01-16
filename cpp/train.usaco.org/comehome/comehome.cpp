/*
TASK:comehome
LANG:C++
ID:xingrui1
*/
#include<bits/stdc++.h>
using namespace std;
int a['z'+1]['z'+1];
int dijkstra(int start,int end){
    int dist[128];
    memset(dist,0x3c,sizeof(dist));
    for(int j='A'; j<='z'; j++){
        if(j>'Z'&&j<'a') continue;
        dist[j]=a[start][j];
    }
    bool e;
    while(1){
        e=1;
        for(int i='A'; i<='z'; i++){
            if(i>'Z'&&i<'a') continue;
            if(dist[i]<0x33333333){
                for(int j='A'; j<='z'; j++){
                    if(j>'Z'&&j<'a') continue;
                    if(i==j||a[i][j]>0x33333333) continue;
                    if(dist[j]>dist[i]+a[i][j]){
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
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    memset(a,0x3c,sizeof(a));
    int p;
    cin>>p;
    for(int i=0; i<p; i++){
        char a,b;
        int c;
        cin>>a>>b>>c;
        if(::a[a][b]>c)::a[a][b]=::a[b][a]=c;
    }
    int minpath=0x7fffffff;
    char minbarn='.';
    for(char i='A'; i<'Z'; i++){
        int t=dijkstra(i,'Z');
        if(minpath>t) minbarn=i,minpath=t;
    }
    // cout<<dijkstra('R','Z')<<endl;
    cout<<minbarn<<' '<<minpath<<endl;
}