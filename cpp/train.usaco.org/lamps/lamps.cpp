/*
ID:xingrui1
LANG:C++
TASK:lamps
*/
#include<bits/stdc++.h>
using namespace std;
int n,c;
vector<int> on,off;
string press(string lamps,int button){
    switch(button){
        case 1:
        for(int i=0; i<lamps.size(); i++){
            if(lamps[i]=='1') lamps[i]='0';
            else lamps[i]='1';
        }
        break;
        case 2:
        for(int i=0; i<lamps.size(); i+=2){
            if(lamps[i]=='1') lamps[i]='0';
            else lamps[i]='1';
        }
        break;
        case 3:
        for(int i=1; i<lamps.size(); i+=2){
            if(lamps[i]=='1') lamps[i]='0';
            else lamps[i]='1';
        }
        break;
        default:
        for(int i=0; 3*i<lamps.size(); i++){
            if(lamps[3*i]=='1') lamps[3*i]='0';
            else lamps[3*i]='1';
        }
        break;
    }
    return lamps;
}
bool possible(string lamps){
    for(auto i=on.begin(); i!=on.end(); i++){
        if(!(lamps[*i-1]-'0')) return 0;
    }
    for(auto i=off.begin(); i!=off.end(); i++){
        if(lamps[*i-1]-'0') return 0;
    }
    return 1;
}
bool cmp(string x,string y){
    for(int i=0; i<x.size(); i++){
        if(x[i]==y[i]) continue;
        return x[i]<y[i];
    }
    return 1;
}
int main(){
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    cin>>n>>c;
    for(int t=0; t!=-1; ){
        cin>>t;
        on.push_back(t);
    }
    on.pop_back();
    for(int t=0; t!=-1; ){
        cin>>t;
        off.push_back(t);
    }
    off.pop_back();
    string start="";
    for(int i=0; i<n; i++) start+='1';
    // cout<<press(start,4)<<endl;
    vector<string> got;
    if(possible(start)) got.push_back(start);
    if(c>=1)
    for(int i=1; i<=4; i++){
        if(possible(press(start,i))) got.push_back(press(start,i));
    }
    if(c>=2){
        start=press(start,4);
        for(int i=1; i<=3; i++){
            if(possible(press(start,i))) got.push_back(press(start,i));
        }
    }
    if(got.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    sort(got.begin(),got.end(),cmp);
    for(auto i=got.begin(); i!=got.end(); i++){
        cout<<*i<<endl;
    }
}