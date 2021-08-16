#include<bits/stdc++.h>
#include<random>
using namespace std;
int main(){
    freopen("beads.in","w",stdout);
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,2);
    cout<<1000000<<endl;
    for(int i=0; i<1000000; i++){
        int t=u(e);
        if(t==0) putchar('w');
        else if(t==1) putchar('r');
        else putchar('b');
    }
    cout<<endl;
}