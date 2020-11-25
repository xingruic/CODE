#include<bits/stdc++.h>
using namespace std;
void cout_diff(string a,string b){
	int ia[a.size()]={0}, ib[a.size()]={0}, ans[a.size()]={0};
	for(int i=0; i<a.size(); i++){
		ia[i]=a[a.size()-i-1]-'0';
	}
	for(int i=0; i<b.size(); i++){
		ib[i]=b[b.size()-i-1]-'0';
	}
	for(int i=0; i<a.size(); i++){
		if(ia[i]-ib[i]<0){
			ans[i]=ia[i+1]*10+ia[i]-ib[i];
			if(ans[i]/10<ia[i+1]){
				ia[i+1]--;
			}
			ans[i]%=10;
		}else{
			ans[i]=ia[i]-ib[i];
		}
	}
	for(int i=0; i<a.size()-1; i++){
		if(ans[i]>=10){
			ans[i+1]++;
			ans[i]%=10;
		}
	}
	int s=0;
	for(int i=a.size()-1; i>=0; i--){
		if(0!=ans[i]){
			break;
		}
		s++;
	}
	string final="";
	for(int i=a.size()-1-s; i>=0; i--){
		final=final+(char)(ans[i]+'0');
	}
	if(a.size()==s){
		cout<<0;
	}
	for(int i=a.size()-1-s; i>=0; i--){
		cout<<ans[i];
	}
}
int main(){
	string a,b;
	cin>>a>>b;
	cout_diff(a,b);
}
