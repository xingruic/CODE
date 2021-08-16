/*
ID:xingrui1
LANG:C++
TASK:milk2
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n;
    cin>>n;
    int s[n],e[n];
    int m=0,m2=0x7fffffff;
    for(int i=0; i<n; i++){
        cin>>s[i]>>e[i];
        m=max(m,e[i]);
        m2=min(m2,s[i]);
    }
    bool milking[m+5]={0};
    for(int i=0; i<n; i++){
        for(int j=s[i]; j<e[i]; j++) milking[j]=1;
    }
    int maxcnt=0,cnt=0;
    int maxcnt2=0,cnt2=0;
    for(int i=m2; i<=m; i++){
        if(milking[i]){
            cnt++;
            maxcnt2=max(cnt2,maxcnt2);
            cnt2=0;
        }else{
            cnt2++;
            maxcnt=max(cnt,maxcnt);
            cnt=0;
        }
    }
    cout<<maxcnt<<' '<<maxcnt2<<endl;
}