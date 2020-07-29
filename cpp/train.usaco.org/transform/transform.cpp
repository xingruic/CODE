/*
ID: xingrui1
TASK: transform
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
char a[15][15],b[15][15];
void rotate_matrix(char a[15][15]){
    char f[15][15];
    // transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            f[j][i]=a[i][j];
        }
    }
    // flip vertically
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            a[n-i-1][j]=f[i][j];
        }
    }
}
int main(){
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>a[i][j];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>b[i][j];
    bool f=1;
    // 90 deg
    rotate_matrix(a);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(a[i][j]!=b[i][j]) f=0;
    if(f){
        cout<<1<<endl;
        return 0;
    }
    f=1;
    // 180 deg
    rotate_matrix(a);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(a[i][j]!=b[i][j]) f=0;
    if(f){
        cout<<2<<endl;
        return 0;
    }
    f=1;
    // 270 deg
    rotate_matrix(a);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(a[i][j]!=b[i][j]) f=0;
    if(f){
        cout<<3<<endl;
        return 0;
    }
    f=1;
    // flip horizontally
    rotate_matrix(a);
    char c[15][15];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            c[i][n-j-1]=a[i][j];
        }
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(c[i][j]!=b[i][j]) f=0;
    if(f){
        cout<<4<<endl;
        return 0;
    }
    f=1;
    // combination
    for(int k=0; k<3; k++){
        f=1;
        rotate_matrix(c);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(c[i][j]!=b[i][j]) f=0;
        if(f){
            cout<<5<<endl;
            return 0;
        }
    }
    f=1;
    // no change
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(a[i][j]!=b[i][j]) f=0;
    if(f){
        cout<<6<<endl;
        return 0;
    }
    // invalid
    cout<<7<<endl;
}