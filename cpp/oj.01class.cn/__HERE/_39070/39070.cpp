#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,s,t;
    cin>>n>>m;
    int a[n+1][n+1];
    memset(a,0x3c,sizeof(a));
    for(int i=0; i<m; i++){
        int b,c;
        cin>>b>>c;
        a[b][c]=1;
    }
    cin>>s>>t;
    if(s>n||t>n){
        cout<<-1<<endl;
        return 0;
    }
    // BFS
    queue<int> q;
    bool got[n+1]={0};
    q.push(t);
    int x,i;
    int dist[n+1];
    memset(dist,0x3c,sizeof(dist));
    dist[t]=0;
    int parent[n+1];
    memset(parent,0x3c,sizeof(parent));
    while(!q.empty()){
        x=q.front();
        got[x]=1;
        q.pop();
        if(x!=s)
        for(i=1; i<=n; i++){
            if(!got[i]&&a[x][i]<0x3c3c3c3c){
                cout<<x<<'>'<<i<<"&"<<endl;
                break;
            }
        }
        if(i<=n){
            cout<<parent[x]<<endl;
            dist[parent[x]]=0x3c3c3c3c;
            continue;
        }
        for(i=1; i<=n; i++){
            if(got[i]) continue;
            if(a[i][x]<0x3c3c3c3c){
                cout<<x<<'<'<<i<<endl;
                q.push(i);
                parent[i]=x;
                dist[i]=dist[x]+1;
            }
        }
    }
    cout<<(dist[s]==0x3c3c3c3c?-1:dist[s])<<endl;
}