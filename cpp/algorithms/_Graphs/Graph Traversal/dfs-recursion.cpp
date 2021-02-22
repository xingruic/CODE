#include<bits/stdc++.h>
using namespace std;
int n,m,start,a[100][100];
bool accessed[100]={0};
void dfs(int x=start){
    if(accessed[x]) return;
    accessed[x]=1;
    cout<<x+1<<endl;
    for(int i=0; i<n; i++){
        if(a[x][i]>-1) dfs(i);
    }
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("dfs-recursion.out","w",stdout);
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
    dfs();
}