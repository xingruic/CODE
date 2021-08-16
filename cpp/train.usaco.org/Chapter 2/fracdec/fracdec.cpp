/*
LANG:C++
ID:xingrui1
TASK:fracdec
*/
#include<bits/stdc++.h>
using namespace std;
string substring(string s,int i,int len){
    char ans[len];
    for(int j=i; j<i+len; j++){
        ans[j-i]=s[j];
    }
    return string(ans,ans+len);
}
string tostring(int n){
    if(n==0) return "0";
    string ans="";
    while(n>0){
        ans=(char)(n%10+'0')+ans;
        n/=10;
    }
    return ans;
}
int main(){
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    // int t2=clock();
    int n,d;
    cin>>n>>d;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    string ans="";
    vector<int> passed;
    int t=0;
    while(n>=d){
        t+=1;
        n-=d;
    }
    ans+=tostring(t)+".";
    // cout<<ans<<endl; 
    while(1){
        passed.push_back(n);
        n*=10;
        t=0;
        while(n>=d){
            t+=1;
            n-=d;
        }
        ans+=tostring(t);
        int i;
        for(i=0; i<passed.size(); i++){
            if(n==passed[i]){
                // cout<<i<<endl;
                int j;
                for(j=0; ans[j]!='.'; j++){
                }
                j++;
                ans=substring(ans,0,i+j)+'('+substring(ans,i+j,ans.size()-i-j)+')';
                break;
            }
        }
        if(i<passed.size()) break;
        // cout<<t<<endl;
    }
    if(substring(ans,ans.size()-3,3)=="(0)") for(int i=0; i<3; i++) ans.pop_back();
    if(ans[ans.size()-1]=='.') ans+='0';
    int start=0;
    if(ans.size()>76){
        while(ans.size()-start>76){
            cout<<substring(ans,start,76)<<endl;
            start+=76;
        }
        cout<<substring(ans,start,ans.size()-start)<<endl;
    }
    else cout<<ans<<endl;
    // cout<<(clock()-t2)*1.0/CLOCKS_PER_SEC<<endl;
}