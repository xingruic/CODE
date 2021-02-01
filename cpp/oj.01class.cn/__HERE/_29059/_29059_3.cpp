#include<bits/stdc++.h>
using namespace std;
int shift=0;
int getfromspiral(int N, int I, int J, int i=0, int j=0){
    if(I-1==0){
        return shift+J;
    }
    if(J-1==0){
        if(I-1!=i){
            return shift+3*N+N-I-2;
        }
        return shift+1;
    }
    if(I==N){
        return shift+3*N-2-J+1;
    }
    if(J==N){
        return shift+N+I-1;
    }
    shift+=N*4-4;
    return getfromspiral(N-2,--I,--J,++i,++j);
}
int main(){
    int N,I,J;
    cin>>N>>I>>J;
    cout<<getfromspiral(N,I,J);
}