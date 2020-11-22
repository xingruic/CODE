#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int CNT=0;
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=i; j++){
            int a=j,b=i-j,c=i;
            int t1=a,t2=b,t3=c;
            int cnt=4;
            int t;
            do{
                t=a%10;
                switch(t){
                    case 0:
                        cnt+=6;
                        break;
                    case 1:
                        cnt+=2;
                        break;
                    case 2:
                        cnt+=5;
                        break;
                    case 3:
                        cnt+=5;
                        break;
                    case 4:
                        cnt+=4;
                        break;
                    case 5:
                        cnt+=5;
                        break;
                    case 6:
                        cnt+=6;
                        break;
                    case 7:
                        cnt+=3;
                        break;
                    case 8:
                        cnt+=7;
                        break;
                    default:
                        cnt+=6;
                        break;
                }
                a/=10;
            }while(a>0);
            do{
                t=b%10;
                switch(t){
                    case 0:
                        cnt+=6;
                        break;
                    case 1:
                        cnt+=2;
                        break;
                    case 2:
                        cnt+=5;
                        break;
                    case 3:
                        cnt+=5;
                        break;
                    case 4:
                        cnt+=4;
                        break;
                    case 5:
                        cnt+=5;
                        break;
                    case 6:
                        cnt+=6;
                        break;
                    case 7:
                        cnt+=3;
                        break;
                    case 8:
                        cnt+=7;
                        break;
                    default:
                        cnt+=6;
                        break;
                }
                b/=10;
            }while(b>0);
            do{
                t=c%10;
                switch(t){
                    case 0:
                        cnt+=6;
                        break;
                    case 1:
                        cnt+=2;
                        break;
                    case 2:
                        cnt+=5;
                        break;
                    case 3:
                        cnt+=5;
                        break;
                    case 4:
                        cnt+=4;
                        break;
                    case 5:
                        cnt+=5;
                        break;
                    case 6:
                        cnt+=6;
                        break;
                    case 7:
                        cnt+=3;
                        break;
                    case 8:
                        cnt+=7;
                        break;
                    default:
                        cnt+=6;
                        break;
                }
                c/=10;
            }while(c>0);
            if(cnt==n){
                CNT++;
                // cout<<t1<<'+'<<t2<<'='<<t3<<'\t'<<cnt<<endl;
            }
        }
    }
    cout<<CNT<<endl;
}