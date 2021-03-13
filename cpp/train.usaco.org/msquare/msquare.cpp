#include<bits/stdc++.h>
using namespace std;
string S="";
vector<string> trail,cubes;
string trans(string s,char c){
    switch(c){
        case 'A':
            swap(s[0],s[4]);
            swap(s[1],s[5]);
            swap(s[2],s[6]);
            swap(s[3],s[7]);
            break;
        case 'B':
            for(int i=3; i>=1; i--){
                swap(s[i],s[i-1]);
                swap(s[i+4],s[i+3]);
            }
            break;
        default:
            swap(s[1],s[2]);
            swap(s[1],s[6]);
            swap(s[1],s[5]);
            break;
    }
    return s;
}
bool find_in_trail(string str){
    for(string i:trail){
        if(str==i) return 1;
    }
    return 0;
}
int main(){
    // failed
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    for(int i=1; i<=8; i++){
        char t;
        cin>>t;
        S+=t;
    }
    cout<<S<<endl;
    trail.push_back("");
    cubes.push_back("12348765");
    string T,C;
    int min_cnt=0x7fffffff;
    string min_str="";
    while(!cubes.empty()){
        T=trail.front(),C=cubes.front();
        cout<<C<<' '<<T<<endl;
        trail.erase(trail.begin());
        cubes.erase(cubes.begin());
        if(T.size()>=min_cnt) continue;
        if(find_in_trail(T)) continue;
        if(C==S){
            if(min_cnt>T.size()) min_cnt=T.size(),min_str=T;
            continue;
        }
        trail.push_back(T+'A');
        cubes.push_back(trans(C,'A'));
        trail.push_back(T+'B');
        cubes.push_back(trans(C,'B'));
        trail.push_back(T+'C');
        cubes.push_back(trans(C,'C'));
    }
    cout<<min_cnt<<endl<<min_str<<endl;
}