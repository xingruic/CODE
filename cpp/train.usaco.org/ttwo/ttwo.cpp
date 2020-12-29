/*
ID:xingrui1
LANG:C++
TASK:ttwo
*/
#include<bits/stdc++.h>
using namespace std;
class passed{
    public:
    int i,j;
    char dir;
    passed(int ii,int jj,int ddir){
        i=ii,j=jj,dir=ddir;
    }
};
int main(){
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    // int t1=clock();
    char forest[10][10];
    int fi,fj,ci,cj; // position of farmer and cows
    int fdir=0,cdir=0; // 0=up,1=right,2=down,3=left
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            forest[i][j]=getchar();
            if(forest[i][j]=='\n') forest[i][j]=getchar();
            if(forest[i][j]=='F') fi=i,fj=j,forest[i][j]='.';
            if(forest[i][j]=='C') ci=i,cj=j,forest[i][j]='.';
        }
    }
    vector<passed> fpassed,cpassed;
    int cnt=0;
    while(fi!=ci||fj!=cj){
        // for(int i=0; i<10; i++){
        //     for(int j=0; j<10; j++){
        //         if(i==fi&&j==fj) cout<<'F';
        //         else if(i==ci&&j==cj) cout<<'C';
        //         else cout<<forest[i][j];
        //         cout<<' ';
        //     }cout<<endl;
        // }
        // cout<<fdir<<' '<<cdir<<endl;
        // cout<<endl;
        int T=0,TT=0;
        for(int i=0; i<fpassed.size(); i++){
            int t=0,tt=0;
            if(fpassed[i].i==fi&&fpassed[i].j==fj&&fpassed[i].dir==fdir){
                t=1;
                T=1;
            }
            if(cpassed[i].i==ci&&cpassed[i].j==cj&&cpassed[i].dir==cdir){
                tt=1;
                TT=1;
            }
            if(t&&tt){
                cout<<0<<endl;
                return 0;
            }
        }
        if(!T) fpassed.push_back(passed(fi,fj,fdir));
        if(!TT) cpassed.push_back(passed(ci,cj,cdir));
        switch(fdir){
            case 0:
            if(fi-1<0||forest[fi-1][fj]=='*'){
                fdir++;
                break;
            }
            fi--;
            break;

            case 1:
            if(fj+1==10||forest[fi][fj+1]=='*'){
                fdir++;
                break;
            }
            fj++;
            break;

            case 2:
            if(fi+1==10||forest[fi+1][fj]=='*'){
                fdir++;
                break;
            }
            fi++;
            break;

            default:
            if(fj-1<0||forest[fi][fj-1]=='*'){
                fdir=0;
                break;
            }
            fj--;
            break;
        }
        switch(cdir){
            case 0:
            if(ci-1<0||forest[ci-1][cj]=='*'){
                cdir++;
                break;
            }
            ci--;
            break;

            case 1:
            if(cj+1==10||forest[ci][cj+1]=='*'){
                cdir++;
                break;
            }
            cj++;
            break;

            case 2:
            if(ci+1==10||forest[ci+1][cj]=='*'){
                cdir++;
                break;
            }
            ci++;
            break;

            default:
            if(cj-1<0||forest[ci][cj-1]=='*'){
                cdir=0;
                break;
            }
            cj--;
            break;
        }
        cnt++;
    }
    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++){
    //         if(i==fi&&j==fj) cout<<'F';
    //         else if(i==ci&&j==cj) cout<<'C';
    //         else cout<<forest[i][j];
    //         cout<<' ';
    //     }cout<<endl;
    // }
    // cout<<fdir<<' '<<cdir<<endl;
    cout<<cnt<<endl;
    // cout<<clock()-t1<<endl;
    // cout<<fi<<' '<<fj<<' '<<ci<<' '<<cj<<endl;
}