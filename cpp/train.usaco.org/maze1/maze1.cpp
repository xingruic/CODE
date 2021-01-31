/*
ID:xingrui1
LANG:C++
TASK:maze1
*/
#include<bits/stdc++.h>
using namespace std;
int x1=-1,_y1=-1,x2=-1,y2=-1;
int h,w;
bool path[3800][3800]={{0}};// 邻接矩阵
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    // int t=clock();
    cin>>w>>h;
    char input[h*2+1][w*2+1];
    for(int i=0; i<h*2+1; i++){
        for(int j=0; j<w*2+1; j++){
            input[i][j]=getchar();
            if(input[i][j]=='\n') input[i][j]=getchar();// 不要换行字符
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int x=2*i+1,y=2*j+1;
            bool up=(input[x-1][y]=='-'),down=(input[x+1][y]=='-'),left=(input[x][y-1]=='|'),right=(input[x][y+1]=='|');
            //needs work
            // if(i>0&&!up) path[i*h+j][(i-1)*h+j]=path[(i-1)*h+j][i*h+j]=1;
            // if(j>0&&!left) path[i*h+j][i*h+j-1]=path[i*h+j-1][i*h+j]=1;
            if(i==0&&!up||j==0&&!left||i==h-1&&!down||j==w-1&&!right){
                if(x1==-1) x1=i,_y1=j;
                else x2=i,y2=j;
            }
        }
    }
    for(int i=0; i<h*w; i++){
        for(int j=0; j<h*w; j++) cout<<path[i][j]<<' ';
        cout<<endl;
    }
}