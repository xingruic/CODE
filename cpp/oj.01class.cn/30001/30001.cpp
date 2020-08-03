#include<iostream>
using namespace std;
int main(){
    freopen("30001.in","r",stdin);
    freopen("30001.out","w",stdout);
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
    bool selected[n]={1};
    int num=1;
    int ans=0;
    while(num<n){
        int u,v;
        int min=0x7fffffff;
        for(int i=0; i<n; i++){
            if(selected[i]){
                for(int j=0; j<n; j++){
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
        ans+=a[u][v];
        selected[v]=1;
    }
    cout<<ans<<endl;
}