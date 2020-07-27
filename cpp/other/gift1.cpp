/*
ID: xingrui1
TASK: gift1
LANG: C++                 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
  int NP=0;
  fin>>NP;
  string people[NP];
  int money[NP]={0}, NGi, paid[NP]={0};
  for(int i=0; i<NP; i++){
    fin>>people[i];
  }
  for(int i=0; i<NP; i++){
    string name;
    fin>>name>>paid[i]>>NGi;
    for(int j=0; j<NGi; j++){
        string currentPaid;
        fin>>currentPaid;
	    for(int k=0; k<NP; k++){
	      if(currentPaid==people[k]){
	        if(NGi!=0){
		        money[k]+=paid[i]/NGi;
//		        cout<<paid[i]<<' '<<money[k]<<endl;
	        }
	      }
	    }
	}
    if(NGi!=0){
      for(int h=0; h<NP; h++){
        if(name==people[h]){
        	money[h]-=paid[i]-paid[i]%NGi;
        }
	  } 
    }
  }
  for(int i=0; i<NP; i++){
    fout<<people[i]<<' '<<money[i]<<endl;
  }
}
