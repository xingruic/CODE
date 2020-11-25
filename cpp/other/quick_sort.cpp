#include<bits/stdc++.h>
using namespace std;
void quick_sort(int a[], int idx1, int idx2){
	if(idx2<=idx1){
		return;
	}
	int wall=a[idx1];
	int cnt=idx1;
	for(int i=idx1; i<=idx2; i++){
		if(a[i]<wall){
			swap(a[i],a[++cnt]);
		}
	}
	swap(a[idx1],a[cnt]);
//	for(int i=0; i<=idx2; i++){
//		cout<<a[i]<<' ';
//	}cout<<endl;
	quick_sort(a,idx1,cnt);
	quick_sort(a,cnt+1,idx2);
}
int main(){
	int a[]={10,9,8,7,6,5,4,3,2,1};
	quick_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i=0; i<sizeof(a)/sizeof(int); i++){
		cout<<a[i]<<' ';
	}cout<<endl;
}
