#include<iostream>
using namespace std;
int hello(string name){
	cout<<"Hello "<<name<<"!"<<endl;
	return 0;
}
int main(){
	string s;
	cout<<"What's your name?"<<endl;
	cin>>s;
	hello(s);
	return 0;
}
