#include<bits/stdc++.h>
using namespace std;
int main(){
	set<string> s;
	s.insert("hello");
	s.insert("hi");
	s.insert("hola");
	s.insert("bonjour");
	s.erase("hi");
	set<string>::iterator i;
	for(i=s.begin();i!=s.end();i++){
		cout<<*i<<endl;
	}
}
