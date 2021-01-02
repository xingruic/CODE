#include<bits/stdc++.h>
using namespace std;
string sub(string a, string b){
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
	if(s==a.size()){
		final="0";
	}
	return final;
}
bool gt0(string a, string b){//a-b是否大于零 
	if(a.size()>b.size()){
		return 1;
	}
	if(a.size()<b.size()){
		return 0;
	}
	for(int i=0; i<a.size(); i++){
		if(a[i]>b[i]){
			return 1;
		}
	}
	return 0;
}
string div(string a, string b, char c){
	string temp="", e="";
	int i=0, ftemp_dig=0;
	string R="", Q="";
	for(int count=0, j=0; count<a.size(); count++){
		for(i=count; gt0(b,temp); i++){
			temp=temp+a[i];
		}//i是temp最后一位的下标
		/********************* 
		借位时往商的后面添零 |
		                   \/
		*********************/
		if(temp.size()>b.size()){
			Q=Q+'0';
		}
		if(j==0){
			count=i;
		}
		cout<<temp<<endl;
		for(i=0; gt0(temp, sub(b,"1")); i++){
			cout<<temp<<'-'<<b<<'=';
			temp = sub(temp,b);
			if(temp=="0"){
				temp="";
			}
			cout<<temp<<endl;
		}
		Q=Q+(char)(i+'0');
		j++;
	}
	R=temp;
	if(R==""){
		R="0";
	}
	if('q'==c){
		return Q;
	}else{
		return R;
	}
}
int main(){
	string a,b;
	cin>>a>>b;
//	cout<<sub(a,b);
	cout<<div(a,b,'q')<<endl<<div(a,b,'r');
}
