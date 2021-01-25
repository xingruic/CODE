#include<bits/stdc++.h>
using namespace std;
int n,k,m,s,t,b[105],a[105][105]; // no. of countries, no. of beliefs, no. of roads, start, end, belief id of country, adjacency matrix
bool bad[105][105],learned[105]; // countries who hate each other's beliefs
int ans=0x7fffffff;
void Main(int i=s,int sum=0){
    learned[b[i]]=1;
    if(i==t){
        ans=min(ans,sum);
        return;
    }
    // cout<<sum<<endl;
    // assert(b[i]>-1);
    for(int j=1; j<=n; j++){
        if(a[i][j]>0x33333333||bad[b[j]][b[i]]||learned[b[j]]) continue;
        Main(j,sum+a[i][j]);
    }
}
int main(){
    memset(b,-1,sizeof(b));
    memset(a,0x3c,sizeof(a));
    memset(bad,0,sizeof(bad));
    cin>>n>>k>>m>>s>>t;
    for(int i=1; i<=n; i++){
        cin>>b[i];
    }
    for(int i=1; i<=k; i++) for(int j=1; j<=k; j++){
        cin>>bad[i][j];
    }
    for(int i=1; i<=m; i++){
        int c1,c2,c3;
        cin>>c1>>c2>>c3;
        a[c1][c2]=min(a[c1][c2],c3);
        // c1 hates c2 doesn't mean c2 hates c1, so there's no need for a[c2][c1]
        // if c1 and c2 are the same, it means the country hates anyone with the same belief coming from outside
    }
    Main();
    cout<<(ans>0x77777777?-1:ans)<<endl;
}