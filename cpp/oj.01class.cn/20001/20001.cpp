/*
ID: xingrui1
TASK: ride
LANG: C++
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  string a,b;
  int suma,sumb;
  fin>>a>>b;
  for(int i=0; i<a.size(); i++){
    suma += (int)a[i]-64;
  }
  for(int i=0; i<b.size(); i++){
    sumb += (int)b[i]-64;
  }
  if(suma==sumb)fout<<"GO"<<endl;
  else fout<<"STAY"<<endl;
  return 0;
}
