#include<iostream>
using namespace std;
int main(){
	int array[]={22,34,3,32,82,55,89,50,37,5,64,35,9,70};
	bool sorted=false,swaped=false;
	while(sorted==false){
		swaped=0;
		for(int j=0; j<sizeof(array)/sizeof(int)-1; j++){
			if(array[j]<array[j+1]){
				swap(array[j],array[j+1]);
				swaped=1;
			}
		} 
		if(!swaped)sorted=1;
	}
	for(int i=0; i<sizeof(array)/sizeof(int); i++){
		cout<<array[i]<<endl;
	}
}
