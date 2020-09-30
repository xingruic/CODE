#include<bits/stdc++.h>
using namespace std;
struct Travel{
    bool type;
    int price;
    int time;
    bool discarded;
};
int main(){
    int n;
    cin>>n;
    Travel a[n];
    for(int i=0; i<n; i++){
        cin>>a[i].type>>a[i].price>>a[i].time;
        a[i].discarded=a[i].type;
    }
    // int t1=clock();
    int money_spent=0;
    for(int i=0; i<n; i++){
        if(a[i].type==0){
            // cout<<0<<endl;
            money_spent+=a[i].price;
        }else{
            // cout<<1;
            int j;
            for(j=max(i-45,0); j<i; j++){
                if(!a[j].discarded){
                    // cout<<0;
                    if(a[i].price<=a[j].price&&a[i].time-a[j].time<=45){
                        // cout<<0<<endl;
                        a[j].discarded=1;
                        break;
                    }
                }
            }
            if(j==i){
                // cout<<1<<endl;
                money_spent+=a[i].price;
            }
        }
    }
    cout<<money_spent<<endl;
    // cout<<clock()-t1<<endl;
}
