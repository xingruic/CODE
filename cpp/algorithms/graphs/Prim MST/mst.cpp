#include<iostream>
#define n 5
using namespace std;
int a[n][n]={
    { 0, 2, 0, 6, 0 }, 
    { 2, 0, 3, 8, 5 }, 
    { 0, 3, 0, 0, 7 }, 
    { 6, 8, 0, 0, 9 }, 
    { 0, 5, 7, 9, 0 }
};
int main(){
    bool selected[n]={1};
    int num=1;
    while(num<n){
        int u,v;
        int min=0x7fffffff;
        for(int i=0; i<n; i++){
            if(selected[i]){
                for(int j=0; j<n; j++){
                    if(!selected[j]&&a[i][j]){
                        if(a[i][j]<min){
                            min=a[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        cout<<num++<<".\t"<<u<<'-'<<v<<" : "<<a[u][v]<<endl;
        selected[v]=1;
    }
}