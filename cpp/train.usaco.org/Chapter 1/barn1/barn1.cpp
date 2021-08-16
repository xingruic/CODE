/*
ID: xingrui1
TASK: barn1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int m,s,c;
    cin>>m>>s>>c;
    int a[c];
    for(int i=0; i<c; i++){
        cin>>a[i];
    }
    sort(a,a+c);
    int gap[c-1];
    for(int i=0; i<c-1; i++){
        gap[i]=a[i+1]-a[i]-1;
    }
    sort(gap,gap+c-1);
    int ans=a[c-1]-a[0]+1;
    for(int i=c-2; i>=0&&m>1; i--){
        ans-=gap[i];
        // cout<<gap[i]<<endl;
        m--;
    }
    cout<<ans<<endl;
}