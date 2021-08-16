/*
ID:xingrui1
LANG:C++
TASK:concom
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    int m;
    cin>>m;
    int a[110][110];
    memset(a,0,sizeof(a));
    int n=0;
    for(int i=1; i<=m; i++){
        // a[i][i]=100; m和n不一样，这一句不能写在这
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        n=max(n,max(t1,t2));
        a[t1][t2]=t3;
    }
    n++;
    bool control[n+5][n+5];
    memset(control,0,sizeof(control));
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        if(a[i][j]>50) control[i][j]=1;
        control[i][i]=1;
    }
    bool did_stuff=0;
    do{
        did_stuff=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!control[i][j]){
                    int t=0;
                    for(int k=1; k<=n; k++){
                        if(control[i][k]){
                            t+=a[k][j];
                        }
                    }
                    if(t>50&&!control[i][j]){
                        control[i][j]=1;
                        did_stuff=1;
                    }
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i==j) continue;
        //         if(control[i][j]) cout<<i<<' '<<j<<'\t';
        //     }
        // }cout<<endl;
    }while(did_stuff);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(control[i][j]) cout<<i<<' '<<j<<endl;
        }
    }
}