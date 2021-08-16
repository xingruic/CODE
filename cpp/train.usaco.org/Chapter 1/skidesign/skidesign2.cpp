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
    int minsum=0x7fffffff;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            if(b[j]<b[i]){
                sum+=(b[i]-b[j])*(b[i]-b[j]);
            }
            if(b[j]>b[i]+17){
                sum+=(b[j]-(b[i]+17))*(b[j]-(b[i]+17));
            }
        }
        minsum=min(sum,minsum);
    }
    cout<<minsum<<endl;
}