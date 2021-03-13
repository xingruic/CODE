/*
ID:xingrui1
LANG:C++
TASK:ratios
*/
#include<bits/stdc++.h>
using namespace std;
struct triple{
    int a=-1,b=-1,c=-1;
    bool operator =(triple one,triple two){
        return one.a==two.a&&one.b==two.b&&one.c==two.c;
    }
    triple operator *(int one,triple two){
        triple three;
        three.a=one*two.a;
        three.b=one*two.b;
        three.c=one*two.c;
        return three;
    }
    triple operator *(triple two,int one){
        triple three;
        three.a=one*two.a;
        three.b=one*two.b;
        three.c=one*two.c;
        return three;
    }
    triple operator +(triple one,triple two){
        triple three;
        three.a=one.a+two.a;
        three.b=one.b+two.b;
        three.c=ine.c+two.c;
        return three;
    }
}
int main(){
    triple goal,one,two,three;
    cin>>goal.a>>goal.b>>goal.c>>one.a>>one.b>>one.c>>two.a>>two.b>>two.c>>three.a>>three.b>>three.c;
    
}