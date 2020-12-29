/*
ID:xingrui1
LANG:C++14
TASK:zerosum
*/
#include<bits/stdc++.h>
using namespace std;
int n;
string start="";
int calc(string s){
    int sum=0;
    for(int i=1; i<2*n-1; i++){
        if(s[i]==' ') s=s.substr(0,i)+s.substr(i+1,s.size()-i);
    }
    // cout<<s<<endl;
    int last=-1;
    char lastc='+';
    for(int i=1; i<s.size(); i++){
        if(s[i]=='+'||s[i]=='-'){
            if(lastc=='+'){
                sum+=stoi(s.substr(last+1,i-last+1));
                last=i;
                lastc=s[i];
            }else{
                sum-=stoi(s.substr(last+1,i-last+1));
                last=i;
                lastc=s[i];
            }
        }
    }
    if(lastc=='+'){
        sum+=stoi(s.substr(last+1,s.size()-last+1));
    }else{
        sum-=stoi(s.substr(last+1,s.size()-last+1));
    }
    return sum;
}
vector<string> already;
void zerosum(string s,int i){
    if(i>2*n-1) return;
    if(calc(s)==0){
        bool t=1;
        for(string i:already) if(i==s){
            t=0;
            break;
        }
        if(t){
            already.push_back(s);
            cout<<s<<endl;
        }
    }
    zerosum(s,i+2);
    s[i]='+';
    zerosum(s,i+2);
    s[i]='-';
    zerosum(s,i+2);
    return;
}
int main(){
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    // int t1=clock();
    cin>>n;
    for(int i=1; i<n; i++){
        start+=(char)(i+'0');
        start+=' ';
    }start+=(char)(n+'0');
    zerosum(start,3);
    start[1]='+';
    zerosum(start,3);
    start[1]='-';
    zerosum(start,3);
    // cout<<calc("1+2+3+4+5 6+7 8 9")<<endl;
    // cout<<clock()-t1<<endl;
}