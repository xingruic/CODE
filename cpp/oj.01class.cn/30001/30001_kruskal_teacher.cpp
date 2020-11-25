#include<bits/stdc++.h>
using namespace std;
int n,cnt,sum,ans;
int fa[105];
 
struct edg{
    int from,to,dis;
}edge[10005];
 
bool cmp(edg x,edg y){
    return x.dis<y.dis;
}
 
int find(int x){ 
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
 
void join(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x!=y) fa[x]=y;
}
 
int main(){
    freopen("30001.in","r",stdin);
    freopen("30001.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(i!=j){
                cnt++;
                edge[cnt].dis=x;
                edge[cnt].from=i,edge[cnt].to=j;
            }
        }
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        cout<<find(edge[i].from)<<' '<<find(edge[i].to)<<' '<<edge[i].dis<<endl;
        if(find(edge[i].from)!=find(edge[i].to)){
            join(edge[i].from,edge[i].to);
            sum+=edge[i].dis;
            ans++;
        }
        if(ans==n-1) break;
    }
    cout<<sum;
    return 0;
}