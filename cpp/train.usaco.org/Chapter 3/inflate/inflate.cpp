/*
TASK:inflate
LANG:C++
ID:xingrui1
*/
// 哈利
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
	int m,n;
	cin>>m>>n;//m是时间，n是题目种类的数量 
	int a[n+1],b[n+1];//a是每种题目的分数，b是时间；
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int c[m+1];
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
		for(int j=b[i];j<=m;j++)
				c[j]=max(c[j-b[i]]+a[i],c[j]);	 
    cout<<c[m]<<endl;
	return 0;
}