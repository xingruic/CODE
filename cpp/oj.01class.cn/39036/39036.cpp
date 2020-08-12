#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
    bool ans=1;
    if(n<2) ans=0;
    for(int i=2; i*i<n; i++) if(n%i==0) ans=0;
    return ans;
}
int main(){
    string word;
    cin>>word;
    int num[26]={0};
    for(int i=0; i<word.size(); i++){
        num[word[i]-'a']++;
        // cout<<word[i]-'a'<<endl;
    }
    // for(int i=0; i<26; i++) cout<<num[i]<<endl;
    int m=0,mi=0x7fffffff;
    for(int i=0; i<26; i++){
        m=max(num[i],m);
        if(num[i])
            mi=min(num[i],mi);
    }
    int n=m-mi;
    // cout<<m<<' '<<mi<<endl;
    if(prime(n)) cout<<"Lucky Word"<<endl<<n<<endl;
    else cout<<"No Answer"<<endl<<0<<endl;
}