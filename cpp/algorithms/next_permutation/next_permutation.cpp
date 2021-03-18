// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
#include<iostream>
using namespace std;
bool next_permutation(int a[],int n){
    int k,l;
    for(k=n-2; k>=0; k--) if(a[k+1]>a[k]) break;
    cout<<k<<endl;
    if(k==-1) return 0;
    for(int i=0; i<n; i++) if(a[i]>a[k]) l=i;
    swap(a[k],a[l]);
    cout<<k<<' '<<l<<endl;
    for(int i=k+1; i<n; i++){
        swap(a[i],a[n-(k+1-i)-1]);
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    // while(next_permutation(a,n)){
    for(int i=0; i<100; i++){
        next_permutation(a,n);
        for(int i=0; i<n-1; i++) cout<<a[i]<<' ';
        cout<<a[n-1]<<endl;
    }
    cout<<"no more permutations."<<endl;
}