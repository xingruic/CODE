#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int grade,cgrade;
    bool job,west;
    int essays;
    int money=0;
};
int main(){
    int n;
    cin>>n;
    Student a[n];
    int total=0;
    int j=0;
    for(int i=0; i<n; i++){
        char t1,t2;
        cin>>a[i].name>>a[i].grade>>a[i].cgrade>>t1>>t2>>a[i].essays;
        a[i].job=t1=='Y';
        a[i].west=t2=='Y';
        if(a[i].grade>80&&a[i].essays){
            a[i].money+=8000;
        }
        if(a[i].cgrade>80&&a[i].job){
            a[i].money+=850;
        }
        if(a[i].grade>90){
            a[i].money+=2000;
        }
        if(a[i].grade>85&&a[i].west){
            a[i].money+=1000;
        }
        if(a[i].grade>85&&a[i].cgrade>80){
            a[i].money+=4000;
        }
        total+=a[i].money;
        if(a[i].money>a[j].money) j=i;
    }
    for(int i=0; i<n; i++){
        if(a[i].money==a[j].money){
            j=i;
            break;
        }
    }
    // for(int i=0; i<n; i++){
    //     cout<<a[i].money<<endl<<"-----"<<endl;
    // }
    // cout<<a[1].money<<endl;
    cout<<a[j].name<<endl<<a[j].money<<endl<<total<<endl;
}