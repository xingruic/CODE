#include<iostream>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n],r[m-1]={0};
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  for(int i=1; i<m-1; i++){
  	for(int j=0; j<n; j++){
  		if(i%a[j]==0){
  			r[i]++;
		}
	}
	cout<<r[i]<<' ';
  }cout<<endl;
  long long an_2=1,an_1=1,an=1;
  for(int i=2; i<m; i++){
	an=(an_2+an_1+r[i-1])%19940417;
	cout<<"an, an-1, an-2, r[i-1]: "<<an<<' '<<an_1<<' '<<an_2<<' '<<r[i-1]<<endl;
	an_2=an_1%19940417;
	an_1=an%19940417;
  }
  cout<<an<<endl;
}
