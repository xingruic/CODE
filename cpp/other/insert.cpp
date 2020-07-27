#include<iostream>
using namespace std;
int main(){
	int array[14]={22,34,3,32,82,55,89,50,37,5,64,35,9,70}, New[14]={array[0]};
	for(int i=1; i<14; i++){
		for(int j=0; j<14; j++){
			if(array[i]<New[j]){
				cout<<"====="<<New[j]<<"====="<<endl;
				cout<<"====="<<array[i]<<"====="<<endl; 
				for(int k=12; k>=j; k--){
					New[k+1]=New[k];
					cout<<New[k+1]<<"<--"<<New[k]<<endl;
				}
				array[i]=New[j];
				break;
			}
		}
		New[i]=array[i];
	}
	for(int i=0; i<14; i++){
		cout<<New[i]<<endl;
	}
}
