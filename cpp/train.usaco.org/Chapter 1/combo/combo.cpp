/*
TASK: combo
ID: xingrui1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    int n;
    cin>>n;
    int f[3],m[3];
    for(int i=0; i<3; i++) cin>>f[i];
    for(int i=0; i<3; i++) cin>>m[i];
    int cnt=0;
    for(int i=1; i<=n; i++){
        int t=i;
        // if(i>=n-1) i=i-n;
        for(int j=1; j<=n; j++){
            int t1=j;
            // if(j>=n-1) j=j-n;
            for(int k=1; k<=n; k++){
                int t2=k;
                // if(k>=n-1) k=k-n;
                // cout<<abs(f[0]-i)<<' '<<abs(f[1]-j)<<' '<<abs(f[2]-k)<<'\t'<<abs(m[0]-i)<<' '<<abs(m[1]-j)<<' '<<abs(m[2]-k);
                if(((abs(f[0]-i)<=2||abs(f[0]-i)>=n-2)&&(abs(f[1]-j)<=2||abs(f[1]-j)>=n-2)&&(abs(f[2]-k)<=2||abs(f[2]-k)>=n-2))||((abs(m[0]-i)<=2||abs(m[0]-i)>=n-2)&&(abs(m[1]-j)<=2||abs(m[1]-j)>=n-2)&&(abs(m[2]-k)<=2||abs(m[2]-k)>=n-2))){
                    cnt++;
                    // cout<<" √";
                }
                // cout<<endl;
                k=t2;
            }
            j=t1;
        }
        i=t;
    }
    cout<<cnt<<endl;
}