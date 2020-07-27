#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,flag;
	cin>>n>>m; 
	int w[n],s[m];
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<m;i++) s[i]=w[i];
	flag=m;
	while(flag<n){
		for(int i=0;i<m;i++){
			w[i]--;
			if(w[i]==0&&flag<n){
				w[i]=w[flag];
				s[i]=s[i]+w[flag];
				flag++;
			}
		}
	}
	int max=0;
	for(int i=0;i<m;i++){
		if(s[i]>max)
			max=s[i];
	}
	cout<<max;
			return 0;
}