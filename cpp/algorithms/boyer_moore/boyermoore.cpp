#include<bits/stdc++.h>
using namespace std;
bool o[127]={0};
bool occurs(string a,char b){
    for(int i=0; i<a.size(); i++) if(a[i]==b) return 1;
    return 0;
}
int boyermoore(string a,string b,int start=0){
    int as=a.size(),bs=b.size();
    int cnt=0;
    for(int i=start; i+bs<=as;){
        cnt++;
        for(int j=bs-1; j>=0; j--){
            if(b[j]!=a[i+j]){
                if(o[a[i+j]]){
                    i++;
                    break;
                }else{
                    i+=j+1;
                    break;
                }
            }
            if(j==0){
                cout<<cnt<<endl;
                return i;
            }
        }
    }
    return -1;
}
int main(){
    string a,b;
    a="HERE IS A SIMPLE EXAMPLEXAMPLE";
    b="EXAMPLE";
    for(int i=32; i<=126; i++) o[i]=occurs(b,(char)i);
    int c=0;
    while((c=boyermoore(a,b,c+1))!=-1) cout<<"----- "<<c<<" -----"<<endl;
}