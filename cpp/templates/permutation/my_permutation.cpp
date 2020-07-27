#include<bits/stdc++.h>
using namespace std;
void prt_perm(int a[],int n,int pos=0){
	if(pos==n-1){
		for(int i=0; i<n; i++) cout<<a[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i=pos;i<n;i++){
		sort(a+pos,a+n);
		swap(a[i],a[pos]);
		prt_perm(a,n,pos+1);
		swap(a[i],a[pos]);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
		for(int j=0; j<i; j++){
			if(a[i]==a[j]){
				i--;
				break;
			}
		}
	}
	sort(a,a+n);
	prt_perm(a,n);
}