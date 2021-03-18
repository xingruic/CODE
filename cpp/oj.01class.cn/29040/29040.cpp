#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,add;
    cin>>n>>add;
    int mars[n];
    for(int i=0; i<n; i++){
        cin>>mars[i];
    }
    int fact[n]={1}; // factorial
    for(int i=1; i<n; i++){
        fact[i]=fact[i-1]*i;
        // cout<<fact[i]<<' ';
    }
    // cout<<endl;
    long long translated=0;
    for(int i=0; i<n; i++){
        // cout<<translated<<' ';
        int multiplier=mars[i]-1;
        for(int j=0; j<i; j++){
            if(mars[j]<mars[i]) multiplier--;
        }
        translated+=(multiplier<0?0:multiplier)*fact[n-i-1];
        // cout<<(multiplier<0?0:multiplier)*fact[n-i-1]<<'\t';
    }
    cout<<translated<<endl;
    translated+=add; // add the given number to the translated number
    cout<<translated<<endl;
    bool a[n]={0};
    int print=-1;
    for(int i=n-1; i>=0; i--){
        // for(int i=0; i<n; i++) cout<<a[i]<<' ';
        // cout<<endl;
        int t=translated/fact[i];
        for(int j=0; j<=translated/fact[i]; j++) if(a[j]) t++;
        while(a[t]) t++;
        // cout<<t<<endl;
        assert(t<n); 
        if(print>0) cout<<print<<endl;
        print=t+1;
        a[t]=1;
        translated%=fact[i];
    }
    cout<<print<<endl;
}
// 3 4 6* 9 8 7 5 2 1
