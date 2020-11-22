/*
ID: xingrui1
LANG: C++
TASK: ariprog
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[10000],d[10000];
bool s[1000000];
int main(){
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    // int T=clock();
    cin>>n>>m;
    for(int q=0; q<=m; q++){
        for(int p=0; p<=m; p++){
            s[q*q+p*p]=1;
        }
    }
    int t1=0;
    // n>=3 and b>=1, smallest last term is from a,a+1,a+2
    for(int a=0; a+2<=2*m*m; a++){
        if(!s[a]) continue;
        bool t=0;
        // `a+b*(n-1)`, decrease iterations from `a+b`
        for(int b=1; a+b*(n-1)<=2*m*m; b++){
            if(!s[a+b]||!s[a+2*b]) continue;
            if(a+b>2*m*m){
                t=1;
                break;
            }
            int j;
            for(j=a; j<=a+b*(n-1); j+=b){
                if(!s[j]) break;
            }
            if(j>=a+b*n){
                v[t1]=a;
                d[t1++]=b;
            }
        }
        if(t) break;
    }
    if(t1==0){
        cout<<"NONE"<<endl;
        return 0;
    }
    for(int i=0; i<t1; i++) for(int j=1; j<t1; j++) if(d[j]<d[j-1]){
        swap(d[j],d[j-1]);
        swap(v[j],v[j-1]);
    }
    for(int i=0; i<t1; i++) cout<<v[i]<<' '<<d[i]<<endl;
    // cout<<clock()-T<<endl;
}