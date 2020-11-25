/*
ID: xingrui1
TASK: friday
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");
  int N, md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},wkd[7]={0},days=0;
  fin>>N;
  for(int y=1900; y<1900+N; y++){
    if(y%4==0&&y%100!=0||y%400==0){
      md[2]=29;
      for(int m=1; m<13; m++){
        for(int d=1; d<=md[m]; d++){
          days++;
          if(d==13){
          	wkd[days%7]++;
          }
        }
      }
    }else{
      md[2]=28;
      for(int m=1; m<13; m++){
        for(int d=1; d<=md[m]; d++){
          days++;
          if(d==13){
          	wkd[days%7]++;
          }
        }
      }
    }
  }
  fout<<wkd[6]<<' ';
  for(int i=0; i<6; i++){
  	if(i==5){
  		fout<<wkd[i];
	}else{
    	fout<<wkd[i]<<' ';
    }
  }fout<<endl;
}
/*
400:684 687 685 685 687 684 688
*/
