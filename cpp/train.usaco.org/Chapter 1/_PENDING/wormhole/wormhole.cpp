#include<bits/stdc++.h>
using namespace std;
int n,x[20],y[20],p[21],r[20],cnt=0;
bool check(){
    for(int i=0; i<n; i++){
        // at most n times before loop, no loop in n times = no loop at all
        int t=i;
        for(int j=0; j<n; j++){
            t=p[r[t]+1];
            if(t==-1){
                break;
            }
        }
        if(t!=-1) return 1;
    }
    return 0;
}
void worm(){
    bool t=0;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(p[i]==-1&&p[j]==-1){
                t=1;
                p[i]=j;
                p[j]=i;
                worm();
                p[i]=-1;
                p[j]=-1;
            } 
        }
    }
    if(!t){
        // for(int i=1; i<=n; i++){
        //     cout<<i<<':'<<p[i]<<' ';
        // }cout<<check()<<endl;
        if(check()) cnt++;
    }
}
int main(){
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    memset(p,-1,sizeof(p));
    memset(r,-1,sizeof(r));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(x[j]>x[i]&&y[j]==y[i]){
                if(r[i]==-1||x[r[i]]>x[j]) r[i]=j;
            }
        }
        // cout<<r[i]<<endl;
    }
    worm();
    cout<<cnt/2<<endl;
}