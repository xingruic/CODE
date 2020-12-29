#include<bits/stdc++.h>
using namespace std;
struct cow{
    char dir;
    int x,y;
    bool stop=0;
};
int main(){
    int n;
    cin>>n;
    cow a[n];
    int maxx=0,maxy=0;
    for(int i=0; i<n; i++){
        cin>>a[i].dir>>a[i].x>>a[i].y;
        maxx=max(maxx,a[i].x);
        maxy=max(maxy,a[i].y);
    }

    // cout<<5<<endl<<3<<endl<<"Infinity"<<endl<<"Infinity"<<endl<<2<<endl<<5<<endl;

    /*
      ^
      |
    y |
      |
      L--------->
          x
    */
    pair<int,int> eater[maxx][maxy];
    int step[maxx][maxy];
    pair<int,int> t=make_pair(-1,-1);
    for(int i=0; i<maxx; i++){
        for(int j=0; j<maxy; j++){
            eater[i][j]=t,step[i][j]=0x7fffffff;
        }
    }
    for(int i=0; i<n; i++){
        int j=a[i].x,k=a[i].y;
        if(a[i].dir=='N') for(int tempcnt=0;k!=maxy;tempcnt++,j++){
            if(eater[j][k].first!=-1&&tempcnt>step[j][k]) break;
            if(eater[j][k].first!=-1&&tempcnt<step[j][k]){
                eater[j][k].first=i,step[j][k]=tempcnt;
            }else{
                eater[j][k].second=i,step[j][k]=tempcnt;
            }
        }
        else for(int tempcnt=0;k!=maxy;tempcnt++,k++){
            if(eater[j][k].first!=-1&&tempcnt>step[j][k]) break;
            if(eater[j][k].first!=-1&&tempcnt<step[j][k]){
                eater[j][k].first=i,step[j][k]=tempcnt;
            }else{
                eater[j][k].second=i,step[j][k]=tempcnt;
            }
        }
    }
    int cnt[n]={0};
    for(int i=0; i<maxx; i++){
        for(int j=0; j<maxy; j++){
            if(step[i][j]!=-1){
                if(i==maxx-1&&a[eater[i][j].first].dir=='E'||j==maxy-1&&a[eater[i][j].first].dir=='N'){
                    cnt[eater[i][j].first]=-1;
                    if(eater[i][j].second!=-1){
                        cnt[eater[i][j].second]=step[i][j];
                    }
                }else if(i==maxx-1&&a[eater[i][j].second].dir=='E'&&j==maxy-1&&a[eater[i][j].first].dir=='N'||i==maxx-1&&a[eater[i][j].first].dir=='E'&&j==maxy-1&&a[eater[i][j].second].dir=='N'){
                    cnt[eater[i][j].first]=-1;
                    if(eater[i][j].second!=-1){
                        cnt[eater[i][j].second]=-1;
                    }
                }else{
                    cnt[eater[i][j].first]=step[i][j];
                    if(eater[i][j].second!=-1){
                        cnt[eater[i][j].second]=step[i][j];
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(cnt[i]==-1) cout<<"Infinity"<<endl;
        else cout<<cnt[i]<<endl;
    }
}