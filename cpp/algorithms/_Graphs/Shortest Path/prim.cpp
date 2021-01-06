#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,n;
    cin>>t>>n;
    int a[n+1][n+1];
    // int dist[n+1]; // distance to bessie's forest from each landmark
    memset(a,0x0f,sizeof(a));
    for(int i=1; i<=n; i++) a[i][i]=0;
    for(int i=0; i<t; i++){
        int q,b,c;
        cin>>q>>b>>c;
        a[q][b]=c;
        a[b][q]=c;
    }
    bool selected[n+1];
    memset(selected,0,sizeof(selected));
    selected[1]=1;
    int num=1;
    int cnt=0;
    while(num<n){
        int u,v;
        int min=0x7fffffff;
        for(int i=1; i<=n; i++){
            if(selected[i]){
                for(int j=1; j<=n; j++){
                    if(!selected[j]&&a[i][j]){
                        if(a[i][j]<min){
                            min=a[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        num++;
        cnt+=a[u][v];
        selected[v]=1;
    }
    cout<<cnt<<endl;
}