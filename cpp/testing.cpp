#include<bits/stdc++.h>
using namespace std;
void f(vector<int> p=vector<int>(),int i=0){
	if(i==3){
		for(int i=0; i<p.size(); i++) cout<<p[i]<<' ';
		cout<<endl;
	}
	f(p,i+1);
	p.push_back(i);
	f(p,i+1);
}
int main(){
	f();
}