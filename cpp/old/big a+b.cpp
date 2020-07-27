#include<bits/stdc++.h>
using namespace std;
void cout_sum(string a, string b){
	int ia[max(a.size(),b.size())]={0}, ib[max(a.size(),b.size())]={0}, ans[max(a.size(),b.size())+1]={0};
	for(int i=0; i<a.size(); i++){
		ia[i]=a[a.size()-i-1]-'0';
	}
	for(int i=0; i<b.size(); i++){
		ib[i]=b[b.size()-i-1]-'0';
	}
	for(int i=0; i<max(a.size(),b.size()); i++){
		ans[i]=ia[i]+ib[i];
	}
	for(int i=0; i<max(a.size(),b.size()); i++){
		if(ans[i]>=10){
			ans[i+1]+=1;
			ans[i]%=10;
		}
	}
	if(ans[max(a.size(),b.size())]) cout<<ans[max(a.size(),b.size())];
	for(int i=max(a.size(),b.size())-1; i>=0; i--){
		cout<<ans[i];
	}
	cout<<endl;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout_sum(a,b);
	return 0;
}
