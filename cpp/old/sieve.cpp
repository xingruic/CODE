#include<bits/stdc++.h>
using namespace std;
int prime[10000000]={0};
int main(){
	int count=0;
	for(int i=2;i<10000001;i++){
		prime[i]=i;
	}
	for(int i=0;i<10000000;i++){
		if(prime[i]){
			for(int j=i+prime[i];j<10000000;j+=i){
				prime[j]=0;
			}
		}
	}
	for(int i=0;i<10000000;i++){
		if(prime[i]){
			count++;
			//		cout<<prime[i]<<endl;
		}
	}
	cout<<count<<endl;
}
