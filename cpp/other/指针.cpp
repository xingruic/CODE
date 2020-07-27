#include<iostream>
using namespace std;
int main(){
	int a[6]={0,1,2,3,4,5};
//	for(int i=0; i<6; i++){
//		cout<<a+i<<endl;
//		cout<<*(a+i)<<endl;
//		cout<<a[i]<<endl;
//	}
	cout<<*a<<endl;
	cout<<*(a+0)<<endl;
	cout<<*(a+1)<<endl;
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
}
