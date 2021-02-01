#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,I,J;
    cin>>N>>I>>J;
    int spiral[N][N];
    memset(spiral,0,sizeof(spiral));
    int i=0,j=0;
    int dir=0;
    int cnt=1;
    bool done=0;
    while(!done){
        spiral[i][j]=cnt;
        switch(dir){
            case 0:
                if(j+1<N&&spiral[i][j+1]==0){
                    j++;
                    cnt++;
                }
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            case 1:
                if(i+1<N&&spiral[i+1][j]==0){
                    i++;
                    cnt++;
                }
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            case 2:
                if(i-1<N&&spiral[i-1][j]==0){
                    i--;
                    cnt++;
                }
                else if((i+1>=N||spiral[i+1][j])&&(j+1>=N||spiral[i][j+1])&&(i<1||spiral[i-1][j])&&(j<1||spiral[i][j-1])){
                    done=1;
                }else{
                    dir++;
                    dir%=4;
                }
                break;
            case 3:
                if(j-1<N&&spiral[i][j-1]==0){
                    j--;
                    cnt++;
                }
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
    cout<<spiral[I-1][J-1]<<endl;
}