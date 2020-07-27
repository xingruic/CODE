/*
ID: xingrui1
LANG: C++
TASK: beads
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	int n;
	cin>>n;
	string b;
	cin>>b;
	int numm=0;
	string a;
	for(int i=0; i<n*2; i++){
		a=b+b;
		int num=1;
		int j;
		for(j=i; j<n*2-1; j++){
			if(a[j]=='w'){
				a[j]=a[j+1];
			}
			if(a[j+1]=='w'){
				num++;
				a[j+1]=a[j];
				continue;
			}
			if(a[j]!=a[j+1]) break;
			num++;
		}
		num++;
		a=b+b;
		for(j=i-1; j>0; j--){
			if(a[j-1]=='w'){
				num++;
				a[j-1]=a[j];
				continue;
			}
			if(a[j-1]!=a[j]) break;
			num++;
		}
		numm=max(num,numm);
		// cout<<endl;
	}
	if(numm>n) numm=n;
	cout<<numm<<endl;
	return 0;
}
