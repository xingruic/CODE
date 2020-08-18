#include<bits/stdc++.h>
using namespace std;
int findfirst(string large,string find,int first=0){
    if(first>=large.size()) return -1;
    for(int i=first; i<large.size(); i++){
        int j;
        for(j=0; j<find.size(); j++){
            if(find[j]!=large[i+j]){
                break;
            }
        }
        if(j==find.size()){
            return i;
        }
    }
    return -1;
}
// int kmp(string large,string find,int first=0){
//     if(first>=large.size()) return -1;
//     int kmp[find.size()]={0};
//     for(int i=0; i<find.size(); i++){
//         int a[i],b[i];
//         for(int j=0; j<i; j++){
//             a[j]=find[]
//         }
//     }
//     for(int i=first; i<large.size(); i++){
//         int j;
//         for(j=0; j<find.size(); j++){
//             if(find[j]!=large[i+j]){
//                 break;
//             }
//         }
//         if(j==find.size()){
//             return i;
//         }
//     }
//     return -1;
// }
int main(){
    string large,find;
    large="thisisbbfsdfjdsdfjddsdfcjdsdfjd";
    find="sdfjd";
    for(int i=0;(i=findfirst(large,find,i))!=-1;i++){
        
    }
}