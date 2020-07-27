#include<bits/stdc++.h>
using namespace std;
struct point{
  int x,y;
  int range=(int)NULL;
};
int main(){
  point d1, d2;
  int n;
  cin>>d1.x>>d1.y>>d2.x>>d2.y>>n;
  point msl[n];
  for(int i=0; i<n; i++){
    cin>>msl[i].x>>msl[i].y;
    if(d1.x-msl[i].x+d1.y-msl[i].y<d2.x-msl[i].x+d2.y-msl[i].y){
      d1.range=min(d1.range,min(msl[i].x,msl[i].y));
    }else{
      d2.range=min(d2.range,min(msl[i].x,msl[i].y));
    }
  }
  int ans=d1.range*d1.range+d2.range*d2.range;
  cout<<ans<<endl;
}
