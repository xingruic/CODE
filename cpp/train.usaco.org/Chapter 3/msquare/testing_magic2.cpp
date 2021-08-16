#include<bits/stdc++.h>
using namespace std;
string A(string x){
	string xx=x;
	for(int i=0;i<4;i++){
		char x1=x[i];
		x[i]=x[7-i];
		x[7-i]=x1;
	}
	return x;
}
string B(string x){
	string xx=x;
	x[0]=xx[3],x[1]=xx[0],x[2]=xx[1],x[3]=xx[2],x[4]=xx[5],x[5]=xx[6],x[6]=xx[7],x[7]=xx[4];
	return x;
}
string C(string x){
	string xx=x;
	x[1]=xx[6],x[2]=xx[1],x[5]=xx[2],x[6]=xx[5];
	return x;
}
int main(){
    string t="CCBBB";
    string squares="12345678";
    for(int i=0; i<t.size(); i++){
        cout<<squares<<endl;
        switch(t[i]){
            case 'A':
                squares=A(squares);
                break;
            case 'B':
                squares=B(squares);
                break;
            default:
                squares=C(squares);
                break;
        }
    }
    cout<<squares<<endl;
}