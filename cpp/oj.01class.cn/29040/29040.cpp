#include<bits/stdc++.h>
using namespace std;
int n,mars[10000],add;
int main(){
    cin>>n>>add;
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
    cout<<translated<<endl;
    string result="";
    vector<int> a;
    a.reserve(n);
    for(int i=0; i<n; i++) a[i]=i+1;
    for(int i=4; i>=0; i--){
        translated%=fact[i];
        cout<<translated<<' '<<fact[i]<<' ';
        result=(char)(a[translated]+'0')+result;
        vector<int>::iterator itr=a.begin();
        for(int j=0; j<translated-1; j++){
            itr++;
        }
        a.erase(itr);
    }
    cout<<result<<endl;
}