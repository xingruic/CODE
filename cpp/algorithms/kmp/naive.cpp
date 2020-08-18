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
    getline(cin,find);
    getline(cin,large);
    to_lower(large);
    to_lower(find);
    string t="";
    int a=-1,b=0;
    for(int i=0; i+find.size()<=large.size(); i++){
        int j;
        for(j=i; j<i+find.size(); j++){
            t+=large[j];
        }
        bool flag=1;
        if(j<large.size()&&large[j]!=' ') flag=0;
        if(i>0&&large[i-1]!=' ') flag=0; 
        if(t==find&&flag){
            if(a==-1) a=i;
            b++;
        }
        t="";
    }
    if(a>=0) cout<<b<<' '<<a<<endl;
    else cout<<a<<endl;
}