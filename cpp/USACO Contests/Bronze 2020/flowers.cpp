#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    int n;
    cin>>n;
    cnt+=n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double sum=0;
            for(int k=i; k<=j; k++){
                // cout<<a[k]<<' ';
                sum+=a[k];
            }// cout<<sum<<endl;
            sum/=(j-i+1);
            for(int k=i; k<=j; k++){
                if(a[k]==sum){
                    // cout<<i<<' '<<j<<' '<<sum<<endl;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;
}