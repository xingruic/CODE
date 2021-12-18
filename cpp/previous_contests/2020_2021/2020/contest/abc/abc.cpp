#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[7];
    int m=0x7fffffff;
    for(int i=0; i<7; i++){
        cin>>arr[i];
        m=min(arr[i],m);
    }
    sort(arr,arr+7);
    for(int ic=0; ic<7; ic++){
        int c=arr[ic];
        for(int b=arr[1]; b==arr[1]; b++){
            for(int a=arr[0]; a==arr[0]; a++){
                bool flag[7]={0};
                bool aa,bb,cc,ab,bc,ac,abc;
                aa=bb=cc=ab=bc=ac=abc=0;
                for(int i=0; i<7; i++){
                    if(arr[i]==a&&!flag[i]&&!aa){
                        flag[i]=1;
                        aa=1;
                    }
                    if(arr[i]==b&&!flag[i]&&!bb){
                        flag[i]=1;
                        bb=1;
                    }
                    if(arr[i]==c&&!flag[i]&&!cc){
                        flag[i]=1;
                        cc=1;
                    }
                    if(arr[i]==a+b&&!flag[i]&&!ab){
                        flag[i]=1;
                        ab=1;
                    }
                    if(arr[i]==a+c&&!flag[i]&&!ac){
                        flag[i]=1;
                        ac=1;
                    }
                    if(arr[i]==b+c&&!flag[i]&&!bc){
                        flag[i]=1;
                        bc=1;
                    }
                    if(arr[i]==a+b+c&&!flag[i]&&!abc){
                        flag[i]=1;
                        abc=1;
                    }
                }
                int i;
                for(i=0; i<7; i++){
                    if(!flag[i]) break;
                }
                if(i==7){
                    cout<<a<<' '<<b<<' '<<c<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}