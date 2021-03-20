// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
#include<bits/stdc++.h>
using namespace std;
bool my_next_permutation(int a[],int n){
    int k=-1,l;
    for(int i=0; i<n-1; i++) if(a[i]<a[i+1]) k=i;
    if(k==-1) return 0;
    for(int i=k+1; i<n; i++) if(a[k]<a[i]) l=i;
    swap(a[l],a[k]);
    reverse(a+k+1,a+n);
    return 1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    while(my_next_permutation(a,n)){
        my_next_permutation(a,n);
        for(int i=0; i<n-1; i++) cout<<a[i]<<' ';
        cout<<a[n-1]<<endl;
    }
    cout<<"no more permutations."<<endl;
}