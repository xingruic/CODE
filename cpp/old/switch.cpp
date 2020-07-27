#include<iostream>
using namespace std;
int main(){
	int array[14]={22,34,3,32,82,55,89,50,37,5,64,35,9,70}, New[15]={array[0]};
	for(int i=14; i>1; i--){
		New[i]=array[i-1];
	}
	for(int i=0; i<15; i++){
		cout<<New[i]<<endl;
	}
}
