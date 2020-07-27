#include<iostream>
using namespace std;
int main(){
	int array[]={22,34,3,32,82,55,89,50,37,5,64,35,9,70}, sorted[sizeof(array)/4]={0},smallest=100,sindex;
	for(int i=0; i<sizeof(array)/4; i++){
		for(int each=0; each<sizeof(array)/4; each++){
			if(array[each]<smallest){
				smallest=array[each];
				sindex=each;
			}
		}
		sorted[i]=smallest;
		array[sindex]=1000;
		smallest=100;
	}for(int i=0; i<sizeof(sorted)/4; i++){
		cout<<sorted[i]<<endl;
	}
}
