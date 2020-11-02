#include<bits/stdc++.h>
using namespace std;
vector<string> gary(int n,int b){
    if(n<1) return {"0"};
    if(n==1){
        vector<string> t;
        for(int i='0'; i<b+'0'; i++){
            t.push_back(""+i);
        }
        return t;
    }
    vector<string> last=gary(n-1,b);
    vector<string> main;
    for(int i=0; i<last.size(); i++){
        main.push_back('0'+last[i]);
    }
    for(int i=last.size()-1; i>=0; i--){
        main.push_back('1'+last[i]);
    }
    return main;
}
int main(){
    int n,b;
    cin>>n>>b;
    vector<string> code=gary(n,b);
    for(auto i=code.begin(); i!=code.end(); i++){
        cout<<*i<<endl;
    }
}