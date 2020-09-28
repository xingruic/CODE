#include<bits/stdc++.h>
using namespace std;
void cout_vec(vector<string> code){
    for(vector<string>::iterator i=code.begin(); i!=code.end(); i++){
        cout<<*i<<endl;
    }
}
vector<string> gray(int n,int t=2,vector<string> code=vector<string>()){
    if(t==2){
        code.push_back("0");
        code.push_back("1");
    }
    if(code[0].size()>=n) return code;
    for(int i=t-1; i>=0; i--){
        code.push_back('1'+code[i]);
    }
    // cout_vec(code);
    for(int i=0; i<t; i++){
        code[i]='0'+code[i];
    }
    // cout<<endl;
    // cout_vec(code);
    // cout<<t<<endl<<"-----"<<endl;
    return gray(n,code.size(),code);
}
int main(){
    int n;
    cin>>n;
    vector<string> code=gray(n);
    cout_vec(code);
}