/*
TASK: msquare
ID: xingrui1
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
string input,start="12348765";
map<int,string> m; // map<hash(current_squares),steps_to_current_squares>
int myhash(string arr){
    int result=1;
    for(int i=0; i<8; i++){
        result=(result*13+arr[i])%1199083267;
    }
    return result;
}
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
int main(){
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    for(int i=0; i<4; i++){
        char t;
        cin>>t;
        input+=t;
    }
    for(int i=7; i>=4; i--){
        char t;
        cin>>t;
        input+=t;
    }
    if(input=="12345678"){
        cout<<0<<endl<<""<<endl;
        return 0;
    }
    queue<string> q; // bfs queue
    q.push(trans(start,'A'));
    q.push(trans(start,'B'));
    q.push(trans(start,'C'));
    m[myhash(trans(start,'A'))]="A";
    m[myhash(trans(start,'B'))]="B";
    m[myhash(trans(start,'C'))]="C";
    while(!q.empty()){
        string t=q.front();
        // cout<<t<<endl;
        q.pop();
        bool flag=1; // 1 -> found target! 0 -> continue finding...
        for(int i=0; i<4; i++){
            if(t[i]!=input[i]){
                flag=0;
                break;
            }
        }
        if(t[4]!=input[7]||t[5]!=input[6]||t[6]!=input[5]||t[7]!=input[4]) flag=0;
        if(flag){
            // cout<<"====="<<t<<"====="<<endl;
            cout<<m[myhash(t)].size()<<endl<<m[myhash(t)]<<endl;
            return 0;
        }
        if(m[myhash(trans(t,'A'))]==""){
            q.push(trans(t,'A'));
            m[myhash(trans(t,'A'))]=m[myhash(t)]+'A';
        }
        if(m[myhash(trans(t,'B'))]==""){
            q.push(trans(t,'B'));
            m[myhash(trans(t,'B'))]=m[myhash(t)]+'B';
        }
        if(m[myhash(trans(t,'C'))]==""){
            q.push(trans(t,'C'));
            m[myhash(trans(t,'C'))]=m[myhash(t)]+'C';
        }
    }
    cout<<"???"<<endl;
}