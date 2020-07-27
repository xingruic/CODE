#include<iostream>
using namespace std;
int main(){
  int k,a,n1=0,n5=0,n10=0;
  cin>>k;
  for(int i = 0; i < k; i++){
    cin>>a;
    switch(a){
      case 1:
        n1++;
        break;
      case 5:
        n5++;
        break;
      case 10:
        n10++;
        break;
    }
  }
  cout<<n1<<endl<<n5<<endl<<n10<<endl;
}
