#include<iostream>
using namespace std;
int main(){
	char a;
	int b;
	cin>>a>>b;int i=b;
	while(i>0){
		int j=i;
		while(j>0){
			cout<<a;j--;
		}
		cout<<endl;i--;
	}
}
