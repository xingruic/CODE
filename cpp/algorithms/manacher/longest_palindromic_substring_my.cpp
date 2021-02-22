#include<bits/stdc++.h>
using namespace std;
bool palin(string s){
    for(int i=0; i<s.size()/2+1; i++){
        if(s[i]!=s[s.size()-1-i]) return 0;
    }
    return 1;
}
int main(){
    string s;
    cin>>s;
    string longest="";
    for(int i=s.size()-2; i>=1; i--){
        for(int j=0; j<=s.size()-2-i; j++){
            string t="";
            for(int k=j; k<=j+i; k++) t+=s[k];
            if(palin(t)){
                cout<<t<<endl;
                return 0;
            }
        }
    }
}