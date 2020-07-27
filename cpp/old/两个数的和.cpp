#include<bits/stdc++.h>
using namespace std;
bool he(int s, int l, int a[], int sum=0, int i=0){
	if(i==l){
		return sum==s;
	}
	if(he(s,l,a,sum,i+1)){
		return true;
	}
	if(he(s,l,a,sum+a[i],i+1)){
		cout<<a[i]<<' ';
		return true;
	}
	return false;
}
int main(){
	int l,sum;
	cin>>l;
	int a[l];
	for(int i=0; i<l; i++){
		cin>>a[i];
	}
	cin>>sum;
	if(he(sum,l,a)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}
