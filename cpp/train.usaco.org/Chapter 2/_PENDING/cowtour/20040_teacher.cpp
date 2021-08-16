/*
ID:xingrui1
LANG:C++
TASK:cowtour
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
const int inf=0x3f3f3f3f;
struct node{
    int x;
    int y;
}a[maxn];
double cal(int i,int j){
    return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
int n;
double dis[maxn][maxn],ldis[maxn],l1,l2=inf,ans;
int main(){
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    int tmp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            scanf("%1d",&tmp);
            if(tmp)dis[i][j]=cal(i,j);
            else if(i!=j)dis[i][j]=inf;
        }    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];//Floyd
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(dis[i][j]!=inf)ldis[i]=max(dis[i][j],ldis[i]);//��ÿһ�����������Զ�ĵ�ľ���
            l1=max(l1,ldis[i]);//���������Ŀǰ�����ֱ��
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dis[i][j]==inf)
                l2=min(ldis[i]+cal(i,j)+ldis[j],l2);//ö����������ͨ�ĵ㣬Ȼ��Ϳ��Լ����µ�������ֱ��
    ans=max(l1,l2);//�п�������ͨ��������û��ԭ�������������Ի�Ҫ��ȡһ�����ֵ
    printf("%.6f\n",ans);
    return 0;
}