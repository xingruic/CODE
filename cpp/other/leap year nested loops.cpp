#include<iostream>
using namespace std;
int main(){
	int year;
	cin>>year;
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				cout<<'y'<<endl;
			}else{
				cout<<'n'<<endl;
			}
		}else{
			cout<<'y'<<endl;
		}
	}else{
		cout<<'n'<<endl;
	}
}
