#include<bits/stdc++.h>
using namespace std;
void knary(int n,int a[],int b,int l){
	if(n==0){
		for(int i=0; i<l; i++){
			cout<<a[i];
		}cout<<endl;
		return;
	}
	for(int i=0; i<b; i++){
		a[n-1]=i;
		knary(n-1,a,b,l);
	}
//	a[n-1]=2;
//	binstr(n-1,a);
//	a[n-1]=1;
//	binstr(n-1,a);
//	a[n-1]=0;
//	binstr(n-1,a);
}
int main(){
	int b,l;
	cin>>b>>l;
	int a[l]={0};
	knary(l,a,b,l);
}
