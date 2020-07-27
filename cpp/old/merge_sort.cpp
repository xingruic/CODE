#include<iostream>
#include<algorithm>
using namespace std;
void print(int a[],int s,int l){
	for(int i=s; i<l; i++){
		cout<<a[i]<<' ';
	}cout<<endl;
}
void _merge(int a[], int idx1, int idx2, int end){
	int c[end-idx1+1];
	int ins=0;
	int i=idx1,j=idx2;
	while(i<idx2&&j<end){
		if(a[i]<=a[j]){
			c[ins++]=a[i++];
		}else c[ins++]=a[j++];
	}
	while(j<end) c[ins++]=a[j++];
	while(i<idx2) c[ins++]=a[i++];
	for(int i=idx1; i<end; i++){
		a[i]=c[i-idx1];
	}
	print(a,0,8);
}
//void _merge(int arr[], int l, int m, int r) 
//{ 
//    int i, j, k; 
//    int n1 = m - l + 1; 
//    int n2 = r - m; 
//  
//    /* create temp arrays */
//    int L[n1], R[n2]; 
//  
//    /* Copy data to temp arrays L[] and R[] */
//    for (i = 0; i < n1; i++) 
//        L[i] = arr[l + i]; 
//    for (j = 0; j < n2; j++) 
//        R[j] = arr[m + 1 + j]; 
//  
//    /* Merge the temp arrays back into arr[l..r]*/
//    i = 0; // Initial index of first subarray 
//    j = 0; // Initial index of second subarray 
//    k = l; // Initial index of merged subarray 
//    while (i < n1 && j < n2) { 
//        if (L[i] <= R[j]) { 
//            arr[k] = L[i]; 
//            i++; 
//        } 
//        else { 
//            arr[k] = R[j]; 
//            j++; 
//        } 
//        k++; 
//    } 
//  
//    /* Copy the remaining elements of L[], if there 
//       are any */
//    while (i < n1) { 
//        arr[k] = L[i]; 
//        i++; 
//        k++; 
//    } 
//  
//    /* Copy the remaining elements of R[], if there 
//       are any */
//    while (j < n2) { 
//        arr[k] = R[j]; 
//        j++; 
//        k++; 
//    } 
//} 
void split(int a[], int idx1, int idx2){
	if(idx1<idx2){
		split(a,idx1,(idx2+idx1)/2);
		split(a,(idx2+idx1)/2+1,idx2);
	}
		_merge(a,idx1,(idx1+idx2)/2,idx2);
}
int main(){
	int a[]={ 12, 11, 13, 5, 6, 7, 899, 900 };
	split(a,0,8);
//_merge(a,0,5,10);
	for(int i=0; i<8; i++) cout<<a[i]<<endl;
}
