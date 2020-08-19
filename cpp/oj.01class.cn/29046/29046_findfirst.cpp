#include<bits/stdc++.h>
using namespace std;
int findfirst(string large,string find,int first=0){
    if(first>=large.size()) return -1;
    for(int i=first; i<large.size(); i++){
        int j;
        for(j=0; j<find.size(); j++){
            if(find[j]!=large[i+j]){
                break;
            }
        }
        if(j==find.size()){
            bool flag=1;
            if(i>0) if(large[i-1]!=' ') flag=0;
            if(i+find.size()<large.size()) if(large[i+find.size()]!=' ') flag=0;
            if(flag){
                return i;
            }
        }
    }
    return -1;
}
void to_lower(string &s){
    for(int i=0; i<s.size(); i++){
        if(s[i]<'a'&&s[i]>='A'){
            s[i]+='a'-'A';
        }
    }
    return;
}
int main(){
    freopen("29046.in","r",stdin);
    string large,find;
    int t1=clock();
    getline(cin,find);
    getline(cin,large);
    int t2=clock();
    cout<<1<<' '<<t2-t1<<endl;
    t1=clock();
    to_lower(large);
    to_lower(find);
    t2=clock();
    cout<<2<<' '<<t2-t1<<endl;
    int first=-1,cnt=0;
    t1=clock();
    int c=0;
    for(int i=0;(i=findfirst(large,find,i))!=-1;i++){
        if(first==-1) first=i;
        cnt++;
    }
    cout<<'c'<<' '<<c<<endl;
    t2=clock();
    cout<<3<<' '<<t2-t1<<endl;
    if(first==-1) cout<<-1<<endl;
    else cout<<cnt<<' '<<first<<endl;
}