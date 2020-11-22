#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t>>n>>m;
    int a[t][n];
    for(int i=0; i<t; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<t-1; i++){
        // cout<<m<<endl;
        // cout<<a[i][0]<<endl;
        int t=0,r=0;
        bool done;
        do{
            done=1;
            for(int j=0; j<n; j++){
                if(m/a[i][j]*a[i+1][j]>m){
                    done=0;
                    t=m/a[i][j]*a[i+1][j];
                    r=m%a[i][j];
                }
            }
            m+=t;
            t=r;
        }while(!done);
        // int t=max(m/a[i][0]*a[i+1][0]+m%a[i][0],m);
    }
    cout<<m<<endl;
}