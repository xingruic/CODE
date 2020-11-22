#include<bits/stdc++.h>
using namespace std;
int T,n;
int t[105],v[105];
int a[1005][1005];
int KS(){
    int b[1005]={0};
    for(int j=1; j<=T; j++) b[j]=-0x7fffffff;
    for(int i=0; i<n; i++){
        for(int j=T; j>=0; j--){
            if(j<t[i]) continue;
            b[j]=max(b[j],b[j-t[i]]+v[i]);
        }
    }
    return b[T];
}
int main(){
    memset(a,-1,sizeof(a));
    cin>>T>>n;
    for(int i=0; i<n; i++) cin>>t[i]>>v[i];
    cout<<KS()<<endl;
}