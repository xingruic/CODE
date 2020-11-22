#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("39044.in","r",stdin);
    int m,n;
    cin>>m>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int mem[m],t=0;
    memset(mem,-1,sizeof(m));
    int cnt=0;
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<m; j++) if(mem[j]==a[i]) break;
        if(j==m){
            if(t<m){
                mem[t++]=a[i];
                cnt++;
            }else{
                for(j=1; j<m; j++) mem[j-1]=mem[j];
                mem[t-1]=a[i];
                cnt++;
            }
        }
        // for(j=0; j<m; j++) cout<<mem[j]<<' ';
        // cout<<endl;
    }
    cout<<cnt<<endl;
}