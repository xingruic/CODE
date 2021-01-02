/*
LANG:C++
ID:xingrui1
TASK:fracdec
*/
#include<bits/stdc++.h>
using namespace std;
int ip=0; // insertion point = ip, to mark where to insert characters
int pip=0; // ip of passed[] array
char ans[60000]={0};
void append(string str){
    int stop=ip+str.size();
    int i;
    for(i=ip; i<stop; i++){
        ans[i]=str[i-ip];
    }
    ip=i;
    return;
}
void add_parens(int i,int j){
    for(int k=ip-1; k>=i+j; k--){
        ans[k+1]=ans[k];
    }
    ans[i+j]='(';
    ip++;
    ans[ip]=')';
    ip++;
    return;
}
int main(){
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    int n,d;
    cin>>n>>d;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    int passed[60000];
    memset(passed,-1,sizeof(passed));
    int t=0;
    while(n>=d){
        t++;
        n-=d;
    }
    append(to_string(t)+'.');
    while(1){
        passed[pip++]=n;
        n*=10;
        t=0;
        while(n>=d){
            t++;
            n-=d;
        }
        append(to_string(t));
        int i;
        for(i=0; i<pip; i++){
            if(n==passed[i]){
                int j;
                for(j=0; ans[j]!='.'; j++){}
                j++;
                add_parens(i,j);
                break;
            }
        }
        if(i<pip) break;
    }
    if(ans[ip-3]=='('&&ans[ip-2]=='0') ip-=3;
    if(ans[ip-1]=='.') append("0");
    int start=0;
    if(ip>76){
        while(ip-start>76){
            for(int i=start; i<start+76; i++) cout<<ans[i];
            cout<<endl;
            start+=76;
        }
        for(int i=start; i<ip; i++) cout<<ans[i];
    }else for(int i=0; i<ip; i++) cout<<ans[i];
    cout<<endl;
}