#include<bits/stdc++.h>
using namespace std;
//bool ugly(int num){
//	while(!(num%2)){
//		num/=2;
//	}
//	while(!(num%3)){
//		num/=3;
//	}
//	while(!(num%5)){
//		num/=5;
//	}
//	return num==1;
//}
int main(){
  int cnt=0,num;
  cin>>num;
  int uglies[num+1];
  queue<int>q2,q3,q5;
  uglies[1]=1;
  //for
  for(int i=1; i<num+1; i++){
  	if(i!=1){
  		int v=min(q2.front(),min(q3.front(),q5.front()));
		uglies[i]=v;
		if(v==q2.front()) q2.pop();
		if(v==q3.front()) q3.pop();
		if(v==q5.front()) q5.pop();
	}
	q2.push(uglies[i]*2);
	q3.push(uglies[i]*3);
	q5.push(uglies[i]*5);
  }
  cout<<uglies[num]<<endl;
//  int i=0;
//  while(cnt<num){
//  	i++;
//  	if(ugly(i)) cnt++;
//  }
//  cout<<i<<endl;
}
