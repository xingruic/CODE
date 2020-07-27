#include<bits/stdc++.h>
using namespace std;
int a[100]={1,2,4,7};
int n=4,k=13;

bool partsum(int i, int sum){
	if(i==n) return sum==k;
	if(partsum(i+1,sum))
		return true;
	if(partsum(i+1,sum+a[i])){
		return true;
	}
	return false;
}

int main(){
	if(partsum(0,0)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
