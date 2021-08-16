/*
ID: xingrui1
TASK: skidesign
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    // sort(a,a+n);
    // sort(b,b+n);
    // for(int i=0; i<=n/2; i++){
    //     for(int j=1; j<n-i-i+1; j++)
    //     if(abs(a[i]-a[n-i-j])>17){
    //         bool t=0;
    //         while(abs(a[i]-a[n-i-1])>17){
    //             if(t) a[i]++;
    //             else a[n-i-1]--;
    //             t=!t;
    //         }
    //         // cout<<a[i]<<endl;
    //     }
    // }
    int x,y;
    int m=0,p=0x7fffffff;
    for(int i=0; i<n; i++){
        if(a[i]>m){
            m=a[i];
            x=i;
        }if(a[i]<p){
            p=a[i];
            y=i;
        }
    }
    int cnt=0x7fffffff;
    for(int i=p; i<=m-17; i++){
        int t=0;
        for(int j=0; j<n; j++){
            if(a[j]<i){
                t+=(i-a[j])*(i-a[j]);
            }else if(a[j]>i+17){
                t+=(a[j]-i-17)*(a[j]-i-17);
            }
        }
        cnt=min(cnt,t);
    }
    for(int i=0; i<n; i++){
        // cout<<a[i]<<endl;
    }
    cout<<cnt<<endl;
}