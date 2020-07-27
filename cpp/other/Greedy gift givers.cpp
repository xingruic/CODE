#include<iostream>
#include<string>
using namespace std;
int main(){
  int NP=0;
  cin>>NP;
  string people[NP];
  int money[NP]={0}, NGi, paid[NP]={0};
  for(int i=0; i<NP; i++){
    cin>>people[i];
  }
  for(int i=0; i<NP; i++){
    string name;
    cin>>name>>paid[i]>>NGi;
    for(int j=0; j<NGi; j++){
        string currentPaid;
        cin>>currentPaid;
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
    cout<<people[i]<<' '<<money[i]<<endl;
  }
}
