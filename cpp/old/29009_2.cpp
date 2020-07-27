#include<bits/stdc++.h>
using namespace std;
struct student{
  int LA, M, G, sum, num;
};
bool comp(student a,student b){
  if(a.sum>b.sum)return 1;
  else if(a.sum==b.sum&&a.LA>b.LA)return 1;
  else if(a.sum==b.sum&&a.LA==b.LA&&a.num<b.num)return 1;
  return 0;
}
int main(){
  int students;
  cin>>students;
  student stu[students];
  for(int i=0; i<students; i++){
    cin>>stu[i].LA>>stu[i].M>>stu[i].G;
    stu[i].sum=stu[i].LA+stu[i].M+stu[i].G;
    stu[i].num=i+1;
  }
  sort(stu,stu+students,comp);
  for(int i=0; i<5; i++){
    cout<<stu[i].num<<' '<<stu[i].sum<<endl;
  }
}

