/*
TASK:comehome
LANG:C++
ID:xingrui1
*/
#include<bits/stdc++.h>
using namespace std;
int a['Z'+1]['Z'+1];
bool cow['Z'+1]={0};
int dijkstra(int start,int end){
    int dist['Z'+1];
    memset(dist,0x3d,sizeof(dist));
    dist[start]=0;
    bool included['Z'+1];
    memset(included,0,sizeof(included));
    included[start]=1;
    while(1){
        bool did_stuff=0;
        for(int i='A'; i<='Z'; i++){
            if(included[i]){
                for(int j='A'; j<='Z'; j++){
                    if(i==j) continue;
                    if(a[i][j]>-1){
                        // cout<<a[i][j]<<' '<<(char)i<<' '<<(char)j<<endl;
                        if(!included[j]) did_stuff=1;
                        included[j]=1;
                        if(dist[j]>dist[i]+a[i][j]){
                            dist[j]=dist[i]+a[i][j];
                            did_stuff=1;
                        }
                    }
                }
            }
        }
        // cout<<endl;
        if(did_stuff==0) break;
    }
    return dist[end];
}
int main(){
    memset(a,-1,sizeof(a));
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int p;
    cin>>p;
    for(int i=0; i<p; i++){
        char a,b;
        int c;
        cin>>a>>b>>c;
        bool cowa=1,cowb=1;
        if(a>='a') a-='a'-'A',cowa=0;
        if(b>='a') b-='a'-'A',cowb=0;
        ::a[a][b]=::a[b][a]=c;
        cow[a]=cowa,cow[b]=cowb;
    }
    int minpath=0x7fffffff;
    char minbarn='.';
    for(char i='A'; i<'Z'; i++){ // no cows in barn, so i<'Z', not <='Z'
        if(cow[i]) if(minpath>dijkstra(i,'Z')){
            minpath=dijkstra(i,'Z'),minbarn=i;
            // cout<<i<<endl;
        }
    }
    cout<<minbarn<<' '<<minpath<<endl;
}