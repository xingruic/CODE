#include<iostream>
using namespace std;
long long ex(int x=1, int y=1){
	if(y==0){
		return 1;
	}
	return x*ex(x,y-1);
}
int main(){
	int x,y;
	cin>>x>>y;
	cout<<ex(x,y); 
}
