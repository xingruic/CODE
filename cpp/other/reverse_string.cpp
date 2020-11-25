//#include<bits/stdc++.h>
//using namespace std;
//string reverse(string s){
//	for(int i=0; i<s.size()/2; i++){
//		swap(s[i],s[s.size()-1-i]);
//	}
//	return s;
//}
//int main(){
//	cout<<("12345");
//}
#include<bits/stdc++.h>
using namespace std;

void reverse(char *a,char *b){
 while(a<b){
  swap(*(a++),*(b--));
//  swap(*a,*b);
//  a++;
//  b--;
 }
}

int main(){
 string s="12345";
 cout<<s[0]<<endl;
 //reverse(s.begin(),s.end());
 reverse(s.begin(),s.end());
 cout<<s<<endl;
 return 0;
}
