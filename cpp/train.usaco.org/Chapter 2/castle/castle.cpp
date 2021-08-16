/*
ID: xingrui1
LANG: C++
TASK: castle
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int parent[5000];
// int tempcnt=0;
struct unit{
    bool up=1,down=1,left=1,right=1;
    int room_size=1;
};
unit a[100][100];
int find(int i){
    // tempcnt++;
    if(parent[i]==-1||parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void join(int i,int j){
    parent[find(j)]=find(i);
}
bool same_room(int x,int y){
    return find(y)==find(x);
}
int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    memset(parent,-1,sizeof(parent));
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t;
            cin>>t;
            bitset<4> b(t);
            a[i][j].left=b[0];
            a[i][j].up=b[1];
            a[i][j].right=b[2];
            a[i][j].down=b[3];
        }
    }
    // cerr<<'1'<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!a[i][j].left&&!a[i][j-1].right){
                join(i*m+j,i*m+j-1);
            }
            if(!a[i][j].up&&!a[i-1][j].down){
                join(i*m-m+j,i*m+j);
            }
        }
    }
    // cerr<<'2'<<endl;
    int f[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // tempcnt=0;
            f[i][j]=find(i*m+j);
            // cout<<tempcnt<<endl;
        }
    }
    // cerr<<'3'<<endl;
    int mark[n*m];
    memset(mark,0,sizeof(mark));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mark[f[i][j]]++;
        }
    }
    // cerr<<'4'<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++)
    //         cout<<mark[f[i][j]]<<'\t';
    //     cout<<endl;
    // }
    int cnt=0,max_=0;
    for(int i=0; i<n*m; i++){
        if(mark[i]>0) cnt++;
        if(mark[i]>max_) max_=mark[i];
    }
    // cerr<<'5'<<endl;
    cout<<cnt<<endl<<max_<<endl;
    int max_size=0,maxi=1000,maxj=1000;
    char d='E';
    for(int j=0; j<m; j++){
        for(int i=n-1; i>=0; i--){
            if(i<n-1&&f[i][j]!=f[i+1][j]){
                if((mark[f[i][j]]+mark[f[i+1][j]]>max_size||(mark[f[i][j]]+mark[f[i][j+1]]==max_size&&d!='N'))&&(j<maxj||j==maxj&&i>maxi)){
                    max_size=mark[f[i][j]]+mark[f[i+1][j]];
                    maxi=i+1;
                    maxj=j;
                    d='N';
                    // cout<<i+1<<' '<<j+1<<' '<<d<<endl;
                }
            }
            if(i>0&&f[i][j]!=f[i-1][j]){
                if(mark[f[i][j]]+mark[f[i-1][j]]>max_size||(mark[f[i][j]]+mark[f[i-1][j]]==max_size&&d!='N'&&(j<maxj||j==maxj&&i>maxi))){
                    max_size=mark[f[i][j]]+mark[f[i-1][j]];
                    maxi=i;
                    maxj=j;
                    d='N';
                    // cout<<i+1<<' '<<j+1<<' '<<d<<endl;
                }
            }
            if(j<m-1&&f[i][j]!=f[i][j+1]){
                if(mark[f[i][j]]+mark[f[i][j+1]]>max_size||(mark[f[i][j]]+mark[f[i][j+1]]==max_size&&d!='N'&&(j<maxj||j==maxj&&i>maxi))){
                    max_size=mark[f[i][j]]+mark[f[i][j+1]];
                    maxi=i;
                    maxj=j;
                    d='E';
                    // cout<<i+1<<' '<<j+1<<' '<<d<<endl;
                }
            }
            if(j>0&&f[i][j]!=f[i][j-1]){
                if(mark[f[i][j]]+mark[f[i][j-1]]>max_size||(mark[f[i][j]]+mark[f[i][j-1]]==max_size&&d!='N'&&(j<maxj||j==maxj&&i>maxi))){
                    max_size=mark[f[i][j]]+mark[f[i][j-1]];
                    maxi=i;
                    maxj=j-1;
                    d='E';
                    // cout<<i+1<<' '<<j+1<<' '<<d<<endl;
                }
            }
        }
    }
    // cerr<<"done"<<endl;
    cout<<max_size<<endl<<maxi+1<<' '<<maxj+1<<' '<<d<<endl;
    // int cnt=0;
    // vector<int> passed;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         bool t=0;
    //         int t1=find(i*m+j);
    //         for(auto k=passed.begin(); k!=passed.end(); k++)
    //             if(t1==*k) t=1;
    //         if(!t){
    //             passed.push_back(t1);
    //             cnt++;
    //         }
    //     }
    // }
    // cout<<cnt<<endl;
    // break_wall();
}