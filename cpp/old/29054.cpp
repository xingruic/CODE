#include<iostream>
using namespace std;

int main(){
    int num,ans=0,prod=1;
    char op;
    cin>>num;
    while(cin>>op){
        prod*=num; 
        prod%=10000;
        if(op=='+') {ans+=prod;ans%=10000;prod=1;}   
        cin>>num; 
        num%=10000;
    }
    prod*=num;  
    ans+=prod;
    ans%=10000;
    cout<<ans;
    return 0;
}
//#include<iostream>
//using namespace std;
//
//int main(){
//    int n,ans=0,temp=1;
//    char ch;
//    cin>>n;
//    while(cin>>ch){
//        temp*=n; 
//        temp%=10000;
//        if(ch=='+') {ans+=temp;ans%=10000;temp=1;}   
//        cin>>n;
//        n%=10000;  
//    }
//    temp*=n;  
//    ans+=temp;
//    ans%=10000;
//    cout<<ans;
//    return 0;
//}
