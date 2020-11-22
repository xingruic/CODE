#include<bits/stdc++.h>
using namespace std;
int main(){
	int array[]={22,34,3,32,82,55,89,50,37,5,64,35,9,70},sorted[sizeof(array)/sizeof(int)]={0};
	sorted[0]=array[0]
	for(int i=1; i<sizeof(array)/sizeof(int); i++){
		for(int j=0; sizeof(sorted)<=sizeof(array); j++){
			if(array[i]<sorted[j]){
				for(int k=sizeof(sorted)/sizeof(int)-1; k>=j; k--){
					swap(sorted[k],sorted[k+1]);
				}
				sorted[j]=array[i];
				continue;
			}else{
				if(array[i]<sorted[j+1]){
					for(int k=sizeof(sorted)/sizeof(int)-1; k>j; k--){
						swap(sorted[k],sorted[k+1]);
					}
					sorted[j+1]=array[i];
					continue;
				}else{
					if(array[i]<sorted[j+2]){
						for(int k=sizeof(sorted)/sizeof(int)-1; k>j+1; k--){
							swap(sorted[k],sorted[k+1]);
						}
						sorted[j+2]=array[i];
						continue;
					}
				}
			}
		}
	}
}
