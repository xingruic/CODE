#include<bits/stdc++.h>
using namespace std;
int a[100][100];
set<int>added,pending;
added.insert(0);
void mst(int n, int i=0){
    for(int j=0; j<n; j++){
        if(a[i][j]!=0){
            pending.insert(a[i][j]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    memset(a,0,sizeof(a)/sizeof(int));
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
    
}