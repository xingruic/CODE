/*
ID: xingrui1
LANG: C++
TASK: sort3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    // int t=clock();
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    int cnt=0;
    sort(a,a+n);
    for(int i=0; i<n; i++){
        for(int v=1; v<=3; v++)
            if(a[i]==v){
                for(int j=0; j<n; j++){
                    if(j==i) continue;
                    if(a[i]!=b[i]&&a[j]!=b[j]&&b[j]==a[i]&&a[j]==b[i]){
                        cnt++;
                        swap(b[i],b[j]);
                        // for(int i=0; i<n; i++){
                        //     cerr<<b[i]<<' ';
                        // }cerr<<endl;
                        // cerr<<i<<' '<<j<<endl;
                    }
                }
            }
    }
    // 1-2 2-3 3-1
    for(int i=0; i<n; i++){
        if(a[i]==1&&b[i]==2){
            for(int j=0; j<n; j++){
                if(a[j]==2&&b[j]==3){
                    int k;
                    for(k=0; k<n; k++){
                        if(a[k]==3&&b[k]==1){
                            cnt+=2;
                            swap(b[i],b[j]);
                            swap(b[i],b[k]);
                            // for(int i=0; i<n; i++){
                            //     cerr<<b[i]<<' ';
                            // }cerr<<endl;
                            // cerr<<i<<' '<<j<<' '<<k<<endl;
                            break;
                        }
                    }
                    if(k<n) break;
                }
            }
        }
    }
    // 2-1 3-2 1-3
    for(int i=0; i<n; i++){
        if(a[i]==2&&b[i]==1){
            for(int j=0; j<n; j++){
                if(a[j]==3&&b[j]==2){
                    int k;
                    for(k=0; k<n; k++){
                        if(a[k]==1&&b[k]==3){
                            cnt+=2;
                            swap(b[i],b[j]);
                            swap(b[j],b[k]);
                            // for(int i=0; i<n; i++){
                            //     cerr<<b[i]<<' ';
                            // }cerr<<endl;
                            // cerr<<i<<' '<<j<<' '<<k<<endl;
                        }
                    }
                    if(k<n) break;
                }
            }
        }
    }
    cout<<cnt<<endl;
    // cout<<clock()-t<<endl;
}