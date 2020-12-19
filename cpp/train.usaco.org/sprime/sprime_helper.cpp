#include<bits/stdc++.h>
using namespace std;
bool prime(int x){
    if(x<2) return 0;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    cout<<'{';
    for(int i=1; i<100000000; i++){
        int t=i;
        while(t>0){
            if(!prime(t)) break;
            t/=10;
        }
        if(t==0) cout<<i<<',';
    }
    cout<<'}'<<endl;
}