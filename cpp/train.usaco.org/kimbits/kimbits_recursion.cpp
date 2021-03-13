/*
TASK:kimbits
ID:xingrui1
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n,l,I;
int T;
long long cnt=1;
// void findkim(string s="",int onecnt=0){
//     if(s.size()>n) return;
//     if(onecnt>l){
//         return;
//     }
//     if(s.size()==n){
//         cnt++;
//         // cout<<s<<'&'<<endl;
//     }
//     if(cnt==I+1){
//         while(s.size()<n) s=s+'0';
//         cout<<s<<endl;
//         cout<<clock()-T<<endl;
//         exit(0);
//     }
//     findkim(s+'0',onecnt);
//     findkim(s+'1',onecnt+1);
// }
void findkim(char s[],int onecnt=0){
    if(onecnt>l){
        return;
    }
    int len=strlen(s);
    if(len>n) return;
    if(len==n){
        cnt++;
    }
    if(cnt==I+1){
        char S[n+1];
        for(int i=0; i<n; i++) S[i]='0';
        for(int i=0; i<len; i++) S[i]=s[i];
        S[n]='\0';
        for(int i=0; i<n; i++) cout<<S[i];
        cout<<endl;
        // cout<<clock()-T<<endl;
        exit(0);
    }
    char S[len+2];
    S[len+1]='\0';
    for(int i=0; i<len; i++) S[i]=s[i];
    S[len]='0';
    findkim(S,onecnt);
    S[len]='1';
    findkim(S,onecnt+1);
}
int main(){
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    T=clock();
    cin>>n>>l>>I;
    char s[]="";
    findkim(s);
}