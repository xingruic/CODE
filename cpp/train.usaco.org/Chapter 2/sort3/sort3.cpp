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
    int n;
    cin>>n;
    int b[n],a[n];
    for(int i=0; i<n; i++){
        cin>>b[i];
        a[i]=b[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0; i<n; i++){
        if(b[i]!=a[i]){
            if(a[i]==1){
                for(int j=0; j<n; j++){
                    if(a[j]==b[i]){
                        if(b[j]==a[i]){
                            swap(b[j],b[i]);
                            // cout<<j<<' '<<i<<endl;
                            cnt++;
                            // if(b[i]!=a[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                }
            }
            if(a[i]==2){
                for(int j=0; j<n; j++){
                    if(a[j]==b[i]){
                        if(b[j]==a[i]){
                            swap(b[j],b[i]);
                            // cout<<j<<' '<<i<<endl;
                            cnt++;
                            // if(b[i]!=a[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                }
            }
            if(a[i]==3){
                for(int j=0; j<n; j++){
                    if(a[j]==b[i]){
                        if(b[j]==a[i]){
                            swap(b[j],b[i]);
                            // cout<<j<<' '<<i<<endl;
                            cnt++;
                            // if(b[i]!=a[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    // // 1->2 2->3 3->1
    // for(int i=0; i<n; i++){
    //     if(b[i]!=a[i]){
    //         if(a[i]!=1||b[i]!=2) continue;
    //         for(int j=0; j<n; j++){
    //             // if(b[i]!=a[i]){
    //                 if(a[j]!=2||b[j]!=3) continue;
    //                 int k;
    //                 for(k=0; k<n; k++){
    //                     // if(b[i]!=a[i]){
    //                         if(a[k]!=3||b[k]!=1) continue;
    //                         swap(b[i],b[j]);
    //                         swap(b[i],b[k]);
    //                         // cout<<i<<' '<<j<<' '<<k<<endl;
    //                         cnt+=2;
    //                         // if(b[i]!=a[i]) cout<<"???????"<<endl;
    //                         break;
    //                     // }
    //                 }
    //                 if(k<n) break;
    //             // }
    //         }
    //     }
    // }
    // // 1->3 3->2 2->1
    // for(int i=0; i<n; i++){
    //     if(a[i]!=1||b[i]!=3) continue;
    //     if(b[i]!=a[i]){
    //         for(int j=0; j<n; j++){
    //             // if(b[i]!=a[i]){
    //                 if(a[j]!=3||b[j]!=2) continue;
    //                 int k;
    //                 for(k=0; k<n; k++){
    //                     // if(b[i]!=a[i]){
    //                         if(a[k]!=2||b[k]!=1) continue;
    //                         swap(b[i],b[j]);
    //                         swap(b[i],b[k]);
    //                         // cout<<i<<' '<<j<<' '<<k<<endl;
    //                         cnt+=2;
    //                         // if(b[i]!=a[i]) cout<<"???????"<<endl;
    //                         break;
    //                     // }
    //                 }
    //                 if(k<n) break;
    //             // }
    //         }
    //     }
    // }
    for(int i=0; i<n; i++){
        cout<<b[i]<<' ';
    }cout<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<' ';
    }cout<<endl;
    cout<<cnt<<endl;
}
/*
20 
1 
1 
3 
2 
1 
1 
1 
3 
2 
1 
3 
3 
2 
1 
3 
1 
1 
2 
3 
1 
*/