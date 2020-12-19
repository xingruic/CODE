/*
ID:xingrui1
LANG:C++
TASK:runround
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool runround(int x){
    string s=to_string(x);
    {
        bool t['9'+1];
        memset(t,0,sizeof(t));
        for(int i=0; i<s.size(); i++){
            // cout<<t[s[i]]<<endl;
            if(t[s[i]]) return 0;
            t[s[i]]=1;
        }
    }
    bool t[s.size()];
    memset(t,0,sizeof(t));
    int j=0;
    for(int i=0; i<s.size(); i++){
        // cout<<s[j]<<endl;
        t[j]=1;
        j+=s[j]-'0';
        j%=s.size();
    }
    for(int i=0; i<s.size(); i++) if(!t[i]) return 0;
    return j==0;
}
int nextr(){
    int i;
    for(i=n+1; !runround(i); i++){}
    return i;
}
int main(){
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    cin>>n;
    cout<<nextr()<<endl;
    // cout<<runround(81364)<<endl;
}