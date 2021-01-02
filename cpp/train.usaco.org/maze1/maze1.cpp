#include<bits/stdc++.h>
using namespace std;
struct cell{
    bool up=0,down=0,left=0,right=0;
};

int w,h;

char maze[16000][16000]={{0}};

cell cells[8000][8000];

int i1=-1,j1=-1,i2=-1,j2=-1;

int filled[8000][8000]={{0}};

void fill(int i,int j,int num=0,vector<pair<int,int>> passed=vector<pair<int,int>>()){
    if(i<0||j<0||i>=h*2+1||j>=w*2+1) return;
    for(auto k:passed) if(i==k.first&&j==k.second) return;
    passed.push_back(make_pair(i,j));
    filled[i][j]=num;
    if(cells[i][j].up) fill(i-1,j,num+1,passed);
    if(cells[i][j].down) fill(i+1,j,num+1,passed);
    if(cells[i][j].right) fill(i,j+1,num+1,passed);
    if(cells[i][j].left) fill(i,j-1,num+1,passed);
}
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>w>>h;
    int n=h*2+1,m=w*2+1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            maze[i][j]=getchar();
            if(maze[i][j]=='\n') maze[i][j]=getchar();
        }
    }
    for(int i=1; i<n; i+=2){
        for(int j=1; j<m; j+=2){
            cells[i][j].up=maze[i-1][j]!=' ';
            cells[i][j].down=maze[i+1][j]!=' ';
            cells[i][j].left=maze[i][j-1]!=' ';
            cells[i][j].right=maze[i][j+1]!=' ';
            if(i==1&&!cells[i][j].up){
                if(i1==-1) i1=i,j1=j;
                else i2=i,j2=j;
            }
        }
    }
    int minsteps=0x7fffffff;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            fill(i,j);
            minsteps=min(minsteps,min(filled[i1][j1],filled[i2][j2]));
        }
    }
    cout<<minsteps<<endl;
}