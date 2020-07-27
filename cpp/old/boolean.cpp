#include<iostream>
using namespace std;
int main(){
	bool a,b;
	cin>>a>>b;
	if(a&&b){
		cout<<true<<endl;
	}if(a||b){
		cout<<true<<endl;
	}if(!(a&&b)){
		cout<<false<<endl;
	}
}
