#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int NN=0; NN<n; NN++){
        int S,T,A,B;
        cin>>S>>T>>A>>B;
        int x1[S],y1[S],x2[S],y2[S],x3[S],y3[S],t[S];
        int maxx=-1,maxy=-1;
        for(int i=0; i<S; i++){
            cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>x3[i]>>y3[i]>>t[i];
            maxx=max(x1[i],max(x2[i],max(x3[i],maxx)));
            maxy=max(y1[i],max(y2[i],max(y3[i],maxy)));
        }
        int plane[maxx+1][maxy+1];
        memset(plane,-1,sizeof(plane));
        for(int i=0; i<S; i++){
            plane[x1[i]][y1[i]]=plane[x2[i]][y2[i]]=plane[x3[i]][y3[i]]=i;
            // 中点=((x1+x2)/2,(y1+y2)/2)
            //        ^  ^      ^  ^        不是代码里的数组
            
        }
    }
}