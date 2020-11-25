#include<bits/stdc++.h>
using namespace std;
int main(){
	int array[]={22,34,3,32,82,55,89,50,37,5,64,35,9,70};
	int len=(int)sizeof(array)/sizeof(int);
	int i,j,temp;
	for(i=len-1; i>0; i--){
		temp=array[i];
		for(j=i;j<len&&array[j+1]<temp;j++)array[j-1]=array[j];
		array[j]=temp;
	}
	for(i=0;i<len;i++)cout<<array[i]<<' ';
}
