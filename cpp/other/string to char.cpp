#include<bits/stdc++.h>
using namespace std;
int main(){
	char c[]="qwerty";//qwerty∫Û√Ê”–\n 
	string s="123457989078078979870979080";
//	char d[]=s;
	for(int i=0; i<7; i++){
		cout<<c[i];
	}
	cout<<endl;
	for(int i=0; i<s.size(); i++){
		cout<<','<<s[i];
	}
	cout<<endl<<s<<endl<<sizeof(c)<<' '<<sizeof(s);//sizeof(string)=8
}
