#include<bits/stdc++.h>
using namespace std;
int I=0;
int o[127]={0};
int occurs(string a,char b,int stop){
    for(int i=0; i<stop; i++) if(a[i]==b) return i;
    return -1;
}
int boyermoore(char* a,char* b,int start=0){
    int as=strlen(a),bs=strlen(b);
    int cnt=0;
    if(start+bs>as) return -1;
    for(int i=start; i+bs<=as;){
        cnt++;
        for(int j=bs-1; j>=0; j--){
            // cout<<j<<endl;
            if(b[j]!=a[i+j]){
                if(o[a[i+j]]>=0){
                    i+=j-o[a[i+j]];
                    break;
                }else{
                    i+=j+1;
                    break;
                }
            }
            if(j==0){
                // cout<<a<<endl;
                // for(int j=0; j<i; j++) cout<<' ';
                // cout<<b<<endl;
                // cout<<cnt<<endl;
                return i;
            }
        }
        // cout<<a<<endl;
        // for(int j=0; j<i; j++) cout<<' ';
        // cout<<b<<endl;
    }
    return -1;
}
int main(){
    freopen("HarryPotter.txt","r",stdin);
    char a[7000000],b[]="Harry";
    int I=0;
    char c;
    while((c=getchar())!=EOF) a[I++]=c;
    a[I]='\0';
    // char a[]="THIS IS A SIMPLE EXAMPLEXAMPLE";
    // char b[]="EXAMPLE";
    for(int i=32; i<=126; i++) o[i]=occurs(b,(char)i,strlen(b));
    int t=0;
    int i=0;
    while((t=boyermoore(a,b,t+1))!=-1){
        cout<<"----- "<<t<<" -----"<<endl;
        i++;
    }
    cout<<i<<endl;
}