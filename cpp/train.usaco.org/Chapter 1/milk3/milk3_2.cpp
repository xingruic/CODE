/*
ID: xingrui1
TASK: milk3
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int capa,capb,capc;
bool m[25][25][25];
bool f[25];
bool first=1;
void milk(int a,int b,int c){
    if(m[a][b][c]) return;
    m[a][b][c]=1;
    if(a==0){
        f[c]=1;
    }
    first=1;
    if(a>capb-b) milk(a-(capb-b),capb,c);
    else milk(0,b+a,c);
    
    if(b>capa-a) milk(capa,b-(capa-a),c);
    else milk(a+b,0,c);

    if(b>capc-c) milk(a,b-(capc-c),capc);
    else milk(a,0,c+b);

    if(c>capb-b) milk(a,capb,c-(capb-b));
    else milk(a,b+c,0);

    if(c>capa-a) milk(capa,b,c-(capa-a));
    else milk(a+c,b,0);

    if(a>capc-c) milk(a-(capc-c),b,capc);
    else milk(0,b,c+a);

    return;
}
int main(){
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    cin>>capa>>capb>>capc;
    memset(m,0,sizeof(m));
    memset(f,0,sizeof(f));
    milk(0,0,capc);
    for(int i=0; i<capc; i++){
        if(f[i]) cout<<i<<' ';
    }
    cout<<capc<<endl;
}