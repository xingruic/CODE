#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+=s;
    n*=2;
    int l2r[n],r2l[n];
    memset(l2r,0,sizeof(l2r));
    memset(r2l,0,sizeof(r2l));
    l2r[0]=1;
    int numw=s[0]=='w'?1:0;
    char lastchar=s[0];
    for(int i=1; i<n; i++){
        if(s[i]=='w'){
            l2r[i]=l2r[i-1]+1;
            numw++;
        }
        else{
            if(i==1&&s[0]=='w'){
                l2r[i]=l2r[i-1]+1;
            }else if(s[i]==lastchar){
                l2r[i]=l2r[i-1]+1;
            }else{
                l2r[i]=numw+1;
            }
            numw=0;
            lastchar=s[i];
        }
        // cout<<l2r[i]<<endl;
    }
    r2l[n-1]=1;
    numw=s[n-1]=='w'?1:0;
    lastchar=s[n-1];
    for(int i=n-2; i>=0; i--){
        if(s[i]=='w'){
            r2l[i]=r2l[i+1]+1;
            numw++;
        }
        else{
            if(i==n-2&&s[n-1]=='w'){
                r2l[i]=r2l[i+1]+1;
            }else if(s[i]==lastchar){
                r2l[i]=r2l[i+1]+1;
            }else{
                r2l[i]=numw+1;
            }
            numw=0;
            lastchar=s[i];
        }
        // cout<<r2l[i]<<endl;
    }
    int mx=0;
    for(int i=0; i<n-1; i++){
        mx=max(l2r[i]+r2l[i+1],mx);
    }
    cout<<min(n/2,mx)<<endl;
}