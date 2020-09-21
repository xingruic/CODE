#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct farmer{
  int price;
  int daily;
};
int main(){
  int need,farms,minPrice=0;
  cin>>need>>farms;
  farmer f[farms];
  for(int i=0; i<farms; i++){
    cin>>f[i].price>>f[i].daily;
  }
  for(int i=0; i<farms; i++){
    for(int j=0; j<farms; j++){
      if(f[j].price>f[j+1].price){
        swap(f[j],f[j+1]);
      }
    }
  }
  for(int i=0; i<farms; i++){
    for(;f[i].daily>0&&need>0;f[i].daily--){
      need--;
      minPrice+=f[i].price;
    }
  }
  cout<<minPrice<<endl;
  return 0;
}
