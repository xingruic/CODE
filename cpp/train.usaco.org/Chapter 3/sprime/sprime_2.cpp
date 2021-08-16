/*
ID: xingrui1
TASK: sprime
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool prime(int x){
    if(x<2) return 0;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return 0;
    }
    return 1;
}
bool allowed(int n){
    while(n>0){
        if(n<10) switch(n%10){
            case 2:
            case 3:
            case 5:
            case 7:
            break;
            default:
            return 0;
        }else if(n%10%2==0) return 0;
        n/=10;
    }
    return 1;
}
bool special_allowed(int n){
    switch(n/10000000){
        case 2:
        case 3:
        case 5:
        case 7:
        break;
        default:
        return 0;
    }
    if(n/10%10%2==0) return 0;
    if(n/100%10%2==0) return 0;
    if(n/1000%10%2==0) return 0;
    if(n/10000%10%2==0) return 0;
    if(n/100000%10%2==0) return 0;
    if(n/1000000%10%2==0) return 0;
    return 1;
}
int main(){
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    // int t=clock();
    int n;
    cin>>n;
    int a=pow(10,n-1),b=pow(10,n);
    // int cnt=0;
    if(n==8){
        for(int i=a%2==0?a+1:a; i<b; i+=2){
            if(!special_allowed(i)) continue;
            // cnt++;
            int j;
            for(j=n-1; j>=0; j--) if(!prime(i/(a/pow(10,j)))) break;
            if(j>=0) continue;
            cout<<i<<endl;
        }
        // cout<<cnt<<endl;
        // cout<<(clock()-t)*1.0/CLOCKS_PER_SEC<<endl;
        return 0;
    }
    for(int i=a%2==0?a+1:a; i<b; i+=2){
        if(!allowed(i)) continue;
        // cnt++;
        int j;
        for(j=n-1; j>=0; j--) if(!prime(i/(a/pow(10,j)))) break;
        if(j>=0) continue;
        cout<<i<<endl;
    }
    // cout<<cnt<<endl;
    // cout<<(clock()-t)*1.0/CLOCKS_PER_SEC<<endl;
}