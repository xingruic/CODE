/*
ID: xingrui1
TASK: skidesign
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int change[n];
    memset(change,0,sizeof(change));
    int price=0;
    sort(a,a+n);
    do{
        // cout<<a[0]<<endl<<a[n-1]<<endl;
        bool b=0;
        while(a[n-1]-a[0]>17){
            if(b){
                a[n-1]--;
                change[n-1]++;
            }else{
                a[0]++;
                change[0]++;
            }
            b=!b;
        }
        cout<<a[n-1]<<endl<<a[0]<<endl<<endl;
        // cout<<"-----"<<endl<<change[0]<<endl<<change[n-1]<<endl<<"-----"<<endl;
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                if(a[j-1]>a[j]){
                    swap(a[j-1],a[j]);
                    swap(change[j-1],change[j]);
                }
            }
        }
    }while(a[n-1]-a[0]>17);
    cout<<"-------------------------"<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<endl;
    }
    cout<<"-------------------------"<<endl;
    for(int i=0; i<n; i++){
        cout<<change[i]<<endl;
        price+=change[i]*change[i];
    }
    cout<<price<<endl;
}