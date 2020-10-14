#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n],g[n],k[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    int x,y;
    cin>>x>>y;
    for(int i=n-1; i>=0; i--){
        if(x>=a[i]&&x<a[i]+g[i]&&y>=b[i]&&y<b[i]+k[i]){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}