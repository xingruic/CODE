#include<bits/stdc++.h>
using namespace std;
int a[20000]={0},cnt=0;
int sumany(int x[],int n,int tk,int sum=0){
	if(tk==0) return sum;
	for(int i=0; i<n; i++){
		a[cnt++]=sumany(x,n,tk-1,sum+x[i]);
	}
	return 0;
}
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	int x[n]={0};
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	int var = sumany(x,n,k);
//	for(int i=0; i<cnt; i++){
//		for(int j=2; j<a[i]; j++){
//			if(a[i]%j!=0){
//				ans++;
//			}
//		}
//	}
//	cout<<ans<<endl;
for(int i=0; i<cnt; i++){
	cout<<a[i]<<endl;
}
}
