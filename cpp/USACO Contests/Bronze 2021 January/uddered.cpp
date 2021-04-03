#include<bits/stdc++.h>
using namespace std;
int main(){
    string cowphabet,word;
    cin>>cowphabet>>word;
    int cnt=0;
    while(!word.empty()){
        for(int i=0; i<cowphabet.size(); i++) if(word[0]==cowphabet[i]) word.erase(word.begin());
        cnt++;
    }
    cout<<cnt<<endl;
}