#include<iostream>
using namespace std;
int main(){
	int a=10;
	while(a<20){
		cout<<a<<endl;
		a++;
		if(a%7==0){
			break;
		}
	};
}
