#include<iostream>
using namespace std;
int main(){
	int a,b;
	char op;
	cin>>a>>b>>op;
	
	switch(op){
		case '+':
			cout<<a+b<<endl;
			break;
		case '-':
			cout<<a-b<<endl;
			break;
		case '*':
			cout<<a*b<<endl;
			break;
		case '/':
			if(b==0){
				cout<<"Divded by zero"<<endl;
			}else{
				cout<<a/b<<endl;
			}
			break;
//		default:
//			cout<<"Invalid operation"<<endl;
	}
}
