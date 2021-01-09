/*
ID:xingrui1
LANG:C++
TASK:maze1
*/
#define NDEBUG
#include<bits/stdc++.h>
using namespace std;
int x1=-1,_y1=-1,x2=-1,y2=-1;
struct cell{
    bool up=1,down=1,left=1,right=1;
}cells[101][39];
int w,h;
int num1,num2;
void dijkstra(int starti,int startj){
    bool in[h][w];
    memset(in,0,sizeof(in));
    int a=starti,b=startj,c=x1,d=_y1;
    in[a][b]=1;
    int dist[h][w];
    memset(dist,0x3d,sizeof(dist));
    dist[a][b]=0;
    while(1){
        bool did_something=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(in[i][j]){
                    if(i>0&&!cells[i][j].up&&!in[i-1][j]){
                        dist[i-1][j]=dist[i][j]+1;
                        in[i-1][j]=1;
                        did_something=1;
                        // if(i==2&&j==4) cout<<i-1<<' '<<j<<' '<<in[i-1][j]<<endl;
                    }
                    if(j>0&&!cells[i][j].left&&!in[i][j-1]){
                        dist[i][j-1]=dist[i][j]+1;
                        in[i][j-1]=1;
                        did_something=1;
                        // if(i==2&&j==4) cout<<i<<' '<<j-1<<' '<<in[i][j-1]<<endl;
                    }
                    if(i<h-1&&!cells[i][j].down&&!in[i+1][j]){
                        dist[i+1][j]=dist[i][j]+1;
                        in[i+1][j]=1;
                        did_something=1;
                        // if(i==2&&j==4) cout<<i+1<<' '<<j<<' '<<in[i+1][j]<<endl;
                    }
                    if(j<w-1&&!cells[i][j].right&&!in[i][j+1]){
                        dist[i][j+1]=dist[i][j]+1;
                        in[i][j+1]=1;
                        did_something=1;
                        // if(i==2&&j==4) cout<<i<<' '<<j+1<<' '<<in[i][j+1]<<endl;
                    }
                    // cout<<endl;
                }
            }
        }
        if(!did_something) break;
    }
    // for(int i=0; i<h; i++){
    //     for(int j=0; j<w; j++){
    //         cout<<(dist[i][j]>0x33333333?-1:dist[i][j])<<' ';
    //     }cout<<endl;
    // }
    num1=dist[c][d],num2=dist[x2][y2];
}
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    // int t=clock();
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
            // cout<<up<<right<<down<<left<<' ';
            cells[i][j].up=up,cells[i][j].down=down,cells[i][j].left=left,cells[i][j].right=right;
            if(i==0&&!up||j==0&&!left||i==h-1&&!down||j==w-1&&!right){
                if(x1==-1) x1=i,_y1=j;
                else x2=i,y2=j;
            }
        }// cout<<endl;
    }
    int distance=0;
    // cout<<x1<<_y1<<endl;
    // cout<<dijkstra(0,0,x1,_y1)<<endl;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int t=distance;
            assert(x1>-1);
            assert(_y1>-1);
            assert(x2>-1);
            assert(y2>-1);
            dijkstra(i,j);
            distance=max(distance,min(num1,x2>-1?num2:0x7fffffff));
            // if(t!=distance) cout<<i<<j<<' ';
        }// cout<<endl;
    }
    cout<<distance+1<<endl;
    // cout<<clock()-t<<endl;
}