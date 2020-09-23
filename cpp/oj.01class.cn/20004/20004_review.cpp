#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s+=s;
    string S=s;
    n*=2;
    int mx=0,x,y,z;
    for(int i=0; i<n; i++){
        int cnt=2;
        bool f=0;
        if(s[i]=='w'){
            f=1;
            for(int j=i-1; j>1; j--){
                if(s[j]!='w'){
                    s[i]=s[j];
                    break;
                }
            }
        }
        int j;
        for(j=i; j>0; j--){
            if(s[j-1]=='w'){
                s[j-1]=s[j];
            }
            if(s[j]==s[j-1]){
                cnt++;
            }else{
                break;
            }
        }
        int t=j+1;
        if(f){
            for(int j=i+1; j<n; j++){
                if(s[j]!='w'){
                    s[i]=s[j];
                    break;
                }
            }
        }
        for(j=i+1; j<n-1; j++){
            if(s[j+1]=='w'){
                s[j+1]=s[j];
            }
            if(s[j]==s[j+1]){
                cnt++;
            }else{
                break;
            }
        }
        s=S;
        if(cnt>mx){
            // x=t;
            // y=j-1;
            // z=i;
            mx=cnt;
        }
    }
    cout<<min(mx,n/2)<<endl;
}