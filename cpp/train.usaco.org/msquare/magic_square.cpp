#include<bits/stdc++.h>
using namespace std;
struct Squares
{
    int a[9];
    int n;
    char p[100];
}s[40321];
struct squares
{
    int a[9];
    bool n;
}f[40321];
int ans[9];
int l=0,r=1;
int t1,t2;
bool cmp(int a[])
{
    for(int i=1;i<=8;++i)
    {
        if(a[i]!=ans[i])
        return false;
    }
    return true;
}
int big_small(int a[],int b[])
{
    for(int i=1;i<=8;++i)
    {
        if(a[i]>b[i])
        return 1;
        if(a[i]<b[i])
        return -1;
    }
    return 0;
}
bool used(int a[])
{
    int l=1,r=40320,mid,t;
    while(l<=r)
    {
        mid=(l+r)/2;
        t=big_small(f[mid].a,a);
        if(t>0)
        r=mid-1;
        if(t<0)
        l=mid+1;
        if(t==0)
        break;
    }
    if(f[mid].n==false)
    {
        f[mid].n=true;
        return false;
    }
    else
    return true;
}
void A()
{
    s[r]=s[l];
    for(int i=1;i<=4;++i)
    {
        t1=s[r].a[i];
        s[r].a[i]=s[r].a[8-i+1];
        s[r].a[8-i+1]=t1;
    }
    if(used(s[r].a)==true)
    {
        return ;
    }
    s[r].p[s[r].n]='A';
    ++s[r].n;
    ++r;
}
void B()
{
    s[r]=s[l];
    t1=s[r].a[4];
    t2=s[r].a[5];
    for(int i=4;i>=2;--i)
    {
        s[r].a[i]=s[r].a[i-1];
        s[r].a[8-i+1]=s[r].a[8-i+2];
    }
    s[r].a[1]=t1;
    s[r].a[8]=t2;
    if(used(s[r].a)==true)
    {
        return ;
    }
    s[r].p[s[r].n]='B';
    ++s[r].n;
    ++r;
}
void C()
{
    s[r]=s[l];
    t1=s[r].a[2];
    s[r].a[2]=s[r].a[7];
    s[r].a[7]=s[r].a[6];
    s[r].a[6]=s[r].a[3];
    s[r].a[3]=t1;
    if(used(s[r].a)==true)
    {
        return ;
    }
    s[r].p[s[r].n]='C';
    ++s[r].n;
    ++r;
}
int main()
{
    for(int i=1;i<=8;++i)
    {
        scanf("%d",&ans[i]);
    }
    f[1].n==true;
    for(int i=1;i<=8;++i)
    {
        s[l].a[i]=i;
    }
    for(int i=1;i<=40320;++i)
    {
        for(int j=1;j<=8;++j)
        {
            f[i].a[j]=s[l].a[j];
        }
        next_permutation(s[l].a+1,s[l].a+1+8);
    }
    for(int i=1;i<=8;++i)
    {
        s[l].a[i]=i;
    }
    while(1)
    {
        if(cmp(s[l].a)==true)
        break;
        A();
        B();
        C();
        ++l;
    }
    printf("%d",s[l].n);
    for(int i=0;i<s[l].n;++i)
    {
        if(i%60==0)
        printf("\n");
        printf("%c",s[l].p[i]);
    }
}