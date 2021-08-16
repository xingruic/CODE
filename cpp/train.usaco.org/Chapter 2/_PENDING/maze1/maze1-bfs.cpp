#include<bits/stdc++.h>
using namespace std;
const int dx[]= {1,-1,0,0},dy[]= {0,0,1,-1};
char x[500];  //������ַ��������ж���
int w,h;	//��ͳ�
int ans,now_long;
int fx[2],fy[2];
int f[210][210];		//��¼�㵽����һ�����ڵ���̾���
int flag[210][210];		//����ǲ���ǽ
bool arr[210][210];		//��Ƿ��ʹ�û��
struct node{
	int x,y;
} now;
queue <node> que;		//BFS����
void init(){//������
	cin.getline(x,500);
	for(int i=0; i<210; i++)	//��ʼ��
		fill(f[i],f[i]+210,INT_MAX),fill(flag[i],flag[i]+210,1);
	for(int i=1; i<=h; i++)	{
		cin.getline(x,500);
		for(int j=1; j<=w; j++)
			if(x[j-1]==' ')	{
				flag[i][j]=0;//���Ϊ���Է���
				if((i==1||j==1||i==h||j==w)&&flag[i][j]==0)
					fx[now_long]=i,fy[now_long]=j,f[i][j]=1,now_long++;		//�ҳ���
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
	init();		//����+��ʼ��
	for(int i=0; i<now_long; i++){
		bfs(fx[i],fy[i]);
		for(int j=0; j<210; j++)
			fill(arr[j],arr[j]+210,0);	//ע�⣺����Ҫ���³�ʼ��������ͻ�WA��
	}
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			if(f[i][j]<INT_MAX)		//�����¹�����Ϊ��ֵ��INT_MAX
				ans=max(ans,f[i][j]);
	cout<<ans/2<<endl;
	return 0;
}