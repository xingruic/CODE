#include<bits/stdc++.h>
using namespace std;
void to_lower(string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]<'a'&&s[i]>='A'){
            s[i]+='a'-'A';
        }
    }
    return;
}
int _hash(string s){
    int sum=0;
    for(int i=0; i<s.size(); i++) sum+=i*s[i];
    return sum%1000000007;
}
vector<int> rk(string large, string find){
    int hashf=_hash(find);
    int n=large.size()-find.size()+1;
    int hashl[n];
    string t[n];
    memset(hashl,0,sizeof(hashl)/sizeof(int));
    for(int i=0; i<n; i++){
        t[i]="";
        for(int j=i; j<i+find.size(); j++){
            t[i]+=large[j];
        }
        hashl[i]=_hash(t[i]);
    }
    vector<int> locations;
    for(int i=0; i<n; i++){
        // cout<<hashf<<' '<<hashl[i]<<endl;
        if(hashl[i]==hashf){
            if(t[i]==find){
                locations.push_back(i);
            }
        }
    }
    return locations;
}
