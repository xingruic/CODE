/*
ID:xingrui1
LANG:C++
TASK:ride
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    string comet,group;
    cin>>comet>>group;
    int sum1=1,sum2=1;
    for(int i=0; i<comet.size(); i++){
        sum1*=(comet[i]-'A'+1);
    }
    for(int i=0; i<group.size(); i++){
        sum2*=(group[i]-'A'+1);
    }
    if(sum1%47==sum2%47) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
}