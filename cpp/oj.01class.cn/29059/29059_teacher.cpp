#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,a,b; 
    cin>>n;
    cin>>a;
    cin>>b;
    int ans=1;
    while(a!=n && b!=n && a>1 && b>1){
       a--;b--;
       ans+=(4*(n-1));
       n-=2;
    }
    if(a==1)
        ans+=b-1;
    else if(a>1 && a!=n){
        if(b==1)
            ans+=(4*n-5-a+2);
        else
            ans+=(n+a-2);
    }
    else
        ans+=(3*n-2-b);
    cout<<ans<<endl;
    return 0;
}
