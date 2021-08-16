/*
ID: xingrui1
TASK: namenum
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    string num;
    cin>>num;
    freopen("dict.txt","r",stdin);
    string t;
    bool check=0;
    for(int i=0; i<4530; i++){
        cin>>t;
        if(t.size()!=num.size()) continue;
        for(int j=0; j<t.size(); j++){
            if(num[j]=='2'&&t[j]!='A'&&t[j]!='B'&&t[j]!='C') break;
            if(num[j]=='3'&&t[j]!='D'&&t[j]!='E'&&t[j]!='F') break;
            if(num[j]=='4'&&t[j]!='G'&&t[j]!='H'&&t[j]!='I') break;
            if(num[j]=='5'&&t[j]!='J'&&t[j]!='K'&&t[j]!='L') break;
            if(num[j]=='6'&&t[j]!='M'&&t[j]!='N'&&t[j]!='O') break;
            if(num[j]=='7'&&t[j]!='P'&&t[j]!='R'&&t[j]!='S') break;
            if(num[j]=='8'&&t[j]!='T'&&t[j]!='U'&&t[j]!='V') break;
            if(num[j]=='9'&&t[j]!='W'&&t[j]!='X'&&t[j]!='Y') break;
            if(j==t.size()-1){
                cout<<t<<endl;
                check=1;
            }
        }
    }
    if(!check) cout<<"NONE"<<endl;
}