#include<bits/stdc++.h>
using namespace std;
int cnt=0;
bool he(int s,int l,int a[],int sum=0,int i=0){
	if(s==0){
		return 0;
	}
	if(i==l){
		if(cnt==2)
			return sum==s;
	}
	if(he(s,l,a,sum,i+1)){
		if(cnt==2)
			return 1;
	}
	if(he(s,l,a,sum+a[i],i+1)){
		cnt++;
		cout<<a[i]<<endl;
		if(cnt==2)
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
	int s;
	cin>>s;
	cout<<he(s,l,a)<<endl;
	return 0;
}
