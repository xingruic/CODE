/*
ID:xingrui1
LANG:C++
TASK:maze1
*/
#include<bits/stdc++.h>
using namespace std;
/**
 * 还没做完
 */
short int w,h;
bool input[205][80]={{0}};
bool up[105][40]={{0}},dn[105][40]={{0}},lf[105][40]={{0}},rt[105][40]={{0}};
bool connect[105][40]={{0}};
int main(){
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>w>>h;
    short int n=2*h+1,m=2*w+1;
    for(short int i=0; i<n; i++){
        for(short int j=0; j<m; j++){
            char t=getchar();
            if(t=='\n') t=getchar();
            if(t=='-'||t=='+'||t=='|') input[i][j]=1;
        }
    }
    ;;;for(short int i=0; i<n; i++){
    ;;;    for(short int j=0; j<m; j++) cout<<(input[i][j]?'X':' ')<<' ';
    ;;;    cout<<endl;
    ;;;}
    short int x1,y1,x2,y2;
    x1=y1=x2=y2=-1;
    for(short int i=0; i<n; i++){
        for(short int j=0; j<m; j++){
            if(i==0&&!input[i][j]){
                if(x1==-1) x1=(i-1)/2,y1=(j-1)/2;
                else x2=(i-1)/2,y2=(j-1)/2;
                ;;;cout<<i<<' '<<j<<endl;
            }
            if(i==n-1&&!input[i][j]){
                if(x1==-1) x1=(i-1)/2,y1=(j-1)/2;
                else x2=(i-1)/2,y2=(j-1)/2;
                ;;;cout<<i<<' '<<j<<endl;
            }
            if(j==0&&!input[i][j]){
                if(x1==-1) x1=(i-1)/2,y1=(j-1)/2;
                else x2=(i-1)/2,y2=(j-1)/2;
                ;;;cout<<i<<' '<<j<<endl;
            }
            if(j==m-1&&!input[i][j]){
                if(x1==-1) x1=(i-1)/2,y1=(j-1)/2;
                else x2=(i-1)/2,y2=(j-1)/2;
                ;;;cout<<i<<' '<<j<<endl;
            }
        }
    }
    ;;;cout<<x1<<' '<<y1<<endl<<x2<<' '<<y2<<endl;
    for(short int i=1; i<n; i+=2){
        for(short int j=1; j<m; j+=2){
            up[i/2][j/2]=!input[i-1][j];
            dn[i/2][j/2]=!input[i+1][j];
            lf[i/2][j/2]=!input[i][j-1];
            rt[i/2][j/2]=!input[i][j+1];
            ;;;cout<<input[i-1][j]<<input[i+1][j]<<input[i][j-1]<<input[i][j+1]<<' ';
        }
        ;;;cout<<endl;
    }

    queue<short int> i,j;
    short int ci=-1,cj=-1;
    short int dist[h][w];
    memset(dist,-1,sizeof(dist));

    i.push(x1);
    j.push(y1);
    dist[x1][y1]=0;
    while(!i.empty()){
        ci=i.front(),cj=j.front();
        i.pop();
        j.pop();
        if(ci>0&&up[ci][cj]&&dist[ci-1][cj]>=0){
            i.push(ci-1);
            j.push(cj);
            dist[ci-1][cj]=dist[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<0<<endl;
        }
        if(ci<h-1&&dn[ci][cj]&&dist[ci+1][cj]>=0){
            i.push(ci+1);
            j.push(cj);
            dist[ci+1][cj]=dist[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<1<<endl;
        }
        if(cj>0&&lf[ci][cj]&&dist[ci][cj-1]>=0){
            i.push(ci);
            j.push(cj-1);
            dist[ci][cj-1]=dist[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<2<<endl;
        }
        if(cj<w-1&&rt[ci][cj]&&dist[ci][cj+1]>=0){
            i.push(ci);
            j.push(cj+1);
            dist[ci][cj+1]=dist[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<3<<endl;
        }
    }
    ;;;cout<<ci<<' '<<cj<<endl;

    short int mindist=dist[ci][cj];
    if(x1==x2&&y1==y2){
        cout<<mindist+1<<endl;
        return 0;
    }

    ci=-1,cj=-1;
    short int dist2[h][w];
    memset(dist2,0x3c,sizeof(dist2));

    ci=cj=-1;
    i.push(x2);
    j.push(y2);
    dist2[x2][y2]=0;
    while(!i.empty()){
        ci=i.front(),cj=j.front();
        i.pop();
        j.pop();
        if(ci>0&&up[ci][cj]&&dist[ci-1][cj]>=0&&dist2[ci][cj]+1<=dist[ci-1][cj]){
            i.push(ci-1);
            j.push(cj);
            dist2[ci-1][cj]=dist2[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<0<<endl;
        }
        if(ci<h-1&&dn[ci][cj]&&dist[ci+1][cj]>=0&&dist2[ci][cj]+1<=dist[ci+1][cj]){
            i.push(ci+1);
            j.push(cj);
            dist2[ci+1][cj]=dist2[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<1<<endl;
        }
        if(cj>0&&lf[ci][cj]&&dist[ci][cj-1]>=0&&dist2[ci][cj]+1<=dist[ci][cj-1]){
            i.push(ci);
            j.push(cj-1);
            dist2[ci][cj-1]=dist2[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<2<<endl;
        }
        if(cj<w-1&&rt[ci][cj]&&dist[ci][cj+1]>=0&&dist2[ci][cj]+1<=dist[ci][cj+1]){
            i.push(ci);
            j.push(cj+1);
            dist2[ci][cj+1]=dist2[ci][cj]+1;
            ;;;cout<<ci<<' '<<cj<<' '<<3<<endl;
        }
    }
    ;;;cout<<ci<<' '<<cj<<endl;
    mindist=min(dist2[ci][cj],mindist);
    cout<<mindist+1<<endl;
}