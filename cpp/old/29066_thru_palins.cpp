#include<bits/stdc++.h>
using namespace std;
int rev(int orig){
  int bkwd=0;
  while(orig>0){
  	bkwd=bkwd*10+orig%10;
  	orig/=10;
  }
  return bkwd;
}
bool leap(int year){
  return year%4==0&&year%100!=0||year%400==0;
}
int main(){
	int dt,dtt;
	int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	cin>>dt>>dtt;
	int cnt=0;
	if(dt<=92200229&&dtt>=92200229){
		cnt++;
	}
	for(int i=dt/10000; i<=dtt/10000; i++){
		int date=rev(i);
		if(date/100>12||date/100<1) continue;
		if(date%100>days[date/100]||date%100<1) continue;
		cnt++;
	}
	cout<<cnt<<endl;
}
