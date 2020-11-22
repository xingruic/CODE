#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("HarryPotter.txt","r",stdin);
    freopen("HarryPotter.out","w",stdout);
    char a[7000000];
    int I=0;
    char c;
    while((c=getchar())!=EOF) a[I++]=c;
    a[I]='\0';
    for(int i=4189089; i<I; i++) cout<<a[i];
}