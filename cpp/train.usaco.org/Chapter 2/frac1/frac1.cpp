/*
ID: xingrui1
LANG: C++
TASK: frac1
*/
#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> c[10000];
int cnt=0;
bool _greater(pair<int,int> a,pair<int,int> b){
    return a.first*b.second>a.second*b.first;
}
bool _equal(pair<int,int> a,pair<int,int> b){
    return a.first*b.second==a.second*b.first;
}
int _gcd(int m,int n){
    int t = 1;
    while(t != 0){
        t=m%n;
        m=n;
        n=t;
    }
    return m;
}
void frac(){
    c[cnt++]=make_pair(0,1);
    for(int b=1; b<=n; b++){
        for(int a=1; a<=b; a++){
            if(_gcd(a,b)==1) c[cnt++]=make_pair(a,b);
        }
    }
}
int main(){
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin>>n;
    frac();
    for(int i=1; i<cnt; i++){
        for(int j=1; j<cnt; j++){
            if(!_greater(c[j],c[j-1])) swap(c[j],c[j-1]);
        }
    }
    for(int i=0; i<cnt; i++){
        if(c[i].first>n||c[i].second>n) continue;
        cout<<c[i].first<<'/'<<c[i].second<<endl;
    }
}