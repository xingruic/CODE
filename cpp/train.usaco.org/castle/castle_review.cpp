/*
ID: xingrui1
LANG: C++
TASK: castle
*/
#include<bits/stdc++.h>
using namespace std;
int m,n;
struct cell{
    bool w=0,n=0,e=0,s=0;
};
cell a[50][50];
int mark[50][50];
int current_roomsize[2500]={0};
void fill(int i,int j,int marker){
    if(mark[i][j]!=-1) return;
    current_roomsize[marker]++;
    mark[i][j]=marker;
    if(j>0&&!(a[i][j].w)&&!(a[i][j-1].e)) fill(i,j-1,marker);
    if(i>0&&!(a[i][j].n)&&!(a[i-1][j].s)) fill(i-1,j,marker);
    if(j<m-1&&!(a[i][j].e)&&!(a[i][j+1].w)) fill(i,j+1,marker);
    if(i<n-1&&!(a[i][j].s)&&!(a[i+1][j].n)) fill(i+1,j,marker);
}
int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    memset(mark,-1,sizeof(mark));
    cin>>m>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t;
            cin>>t;
            bitset<4> t1(t);
            a[i][j].w=t1[0];
            a[i][j].n=t1[1];
            a[i][j].e=t1[2];
            a[i][j].s=t1[3];
        }
    }
    int markcnt=0;
    int maxroomsize=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mark[i][j]==-1){
                current_roomsize[markcnt]=0;
                fill(i,j,markcnt);
                maxroomsize=max(maxroomsize,current_roomsize[markcnt]);
                markcnt++;
            }
        }
    }
    int maxfinalsize=0;
    int x=-1,y=m;
    char dir='W';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i>0&&mark[i][j]!=mark[i-1][j]){
                int t=current_roomsize[mark[i][j]]+current_roomsize[mark[i-1][j]];
                if(t>maxfinalsize) maxfinalsize=t,x=i,y=j,dir='N';
                if(t==maxfinalsize){
                    if(i>x&&j<=y||i>=x&&j<y) maxfinalsize=t,x=i,y=j,dir='N';
                    if(i==x&&j==y){
                        if(dir!='N') maxfinalsize=t,x=i,y=j,dir='N';
                    }
                }
            }
            if(j<m-1&&mark[i][j]!=mark[i][j+1]){
                int t=current_roomsize[mark[i][j]]+current_roomsize[mark[i][j+1]];
                if(t>maxfinalsize) maxfinalsize=t,x=i,y=j,dir='E';
                if(t==maxfinalsize){
                    if(i>x&&j<=y||i>=x&&j<y) maxfinalsize=t,x=i,y=j,dir='E';
                    if(i==x&&j==y){
                        if(dir!='N') maxfinalsize=t,x=i,y=j,dir='E';
                    }
                }
            }
        }
    }
    cout<<markcnt<<endl;
    cout<<maxroomsize<<endl;
    cout<<maxfinalsize<<endl<<x+1<<' '<<y+1<<' '<<dir<<endl;
}