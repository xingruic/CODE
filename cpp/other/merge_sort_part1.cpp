#include<bits/stdc++.h>
using namespace std;
void print(int a[],int l){
	for(int i=0; i<l; i++){
		cout<<a[i]<<' ';
	}cout<<endl;
}
void _merge(int a[], int idx1, int idx2, int end){
	int c[end-idx1+1];
	int ins=0;
	int i=idx1,j=idx2;
	while(i<idx2&&j<end){
		if(a[i]<a[j]){
			c[ins++]=a[i++];
		}else c[ins++]=a[j++];
	}
	while(j<end) c[ins++]=a[j++];
	while(i<idx2) c[ins++]=a[i++];
	for(int i=idx1; i<end; i++){
		a[i]=c[i-idx1];
	}
}
int main(){
	int a[]={55,51,	52,		53,54,	9,	17,	20,	39	,50};
	_merge(a,0,5,sizeof(a)/sizeof(int));
	print(a,sizeof(a)/sizeof(int));
}
