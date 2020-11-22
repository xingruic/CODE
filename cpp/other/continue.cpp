#include<iostream>
using namespace std;
int main(){
	
	for(int a=10;a<20;a++){
		if(a==18){
			a++;
			cout<<a<<endl;
			continue;
		}
		cout<<a<<endl;
	};
}
