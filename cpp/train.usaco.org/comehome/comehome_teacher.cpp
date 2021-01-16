#include<bits/stdc++.h>
using namespace std;
int road[53][53];//任意两个牧场的路径长度 
bool visit[53];//每个牧场是否被访问过 
const int INF=0x3f3f3f3f;
int dis[53];//每一个牧场到起点的距离 
int P,d,k,end,minn=INF,start=26;//起点为谷仓 
char ch1,ch2;
void calcdist(char a,char b,int dist);//把两个牧场转为数字存入数组 
void dijkstra();
int main(){
    memset(visit,false,sizeof(visit));
    for(k=0;k<53;k++){
        for(int j=0;j<53;j++){
            if(k==j) road[k][j]=0;
            else road[k][j]=INF;
        }
        dis[k]=INF;
    }
    dis[start]=0;
    visit[start]=true;
    scanf("%d",&P);
    for(k=1;k<=P;k++){
        scanf(" %c %c %d",&ch1,&ch2,&d);
        calcdist(ch1,ch2,d);
    }
    dijkstra();
    printf("%c %d",start-1+'A',dis[start]);
    return 0;
}
void calcdist(char a,char b,int dist){
    int x,y;
    if(a>='a'&&a<='z'){//小写字母存入第27个到第52个 
        x=a-'a'+27;
    }
    else if(a>='A'&&a<='Z'){//大写字母存入第1个到第26个 
        x=a-'A'+1;
    }
    if(b>='a'&&b<='z'){
        y=b-'a'+27;
    }
    else if(b>='A'&&b<='Z'){
        y=b-'A'+1;
    }
    if(dist<road[x][y]){//避免重复输入 
        road[x][y]=dist;
        road[y][x]=dist;
    }
}
void dijkstra(){
    while(start>=26){
        //松弛操作，即找到更短的路径后更新
        for(k=1;k<53;k++){
            if(!visit[k]&&road[start][k]!=INF){
                if(dis[k]>dis[start]+road[start][k]){
                    dis[k]=dis[start]+road[start][k];
                }
            }
        }
        minn=INF;
        //找最小值 
        for(k=1;k<53;k++){
            if(!visit[k]&&dis[k]<minn){
                minn=dis[k];
                start=k;
            }
        }
        visit[start]=true;
    }
}