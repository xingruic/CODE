#include<bits/stdc++.h>
using namespace std;
int main(){
  int len, i, b1=0, b2=0, bmax=0, ans;
  cin>>len;
  string neckl;
  cin>>neckl;
  for(i=0; i<len; i++){
	  for(int j=i+len-1; j<i+len-1+len; j++){
		if(neckl[j%len]=='w'){
	  		neckl[j%len]=neckl[(j-1)%len];
		}else if(neckl[j%len]!=neckl[(j+1)%len]){
			break;
		}
		b1++;
	  }
	  for(int j=i+len-1; j>=i; j--){
	  	if(neckl[j%len]=='w'){
	  		neckl[j%len]=neckl[(j-1)%len];
		}else if(neckl[j%len]!=neckl[(j-1)%len]){
			break;
		}
		b2++;
	  }
	  b1=max(b1,b2);
	  if(b1>bmax){
	  	bmax=b1;
	  	ans=i;
	  }
  }
  cout<<b1;
}
