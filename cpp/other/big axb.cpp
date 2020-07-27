#include<bits/stdc++.h>
using namespace std;
void cout_prod(string a, string b){
	int ia[max(a.size(),b.size())]={0}, ib[max(a.size(),b.size())]={0}, ans[a.size()+b.size()]={0};
	for(int i=0; i<a.size(); i++){
		ia[i]=a[a.size()-i-1]-'0';
	}
	for(int i=0; i<b.size(); i++){
		ib[i]=b[b.size()-i-1]-'0';
	}
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			ans[i+j]+=ia[i]*ib[j];
		}
	}
	for(int i=0; i<a.size()+b.size()-1; i++){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	if(ans[a.size()+b.size()-1]) cout<<ans[a.size()+b.size()-1];
	for(int i=a.size()+b.size()-2; i>=0; i--){
		cout<<ans[i];
	}
	cout<<endl;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout_prod(a,b);
	return 0;
}
