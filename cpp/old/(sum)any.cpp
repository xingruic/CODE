#include<bits/stdc++.h>
using namespace std;
int m=331;
int l=10;
int List[10]={1,5,7,10,21,98,71,23,69,32};
bool any(int s=m,int i=0){
	if(s==0){
		return 1;
	}
	if(i==l){
		return 0;
	}
	if(any(s,i+1))
	return 1;
	if(any(s-List[i],i+1)){
		cout<<List[i]<<endl;
		return 1;
	}
}
int main(){
	cout<<any(m,0);
}
