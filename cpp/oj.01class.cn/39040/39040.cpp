#include<bits/stdc++.h>
using namespace std;
int main(){
    string info1,info2,crypted,decrypted="";
    cin>>info1>>info2>>crypted;
    if(info1==info2){
        cout<<"Failed"<<endl;
        return 0;
    }
    for(int i=0; i<info1.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(info1[j]==info1[i]&&info2[j]!=info2[i]){
                cout<<"Failed"<<endl;
                return 0;
            }
            if(info2[j]==info2[i]&&info1[j]!=info1[i]){
                cout<<"Failed"<<endl;
                return 0;
            }
        }
    }
    for(int i=0; i<crypted.size(); i++){
        int j;
        for(j=0; j<info1.size(); j++){
            if(info1[j]==crypted[i]){
                decrypted+=info2[j];
                break;
            }
        }
        if(j==info1.size()){
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    cout<<decrypted<<endl;
}