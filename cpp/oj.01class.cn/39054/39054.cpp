#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("39054.in","r",stdin);
    freopen("39054.out","w",stdout);
    string k,text;
    // k="AaaB";
    // text="abcfefgjijknmnorqrsvuvwzyzADCDEHGHILKLMPOPQTSTUXWXYB";
    cin>>k>>text;
    char a['Z'+5]['Z'+5];
    for(int i='A'; i<='Z'; i++){
        for(int j='A'; j<='Z'; j++){
            if(j+i-'A'<='Z') a[i][j]=(char)(j+i-'A');
            else a[i][j]=(char)(j+i-'A'-26);
            // cout<<a[i][j]<<' ';
        }// cout<<endl;
    }
    for(int i=0; i<k.size(); i++){
        if(k[i]>'Z') k[i]-='a'-'A';
        if(k[i]=='A') k[i]='[';
    }
    // cout<<k<<endl;
    string key="";
    for(int i=0,j=0; i<text.size(); i++){
        if(j==k.size()) j=0;
        key+=k[j];
        j++;
    }
    // cout<<key<<endl;
    for(int i=0; i<text.size(); i++){
        // cout<<text[i]<<' '<<(char)('A'+'Z'+1-key[i])<<' ';
        if(text[i]<='Z'){
            text[i]=a[text[i]]['A'+'Z'+1-key[i]];
        }else{
            text[i]=a[text[i]-'a'+'A']['A'+'Z'+1-key[i]]-'A'+'a';
        }
        // cout<<text[i]<<endl;
    }
    cout<<text<<endl;
}