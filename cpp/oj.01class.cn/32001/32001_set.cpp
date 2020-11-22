#include<bits/stdc++.h>
using namespace std;
/*
set.end() is not last element,
set.end() will update continually,
*/
void printset(set<int> s){
	set<int>::iterator itr;
	for(itr=s.begin();itr!=s.end();itr++){
		cout<<*itr<<' ';
	}
	cout<<endl;
	return;
}
int main(){
	int n;
	cin>>n;
	int hp[]={2,3,5};
	set<int>chou{1,2,3,5};
//	printset(chou);
	for(int i=0; i<3; i++){
		for(set<int>::iterator itr=chou.begin(); itr!=chou.end(); itr++){
			int t=hp[i];
			if(*itr*t<0) break;
			if(chou.size()>n){
				chou.erase(--chou.end());
				if(*itr*t>*--chou.end()){
					break;
				}
			}
			chou.insert(*itr*t);
//			printset(chou);
		}
	}
//	printset(chou);
	cout<<*----chou.end()<<endl;
}
