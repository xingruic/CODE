/*
ID:xingrui
LANG:C++
TASK:range
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int a[250][250];
bool check(int i,int j,int size){
    if(i+size-1>=n||j+size-1>=n) return 0;
    for(int a=i; a<i+size; a++){
        for(int b=j; b<j+size; b++){
            if(::a[a][b]==0) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[i][j]=getchar();
            if(a[i][j]=='\n') a[i][j]=getchar();
            a[i][j]-='0';
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<a[i][j]<<' ';
    //     }cout<<endl;
    // }
    int cnt[n+1]={0};
    for(int s=2; s<=n; s++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check(i,j,s)){
                    // cout<<i<<' '<<j<<' '<<s<<endl;
                    cnt[s]++;
                }
            }
        }
    }
    for(int i=2; i<=n; i++) if(cnt[i]>0) cout<<i<<' '<<cnt[i]<<endl;
}