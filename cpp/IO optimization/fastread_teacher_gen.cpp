#include<bits/stdc++.h>
using namespace std;
#define TIMES 1000000
#define MAXN 100000
int main()
{
    srand(time(NULL));
    freopen("in.txt","w",stdout);
    for(int i=1;i<=TIMES*2;i++)
    {
        if(rand()%2)
            printf("-");
        printf("%d\n",rand()%MAXN);
    }
}