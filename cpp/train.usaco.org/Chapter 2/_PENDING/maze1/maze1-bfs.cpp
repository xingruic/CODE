#include<bits/stdc++.h>
using namespace std;
const int dx[]= {1,-1,0,0},dy[]= {0,0,1,-1};
char x[500];  //读入的字符串，单行读入
int w,h;	//宽和长
int ans,now_long;
int fx[2],fy[2];
int f[210][210];		//记录点到任意一个出口的最短距离
int flag[210][210];		//标记是不是墙
bool arr[210][210];		//标记访问过没有
struct node{
	int x,y;
} now;
queue <node> que;		//BFS队列
void init(){//读数据
	cin.getline(x,500);
	for(int i=0; i<210; i++)	//初始化
		fill(f[i],f[i]+210,INT_MAX),fill(flag[i],flag[i]+210,1);
	for(int i=1; i<=h; i++)	{
		cin.getline(x,500);
		for(int j=1; j<=w; j++)
			if(x[j-1]==' ')	{
				flag[i][j]=0;//标记为可以访问
				if((i==1||j==1||i==h||j==w)&&flag[i][j]==0)
					fx[now_long]=i,fy[now_long]=j,f[i][j]=1,now_long++;		//找出口
			}
	}
}
void bfs(int x,int y){
	node begin;
	begin.x=x,begin.y=y;
	que.push(begin);
	arr[x][y]=1;
	while(!que.empty()){
		node stor=que.front();
		que.pop();
		for(int i=0; i<4; i++){
			int sx=stor.x+dx[i],sy=stor.y+dy[i];
			if(sx>0&&sx<=h&&sy>0&&sy<=w&&flag[sx][sy]==0&&arr[sx][sy]==0){
				arr[sx][sy]=1;
				f[sx][sy]=min(f[sx][sy],f[stor.x][stor.y]+1);
				now.x=sx,now.y=sy;
				que.push(now);
			}
		}
	}
}
int main(){
	cin>>w>>h;
	w=2*w+1,h=2*h+1;
	init();		//读入+初始化
	for(int i=0; i<now_long; i++){
		bfs(fx[i],fy[i]);
		for(int j=0; j<210; j++)
			fill(arr[j],arr[j]+210,0);	//注意：这里要重新初始化！否则就会WA！
	}
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			if(f[i][j]<INT_MAX)		//被更新过，因为初值是INT_MAX
				ans=max(ans,f[i][j]);
	cout<<ans/2<<endl;
	return 0;
}