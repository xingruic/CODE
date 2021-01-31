#include<bits/stdc++.h>
using namespace std;
int n,m,start,a[100][100];
bool accessed[100]={0};
queue<int> q;
int main(){
    freopen("bfs.in","r",stdin);
    freopen("bfs.out","w",stdout);
    memset(a,-1,sizeof(a));
    for(int i=0; i<n; i++) a[i][i]=0;
    cin>>n>>m>>start;
    start--;
    for(int i=0; i<m; i++){
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        a1--,a2--;
        a[a2][a1]=a[a1][a2]=min(a[a1][a2]==-1?1000000:a[a1][a2],a3);
    }
    q.push(start);
    accessed[start]=1;
    while(!q.empty()){
        int t=q.front();
        cout<<t+1<<endl;
        q.pop();
        for(int i=0; i<n; i++){
            // cout<<t+1<<' '<<i+1;
            if(a[t][i]>-1&&accessed[i]==0){
                // cout<<'*';
                q.push(i),accessed[i]=1;
            }
            // cout<<endl;
        }       
    }
}