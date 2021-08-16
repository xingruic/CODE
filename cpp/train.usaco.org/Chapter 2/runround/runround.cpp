/*
ID:xingrui1
LANG:C++
TASK:runround
*/
#include<bits/stdc++.h>
using namespace std;
bool distdig(long long i){
    string s=to_string(i);
    for(int j=0; j<s.size(); j++){
        for(int k=j+1; k<s.size(); k++){
            if(s[j]==s[k]) return 0;
        }
    }
    return 1;
}
bool zero(long long i){
    string s=to_string(i);
    for(int j=0; j<s.size(); j++){
        if(s[j]=='0') return 1;
    }
    return 0;
}
int cnt=0;
// 81362
bool rround(long long x){
    // int ttt=clock()*1.0/CLOCKS_PER_SEC;
    if(!distdig(x)) return 0;
    string s=to_string(x);
    int n=s.size();
    int idx=0;
    bool touch[n];
    memset(touch,0,sizeof(touch));
    if(zero(x)) return 0;
    int t;
    for(int i=0; 1; i++){
        cnt++;
        touch[idx%n]=1;
        t=idx;
        idx=(idx+s[idx%n]-'0')%n;
        if(idx%n==0){
            bool _t=0;
            for(int j=0; j<n; j++) if(!touch[j]){
                if(i<n){
                    _t=1;
                    break;
                }else return 0;
            }
            if(!_t){
                // cout<<clock()*1.0/CLOCKS_PER_SEC-ttt<<endl;
                return 1;
            }
        }
        if(touch[idx%n]||i>n) return 0;
    }
    return 0;
}
int main(){
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    // int ttt=clock();
    long long m;
    cin>>m;
    // cout<<rround(134259)<<endl;
    for(long long i=m+1; 1; i++){
        if(rround(i)){
            cout<<i<<endl;
            // cout<<(clock()-ttt)*1.0/CLOCKS_PER_SEC<<endl;
            return 0;
        }
    }
    // cout<<cnt<<endl;
}