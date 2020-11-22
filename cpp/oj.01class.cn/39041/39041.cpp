#include<bits/stdc++.h>
using namespace std;
int __gcd(int a,int b) {
   if(b==0) return a;
   return __gcd(b,a % b);
}
int main(){
    int n;
    cin>>n;
    int a0[n],a1[n],b0[n],b1[n];
    for(int i=0; i<n; i++){
        cin>>a0[i]>>a1[i]>>b0[i]>>b1[i];
    }
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=a1[i]; j<=b1[i]; j+=a1[i]){
            int t;
            if((t=__gcd(j,a0[i]))==a1[i]&&j*b0[i]/t==b1[i]){
                // cout<<j<<endl;
                cnt++;
            }
        }
        cout<<cnt<<endl;
        // cout<<"-----"<<endl;
    }
}