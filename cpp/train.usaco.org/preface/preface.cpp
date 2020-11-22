/*
ID:xingrui1
LANG:C++11
TASK:preface
*/
#include<bits/stdc++.h>
using namespace std;
int n;
pair<string,int> roman[13]={
    {"I",1},
    {"IV",4},
    {"V",5},
    {"IX",9},
    {"X",10},
    {"XL",40},
    {"L",50},
    {"XC",90},
    {"C",100},
    {"CD",400},
    {"D",500},
    {"CM",900},
    {"M",1000}
};
int main(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    cin>>n;
    string num="";
    for(int i=1; i<=n+1; i++){
        int t=i;
        for(int j=12; j>=0; j--){
            while(roman[j].second<t){
                t-=roman[j].second;
                num+=roman[j].first;
            }
        }
    }
    // cout<<num<<endl;
    map<char,int> counts={
        {'I',0},
        {'V',0},
        {'X',0},
        {'L',0},
        {'C',0},
        {'D',0},
        {'M',0}
    };
    for(int i=0; i<num.size(); i++){
        counts[num[i]]++;
    }
    if(counts['I']>0) cout<<'I'<<' '<<counts['I']<<endl;
    if(counts['V']>0) cout<<'V'<<' '<<counts['V']<<endl;
    if(counts['X']>0) cout<<'X'<<' '<<counts['X']<<endl;
    if(counts['L']>0) cout<<'L'<<' '<<counts['L']<<endl;
    if(counts['C']>0) cout<<'C'<<' '<<counts['C']<<endl;
    if(counts['D']>0) cout<<'D'<<' '<<counts['D']<<endl;
    if(counts['M']>0) cout<<'M'<<' '<<counts['M']<<endl;
}