//#include<bits/stdc++.h>
//using namespace std;
//string value(int n){
//  string ans;
//  while(n>0){
//    ans+=n%10+'0';
//    n/=10;
//  }
//  return ans;
//}
//bool palin(string pal){
//  for(int i=0; i<pal.size()/2; i++){
//    if(pal[i]!=pal[pal.size()-1-i]) return 0;
//  }
//  return 1;
//}
//bool leap(int year){
//  return year%4==0&&year%100!=0||year%400==0;
//}
//int main(){
//  int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//  int dt1,dt2;
//  cin>>dt1>>dt2;
//  int cnt=0;
//  int y1=0,y2=0,m1=0,m2=0,d1=0,d2=0;
//  y1=dt1/10000;
//  y2=dt2/10000;
//  m1=dt1%10000/100;
//  m2=dt2%10000/100;
//  d1=dt1%100;
//  d2=dt2%100;
//  for(int yi=y1; yi<=y2; yi++){
//    for(int mi=m1; mi<=m2; mi++){
//      int temp=days[mi];
//      if(leap(yi))temp++;
//      for(int di=d1+1; mi==m2&&di<d2||mi!=m2&&di<=temp; di++){
//        if(palin(value(yi)+value(mi)+value(di))){
//          cnt++;
//        }
//      }
//    }
//  }
//  cout<<cnt<<endl;
//}
