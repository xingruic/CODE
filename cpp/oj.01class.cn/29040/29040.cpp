#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,add;
    cin>>n>>add;
    int mars[n];
    for(int i=0; i<n; i++){
        cin>>mars[i];
    }
    unsigned long long fact[n]={1}; // factorial
    for(int i=1; i<n; i++){
        fact[i]=fact[i-1]*i;
        // cout<<fact[i]<<' ';
    }
    // cout<<endl;
    unsigned long long translated=0;
    for(int i=0; i<n; i++){
        // cout<<translated<<' ';
        unsigned long long multiplier=mars[i]-1;
        for(int j=0; j<i; j++){
            if(mars[j]<mars[i]) multiplier--;
        }
        translated+=(multiplier<0?0:multiplier)*fact[n-i-1];
        // cout<<(multiplier<0?0:multiplier)*fact[n-i-1]<<'\t';
    }
    // cout<<endl;
    // cout<<translated<<endl;
    translated+=add; // add the given number to the translated number
    // cout<<translated<<endl;
    vector<int> a;
    for(int i=1; i<=n; i++) a.push_back(i);
    for(int i=n-1; i>=0; i--){
        int t=translated/fact[i];
        cout<<a[t]<<' ';
        // cout<<<<translated/fact[i]<<' '<<translated<<' '<<fact[i]<<' '<<translated%fact[i]<<"     ";
        // for(int i:a) cout<<i<<' ';
        // cout<<'\t'<<translated<<endl;
        a.erase(a.begin()+t);
        translated%=fact[i];
    }
}