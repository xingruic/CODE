/*
LANG:C++
ID:xingrui1
TASK:agrinet
*/
#include<bits/stdc++.h>
using namespace std;
struct edge{
    // from,to,weight
    int f,t,w;
};
int father[20001];
int size[20001]={0};
bool cmp(edge a,edge b){return a.w<b.w;}
int root(int a){
    if(father[a]==a) return a;
    return father[a]=root(father[a]);
}
void join(int a,int b){
    int x=root(a);
    int y=root(b);
    if(x!=y) father[x]=y;
}
int main(){
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) father[i]=i;
    int b[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>b[i][j];
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cnt++;
        }
    }
    edge a[cnt];
    cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            a[cnt].f=i;
            a[cnt].t=j;
            a[cnt++].w=b[i][j];
        }
    }
    sort(a,a+cnt,cmp);
    int ans=0;
    for(int i=0; i<cnt; i++){
        // cout<<root(a[i].f)<<' '<<root(a[i].t)<<' '<<a[i].w<<endl;
        if(root(a[i].f)!=root(a[i].t)){
            join(a[i].f,a[i].t);
            ans+=a[i].w;
        }
        if(ans==n-1) break;
    }
    cout<<ans<<endl;
}