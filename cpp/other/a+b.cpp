#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int la=a.size(), lb=b.size();
	int ia[max(la,lb)]={0}, ib[max(la,lb)]={0}, sum[max(la,lb)+1]={0};
	for(int i=max(la,lb)-1; i>=max(la,lb)-la; i--){
		ia[i] = (int)a[i]-48;
	}
	for(int i=max(la,lb)-1; i>=max(la,lb)-lb; i--){
		ib[i] = (int)b[i]-48;
	}
	for(int i=0; i<max(la,lb); i++){
		cout<<ia[i];
	}
	cout<<endl;
	for(int i=0; i<max(la,lb); i++){
		cout<<ib[i];
	}
	cout<<endl;
	for(int i=max(la,lb)-1; i>=0; i--){
		if(ia[i]+ib[i]<10){
			sum[i]=ia[i]+ib[i];
		}else{
			sum[i]=(ia[i]+ib[i])%10;
			sum[i+1]=1;
		}
	}
	for(int i=0; i<max(la,lb); i++){
		cout<<sum[i];
	}
	cout<<endl;
}
//#include<bits/stdc++.h>
//#define L 5000
//using namespace std;
//string add(string a, string b){
//	string ans;
//	int na[L]={0},nb[L]={0};
//	int la=a.size(),lb=b.size();
//	for(int i=0; i<la; i++){
//		na[la-i-1]=a[i]-'0';
//	}
//	for(int i=0; i<la; i++){
//		na[lb-1-i]=b[i]-'0';
//	}
//	int lmax=la>lb?la:lb;
//	for(int i=0; i<lmax; i++){
//		na[i]+=nb[i],na[i+1]+=na[i]/10,na[i]%=10;
//	}
//	if(na[lmax])lmax++;
//	for(int i=lmax-1; i>=0; i--){
//		ans+=na[i]+'0';
//	}
//	return ans;
//}
//int main(){
//	string a,b;
//	cin>>a>>b;
//	cout<<add(a,b)<<endl;
//	return 0;
//}
