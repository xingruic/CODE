#include<bits/stdc++.h>
using namespace std;
int road[101][101];//记录是否通路 
int n,k,m,s,t,ans=1000000;
int exc[101][101];//文化间的排斥关系 
int cul[101];//第i座城市的文化种类 
bool ok[101];//判断当前城市的文化是否已经被学习 
void dfs(int x,int sum)//x表示起点，sum表示距离
{
	if(x==t)
	{
		ans=min(ans,sum);//更新最小值 
		return;
	}
	ok[cul[x]]=1;
	for(int i=1;i<=n;i++)
	{
		if(!road[x][i]||exc[cul[i]][cul[x]]||ok[cul[i]]) continue;//如果x，i之间没有通路；
        dfs(i,sum+road[x][i]);                                    //或者文化i的文化排斥x的文化；
	}                                                             //或者当前城市文化已经被学习，跳过 
	ok[cul[x]]=1;//回溯 
}
int main()
{
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++) scanf("%d",&cul[i]);
	for(int i=1;i<=k;i++)
	   for(int j=1;j<=k;j++) scanf("%d",&exc[i][j]);	    
	for(int i=1;i<=m;i++)
	{
	    int gg,zz,xx;
		scanf("%d%d%d",&gg,&zz,&xx);
		road[gg][zz]=xx;
	} 
	dfs(s,0);
	if(ans==1000000) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}