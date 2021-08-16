/*
ID:xingrui1
LANG:C++
TASK:contact
*/
#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
    if(a.size()!=b.size()) return a.size()<b.size();
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) return a[i]=='0';
    }
}
int main(){
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    int a,b,n;
    string s="";
    cin>>a>>b>>n;
    char input;
    while((input=getchar())!=EOF){
        if(input=='\n'){
            input=getchar();
            if(input==EOF) break;
        }
        s+=input;
    }
    map<string,int> m;
    int l=s.size();
    for(int i=0; i<l; i++){
        for(int j=a; j<=b; j++){
            if(i+j>s.size()) break;
            if(m.find(s.substr(i,j))!=m.end()){
                m[s.substr(i,j)]++;
            }else{
                m[s.substr(i,j)]=1;
            }
        }
    }
    int maxcnt=0;
    for(auto i:m){
        maxcnt=max(maxcnt,i.second);
    }
    bool out[maxcnt+1]={0};
    vector<string> output[maxcnt+1];
    for(int i=maxcnt; i>0&&n>0; i--){
        bool f=0;
        for(auto j:m){
            if(j.second==i){
                if(!f){
                    out[i]=1;
                    f=1;
                }
                output[i].push_back(j.first);
            }
        }
    }
    for(int i=maxcnt; i>0&&n>0; i--){
        if(out[i]){
            n--;
            cout<<i<<endl;
            sort(output[i].begin(),output[i].end(),cmp);
            for(int j=0; j<output[i].size()-1; j++){
                if((j+1)%6==0&&j!=0) cout<<output[i][j]<<endl;
                else cout<<output[i][j]<<' ';
            }
            cout<<*(--output[i].end())<<endl;
        }
    }
}