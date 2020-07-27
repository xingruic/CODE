#include<iostream>
using namespace std;
int max2(int int1, int int2){
	if(int1>int2){
		return int1;
	}else{
		return int2;
	}
}
int main(){
	int a = 100;
	int b = 200;
	int ret;
	ret = max2(a,b);
	cout<<"Max value is "<<ret<<endl;
	return 0;
}
