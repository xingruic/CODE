#include<bits/stdc++.h>
using namespace std;
int occurs(string a,char b,int stop){
    for(int i=0; i<stop; i++) if(a[i]==b) return i;
    return -1;
}
int boyermoore(string a,string b,int start=0){
    int as=a.size(),bs=b.size();
    int cnt=0;
    for(int i=start; i+bs<=as;){
        cnt++;
        for(int j=bs-1; j>=0; j--){
            // cout<<j<<endl;
            if(b[j]!=a[i+j]){
                if(occurs(b,a[i+j],j)>=0){
                    i+=j-occurs(b,a[i+j],j);
                    break;
                }else{
                    i+=j+1;
                    break;
                }
            }
            if(j==0){
                // cout<<a<<endl;
                // for(int j=0; j<i; j++) cout<<' ';
                // cout<<b<<endl;
                cout<<cnt<<endl;
                return i;
            }
        }
        // cout<<a<<endl;
        // for(int j=0; j<i; j++) cout<<' ';
        // cout<<b<<endl;
    }
    return -1;
}
int main(){
    string a,b;
    a="HERE IS A SIMPLE EXAMPLEXAMPLE";
    b="EXAMPLE";
    int c=0;
    while((c=boyermoore(a,b,c+1))!=-1) cout<<"----- "<<c<<" -----"<<endl;
}