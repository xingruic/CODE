#include<bits/stdc++.h>
using namespace std;
bool prime(int x){
    if(x<2) return 0;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
	cout<<prime(2331)<<endl;
}