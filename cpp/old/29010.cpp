#include<bits/stdc++.h>
#define MAX 0x7ffffff
using namespace std;
int main(){
    int ms;
    cin>>ms;
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=n-1; i>0; i--){
        // for(int j=0; j<n; j++) cout<<a[j]<<' ';
        // cout<<endl;
        if(a[i]!=0){
            for(int j=0; j<n; j++){
                if(a[j]!=0&&a[i]+a[j]<=ms){
                    ans++;
                    a[i]=0;
                    a[j]=0;
                    break;
                }
            }
            if(a[i]!=0){
                ans++;
                a[i]=0;
            }
        }
    }
    cout<<ans<<endl;
}