#include<bits/stdc++.h>
#define n 10
using namespace std;
bool same(char a[n],char b[n]){
    int cnt=0;
    while(*a==*b&&cnt<n){
        a++;
        b++;
        cnt++;
    }
    if(cnt==n) return 1;
    return 0;
}
int main(){
    char a[]="1234567890",b[]="1234567890";
    cout<<same(a,b)<<endl;
}