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
    int translated=0;
    for(int i=0; i<n; i++){
        // cout<<translated<<' ';
        int multiplier=mars[i]-1;
        for(int j=0; j<i; j++){
            if(mars[j]<mars[i]) multiplier--;
        }
        translated+=(multiplier<0?0:multiplier)*fact[n-i-1];
        // cout<<(multiplier<0?0:multiplier)*fact[n-i-1]<<'\t';
    }
    translated+=add; // add the given number to the translated number
    // cout<<translated<<endl;
    string result="";
    int a[n];
    for(int i=0; i<n; i++){
        a[i]=i+1;
        // cout<<a[i]<<endl;
    }
    for(int i=n-1; i>=0; i--){
        int t=translated/fact[i];
        for(int j=0; j<=t; j++){
            if(a[j]==-1) t++;
        }
        assert(t<n);
        // cout<<endl<<t<<' '<<translated<<' '<<a[t]<<endl;
        assert(a[t]>0);
        result=result+(char)(a[t]+'0')+' ';
        translated%=fact[i];
        a[t]=-1;
    }
    result.pop_back();
    cout<<result<<endl;
}