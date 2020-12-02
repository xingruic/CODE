/*
ID:xingrui1
LANG:C++
TASK:prefix
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> p=vector<string>();
string s="";
int longest=0;
/*
s=efrcdx
p={efrcdx}
*/
int prefix(){
    bool dp[s.size()];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<p.size(); j++){
            int t=p[j].size();
            if(i+1>=t){
                if(p[j]==s.substr(i-t+2,t)){
                    if(dp[i-t]){
                        dp[i]=1;
                        break;
                    }
                }
            }else dp[i]=1;
        }
    }
    for(int i=s.size()-1; i>=0; i--){
        if(dp[i]) return i+2;
    }
    return 0;
}
int main(){
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    {
        string c="";
        while(c!="."){
            cin>>c;
            p.push_back(c);
            longest=max((int)c.size(),longest);
        }
        p.pop_back();
    }
    char c=' ';
    while((c=getchar())!=-1){
        if(c=='\n') continue;
        s+=c;
    }
    // cout<<s.size()<<endl;
    cout<<prefix()<<endl;
}