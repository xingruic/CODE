#include<bits/stdc++.h>
using namespace std;
int n,k,a[100][200]={0};
int main(){
    freopen("nocows.in","r",stdin);
    freopen("nocows.out","w",stdout);
	cin>>n>>k;
    a[1][1]=1;
    a[2][3]=1;
    a[3][5]=2;
    a[3][7]=1;
    a[4][7]=2*2;
    a[4][9]=2*1+4;
    for(int i=3; i<100; i++){
        for(int j=1; j<200; j++){
            a[i][j]+=a[i-1][j-2]*
        }
    }
}