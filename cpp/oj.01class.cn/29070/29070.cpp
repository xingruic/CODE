#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int a[n];
    int l[q];
    int b[q];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<q; i++){
        cin>>l[i]>>b[i];
    }
    sort(a,a+n);
    for(int i=0; i<q; i++){
        int j;
        for(j=0; j<n; j++){
            if(a[j]%(int)pow(10,l[i])==b[i]){
                cout<<a[j]<<endl;
                break;
            }
        }
        if(j==n) cout<<-1<<endl;
    }
}