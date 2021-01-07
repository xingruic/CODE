#include<bits/stdc++.h>
using namespace std;
int x1=-1,_y1=-1,x2=-1,y2=-1;
struct cell{
    bool up=1,down=1,left=1,right=1;
}cells[101][39];
int w,h;
int dijkstra(int starti,int startj,int endi,int endj){
    bool in[w][h];
    memset(in,0,sizeof(in));
    int a=starti,b=startj,c=endi,d=endj;
    in[a][b]=1;
    int dist[w][h];
    memset(dist,0x3d,sizeof(dist));
    dist[a][b]=0;
    while(1){
        bool did_something=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(in[i][j]){
                    if(i>0&&cells[i][j].up&&cells[i-1][j].down&&!in[i-1][j]){
                        dist[i-1][j]=dist[i][j]+1;
                        in[i-1][j]=1;
                        did_something=1;
                    }
                    if(j>0&&cells[i][j].left&&cells[i][j-1].right&&!in[i][j-1]){
                        dist[i][j-1]=dist[i][j]+1;
                        in[i][j-1]=1;
                        did_something=1;
                    }
                    if(i<h-1&&cells[i][j].down&&cells[i+1][j].up&&!in[i+1][j]){
                        dist[i+1][j]=dist[i][j]+1;
                        in[i+1][j]=1;
                        did_something=1;
                    }
                    if(j<w-1&&cells[i][j].right&&cells[i][j+1].left&&!in[i][j-1]){
                        dist[i][j+1]=dist[i][j]+1;
                        in[i][j+1]=1;
                        did_something=1;
                    }
                }
            }
        }
        if(!did_something) break;
    }
    return dist[c][d];
}
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>w>>h;
    char input[h*2+1][w*2+1];
    for(int i=0; i<h*2+1; i++){
        for(int j=0; j<w*2+1; j++){
            input[i][j]=getchar();
            if(input[i][j]=='\n') input[i][j]=getchar();
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int x=2*i+1,y=2*j+1;
            bool up=(input[x-1][y]=='-'),down=(input[x+1][y]=='-'),left=(input[x][y-1]=='|'),right=(input[x][y+1]=='|');
            cout<<up<<right<<down<<left<<' ';
            cells[i][j].up=up,cells[i][j].down=down,cells[i][j].left=left,cells[i][j].right=right;
            if(i==0&&!up||j==0&&!left||i==h-1&&!down||j==w-1&&right){
                if(x1==-1) x1=x,_y1=y;
                else x2=x,y2=y;
            }
        }cout<<endl;
    }
    cout<<dijkstra(0,0,0,1)<<endl;
}