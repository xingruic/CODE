/*
ID:xingrui1
LANG:C++
TASK:hamming
*/
#include<bits/stdc++.h>
using namespace std;
int n,b,d;
int distance(int a,int b){
    bitset<8> c(a^b);
    return c.count();
}
int codes[65],cnt=1;
int newcode(int old){
    for(int i=old+1; 1; i++){
        int j;
        for(j=0; j<cnt; j++){
            if(distance(codes[j],i)<d) break;
        }
        if(j==cnt) return codes[cnt++]=i;
    }
}
void printbits(int t){
    bitset<8> c(t);
    cout<<c.to_string()<<endl;
}
int main(){
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    memset(codes,-1,sizeof(codes));
    codes[0]=0;
    cin>>n>>b>>d;
    int t=0;
    for(int i=0; i<n-1; i++){
        // printbits(t);
        if((i+1)%10) cout<<t<<' ';
        else cout<<t<<endl;
        t=newcode(t);
    }
    cout<<t<<endl;
    // for(int i=0; i<cnt; i++){
    //     for(int j=0; j<cnt; j++){
    //         cout<<distance(codes[i],codes[j])<<endl;
    //     }
    // }
}