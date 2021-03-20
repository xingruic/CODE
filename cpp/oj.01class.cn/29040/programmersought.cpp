#include <cstdio>
#include <string>
#include <cstring>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int fab[100];
bool cmp(char x,char y){
    return x<y;
}
vector<char>v;
vector<char>re;
int main(){

    fab[0]=1;
    for(int i=1;i<100;i++) fab[i]=i*fab[i-1];

int n, k; // n for the location of the string, k is the length of the string
    char s[100];
    scanf("%s",s);
    k=strlen(s);
    for(int i=0;i<k;i++) v.push_back(s[i]);
    scanf("%d",&n);
    for(int i=k;i>0;i--){
        int kk=n/fab[i-1];
        n%=fab[i-1];
        sort(v.begin(),v.end(),cmp);
        //printf("~~~%c\n",v[kk]);
        re.push_back(v[kk]);
        v.erase(v.begin()+kk);
    }
    for(int i=0;i<re.size();i++) printf("%c",re[i]);
    return 0;
}