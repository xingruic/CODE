#include<bits/stdc++.h>
using namespace std;
int n,m,start,a[100][100];
bool accessed[100]={0};
stack<int> stk;
void printstack(){
    auto stktmp=stk;
    while(!stktmp.empty()){
        cout<<stktmp.top()+1<<' ';
        stktmp.pop();
    }
    cout<<endl;
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("dfs.out","w",stdout);
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
    stk.push(start);
    while(!stk.empty()){
        int t=stk.top();
        stk.pop();
        if(accessed[t]==1) continue;
        accessed[t]=1;
        cout<<t+1<<endl;
        for(int i=0; i<n; i++){
            // cout<<t+1<<' '<<i+1;
            if(a[t][i]>-1&&accessed[i]==0){
                // cout<<'*';
                stk.push(i);
            }
            // cout<<endl;
        }
        // printstack();
    }
}