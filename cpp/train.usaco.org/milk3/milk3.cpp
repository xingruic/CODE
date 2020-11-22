/*
ID: xingrui1
TASK: milk3
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int capa,capb,capc;
// vector<int> ans;
bool appeared[20][20][20]={{{0}}};
bool print[20];
// 每次递归更新appeared，发现appeared[a][b][c]是true，退出递归
void milk(int a=0,int b=0,int c=capc){
    if(appeared[a][b][c]) return;
    appeared[a][b][c]=1;
    if(a==0){
        print[c]=1;
    }

    if(capa-a>=b) milk(a+b,0,c);
    else milk(capa,b-(capa-a),c);
    if(capb-b>=a) milk(0,b+a,c);
    else milk(a-(capb-b),capb,c);

    if(capb-b>=c) milk(a,b+c,0);
    else milk(a,capb,c-(capb-b));
    if(capc-c>=b) milk(a,0,c+b);
    else milk(a,b-(capc-c),capc);

    if(capa-a>=c) milk(a+c,b,0);
    else milk(capa,b,c-(capa-a));
    if(capc-c>=a) milk(0,b,c+a);
    else milk(a-(capc-c),b,capc);
}
int main(){
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    // int a=0,b=0,c=capc;
    cin>>capa>>capb>>capc;
    milk();
    for(int i=0; i<capc; i++) if(print[i]) cout<<i<<' ';
    cout<<capc<<endl;
}