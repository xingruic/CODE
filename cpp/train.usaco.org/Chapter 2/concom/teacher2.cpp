#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[102][102];//a[i][j]��ʾ��˾iӵ�й�˾j�ٷ�֮a[i][j]�Ĺɷ�
int cnt[102];//cnt[i]��ʾ��ǰ�׶��й�˾xӵ�й�˾i�ۼ��аٷ�֮cnt[i]�Ĺɷ�
int m;
bool f[102];//f[i]��ʾ��ǰ�׶��е�i����˾�Ƿ�������
bool own[102];//own[i]��ʾ��ǰ�׶��й�˾x�Ƿ��ܿ��ƹ�˾i
void dfs(int x)
{
    if(f[x]==true)//�߽������������ǰ��˾�ѱ�����������ֱ�ӷ���
        return ;
    f[x]=true;//���Ϊ������
    for(int i=m;i;i--)//ö�����й�˾
    {
        cnt[i]+=a[x][i];//���ϵ�ǰ��˾�Ĺɷݰٷֵ�
        if(cnt[i]>50)//��������
        {
            own[i]=true;//����Ϊ�ܹ�����
            dfs(i);//�ݹ�
        }
    }
}
int main()
{
    int i,j,k,u,v,w,n;
    for(scanf("%d",&n);n;n--)
    {
        scanf("%d%d%d",&u,&v,&w);
        a[u][v]=w;//��˾uӵ�й�˾v�ٷ�֮w�Ĺɷ�
        m=max(u,max(m,v));//mΪ��˾�ĸ���
    }
    for(i=1;i<=m;i++)
    {
        memset(f,false,sizeof(f));//�ѱ������ȫ�����
        memset(own,false,sizeof(own));//���������ȫ����Ϊfalse
        memset(cnt,0,sizeof(cnt));//���ۼưٷֵ�ȫ������
        dfs(i);//�ӵ�i����˾��ʼ����
        for(j=1;j<=m;j++)
            if(own[j]==true&&i!=j)//�����˾j���ڹ�˾i��i������j
                printf("%d %d\n",i,j);//�����˾i���ƹ�˾j
    }
    return 0;
}