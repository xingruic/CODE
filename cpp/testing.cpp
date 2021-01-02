#include<bits/stdc++.h>
using namespace std;
int ip=0; // insertion point = ip, to mark where to insert characters
void append(char ans[],string str){
    int stop=ip+str.size();
    for(int i=ip; i<stop; i++){
        ans[i]=str[i-ip];
    }
    return;
}
int main(){
	char ans[100]={0};
    append(ans,"hello");
    for(int i=0; i<10; i++) cout<<ans[i]<<endl;
}