/*
LANG: C++
ID: xingrui1
TASK: holstein
*/
#include<bits/stdc++.h>
using namespace std;
int v,vita[30],g,f[20][30],total[30],mcnt=100,msum=100;
int ans[30];
bool check(int a[],int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<v; j++){
            total[j]+=f[a[i]][j];
        }
    }
    for(int i=0; i<v; i++) if(total[i]<vita[i]){
        memset(total,0,sizeof(total));
        // cout<<5<<endl;
        return 0;
    }
    memset(total,0,sizeof(total));
    return 1;
}
int a[30];
void _find(int i=0, int cnt=0){
    // for(int j=0; j<cnt; j++) cout<<a[j]<<' ';
    // cout<<endl;
    if(i==g){
        // cout<<3<<endl;
        if(check(a,cnt)){
            // cout<<2<<endl;
            if(cnt<=mcnt){
                // cout<<"1"<<endl;
                int sum=0;
                for(int i=0; i<cnt; i++){
                    sum+=a[i];
                }
                if(sum>msum) return;
                for(int i=0; i<cnt; i++) ans[i]=a[i];
                mcnt=cnt;
            }
        }
        return;
    }
    _find(i+1,cnt);
    // cout<<cnt<<endl;
    a[cnt]=i;
    _find(i+1,cnt+1);
}
int main(){
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    cin>>v;
    for(int i=0; i<v; i++) cin>>vita[i];
    cin>>g;
    for(int i=0; i<g; i++) for(int j=0; j<v; j++) cin>>f[i][j];
    _find();
    cout<<mcnt<<' ';
    for(int i=0; i<mcnt-1; i++) cout<<ans[i]+1<<' ';
    cout<<ans[mcnt-1]+1<<endl;
}
// /*
// LANG: C++
// ID: xingrui1
// TASK: holstein
// */
// #include<bits/stdc++.h>
// using namespace std;
// int v,vita[30],g,f[20][30],total[30],mcnt=100;
// string ans="";
// bool check(string str){
//     for(int i=0; i<str.size(); i++){
//         for(int j=0; j<v; j++){
//             total[j]+=f[str[i]-'0'][j];
//         }
//     }
//     for(int i=0; i<v; i++) if(total[i]<vita[i]){
//         memset(total,0,sizeof(total));
//         return 0;
//     }
//     memset(total,0,sizeof(total));
//     return 1;
// }
// void _find(int i=0, int cnt=0, string str=""){
//     cout<<str<<endl;
//     if(i==g){
//         if(check(str)){
//             if(cnt<mcnt){
//                 ans=str;
//                 mcnt=cnt;
//             }
//         }
//         return;
//     }
//     _find(i+1,cnt+1,str+to_string(i));
//     _find(i+1,cnt,str);
// }
// int main(){
//     freopen("holstein.in","r",stdin);
//     freopen("holstein.out","w",stdout);
//     cin>>v;
//     for(int i=0; i<v; i++) cin>>vita[i];
//     cin>>g;
//     for(int i=0; i<g; i++) for(int j=0; j<v; j++) cin>>f[i][j];
//     _find();
//     cout<<mcnt<<' ';
//     for(int i=0; i<mcnt-1; i++) cout<<(char)(ans[i]+1)<<' ';
//     cout<<(char)(ans[mcnt-1]+1)<<endl;
// }