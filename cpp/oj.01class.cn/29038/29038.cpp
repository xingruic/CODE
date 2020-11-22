#include<bits/stdc++.h>
using namespace std;
int dif(int a, int b){
  if(a>b)return a-b;
  else return b-a;
}
int main(){
  int h,l,t;
  cin>>h>>l>>t;
  t--;
  int biao[h][l];
  for(int i=0; i<h; i++){
    for(int j=0; j<l; j++){
      cin>>biao[i][j];
    }
  }
  int zaii=0,zaij;
  int G=0;
  for(int i=0; i<h; i++){
    for(int j=0; j<l; j++){
      	if(biao[i][j]>G)
      	zaij=j;
      	G=max(G,biao[i][j]);
    }
  }
  int sum=0;
  int maxi=0,maxj=0;
  while(1){
    if(t<dif(maxi,-1)) break;
    int g=0;
  	for(int i=0; i<h; i++){
    	for(int j=0; j<l; j++){
      		if(biao[i][j]>g){
//      			cout<<"maxi == "<<maxi<<endl;
//      			cout<<"maxi = "<<i<<endl;
//      			cout<<"maxj == "<<maxj<<endl;
//      			cout<<"maxj = "<<j<<endl<<endl;
      			maxi=i;
	      		maxj=j;
			}
      		g=max(g,biao[i][j]);
    	}
  	}
    t-=dif(zaii,maxi);
//    cout<<zaii<<' '<<maxi<<endl;
    if(t<dif(maxi,-1)) break;
    t-=dif(zaij,maxj);
//    cout<<zaij<<' '<<maxj<<endl;
    if(t<dif(maxi,-1)) break;
    zaii=maxi;
    zaij=maxj;
    biao[maxi][maxj]=0;
    t--;
    if(t<dif(maxi,-1)) break;
    sum+=g;
//    cout<<t<<" <-- t  dif(maxi,0) --> "<<dif(maxi,-1)<<endl;
  }
  cout<<sum<<endl;
}
