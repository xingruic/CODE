/*
ID:xingrui1
TASK:concom
LANG:C++
*/
// #define show_stuff
#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101]={0};
int sum[101]={0};
bool controls[101]={0};
bool touched[101]={0};
int maxcom=0;
void com(int id){
    if(touched[id]) return;
    touched[id]=1;
    for(int i=1; i<=maxcom; i++){
        sum[id]+=a[id][i];
        if(sum[id]>50){
            controls[i]=1;
            memset(sum,0,sizeof(sum));
            #ifdef show_stuff
            cout<<id<<' '<<i<<endl<<endl;
            #endif
            com(i);
        }
    }
}
int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
    #ifdef show_stuff
    int t=clock();
    #endif
    cin>>n;
    for(int i=0; i<n; i++){
        int k,j,p;
        cin>>k>>j>>p;
        maxcom=max(maxcom,max(k,j));
        a[k][j]=p;
    }
    for(int i=1; i<=maxcom; i++){
        com(i);
        for(int j=1; j<=maxcom; j++){
            if(controls[j]) cout<<i<<' '<<j<<endl;
        }
        memset(controls,0,sizeof(controls));
        memset(sum,0,sizeof(sum));
        memset(touched,0,sizeof(touched));
    }
    #ifdef show_stuff
    cout<<(float)(clock()-t)/CLOCKS_PER_SEC<<endl;
    #endif
}