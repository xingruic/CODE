#include<bits/stdc++.h>
using namespace std;
int n;
int c[200001],r[200001];
int q;
int t[200001],h[200001];
int mana[200001];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>c[i]>>r[i];
        mana[i]=c[i];
    }
    cin>>q;
    for(int j=1; j<=n; j++){
        cin>>t[i]>>h[i];
    }
    int last_turn=0;
    for(int i=1; i<=n; i++){
        mana[i]=min(c[i],mana[i]+(t[i]-last_turn)*r[i]);
        last_turn=i;
        
    }
}