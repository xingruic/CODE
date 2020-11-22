#include<iostream>
using namespace std;
void hanoi(int n,char s,char m,char t){
	if(n==1){
		cout<<s<<" to "<<t<<endl;
	}else{
		hanoi(n-1,s,t,m);
		cout<<s<<" to "<<t<<endl;
		hanoi(n-1,m,s,t);
	}
	return;
}
int main(){
	int levels;
	cin>>levels;
	hanoi(levels,'A','B','C');
}
