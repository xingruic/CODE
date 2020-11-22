#include<bits/stdc++.h>
using namespace std;
int k=31;
bool he(int a[],int l,int sum=0,int count=0){
	if(count==l){
		return sum==k;
	}
	if(he(a,l,sum+a[count],count+1)){
		cout<<a[count]<<' ';
		return 1;
	}
	if(he(a,l,sum,count+1)){
		return 1;
	}
	return 0;
}
int main(){
	int l;
	cin>>l;
	int a[l];
	for(int i=0; i<l; i++){
		cin>>a[i];
	}
	he(a,l);
}
