#include<bits/stdc++.h>
using namespace std;
string reverse(string s){
	string n="";
	for(int i=0; i<s.size(); i++){
		n=n+s[i];
		cout<<n<<' '<<s[i];
	}
	return n;
}
int main(){
	cout<<reverse("12345");
}
