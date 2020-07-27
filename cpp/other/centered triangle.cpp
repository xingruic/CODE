#include<iostream>
using namespace std;
int main(){
	int sLen;
	char a;
	cin>>a>>sLen;
	for(int i=0; i<sLen+1; i++){
		for(int j=0; j<sLen-i; j++){
			cout<<' ';
		}
		for(int k=0; k<i+i-1; k++){
			cout<<a;
		}
		cout<<endl;
	}for(int i=sLen-1; i>0; i--){
		for(int j=sLen-i+1; j>1; j--){
			cout<<' ';
		}
		for(int k=i+i-1; k>0; k--){
			cout<<a;
		}
		cout<<endl;
	}
}
