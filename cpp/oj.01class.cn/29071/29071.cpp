#include<bits/stdc++.h>
using namespace std;
int a[105][105];// 棋盘
bool tried[105][105]={0};// 访问过这个格子
int m,n;// 棋盘大小，有颜色的格子的个数
int ttbr(int x=1,int y=1,int sum=0){// ttbr=to the bottom right
    if(x==m&&y==m) return sum;
    int t,l,b,r;// top sum, left sum, bottom sum, right sum;
    t=l=b=r=0x7fffffff;
    if(x>1&&!tried[x-1][y]){// 往左
        tried[x-1][y]=1;
        if(a[x-1][y]==a[x][y]) l=ttbr(x-1,y,sum);// 同色
        else if(a[x-1][y]==-1) a[x-1][y]=a[x][y],l=ttbr(x-1,y,sum+2),a[x-1][y]=-1;// 无色：先把格子设成现在所在的格子的颜色，递归，再重新设为无色
        else l=ttbr(x-1,y,sum+1);// 不同色
        tried[x-1][y]=0;
    }
    if(y>1&&!tried[x][y-1]){// 往上
        tried[x][y-1]=1;
        if(a[x][y-1]==a[x][y]) t=ttbr(x,y-1,sum);
        else if(a[x][y-1]==-1) a[x][y-1]=a[x][y],t=ttbr(x,y-1,sum+2),a[x][y-1]=-1;
        else t=ttbr(x,y-1,sum+1);
        tried[x][y-1]=0;
    }
    if(x<m&&!tried[x+1][y]){// 往右
        tried[x+1][y]=1;
        if(a[x+1][y]==a[x][y]) r=ttbr(x+1,y,sum);
        else if(a[x+1][y]==-1) a[x+1][y]=a[x][y],r=ttbr(x+1,y,sum+2),a[x+1][y]=-1;
        else r=ttbr(x+1,y,sum+1);
        tried[x+1][y]=0;
    }
    if(y<m&&!tried[x][y+1]){// 往下
        tried[x][y+1]=1;
        if(a[x][y+1]==a[x][y]) b=ttbr(x,y+1,sum);
        else if(a[x][y+1]==-1) a[x][y+1]=a[x][y],b=ttbr(x,y+1,sum+2),a[x][y+1]=-1;
        else b=ttbr(x,y+1,sum+1);
        tried[x][y+1]=0;
    }
    if(t==l&&l==b&&b==r&&r==0x7fffffff) return t;
    return min(min(t,l),min(b,r));
}
int main(){
    memset(a,-1,sizeof(a));
    cin>>m>>n;
    for(int i=1; i<=n; i++){
        int x,y,c;// c=1为黄色，c=2为红色，没列出来为无色
        cin>>x>>y>>c;
        a[x][y]=c;
    }
    cout<<ttbr()<<endl;
}