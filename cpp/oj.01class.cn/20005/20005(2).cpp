#include <bits/stdc++.h>
using namespace std;
bool book[1000000];
int n;
int t1,t2,max1,max2;
int l = 999999,r;
int main()
{
 cin>>n;
 for(int i = 1;i <= n;i++)
 {
  int a,b;
  cin>>a>>b;
  l = min(l,a);
  r = max(r,b);
  for(int i = a;i < b;i++)
   book[i] = 1;
 }
 for(int i = l;i < r;i++)
 {
  if(book[i] == 1)
  {
   t1++;
   
   max2 = max(max2,t2);
   t2 = 0;
  }
  else
  {
   t2++;
   
   max1 = max(max1,t1);
   t1 = 0;
  }
 }
 max1 = max(max1,t1);
 max2 = max(max2,t2);
 cout<<max1<<' '<<max2;
} 
