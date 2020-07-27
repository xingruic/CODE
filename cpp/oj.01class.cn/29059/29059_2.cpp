#include<bits/stdc++.h>
using namespace std;
int shift=0;
int getfromspiral(int N, int I, int J, int i=0, int j=0){
    // cout<<I<<endl<<J<<endl<<i<<endl<<j<<endl<<endl;
    if(I-1==0){
        // cout<<1<<endl;
        return shift+J;
    }
    if(J-1==0){
        if(I-1!=i){
            // cout<<21<<endl;
            return shift+3*N+N-I-2;
        }
        // cout<<22<<endl;
        return shift+1;
    }
    if(I==N){
        // cout<<3<<endl;
        return shift+3*N-2-J+1;
    }
    if(J==N){
        // cout<<4<<endl;//ai+n+b=13
        return shift+N+I-1;
    }
    shift+=N*4-4;
    return getfromspiral(N-2,--I,--J,++i,++j);
}
void printspiral(int N){
    int spiral[N][N];
    memset(spiral,0,sizeof(spiral));
    bool done=0;
    int i=0,j=0;
    int dir=0;
    int cnt=1;
    while(!done){
        spiral[i][j]=cnt;
        cnt++;
        switch(dir){
            case 0:
                if(j+1<N&&spiral[i][j+1]==0) j++;
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            case 1:
                if(i+1<N&&spiral[i+1][j]==0) i++;
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            case 2:
                if(i-1<N&&spiral[i-1][j]==0) i--;
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            case 3:
                if(j-1<N&&spiral[i][j-1]==0) j--;
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            default:
                break;
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++) cout<<spiral[i][j]<<'\t';
        cout<<endl;
    }
}
int main(){
    int N,I,J;
    cin>>N>>I>>J;
    cout<<getfromspiral(N,I,J);
    cout<<endl;
    printspiral(N);
}