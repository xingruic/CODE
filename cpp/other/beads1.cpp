/*
ID: xingrui1
TASK: beads
LANG: C++
*/
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int beadsD(string a, int inx, int sum=0){
	if(inx>0&&(a[inx]==a[inx-1]||a[inx-1]=='w')){
		a[inx-1]=a[inx];
		cout<<"a["<<inx<<"]: "<<a[inx]<<endl;
		sum=beadsD(a,inx-1,sum+1);
	}else{
		return sum;
	}
}
int beadsU(string a, int inx, int sum=0){
	if(inx<a.size()&&(a[inx]==a[inx+1]||a[inx+1]=='w')){
		a[inx-1]=a[inx];
		cout<<"a["<<inx<<"]: "<<a[inx]<<endl;
		beadsU(a,inx+1,sum+1);
	}else{
		return sum;
	}
}
int main(){
	int o,sum=0;
	string a;
	cin>>o>>a;
	for(int i=0; i<a.size(); i++){
		int c=beadsD(a,i);
		int d=beadsU(a,i);
		sum=max(sum,c+d);
	}
	cout<<sum<<endl;
	return 0;
}
