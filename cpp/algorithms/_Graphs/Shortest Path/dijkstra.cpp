#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,n;
    cin>>t>>n;
    int a[n+1][n+1];
    // int dist[n+1]; // distance to bessie's forest from each landmark
    memset(a,0x7f,sizeof(a));
    for(int i=1; i<=n; i++) a[i][i]=0;
    for(int i=0; i<t; i++){
        int q,b,c;
        cin>>q>>b>>c;
        a[q][b]=c;
        a[b][q]=c;
    }
    
}