/*
ID: xingrui1
TASK: beads
LANG: C++
*/
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	int l,beads=0;
	cin>>l;
	string a;
	cin>>a;
	a+=a;
	l*=2;
	int i,j,sum=0;
	for(i=0; i<l; i++){
		string temp=a;
		sum=0;
		j=1;
		for(int k=i+1; temp[k]==temp[k-1]; k++){
			cout<<"i = "<<i<<endl;
			cout<<temp[k]<<endl;
			j++;
		}cout<<"j: "<<j<<endl<<"！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl;
		sum+=j;
//		cout<<sum<<endl;
		j=1;
		temp=a;
		for(int k=i; temp[k-1]==temp[k]; k--){
			cout<<temp[k]<<endl;
			j++;
		}cout<<"j: "<<j<<endl<<"！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl;
		sum+=j%l;
		cout<<"sum: "<<sum<<endl;
		cout<<endl;
		beads=max(beads,sum);
	}
	cout<<beads<<endl;
	return 0;
}
