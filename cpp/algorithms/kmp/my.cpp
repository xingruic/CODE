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
int main(){
    string large,find;
    getline(cin,large);
    getline(cin,find);
    to_lower(large);
    to_lower(find);
    if(large.size()<find.size()) swap(large,find);
    string t="";
    int first=-1,cnt=0;
    int cnt2=0;
    for(int i=0; i+find.size()<=large.size();){
        cnt2++;
        int j;
        for(j=i; j<i+find.size(); j++){
            t+=large[j];
        }
        bool flag=1;
        int jump=0;
        for(int i=0; i<t.size(); i++){
            if(t[i]==find[0]){
                if(jump==0){
                    jump=i;
                }
            }
            if(t[i]!=find[i]){
                flag=0;
            }
        }
        if(jump==0) jump=1;
        if(flag){
            cout<<i<<endl;
            if(first==-1) first=i;
            cnt++;
            break;
        }
        t="";
        i+=jump;
    }
    cout<<"comp times: "<<cnt2<<endl;
    cout<<cnt<<' '<<first<<endl;
}