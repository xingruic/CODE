/*
ID: xingrui1
TASK: crypt1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[100],CNT=0;
bool in(int uv){
    while(uv){
        bool f=0;
        for(int i=0; i<n; i++) if(a[i]==uv%10) f=1;
        if(!f) return 0;
        uv/=10;
    }
    return 1;
}
int main(){
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int u=111; u<=999; u++){
        if(!in(u)) continue;
        for(int v=11; v<=99; v++){
            if(!in(v)) continue;
            int p1=u*(v%10);
            int t=p1;
            int p2=u*(v%100/10);
            int t1=p2;
            int prd=p2*10+p1;
            int t2=prd;
            int i;
            for(i=0; p1>0; i++){
                bool flag=1;
                for(int j=0; j<n; j++) if(p1%10==a[j]){
                    flag=0;
                    break;
                }
                if(flag){
                    // cout<<1<<endl;
                    goto END;
                }
                p1/=10;
            }
            if(i!=3){
                // cout<<4<<endl;
                goto END;
            }
            for(i=0; p2>0; i++){
                bool flag=1;
                for(int j=0; j<n; j++) if(p2%10==a[j]){
                    flag=0;
                    break;
                }
                if(flag){
                    // cout<<2<<endl;
                    goto END;
                }
                p2/=10;
            }
            if(i!=3){
                // cout<<5<<endl;
                goto END;
            }
            for(i=0; prd>0; i++){
                bool flag=1;
                for(int j=0; j<n; j++) if(prd%10==a[j]){
                    flag=0;
                    break;
                }
                if(flag){
                    // cout<<3<<endl;
                    goto END;
                }
                prd/=10;
            }
            if(i!=4){
                // cout<<6<<endl;
                goto END;
            }
            // cout<<u<<' '<<v<<' '<<t<<' '<<t1<<' '<<t2<<endl;
            CNT++;
            END:int z;
        }
    }
    cout<<CNT<<endl;
}