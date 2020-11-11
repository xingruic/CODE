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
    int a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            if(b[i]==1){
                for(int j=0; j<n; j++){
                    if(b[j]==a[i]){
                        if(a[j]==b[i]){
                            swap(a[j],a[i]);
                            // cout<<j<<' '<<i<<endl;
                            cnt++;
                            // if(a[i]!=b[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                }
            }
            if(b[i]==2){
                for(int j=0; j<n; j++){
                    if(b[j]==a[i]){
                        if(a[j]==b[i]){
                            swap(a[j],a[i]);
                            // cout<<j<<' '<<i<<endl;
                            cnt++;
                            // if(a[i]!=b[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                }
            }
            if(b[i]==3){
                for(int j=0; j<n; j++){
                    if(b[j]==a[i]){
                        if(a[j]==b[i]){
                            swap(a[j],a[i]);
                            // cout<<j<<' '<<i<<endl;
                            cnt++;
                            // if(a[i]!=b[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    // 1->2 2->3 3->1
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            if(b[i]!=1||a[i]!=2) continue;
            for(int j=0; j<n; j++){
                if(a[i]!=b[i]){
                    if(b[j]!=2||a[j]!=3) continue;
                    int k;
                    for(k=0; k<n; k++){
                        if(a[i]!=b[i]){
                            if(b[k]!=3||a[k]!=1) continue;
                            swap(a[i],a[j]);
                            swap(a[i],a[k]);
                            // cout<<i<<' '<<j<<' '<<k<<endl;
                            cnt+=2;
                            // if(a[i]!=b[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                    if(k<n) break;
                }
            }
        }
    }
    // 1->3 3->2 2->1
    for(int i=0; i<n; i++){
        if(b[i]!=1||a[i]!=3) continue;
        if(a[i]!=b[i]){
            for(int j=0; j<n; j++){
                if(a[i]!=b[i]){
                    if(b[j]!=3||a[j]!=2) continue;
                    int k;
                    for(k=0; k<n; k++){
                        if(a[i]!=b[i]){
                            if(b[k]!=2||a[k]!=1) continue;
                            swap(a[i],a[j]);
                            swap(a[i],a[k]);
                            // cout<<i<<' '<<j<<' '<<k<<endl;
                            cnt+=2;
                            // if(a[i]!=b[i]) cout<<"???????"<<endl;
                            break;
                        }
                    }
                    if(k<n) break;
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<' ';
    // }cout<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<b[i]<<' ';
    // }cout<<endl;
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