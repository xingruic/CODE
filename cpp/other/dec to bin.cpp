#include<bits/stdc++.h>
using namespace std;
int n[1000]={0};
int dec_to_(int dec, int base){
	int i=0;
	while(dec!=0){
		n[i]=dec%base;
		dec/=base;
		i++;
	}
	return i;
}
int main(){
	int a;
	cin>>a;
	int i=dec_to_(a,2);
	for(int j=i-1; j>=0; j--){
		cout<<n[j];
	}
	cout<<endl;
}
