#include<bits/stdc++.h>
using namespace std;
int n;
bool Prime(int a){
    for(int i=2; i<=a/2; i++) if(a%i==0) return 0;
    return 1;
}
void print_ribs(int rib=0,int i=0){
    if(i==n){
        int t=rib;
        while(rib>0){
            if(!Prime(rib)) return;
            rib/=10;
        }
        cout<<t<<endl;
        return;
    }
    if(rib==0){
        print_ribs(2,1);
        print_ribs(3,1);
        print_ribs(5,1);
        print_ribs(7,1);
    }else{
        int t=rib*10;
        while(rib>0){
            if(!Prime(rib)) return;
            rib/=10;
        }
        print_ribs(t+1,i+1);
        print_ribs(t+3,i+1);
        print_ribs(t+7,i+1);
        print_ribs(t+9,i+1);
    }
}
int main(){
    cin>>n;
    print_ribs();
}