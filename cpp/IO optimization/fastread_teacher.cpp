#include<bits/stdc++.h>
using namespace std;
#define TIMES 1000000
double A[5];
void print(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("111.txt","w",stdout);
    int a;
    double t1,t2;
    t1=clock();
    for(int i=1;i<=TIMES;i++)
        // scanf("%d",&a);
        cin>>a;
    t2=clock();
    A[1]=(t2-t1)/1000;
    t1=clock();
    for(int i=1;i<=TIMES;i++)
        read(a);
    t2=clock();
    A[2]=(t2-t1)/1000;
    t1=clock();
    for(int i=1;i<=TIMES;i++)
        printf("%d",a);
    t2=clock();
    A[3]=(t2-t1)/1000;
    t1=clock();
    for(int i=1;i<=TIMES;i++)
        print(a);
    t2=clock();
    A[4]=(t2-t1)/1000;
    fclose(stdout);//为了不输出前面一堆东西
    freopen("out.txt","w",stdout);
    printf("Cin:  %.4lf S\n",A[1]);
    printf("Read:   %.4lf S\n",A[2]);
    printf("Printf: %.4lf S\n",A[3]);
    printf("Print:  %.4lf S",A[4]);
}