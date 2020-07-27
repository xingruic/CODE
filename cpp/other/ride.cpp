/*
ID: xingrui1
TASK: ride
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
  string a,b;
  int inta=1,intb=1;
  fin>>a>>b;
  for(int i=0; i<a.size(); i++){
    inta*=(int)a[i]-64;
  }
  for(int i=0; i<b.size(); i++){
    intb*=(int)b[i]-64;
  } 
  if(inta%47==intb%47){
    fout<<"GO"<<endl;
  }else{
    fout<<"STAY"<<endl;
  }return 0;
}
